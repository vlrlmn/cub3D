/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <raffi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:58:56 by rtchaker          #+#    #+#             */
/*   Updated: 2024/09/12 15:51:32 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_isdigit_str(const char *str)
{
	int	i;

	i = 0;
	if (!str || str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static char	**create_temp_num_array(const char *line)
{
	char	*trimmed;
	char	**temp_num_array;

	if (!line || *(++line) != ' ')
		return (NULL);
	trimmed = ft_strtrim(line, " \t\n\v\f\r");
	if (!trimmed)
		return (NULL);
	temp_num_array = ft_split(trimmed, ',');
	free(trimmed);
	return (temp_num_array);
}

static int	parse_color(const char *line)
{
	char	**temp_num_array;
	int		color_values[3];
	int		i;
	int		hex_color;

	temp_num_array = create_temp_num_array(line);
	if (!temp_num_array)
		return (MEM_ERR);
	i = 0;
	while (temp_num_array[i] && i < 3)
	{
		if (!ft_isdigit_str(temp_num_array[i]))
			return (free_array(temp_num_array), INVALID_COLOR);
		color_values[i] = ft_atoi(temp_num_array[i]);
		i++;
	}
	if (i != 3 || temp_num_array[i])
		return (free_array(temp_num_array), INVALID_COLOR);
	hex_color = rgb_to_hex(color_values);
	return (free_array(temp_num_array), hex_color);
}

static int	handle_color_line(char *line, t_colors *colors)
{
	int	color_value;

	color_value = 0;
	if (*line == 'F')
	{
		if (colors->floor_parsed)
			return (DUPLICATE_FLOOR);
		color_value = parse_color(line);
		if (color_value < 0)
			return (color_value);
		colors->floor_color = color_value;
		colors->floor_parsed = 1;
	}
	else if (*line == 'C')
	{
		if (colors->ceiling_parsed)
			return (DUPLICATE_CEILING);
		color_value = parse_color(line);
		if (color_value < 0)
			return (color_value);
		colors->ceiling_color = color_value;
		colors->ceiling_parsed = 1;
	}
	return (0);
}

int	parse_floor_ceiling_color(char *line, t_game *data)
{
	int	status;

	status = 0;
	status = handle_color_line(line, &data->colors);
	if (status != SUCCESS)
		return (status);
	if (data->colors.ceiling_color != 0 && data->colors.floor_color != 0)
	{
		data->colors.parsed = 1;
		return (0);
	}
	return (1);
}
