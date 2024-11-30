/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <raffi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 08:02:30 by rtchaker          #+#    #+#             */
/*   Updated: 2024/09/12 16:40:32 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_ray_parameters(t_game *data, t_ray *ray, int x)
{
	t_player	*player;

	player = data->player;
	ray->camera_x = 2 * x / (double)WIDTH - 1;
	ray->dir_x = player->dir_x + data->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + data->plane_y * ray->camera_x;
	ray->map_x = (int)(player->pos_x / TILE);
	ray->map_y = (int)(player->pos_y / TILE);
	ray->delta_dist_x = fabs(1 / ray->dir_x);
	ray->delta_dist_y = fabs(1 / ray->dir_y);
}

static void	calculate_step_dist_x(t_player *player, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - ray->map_x * TILE)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = ((ray->map_x + 1.0) * TILE - player->pos_x)
			* ray->delta_dist_x;
	}
}

static void	calculate_step_dist_y(t_player *player, t_ray *ray)
{
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - ray->map_y * TILE)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = ((ray->map_y + 1.0) * TILE - player->pos_y)
			* ray->delta_dist_y;
	}
}

void	calculate_ray_step_dist(t_game *data, t_ray *ray)
{
	t_player	*player;

	player = data->player;
	calculate_step_dist_x(player, ray);
	calculate_step_dist_y(player, ray);
}

void	calculate_line_height(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}
