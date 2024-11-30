/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <raffi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:47:44 by rtchaker          #+#    #+#             */
/*   Updated: 2024/09/12 17:00:28 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	render_frame(t_game *data)
{
	draw_ceiling_and_floor(data);
	draw_walls(data);
	mlx_put_image_to_window(data->win.mlx_ptr, data->win.win_ptr,
		data->win.img_ptr, 0, 0);
}

static int	game_loop(t_game *data)
{
	handle_player_actions(data);
	render_frame(data);
	return (0);
}

void	start_game_loop(t_game *data)
{
	mlx_loop_hook(data->win.mlx_ptr, game_loop, data);
	mlx_hook(data->win.win_ptr, 2, 1L << 0, key_press, data);
	mlx_hook(data->win.win_ptr, 3, 1L << 1, key_release, data);
	mlx_hook(data->win.win_ptr, 17, 0, (int (*)(void *))exit_and_clean, data);
	mlx_loop(data->win.mlx_ptr);
}
