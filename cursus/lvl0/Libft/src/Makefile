# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 11:52:35 by daampuru          #+#    #+#              #
#    Updated: 2022/05/03 20:52:09 by daampuru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

MANDATORY_SRC := $(shell find . \( -name '*.c' -a -not -name 'ft_lst*' -a -not -name 'main.c' \))
MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)

ALL_SRC := $(shell find . \( -name '*.c' -a -not -name 'main.c' \))
ALL_OBJ = $(ALL_SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

%.o: %.c
	$(CC) -c $(CFLAGS) $^


all: $(NAME)

$(NAME): $(MANDATORY_OBJ)
	ar rcs $(NAME) $(MANDATORY_OBJ)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

bonus: $(ALL_OBJ)
	ar rcs $(NAME) $(ALL_OBJ)

norminette:
	norminette -R CheckForbiddenSourceHeader | grep Error

libftTester:
	make -iC ../tests/libftTester LIBFT_PATH=../../src/
	

.PHONY: all clean fclean re bonus
