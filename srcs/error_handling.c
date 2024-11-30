/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <raffi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:46:04 by rtchaker          #+#    #+#             */
/*   Updated: 2024/09/12 10:46:26 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_error(char *msg)
{
	printf("%s", msg);
	return (-1);
}

int	error_free(char *line, int error)
{
	free(line);
	return (error);
}

int	error_closefd(int fd, int error)
{
	close(fd);
	return (error);
}

int	error_free_closefd(int fd, char *line, int error)
{
	free(line);
	line = NULL;
	close(fd);
	return (error);
}
