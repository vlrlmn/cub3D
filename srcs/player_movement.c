/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <raffi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:19:34 by rtchaker          #+#    #+#             */
/*   Updated: 2024/09/12 17:00:03 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	update_player_rotation(t_player *player, double rot, t_game *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rot) - player->dir_y
		* sin(rot);
	player->dir_y = old_dir_x * sin(rot) + player->dir_y
		* cos(rot);
	old_plane_x = data->plane_x;
	data->plane_x = data->plane_x * cos(rot) - data->plane_y
		* sin(rot);
	data->plane_y = old_plane_x * sin(rot) + data->plane_y
		* cos(rot);
}

static void	rotate_player(t_game *data, int i)
{
	t_player	*player;
	double		rotation;

	rotation = 0;
	player = data->player;
	if (i == 1)
	{
		rotation = -ROT_SPEED;
		player->angle += rotation;
	}
	else
	{
		rotation = ROT_SPEED;
		player->angle += ROT_SPEED;
	}
	if (player->angle < 0)
		player->angle += 2 * M_PI;
	if (player->angle >= 2 * M_PI)
		player->angle -= 2 * M_PI;
	update_player_rotation(player, rotation, data);
}

void	move_player(t_game *data, double move_x, double move_y)
{
	double	new_x;
	double	new_y;
	t_map	*map;

	map = data->map;
	new_x = data->player->pos_x + move_x;
	new_y = data->player->pos_y + move_y;
	if ((move_x != 0 || move_y != 0)
		&& map->matrix[(int)((new_y + P_RAD))][(int)((new_x + P_RAD))] != '1'
		&& map->matrix[(int)((new_y + P_RAD))][(int)((new_x - P_RAD))] != '1'
		&& map->matrix[(int)((new_y - P_RAD))][(int)((new_x + P_RAD))] != '1'
		&& map->matrix[(int)((new_y - P_RAD))][(int)((new_x - P_RAD))] != '1')
	{
		data->player->pos_x += move_x;
		data->player->pos_y += move_y;
	}
}

void	handle_rotation(t_game *data)
{
	if (data->player->rotate != 0)
	{
		rotate_player(data, data->player->rotate == -1);
		data->player->rotate = 0;
	}
}

void	handle_movement(t_player *player, double *move_x, double *move_y)
{
	double	angle;

	if (player->left_right != 0)
	{
		angle = player->angle + M_PI_2 * player->left_right;
		*move_x = cos(angle) * MOVE_SPEED;
		*move_y = sin(angle) * MOVE_SPEED;
		player->left_right = 0;
	}
	else if (player->up_down != 0)
	{
		*move_x = player->up_down * player->dir_x * MOVE_SPEED;
		*move_y = player->up_down * player->dir_y * MOVE_SPEED;
		player->up_down = 0;
	}
}
