/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <raffi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:29:06 by rtchaker          #+#    #+#             */
/*   Updated: 2024/09/12 19:03:02 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player_direction_ns(t_game *data)
{
	if (data->map->player_orientation == M_PI_2)
	{
		data->player->dir_x = 0;
		data->player->dir_y = -1;
		data->plane_x = FOV;
		data->plane_y = 0;
	}
	else if (data->map->player_orientation == 3 * M_PI_2)
	{
		data->player->dir_x = 0;
		data->player->dir_y = 1;
		data->plane_x = -FOV;
		data->plane_y = 0;
	}
}

static void	set_player_direction_ew(t_game *data)
{
	if (data->map->player_orientation == 0)
	{
		data->player->dir_x = 1;
		data->player->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = FOV;
	}
	else if (data->map->player_orientation == M_PI)
	{
		data->player->dir_x = -1;
		data->player->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = -FOV;
	}
}

int	initialize_player(t_game *data)
{
	data->player = ft_calloc(1, sizeof(t_player));
	if (!data->player)
		return (MEM_ERR);
	data->player->pos_x = data->map->player_x_map + 0.5;
	data->player->pos_y = data->map->player_y_map + 0.5;
	set_player_direction_ns(data);
	set_player_direction_ew(data);
	data->player->fov_rd = (FOV * M_PI) / 180;
	data->player->angle = -data->map->player_orientation;
	return (SUCCESS);
}
