/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <raffi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:22:16 by rtchaker          #+#    #+#             */
/*   Updated: 2024/09/12 21:58:36 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	handle_more_error(int error)
{
	if (error == MAP_FILE_ERR)
		print_error("Error: Failed to open map file\n");
	if (error == INVALID_MAP)
		print_error("Error: Parsing Map\n");
	else if (error == INVALID_MAP_LINE)
		print_error("Error: Invalid Map Line\n");
	else if (error == OPEN_MAP_BOUNDARY)
		print_error("Error: Open Map Boundary\n");
	else if (error == DUPLICATE_PLAYER)
		print_error("Error: Duplicate Player\n");
	else if (error == INVALID_PLAYER_POSITION)
		print_error("Error: Invalid Player Position\n");
	else if (error == NO_PLAYER)
		print_error("Error: No Player Found\n");
	else if (error == MLX_ERROR)
		print_error("Error: MLX Error\n");
}

int	handle_error(t_game *data, int error)
{
	if (error == TEX_FILE_ERR)
		print_error("Error: Failed to open texture file\n");
	else if (error == INVALID_MAP_FILE)
		print_error("Error: Incomplete or invalid map file\n");
	else if (error == TEXTURE_ERROR)
		print_error("Error: Parsing Texture\n");
	else if (error == TEX_MEM_ERR)
		print_error("Error: Allocating Memory for Textures\n");
	else if (error == DUPLICATE_FLOOR)
		print_error("Error: Duplicate Floor Color\n");
	else if (error == DUPLICATE_CEILING)
		print_error("Error: Duplicate Ceiling Color\n");
	else if (error == INVALID_COLOR_TEXTURE)
		print_error("Error: Invalid texture or color line\n");
	else if (error == COLOR_ERROR)
		print_error("Error: Parsing Color\n");
	else if (error == INVALID_COLOR)
		print_error("Error: Invalid Color\n");
	else if (error == DUPLICATE_TEXTURE)
		print_error("Error: Duplicate Texture\n");
	else
		handle_more_error(error);
	exit_and_clean(data, 1);
	return (0);
}
