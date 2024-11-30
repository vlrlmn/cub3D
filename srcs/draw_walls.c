/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <raffi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 08:00:20 by rtchaker          #+#    #+#             */
/*   Updated: 2024/09/07 14:38:12 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_game *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = data->win.img_addr + (y * data->win.line_length + x
			* (data->win.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_ceiling_and_floor(t_game *data)
{
	unsigned int	*dst;
	unsigned int	i;

	dst = (unsigned int *)data->win.img_addr;
	i = (HEIGHT * WIDTH) / 2;
	while (i--)
		*dst++ = data->colors.ceiling_color;
	i = (HEIGHT * WIDTH) / 2;
	while (i--)
		*dst++ = data->colors.floor_color;
}

int	calculate_texture_x(t_ray *ray, t_player *player, t_texture *texture)
{
	double	wall_x;
	int		texture_x;

	if (ray->side == 0)
		wall_x = player->pos_y / TILE + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = player->pos_x / TILE + ray->perp_wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	texture_x = (int)(wall_x * (double)(texture->width));
	return (texture_x);
}

void	draw_texture_pixels(t_game *data, t_ray *ray, t_texture *texture, int x)
{
	int			texture_x;
	int			texture_y;
	int			color;

	texture_x = calculate_texture_x(ray, data->player, texture);
	if ((ray->side == 0 && ray->dir_x > 0)
		|| (ray->side == 1 && ray->dir_y < 0))
		texture_x = texture->width - texture_x - 1;
	while (ray->draw_start <= ray->draw_end)
	{
		texture_y = ((ray->draw_start * 256 - HEIGHT * 128 + ray->line_height
					* 128) * texture->height) / ray->line_height / 256;
		if (texture_x < 0)
			texture_x = 0;
		else if (texture_x >= texture->width)
			texture_x = texture->width - 1;
		if (texture_y < 0)
			texture_y = 0;
		else if (texture_y >= texture->height)
			texture_y = texture->height - 1;
		color = texture->addr[texture_y * texture->width + texture_x];
		my_mlx_pixel_put(data, x, ray->draw_start++, color);
	}
}

void	draw_walls(t_game *data)
{
	int			x;
	t_ray		ray;
	t_texture	*texture;

	x = 0;
	while (x < WIDTH)
	{
		calculate_ray_parameters(data, &ray, x);
		calculate_ray_step_dist(data, &ray);
		perform_dda(data, &ray);
		calculate_line_height(&ray);
		if (ray.side == 0 && ray.dir_x > 0)
			texture = data->textures.east;
		else if (ray.side == 0 && ray.dir_x < 0)
			texture = data->textures.west;
		else if (ray.side == 1 && ray.dir_y > 0)
			texture = data->textures.south;
		else
			texture = data->textures.north;
		draw_texture_pixels(data, &ray, texture, x);
		x++;
	}
}
