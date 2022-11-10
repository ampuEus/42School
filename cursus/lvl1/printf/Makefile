# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 13:24:17 by daampuru          #+#    #+#              #
#    Updated: 2022/11/07 20:26:29 by daampuru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########## VARIABLES ##########
NAME		= libftprintf.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

AR			= ar
ARFLAGS		= rsc

SRC_PATH	= ./src
SRC			= ft_printf.c \
			ft_getTags.c \
			ft_findTags.c \
			ft_print_cs.c \
			ft_print_nbr.c \
			ft_print_hex.c

INCLUDE		= ./src/ft_printf.h

OBJ_PATH	= ./obj
OBJ			= $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

LIB_PATH	= ./lib
LIBFT		= $(LIB_PATH)/libft.h
LIBFTA		= $(LIB_PATH)/libft.a

########## RULES ##########

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@
#$(LIBFT) $(INCLUDE)
all:	$(NAME)

bonus:	all

clean:
	rm -rf $(OBJ_PATH)/*.o

fclean:	clean
	rm -rf $(NAME)

$(NAME): include_libft $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

include_libft:
	cp $(LIBFTA) $(NAME)

debug_bonus:
	$(CC) $(CFLAGS) -g3 $(addprefix $(SRC_PATH)/, $(SRC)) $(INCLUDE) $(LIBFT) $(LIBFTA) mainV2.c
	lldb ./a.out

fsanitize:
	$(CC) $(CFLAGS) -fsanitize=address -g $(addprefix $(SRC_PATH)/, $(SRC)) $(INCLUDE) $(LIBFT) $(LIBFTA) mainV2.c
	./a.out

.PHONY: clean fclean
