/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:28:10 by rtchaker          #+#    #+#             */
/*   Updated: 2024/09/12 16:27:32 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_release(int keycode, t_game *data)
{
	if (keycode == D)
		data->player->left_right = 0;
	else if (keycode == A)
		data->player->left_right = 0;
	else if (keycode == S)
		data->player->up_down = 0;
	else if (keycode == W)
		data->player->up_down = 0;
	else if (keycode == LEFT_ARROW)
		data->player->rotate = 0;
	else if (keycode == RIGHT_ARROW)
		data->player->rotate = 0;
	return (0);
}

int	key_press(int keycode, t_game *data)
{
	if (keycode == ESC || keycode == 12)
		exit_and_clean(data, 0);
	else if (keycode == A)
		data->player->left_right = -1;
	else if (keycode == D)
		data->player->left_right = 1;
	else if (keycode == S)
		data->player->up_down = -1;
	else if (keycode == W)
		data->player->up_down = 1;
	else if (keycode == LEFT_ARROW)
		data->player->rotate = -1;
	else if (keycode == RIGHT_ARROW)
		data->player->rotate = 1;
	return (0);
}
