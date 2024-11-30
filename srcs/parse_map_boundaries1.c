/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_boundaries1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <raffi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:22:22 by rtchaker          #+#    #+#             */
/*   Updated: 2024/09/12 18:41:13 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_row_and_column_edges(t_map *map)
{
	size_t	i;
	int		j;

	i = 0;
	while (i < map->map_width)
	{
		if (map->matrix[0][i] == '0'
			|| map->matrix[map->map_height - 1][i] == '0')
		{
			return (1);
		}
		i++;
	}
	j = 0;
	while (j < map->map_height)
	{
		if (map->matrix[j][0] == '0'
			|| map->matrix[j][map->map_width - 1] == '0')
		{
			return (1);
		}
		j++;
	}
	return (0);
}

static size_t	get_line_len(t_map *map, int y)
{
	int	len;
	int	x;

	len = 0;
	x = 0;
	while (map->matrix[y][x] != '\0')
		x++;
	len = x;
	return (len);
}

int	is_open_boundary(t_game *data)
{
	size_t	x;
	int		y;
	size_t	line_len;

	if (check_row_and_column_edges(data->map))
		return (OPEN_MAP_BOUNDARY);
	y = 0;
	while (y < data->map->map_height)
	{
		x = 0;
		line_len = get_line_len(data->map, y);
		while (x < data->map->map_width)
		{
			if (data->map->matrix[y][x] == '0')
			{
				if (check_open_boundary(data->map, x, y, line_len))
					return (INVALID_MAP_LINE);
			}
			x++;
		}
		y++;
	}
	return (0);
}
