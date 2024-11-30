/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <raffi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 08:13:06 by rtchaker          #+#    #+#             */
/*   Updated: 2024/09/12 21:58:29 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"

# define WIDTH 800
# define HEIGHT 700
# define TILE 1
# define FOV 0.66
# define ROT_SPEED 0.045
# define MOVE_SPEED 1.0
# define P_RAD 0.1
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define LEFT_ARROW 123
# define RIGHT_ARROW 124

# define ERR -1
# define SUCCESS 0
# define MEM_ERR -8
# define MAP_FILE_ERR -7
# define INVALID_MAP_FILE -6
# define TEXTURE_ERROR -5
# define TEX_MEM_ERR -4
# define COLOR_ERROR -17
# define DUPLICATE_CEILING -9
# define DUPLICATE_FLOOR -10
# define INVALID_COLOR_TEXTURE -11
# define INVALID_MAP -12
# define INVALID_MAP_LINE -13
# define MAP_MEM_ERR -14
# define NO_PLAYER -15
# define OPEN_MAP_BOUNDARY -16
# define DUPLICATE_PLAYER -18
# define INVALID_PLAYER_POSITION -19
# define INVALID_COLOR -20
# define TEX_FILE_ERR -21
# define DUPLICATE_TEXTURE -22
# define MLX_ERROR -23

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		angle;
	float		fov_rd;
	int			rotate;
	int			left_right;
	int			up_down;
}	t_player;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_win;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

typedef struct s_colors
{
	int		wall_color;
	int		ceiling_color;
	int		floor_color;
	int		floor_parsed;
	int		ceiling_parsed;
	int		parsed;
}	t_colors;

typedef struct s_texture
{
	char	*path;
	void	*img;
	int		*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_texture;

typedef struct s_textures_set
{
	t_texture	*north;
	t_texture	*south;
	t_texture	*west;
	t_texture	*east;
	int			parsed;
	int			allocated;
	int			north_parsed;
	int			south_parsed;
	int			west_parsed;
	int			east_parsed;
}	t_textures_set;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		side;
	double	perp_wall_dist;
}	t_ray;

typedef struct s_map
{
	char	**matrix;
	t_list	*map_list;
	double	player_x_map;
	double	player_y_map;
	double	player_orientation;
	size_t	map_width;
	int		map_height;
	int		player_found;
	int		map_started;
}	t_map;

typedef struct s_game
{
	t_win			win;
	t_rect			rect;
	t_map			*map;
	t_player		*player;
	t_colors		colors;
	t_ray			*ray;
	t_textures_set	textures;
	double			plane_x;
	double			plane_y;
	int				error;
	int				map_parsed;
}	t_game;

//Parsing
int		invalid_map_extension(char *file);
int		parse_map_file(char *filename, t_game *data);
int		parse_texture(char *line, t_game *data);
int		parse_floor_ceiling_color(char *line, t_game *data);
void	free_array(char **array);
int		rgb_to_hex(int *array);
int		parse_map(int fd, char *line, t_game *data);
int		fill_matrix(char *dest, const char *src);
size_t	find_map_width(t_list *map_list);
void	free_map(t_map *map);
int		find_player_position(t_game *data);
void	set_player_orientation(t_game *data, char orientation);
int		is_line_empty(const char *line);
int		is_open_boundary(t_game *data);
void	init_game_struct(t_game *data);
int		load_all_textures(t_game *data);
int		is_valid_color_line(const char *line);
int		is_valid_texture_line(const char *line);
int		is_valid_map_line(const char *line, t_map *map);
int		check_open_boundary(t_map *map, size_t x, int y, size_t line_len);
void	init_map(t_map *map);
int		file_exists(const char *path);

//Initialization
int		initialize_game(t_game *data);
int		initialize_player(t_game *data);
void	start_game_loop(t_game *data);

//controls
int		key_release(int keycode, t_game *data);
int		key_press(int keycode, t_game *data);

//movement
void	handle_rotation(t_game *data);
void	move_player(t_game *data, double move_x, double move_y);
void	handle_movement(t_player *player, double *move_x, double *move_y);
void	handle_player_actions(t_game *data);

//graphics
void	draw_walls(t_game *data);
void	draw_ceiling_and_floor(t_game *data);
void	calculate_ray_step_dist(t_game *data, t_ray *ray);
void	calculate_ray_parameters(t_game *data, t_ray *ray, int x);
void	perform_dda(t_game *data, t_ray *ray);
void	calculate_line_height(t_ray *ray);

//Error Management
int		error_free(char *line, int error);
int		print_error(char *msg);
int		error_closefd(int fd, int error);
int		error_free_closefd(int fd, char *line, int error);
int		handle_error(t_game *data, int error);

//cleanup
void	exit_and_clean(t_game *data, int error_code);

#endif
