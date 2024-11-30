/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raffi <raffi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:26:27 by raffi             #+#    #+#             */
/*   Updated: 2024/09/04 15:32:15 by raffi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_orientation(t_game *data, char path)
{
	if (path == 'N')
		data->map->player_orientation = M_PI_2;
	else if (path == 'S')
		data->map->player_orientation = 3 * M_PI_2;
	else if (path == 'E')
		data->map->player_orientation = 0;
	else if (path == 'W')
		data->map->player_orientation = M_PI;
}

void	handle_player_actions(t_game *data)
{
	double	move_x;
	double	move_y;

	move_x = 0;
	move_y = 0;
	handle_rotation(data);
	handle_movement(data->player, &move_x, &move_y);
	move_player(data, move_x, move_y);
}
