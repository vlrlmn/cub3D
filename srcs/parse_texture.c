/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <raffi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:02:27 by rtchaker          #+#    #+#             */
/*   Updated: 2024/09/12 21:21:23 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	alloclate_textures(t_game *data)
{
	t_textures_set	*textures;

	textures = &data->textures;
	textures->parsed = 0;
	textures->north = malloc(sizeof(t_texture));
	textures->south = malloc(sizeof(t_texture));
	textures->east = malloc(sizeof(t_texture));
	textures->west = malloc(sizeof(t_texture));
	if (!textures->north || !textures->south
		|| !textures->east || !textures->west)
		return (TEX_MEM_ERR);
	textures->north->path = NULL;
	textures->north->img = NULL;
	textures->south->path = NULL;
	textures->south->img = NULL;
	textures->east->path = NULL;
	textures->east->img = NULL;
	textures->west->path = NULL;
	textures->west->img = NULL;
	textures->allocated = 1;
	textures->north_parsed = 0;
	textures->east_parsed = 0;
	textures->south_parsed = 0;
	textures->west_parsed = 0;
	return (SUCCESS);
}

static int	set_north_south(char *line, t_game *data, char *path)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		if (data->textures.north_parsed)
			return (DUPLICATE_TEXTURE);
		data->textures.north->path = ft_strdup(path);
		data->textures.north_parsed = 1;
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		if (data->textures.south_parsed)
			return (DUPLICATE_TEXTURE);
		data->textures.south->path = ft_strdup(path);
		data->textures.south_parsed = 1;
	}
	else
		return (TEXTURE_ERROR);
	return (SUCCESS);
}

static int	set_east_west(char *line, t_game *data, char *path)
{
	if (ft_strncmp(line, "WE ", 3) == 0)
	{
		if (data->textures.west_parsed)
			return (DUPLICATE_TEXTURE);
		data->textures.west->path = ft_strdup(path);
		data->textures.west_parsed = 1;
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		if (data->textures.east_parsed)
			return (DUPLICATE_TEXTURE);
		data->textures.east->path = ft_strdup(path);
		data->textures.east_parsed = 1;
	}
	else
		return (TEXTURE_ERROR);
	return (SUCCESS);
}

static int	set_texture_path(char *line, t_game *data, char *path)
{
	int	result;

	result = set_north_south(line, data, path);
	if (result == TEXTURE_ERROR)
		result = set_east_west(line, data, path);
	return (result);
}

int	parse_texture(char *line, t_game *data)
{
	char	*path;
	int		status;

	if (!data->textures.allocated)
	{
		status = alloclate_textures(data);
		if (status != SUCCESS)
			return (status);
	}
	path = ft_strtrim(line + 3, " \n");
	if (file_exists(path) == TEX_FILE_ERR)
		return (error_free(path, TEX_FILE_ERR));
	status = set_texture_path(line, data, path);
	free(path);
	if (status != SUCCESS)
		return (status);
	if (data->textures.north->path && data->textures.south->path
		&& data->textures.west->path && data->textures.east->path)
		data->textures.parsed = 1;
	return (0);
}
