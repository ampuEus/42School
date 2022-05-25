# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: david <david@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 11:52:35 by daampuru          #+#    #+#              #
#    Updated: 2022/05/24 21:00:59 by david            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

#MANDATORY_SRC := $(shell find . \( -name '*.c' -a -not -name '*_bonus.c' -a -not -name 'main.c' \))
MANDATORY_SRC := ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_tolower.c ft_toupper.c \
	ft_bzero.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	ft_atoi.c ft_calloc.c \
	ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
	ft_strdup.c ft_striteri.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_substr.c
MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)

#ALL_SRC := $(shell find . \( -name '*.c' -a -not -name 'main.c' \))
BONUS_SRC := ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
	ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

%.o: %.c
	$(CC) -c $(CFLAGS) $^

# ---------- subject ----------
all: $(NAME) bonus

$(NAME): $(MANDATORY_OBJ)
	ar rcs $(NAME) $(MANDATORY_OBJ)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

bonus: $(BONUS_OBJ)
	ar rcs $(NAME) $(BONUS_OBJ)

# ---------- Other ----------
norminette:
	norminette -R CheckForbiddenSourceHeader | grep Error

# ---------- Testers  ----------
libftTester:
	make -iC ../tests/libftTester LIBFT_PATH=../../src/


.PHONY: all clean fclean re bonus
