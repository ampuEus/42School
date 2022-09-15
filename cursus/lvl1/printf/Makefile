# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 13:24:17 by daampuru          #+#    #+#              #
#    Updated: 2022/09/05 06:45:44 by daampuru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########## VARIABLES ##########
NAME		= libftprintf.a

CC		= gcc
CFLAGS		= -Wall -Wextra -Werror

AR		= ar
AR_CREATE	= rsc

UTILS_PATH	= ./utils
SRC		= ft_printf.c

OBJ_PATH	= ./obj
OBJ		= $(SRC:%.c=$(OBJ_PATH)/%.o)

LIB_PATH	= ./lib
LIBFT		= $(LIB_PATH)/libft.a


########## RULES ##########

%.o:%.c
	$(CC) $(CFLAGS) -c $^

all:	$(NAME)

bonus:	all

clean:
	rm -rf *.o

fclean:	clean
	rm -rf $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(AR) $(AR_CREATE) $(NAME) $(LIBFT) $()

.PHONY: clean fclean
