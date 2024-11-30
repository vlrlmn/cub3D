/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <raffi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:04:36 by rtchaker          #+#    #+#             */
/*   Updated: 2024/09/12 19:32:50 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	process_map_line(t_map *map, char *line, int i)
{
	map->matrix[i] = malloc(sizeof(char) * (map->map_width + 1));
	if (map->matrix[i] == NULL)
		return (error_free(line, MAP_MEM_ERR));
	if (fill_matrix(map->matrix[i], line) != 0)
		return (error_free(line, INVALID_MAP));
	return (0);
}

static int	populate_map_array(t_list *map_list, t_map *map)
{
	int	i;
	int	status;

	i = 0;
	while (map_list)
	{
		if (i == 0)
		{
			map->matrix = ft_calloc(map->map_height, sizeof(char *));
			if (!map->matrix)
				return (MAP_MEM_ERR);
		}
		status = process_map_line(map, (char *)map_list->content, i++);
		if (status != SUCCESS)
			return (status);
		map_list = map_list->next;
	}
	if (i == 0)
		return (INVALID_MAP);
	return (0);
}

static int	handle_map_line(char *line, t_map *map)
{
	t_list	*new_node;
	int		status;

	status = is_valid_map_line(line, map);
	if (status != SUCCESS)
		return (status);
	new_node = ft_lstnew(line);
	if (!new_node)
		return (MAP_MEM_ERR);
	ft_lstadd_back(&map->map_list, new_node);
	return (SUCCESS);
}

static int	parse_map_lines(int fd, char *line, t_map *map)
{
	int		last_line_empty;
	int		status;

	last_line_empty = 0;
	while (line)
	{
		if (is_line_empty(line))
		{
			if (map->map_started)
				last_line_empty = 1;
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		if (last_line_empty && map->map_started)
			return (INVALID_MAP);
		map->map_started = 1;
		last_line_empty = 0;
		status = handle_map_line(line, map);
		if (status != SUCCESS)
			return (status);
		line = get_next_line(fd);
	}
	return (0);
}

int	parse_map(int fd, char *line, t_game *data)
{
	int		status;

	status = 0;
	data->map = ft_calloc(1, sizeof(t_map));
	if (!data->map)
		return (MAP_MEM_ERR);
	init_map(data->map);
	status = parse_map_lines(fd, line, data->map);
	if (status != SUCCESS)
		return (status);
	data->map->map_height = ft_lstsize(data->map->map_list);
	data->map->map_width = find_map_width(data->map->map_list);
	status = populate_map_array(data->map->map_list, data->map);
	if (status != SUCCESS)
		return (status);
	status = is_open_boundary(data);
	if (status != SUCCESS)
		return (status);
	status = find_player_position(data);
	if (status != SUCCESS)
		return (status);
	data->map_parsed = 1;
	return (status);
}
