/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <raffi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:14:06 by rtchaker          #+#    #+#             */
/*   Updated: 2024/09/12 15:31:14 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rgb_to_hex(int *array)
{
	int	i;
	int	hex_value;

	hex_value = 0;
	i = 0;
	while (i < 3)
	{
		if (array[i] < 0 || array[i] > 255)
			return (INVALID_COLOR);
		hex_value = (hex_value << 8) | array[i];
		i++;
	}
	return (hex_value);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (array != NULL)
	{
		while (array[i] != NULL)
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}

int	is_valid_texture_line(const char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0)
	{
		line += 2;
		while (*line == ' ' || *line == '\t')
			line++;
		while (*line)
		{
			if (!(ft_isdigit(*line) || ft_isalpha(*line) || *line == '/'
					|| *line == '.' || *line == '-' || *line == '_'
					|| *line == '~' || *line == '\n'))
				return (0);
			line++;
		}
		return (1);
	}
	return (0);
}

int	is_valid_color_line(const char *line)
{
	int	i;
	int	comma_count;
	int	digit_count;

	if (*line != 'F' && *line != 'C')
		return (0);
	i = 0;
	comma_count = 0;
	digit_count = 0;
	while (line[++i])
	{
		if (ft_isdigit(line[i]))
			digit_count++;
		else if (line[i] == ',' && digit_count && comma_count < 2)
		{
			comma_count++;
			digit_count = 0;
		}
		else if (line[i] != ' ' && line[i] != '\t')
			return (0);
		else if ((line[i] == ' ' || line[i] == '\t') && digit_count)
			return (0);
	}
	return (comma_count == 2 && digit_count > 0);
}
