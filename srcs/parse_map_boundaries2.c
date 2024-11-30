/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_boundaries2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <raffi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:40:06 by rtchaker          #+#    #+#             */
/*   Updated: 2024/09/12 22:06:10 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_open_space_adjacent(t_map *map, size_t x, int y, size_t line_len)
{
	if (x > 0 && map->matrix[y][x - 1] == ' ')
		return (1);
	if (x < line_len && map->matrix[y][x + 1] == ' ')
		return (1);
	if (y > 0 && map->matrix[y - 1][x] == ' ')
		return (1);
	if (y < map->map_height && map->matrix[y + 1][x] == ' ')
		return (1);
	return (0);
}

static int	check_side_boundaries(t_map *map, size_t x, int y, size_t line_len)
{
	if (x - 1 == 0 && (map->matrix[y][x - 1] != '1'
		|| map->matrix[y + 1][x - 1] != '1'
		|| map->matrix[y - 1][x - 1] != '1'))
		return (1);
	if (x + 1 == line_len - 1 && (map->matrix[y][x + 1] != '1'
		|| map->matrix[y + 1][x + 1] != '1'
		|| map->matrix[y - 1][x + 1] != '1'))
		return (1);
	return (0);
}

static int	check_diagonal_boundaries(t_map *map, size_t x, int y)
{
	if (y - 1 == 0 && (map->matrix[y - 1][x] != '1'
		|| map->matrix[y - 1][x + 1] != '1'
		|| map->matrix[y - 1][x - 1] != '1'))
		return (1);
	if (y + 1 == map->map_height - 1 && (map->matrix[y + 1][x] != '1'
		|| map->matrix[y + 1][x + 1] != '1'
		|| map->matrix[y + 1][x - 1] != '1'))
		return (1);
	if (map->matrix[y - 1][x - 1] == ' ' || map->matrix[y - 1][x + 1] == ' '
		|| map->matrix[y + 1][x - 1] == ' ' || map->matrix[y + 1][x] == ' '
		|| map->matrix[y - 1][x - 1] == '\0'
		|| map->matrix[y - 1][x + 1] == '\0'
		|| map->matrix[y + 1][x] == '\0' || map->matrix[y + 1][x + 1] == '\0')
		return (1);
	return (0);
}

int	check_open_boundary(t_map *map, size_t x, int y, size_t line_len)
{
	if (is_open_space_adjacent(map, x, y, line_len))
		return (1);
	if (check_side_boundaries(map, x, y, line_len))
		return (1);
	if (check_diagonal_boundaries(map, x, y))
		return (1);
	return (0);
}
