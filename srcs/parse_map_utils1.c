/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <raffi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:12:00 by rtchaker          #+#    #+#             */
/*   Updated: 2024/09/12 16:06:52 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_map_line(const char *line, t_map *map)
{
	while (*line)
	{
		if (*line != '0' && *line != '1' && *line != 'N' && *line != 'E'
			&& *line != 'W' && *line != 'S' && *line != ' ' && *line != '\n')
			return (INVALID_MAP_LINE);
		if ((*line == 'N' || *line == 'E'
				|| *line == 'W' || *line == 'S'))
		{
			if (map->player_found == 0)
				map->player_found = 1;
			else
				return (DUPLICATE_PLAYER);
		}
		line++;
	}
	return (0);
}

int	fill_matrix(char *dest, const char *src)
{
	while (*src && *src != '\n')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (0);
}

size_t	find_map_width(t_list *map_list)
{
	size_t	max_length;
	size_t	current_length;

	max_length = 0;
	while (map_list)
	{
		current_length = ft_strlen((char *)map_list->content);
		if (current_length > max_length)
		{
			max_length = current_length;
		}
		map_list = map_list->next;
	}
	return (max_length);
}

static int	is_player_position(char c)
{
	return (c == 'N' || c == 'E' || c == 'W' || c == 'S');
}

int	find_player_position(t_game *data)
{
	int		y;
	size_t	x;

	y = 0;
	while (y < data->map->map_height)
	{
		x = 0;
		while (x < data->map->map_width)
		{
			if (is_player_position(data->map->matrix[y][x]))
			{
				data->map->player_x_map = x;
				data->map->player_y_map = y;
				set_player_orientation(data, data->map->matrix[y][x]);
				if (check_open_boundary(data->map, x, y, data->map->map_width))
					return (INVALID_PLAYER_POSITION);
				data->map->matrix[y][x] = '0';
				return (0);
			}
			x++;
		}
		y++;
	}
	return (NO_PLAYER);
}
