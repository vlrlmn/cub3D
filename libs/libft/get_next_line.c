/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <raffi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:31:25 by rtchaker          #+#    #+#             */
/*   Updated: 2024/09/07 14:29:33 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*free_buffer(char **buffer_copy)
{
	free(*buffer_copy);
	*buffer_copy = NULL;
	return (NULL);
}

static char	*extract_line(char *newline_ptr, char **buffer_copy)
{
	int		newline_index;
	int		rem_len;
	char	*line;

	newline_index = newline_ptr - *buffer_copy;
	line = ft_substr(*buffer_copy, 0, newline_index + 1);
	if (line == NULL)
		return (free_buffer(buffer_copy));
	rem_len = ft_strlen(*buffer_copy + newline_index + 1);
	ft_memcpy(*buffer_copy, *buffer_copy + newline_index + 1, rem_len + 1);
	return (line);
}

static char	*complete_line(char *newline_ptr, char **buffer_copy)
{
	char	*line;

	line = NULL;
	if (!newline_ptr && (*buffer_copy)[0] == '\0')
		return (free_buffer(buffer_copy));
	else
	{
		line = *buffer_copy;
		*buffer_copy = NULL;
		return (line);
	}
}

static int	concatenate(char **buffer_copy, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(*buffer_copy, buffer);
	if (temp == NULL)
		return (0);
	free(*buffer_copy);
	*buffer_copy = temp;
	return (1);
}

char	*get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE + 1];
	char			*newline_ptr;
	static char		*buffer_copy;
	int				chars_read;

	newline_ptr = NULL;
	while (!newline_ptr)
	{
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read < 0)
			return (free_buffer(&buffer_copy));
		buffer[chars_read] = '\0';
		if (concatenate(&buffer_copy, buffer) == 0)
			return (free_buffer(&buffer_copy));
		newline_ptr = ft_strchr(buffer_copy, '\n');
		if (chars_read == 0)
			break ;
	}
	if (newline_ptr)
		return (extract_line(newline_ptr, &buffer_copy));
	return (complete_line(newline_ptr, &buffer_copy));
}
