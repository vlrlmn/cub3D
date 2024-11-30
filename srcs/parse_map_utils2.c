/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <raffi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:22:22 by rtchaker          #+#    #+#             */
/*   Updated: 2024/09/12 20:40:52 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_line_empty(const char *line)
{
	if (line == NULL || line[0] == '\0')
		return (1);
	while (*line)
	{
		if (!ft_isspace((unsigned char)*line))
			return (0);
		line++;
	}
	return (1);
}

int	invalid_map_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (ft_strncmp(file + len - 4, ".cub", 4) == 0)
		return (0);
	else
		return (1);
}

void	init_map(t_map *map)
{
	map->map_width = 0;
	map->map_height = 0;
	map->map_list = NULL;
	map->player_orientation = 0;
	map->player_found = 0;
	map->map_started = 0;
}
