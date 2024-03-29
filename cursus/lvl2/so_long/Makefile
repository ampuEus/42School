# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 15:26:14 by daampuru          #+#    #+#              #
#    Updated: 2023/10/19 17:52:10 by daampuru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########## VARIABLES ##########
BIN_PATH	:= ./bin
NAME		:= $(BIN_PATH)/so_long
NAME_BONUS	:= $(BIN_PATH)/so_long_bonus
INCLUDE		:= ./include
UNAME		:= $(shell uname)

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

SRC_PATH	:= ./src
SRC_MAP_PATH := input_map_file
SRC_GUI_PATH := gui
SRC_IMG_PATH := init_imgs
SRC_UTILS_PATH := utils
SRC			:= main.c \
				$(SRC_MAP_PATH)/valid_chars.c \
				$(SRC_MAP_PATH)/is_valid_map.c \
				$(SRC_MAP_PATH)/get_map.c \

COMMON		:=	$(SRC_MAP_PATH)/map_utils.c \
				$(SRC_MAP_PATH)/is_closed_walls.c \
				$(SRC_MAP_PATH)/valid_path.c \
				$(SRC_GUI_PATH)/$(SRC_IMG_PATH)/init_imgs.c \
				$(SRC_GUI_PATH)/$(SRC_IMG_PATH)/init_gnd_imgs.c \
				$(SRC_GUI_PATH)/$(SRC_IMG_PATH)/init_wall_imgs.c \
				$(SRC_GUI_PATH)/$(SRC_IMG_PATH)/init_collect_imgs.c \
				$(SRC_GUI_PATH)/$(SRC_IMG_PATH)/init_playerl_imgs.c \
				$(SRC_GUI_PATH)/$(SRC_IMG_PATH)/init_playerr_imgs.c \
				$(SRC_GUI_PATH)/$(SRC_IMG_PATH)/init_player_dead_imgs.c \
				$(SRC_GUI_PATH)/$(SRC_IMG_PATH)/init_exit_idle_imgs.c \
				$(SRC_GUI_PATH)/$(SRC_IMG_PATH)/init_exit_bad_imgs.c \
				$(SRC_GUI_PATH)/$(SRC_IMG_PATH)/init_exit_good_imgs.c \
				$(SRC_GUI_PATH)/$(SRC_IMG_PATH)/init_enemy_imgs.c \
				$(SRC_GUI_PATH)/map.c \
				$(SRC_GUI_PATH)/render_score.c \
				$(SRC_GUI_PATH)/move.c \
				$(SRC_GUI_PATH)/key_hook.c \
				$(SRC_GUI_PATH)/end_gui.c \
				$(SRC_GUI_PATH)/start_gui.c \
				$(SRC_GUI_PATH)/frame.c \
				$(SRC_UTILS_PATH)/delete_item.c \
				$(SRC_UTILS_PATH)/find_coordenates.c \
				$(SRC_UTILS_PATH)/lists.c

OBJ_PATH	:= ./obj
OBJ			:= $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))
OBJ_COMMON	:= $(addprefix $(OBJ_PATH)/, $(COMMON:.c=.o))


SRC_PATH_BONUS	:= ./src_bonus
SRC_BONUS	:= main_bonus.c \
				valid_chars_bonus.c \
				is_valid_map_bonus.c \
				get_map_bonus.c \

OBJ_BONUS	:= $(addprefix $(OBJ_PATH)/, $(SRC_BONUS:.c=.o))


LIB_PATH	:= ./lib
LIB_H		:= $(LIB_PATH)/libft.h
LIB_A		:= $(LIB_PATH)/libft.a

MLX_PATH		:= $(LIB_PATH)/minilibx/minilibx_opengl
MLX_LINK		:= -L $(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
MLX_PATH_LINUX	:= $(LIB_PATH)/minilibx/minilibx-linux
MLX_LINK_LINUX	:= -L $(MLX_PATH_LINUX) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz


########## IMPLICIT RULES ##########
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
ifeq ($(UNAME), Linux)
	$(CC) $(CFLAGS) -I $(INCLUDE) -I $(LIB_PATH) -I $(MLX_PATH_LINUX) -c $^ -o $@
else
	$(CC) $(CFLAGS) -I $(INCLUDE) -I $(LIB_PATH) -I $(MLX_PATH) -c $^ -o $@
endif

$(OBJ_PATH)/%.o: $(SRC_PATH_BONUS)/%.c | $(OBJ_PATH)
ifeq ($(UNAME), Linux)
	$(CC) $(CFLAGS) -I $(INCLUDE) -I $(LIB_PATH) -I $(MLX_PATH_LINUX) -c $^ -o $@
else
	$(CC) $(CFLAGS) -I $(INCLUDE) -I $(LIB_PATH) -I $(MLX_PATH) -c $^ -o $@
endif

$(OBJ_PATH)/%.o: $(SRC_PATH_BONUS)/%.c | $(OBJ_PATH)
ifeq ($(UNAME), Linux)
	$(CC) $(CFLAGS) -I $(INCLUDE) -I $(LIB_PATH) -I $(MLX_PATH_LINUX) -c $^ -o $@
else
	$(CC) $(CFLAGS) -I $(INCLUDE) -I $(LIB_PATH) -I $(MLX_PATH) -c $^ -o $@
endif


########## EXPLICIT RULES ##########
all: so_long

re: fclean all

clean:
	$(MAKE) -C $(MLX_PATH) clean
	rm -rf $(OBJ_PATH)
	rm -rf *.dSYM

fclean:	clean
	rm -rf $(BIN_PATH)
	rm -rf so_long
	rm -rf *.out

libft: | $(LIB_PATH)
	$(MAKE) -C ../../lvl0/Libft/src fclean
	$(MAKE) -C ../../lvl0/Libft/src all
	cp ../../lvl0/Libft/src/libft.a $(LIB_A)
	cp ../../lvl0/Libft/src/libft.h $(LIB_H)


# Binaries
so_long: $(NAME)

bonus: $(NAME_BONUS)

$(NAME) : $(OBJ) $(OBJ_COMMON)  | $(BIN_PATH)
ifeq ($(UNAME), Linux)
	$(MAKE) -C $(MLX_PATH_LINUX)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_COMMON)  $(MLX_LINK_LINUX) -o $@ $(LIB_A)
else
	$(MAKE) -C $(MLX_PATH)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_COMMON)  $(MLX_LINK) -o $@ $(LIB_A)
endif

$(NAME_BONUS) : $(OBJ_BONUS) $(OBJ_COMMON) | $(BIN_PATH)
ifeq ($(UNAME), Linux)
	$(MAKE) -C $(MLX_PATH_LINUX)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(OBJ_COMMON) $(MLX_LINK_LINUX) -o $@ $(LIB_A)
else
	$(MAKE) -C $(MLX_PATH)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(OBJ_COMMON) $(MLX_LINK) -o $@ $(LIB_A)
endif


# Debug
no_flag: CFLAGS :=
no_flag: $(NAME)

debug: CFLAGS := -g3 -g
debug: $(NAME)

fsanitize: CFLAGS := -g3 -g -fsanitize=address
fsanitize: $(NAME)

leaks: CFLAGS := -D LEAKS=1 -g3
leaks: $(NAME)

# norminette
norm:
	norminette $(INCLUDE) $(SRC_PATH) | grep Error


# tests
run: $(NAME)
	./bin/so_long ./maps/basic_1.ber

run_bonus: $(NAME)
	./bin/so_long_bonus ./maps/enemy_1.ber


# Create dirs
$(OBJ_PATH):
	mkdir -p $@
	mkdir -p $@/$(SRC_MAP_PATH)
	mkdir -p $@/$(SRC_GUI_PATH)
	mkdir -p $@/$(SRC_GUI_PATH)/$(SRC_IMG_PATH)
	mkdir -p $@/$(SRC_UTILS_PATH)

$(BIN_PATH):
	mkdir -p $@

$(LIB_PATH):
	mkdir -p $@

.PHONY: clean fclean leaks
