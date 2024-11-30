/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <raffi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:29:25 by rtchaker          #+#    #+#             */
/*   Updated: 2024/09/12 20:39:51 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	data;
	int		status;

	if (argc != 2 || !argv[1])
		return (printf("Usage: [command] ./cub3D [map] *.cub\n"), 1);
	if (invalid_map_extension(argv[1]))
		return (printf("Error: Map must have .cub extension\n"), 1);
	init_game_struct(&data);
	status = parse_map_file(argv[1], &data);
	if (status != SUCCESS)
		handle_error(&data, status);
	status = initialize_game(&data);
	if (status != SUCCESS)
		handle_error(&data, status);
	exit_and_clean(&data, 0);
	return (0);
}
