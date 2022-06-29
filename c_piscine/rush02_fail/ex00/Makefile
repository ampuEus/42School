# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/05 13:33:33 by jugarte-          #+#    #+#              #
#    Updated: 2022/03/06 23:53:41 by manugarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./main.c ./dict.c ./validation.c ./ft_str.c ./ft_num.c ./spaces.c ./ft_strcmp.c ./ft_strlen.c ./dict_struct.c ./print.c ./memory.c

OBJ = $(SRC:.c=.o)

NAME = rush-02

$(NAME): compile

compile:
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC)

compile-no-flags:
	gcc -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

norminette:
	norminette -R CheckForbiddenSourceHeader | grep Error

test: fclean compile-no-flags
	./$(NAME) 9
	./$(NAME) 98
	./$(NAME) 976
	./$(NAME) 9765
