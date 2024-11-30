/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <raffi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:23:55 by rtchaker          #+#    #+#             */
/*   Updated: 2024/09/12 21:20:45 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	load_texture(t_game *data, t_texture *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(data->win.mlx_ptr, path,
			&texture->width, &texture->height);
	if (!texture->img)
		return (TEXTURE_ERROR);
	texture->addr = (int *)mlx_get_data_addr(texture->img,
			&texture->bits_per_pixel, &texture->line_length, &texture->endian);
	if (!texture->addr)
		return (MLX_ERROR);
	return (SUCCESS);
}

int	load_all_textures(t_game *data)
{
	int	status;

	status = load_texture(data, data->textures.north,
			data->textures.north->path);
	if (status != SUCCESS)
		return (status);
	status = load_texture(data, data->textures.south,
			data->textures.south->path);
	if (status != SUCCESS)
		return (status);
	status = load_texture(data, data->textures.west,
			data->textures.west->path);
	if (status != SUCCESS)
		return (status);
	status = load_texture(data, data->textures.east,
			data->textures.east->path);
	if (status != SUCCESS)
		return (status);
	return (SUCCESS);
}

int	file_exists(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (TEX_FILE_ERR);
	close(fd);
	return (1);
}
