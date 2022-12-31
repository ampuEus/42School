# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 20:45:38 by daampuru          #+#    #+#              #
#    Updated: 2022/12/31 16:49:24 by daampuru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########## VARIABLES ##########
NAME		= push_swap
BIN_PATH	= ./bin

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

AR			= ar
ARFLAGS		= rsc

SRC_PATH	= ./src
SRC			= main.c \
				input.c

INCLUDE		= ./src/push_swap.h

OBJ_PATH	= ./obj
OBJ			= $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

LIB_PATH	= ./lib
LIB_H		= $(LIB_PATH)/libft.h
LIB_A		= $(LIB_PATH)/libft.a


########## RULES ##########

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $^ -o $@

all:	$(NAME)

re: fclean all

clean:
	rm -rf $(OBJ_PATH)

fclean:	clean
	rm -rf $(BIN_PATH)

$(NAME): $(OBJ) | $(BIN_PATH)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_PATH):
	mkdir -p $@

$(BIN_PATH):
	mkdir -p $@

no_flag: | $(BIN_PATH)
	$(CC) $(addprefix $(SRC_PATH)/, $(SRC)) $(INCLUDE) $(LIB_H) $(LIB_A)
	mv a.out $(BIN_PATH)

debug: | $(BIN_PATH)
	$(CC) -g3 $(addprefix $(SRC_PATH)/, $(SRC)) $(INCLUDE) $(LIB_H) $(LIB_A)
#mv -v a.out* $(BIN_PATH)

fsanitize:
	$(CC) -fsanitize=address -g3 $(addprefix $(SRC_PATH)/, $(SRC)) $(INCLUDE) $(LIB_H) $(LIB_A)


.PHONY: clean fclean
