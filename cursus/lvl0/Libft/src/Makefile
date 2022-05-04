# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: david <david@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 11:52:35 by daampuru          #+#    #+#              #
#    Updated: 2022/05/04 17:04:13 by david            ###   ########.fr        #
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

# ---------- subject ----------
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

# ---------- Other ----------
norminette:
	norminette -R CheckForbiddenSourceHeader | grep Error

# ---------- Testers  ----------
libftTester:
	make -iC ../tests/libftTester LIBFT_PATH=../../src/


.PHONY: all clean fclean re bonus
