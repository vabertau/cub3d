# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 12:12:34 by vabertau          #+#    #+#              #
#    Updated: 2024/07/23 19:14:44 by vabertau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D

CC = cc $(FLAGS)

FLAGS = -Wall -Werror -Wextra
LFLAG = -lm

FILENAMES = main.c \
			parsing/get_xpm.c \
			parsing/parser.c \
			parsing/map2d.c \
			parsing/player.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c \
			exit_free/exit_free.c \
			init_data.c \
			mlx_calls/init_window.c \
			mlx_calls/init_sprites.c \
			mlx_calls/hook.c \
			mlx_calls/mlx_new_image.c \
			execution/inter.c \
			execution/raycasting.c \
			execution/render.c \
			execution/move.c \
			execution/util.c \
			parsing/check_map.c \
			parsing/check_xpm.c \
			parsing/check_map_utils.c

SRCS = $(addprefix srcs/, $(FILENAMES))

OBJS_DIR = objs
OBJS = $(SRCS:srcs/%.c=$(OBJS_DIR)/%.o)

MLIB = minilibx-linux/libmlx_Linux.a
MLIB_PATH = minilibx-linux

LIBFT = libft/libft.a
LIBFT_PATH = libft

HEADERS = includes/cub3D.h

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLIB)
	@echo "Compiling $(NAME) ..."
	@$(CC) $(OBJS) $(LIBFT) $(MLIB) -lX11 -lXext -o $(NAME) $(LFLAG)
	@echo "$(NAME) compiled successfully!"

$(OBJS_DIR)/%.o: srcs/%.c $(HEADERS)
	@mkdir -p $$(dirname $@)
	@$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	@echo "Building libft..."
	@make -C $(LIBFT_PATH) all > /dev/null
	@echo "libft built successfully!"

$(MLIB):
	@echo "Building MinilibX..."
	@make -C $(MLIB_PATH) all > /dev/null
	@echo "MinilibX built successfully!"

clean:
	@echo "Cleaning up..."
	@rm -rf $(OBJS_DIR)
	@make -C $(LIBFT_PATH) clean > /dev/null
	@make -C $(MLIB_PATH) clean > /dev/null

fclean: clean
	@echo "Removing executable and full cleanup..."
	@make -C $(LIBFT_PATH) fclean > /dev/null
	@rm -f $(NAME)

re:
	@if [ -e $(NAME) ] || [ -d $(OBJS_DIR) ]; then \
	    $(MAKE) fclean; \
	fi
	$(MAKE) all
	@echo "Rebuilding everything..."
