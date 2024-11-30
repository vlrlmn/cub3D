/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <raffi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:17:35 by rtchaker          #+#    #+#             */
/*   Updated: 2024/09/12 21:57:45 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*trim_line(char *line)
{
	char	*trimmed;

	if (!line || !*line)
		return (NULL);
	trimmed = ft_strtrim(line, " \t\n\v\f\r");
	if (!trimmed)
		return (line);
	return (trimmed);
}

static char	*skip_empty_line(int fd, char *line)
{
	while (line && is_line_empty(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

static int	parse_texture_and_color(char *line, t_game *data)
{
	int	status;

	line = trim_line(line);
	if (is_valid_texture_line(line))
	{
		status = parse_texture(line, data);
		if (status < SUCCESS)
			return (status);
	}
	else if (is_valid_color_line(line))
	{
		status = parse_floor_ceiling_color(line, data);
		if (status < SUCCESS)
			return (status);
	}
	else
		return (INVALID_COLOR_TEXTURE);
	return (0);
}

static int	process_line(char *line, t_game *data, int fd)
{
	int	status;

	if (!data->textures.parsed || !data->colors.parsed)
	{
		status = parse_texture_and_color(line, data);
		if (status != SUCCESS)
			return (error_free_closefd(fd, line, status));
	}
	else if (data->textures.parsed && data->colors.parsed)
	{
		status = parse_map(fd, line, data);
		if (status != SUCCESS)
			return (error_closefd(fd, status));
		return (SUCCESS);
	}
	else
		return (error_closefd(fd, INVALID_MAP_LINE));
	return (SUCCESS);
}

int	parse_map_file(char *filename, t_game *data)
{
	int		fd;
	char	*line;
	int		status;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (MAP_FILE_ERR);
	line = get_next_line(fd);
	while (line)
	{
		line = skip_empty_line(fd, line);
		if (!line)
			break ;
		status = process_line(line, data, fd);
		if (status != SUCCESS)
			return (status);
		if (data->map_parsed)
			break ;
		free(line);
		line = get_next_line(fd);
	}
	if (!data->textures.parsed || !data->colors.parsed || !data->map_parsed)
		return (error_closefd(fd, INVALID_MAP_FILE));
	return (close(fd), SUCCESS);
}
