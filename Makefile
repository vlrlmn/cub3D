# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtchaker <raffi@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 22:17:38 by rtchaker          #+#    #+#              #
#    Updated: 2024/09/12 22:17:43 by rtchaker         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D
CC		= cc
CFLAGS	= -Wall -Werror -Wextra

SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INC_PATH = ./incl/
LIBFT_PATH = ./libs/libft/
MINILIBX_PATH = ./libs/minilibx-mac
MINILIBX_LIB = -lmlx -framework OpenGL -framework AppKit


SRC		= main.c \
		  parse.c \
		  parse_texture.c \
		  parse_map.c \
		  parse_color.c \
		  parse_color_utils.c \
		  parse_map_utils1.c \
		  parse_map_utils2.c \
		  parse_map_boundaries1.c \
		  parse_map_boundaries2.c \
		  parse_texture_utils.c \
		  controls.c \
		  exit.c \
		  initialize_game.c \
		  initialize_player.c \
		  player_utils.c \
		  game_loop.c \
		  error_handling.c \
		  error_utils.c\
		  player_movement.c \
		  draw_walls.c \
		  raycasting.c \
		  raycasting_dda.c

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INC		= -I$(INC_PATH) -I$(LIBFT_PATH) -I$(MINILIBX_PATH) -I./incl

LIBFT = $(LIBFT_PATH)libft.a
MINILIBX = $(MINILIBX_PATH)libmlx.a

all: $(OBJ_PATH) $(LIBFT) $(MINILIBX) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	rm -f $(NAME)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INC) -L$(LIBFT_PATH) -lft -L$(MINILIBX_PATH) $(MINILIBX_LIB)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH) bonus

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_PATH)

clean:
	rm -rf $(OBJ_PATH)
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MINILIBX_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
