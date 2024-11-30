/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <raffi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:29:06 by rtchaker          #+#    #+#             */
/*   Updated: 2024/09/12 20:39:37 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game_struct(t_game *data)
{
	data->textures.north = NULL;
	data->textures.south = NULL;
	data->textures.east = NULL;
	data->textures.west = NULL;
	data->win.mlx_ptr = NULL;
	data->win.win_ptr = NULL;
	data->win.img_ptr = NULL;
	data->win.img_addr = NULL;
	data->colors.parsed = 0;
	data->colors.ceiling_color = 0;
	data->colors.floor_color = 0;
	data->colors.ceiling_parsed = 0;
	data->colors.floor_parsed = 0;
	data->textures.allocated = 0;
	data->textures.parsed = 0;
	data->map = NULL;
	data->player = NULL;
	data->plane_x = 0;
	data->plane_y = 0.66;
	data->error = 0;
	data->map_parsed = 0;
}

int	setup_game_window(t_game *data)
{
	data->win.mlx_ptr = mlx_init();
	if (!data->win.mlx_ptr)
		return (MLX_ERROR);
	data->win.win_ptr = mlx_new_window(data->win.mlx_ptr,
			WIDTH, HEIGHT, "cub3D");
	if (!data->win.win_ptr)
		return (MLX_ERROR);
	data->win.img_ptr = mlx_new_image(data->win.mlx_ptr,
			WIDTH, HEIGHT);
	if (!data->win.img_ptr)
		return (MLX_ERROR);
	data->win.img_addr = mlx_get_data_addr(data->win.img_ptr,
			&data->win.bits_per_pixel, &data->win.line_length,
			&data->win.endian);
	if (!data->win.img_addr)
		return (MLX_ERROR);
	return (SUCCESS);
}

int	initialize_game(t_game *data)
{
	int	status;

	status = setup_game_window(data);
	if (status != SUCCESS)
		return (status);
	status = load_all_textures(data);
	if (status != SUCCESS)
		return (status);
	status = initialize_player(data);
	if (status != SUCCESS)
		return (status);
	start_game_loop(data);
	mlx_destroy_image(data->win.mlx_ptr, data->win.img_ptr);
	return (SUCCESS);
}
