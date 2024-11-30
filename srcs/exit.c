/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <raffi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:32:51 by rtchaker          #+#    #+#             */
/*   Updated: 2024/09/12 20:38:38 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_matrix(t_map *map)
{
	int	i;

	if (map->matrix == NULL)
		return ;
	i = 0;
	while (i < map->map_height)
	{
		if (map->matrix[i] != NULL)
		{
			free(map->matrix[i]);
			map->matrix[i] = NULL;
		}
		i++;
	}
	free(map->matrix);
	map->matrix = NULL;
}

void	free_map(t_map *map)
{
	if (map != NULL && map->matrix != NULL)
		free_matrix(map);
}

static void	free_texture_path(t_texture *texture, void *mlx_ptr)
{
	if (texture)
	{
		if (texture->img)
			mlx_destroy_image(mlx_ptr, texture->img);
		if (texture->path)
			free(texture->path);
		free(texture);
	}
}

void	free_textures(t_game *data)
{
	free_texture_path(data->textures.north, data->win.mlx_ptr);
	free_texture_path(data->textures.south, data->win.mlx_ptr);
	free_texture_path(data->textures.east, data->win.mlx_ptr);
	free_texture_path(data->textures.west, data->win.mlx_ptr);
}

void	exit_and_clean(t_game *data, int error_code)
{
	free_textures(data);
	if (data->map != NULL)
	{
		if (data->map->map_list != NULL)
			ft_lstclear(&data->map->map_list, free);
		free_map(data->map);
		free(data->map);
		data->map = NULL;
	}
	if (data->player != NULL)
	{
		free(data->player);
		data->player = NULL;
	}
	if (data->win.img_ptr != NULL)
		mlx_destroy_image(data->win.mlx_ptr, data->win.img_ptr);
	if (data->win.win_ptr != NULL)
		mlx_destroy_window(data->win.mlx_ptr, data->win.win_ptr);
	if (data->win.mlx_ptr != NULL)
		free(data->win.mlx_ptr);
	data->win.mlx_ptr = NULL;
	printf("Game Ended\n");
	exit(error_code);
}
