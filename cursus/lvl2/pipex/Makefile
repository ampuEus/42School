# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 15:26:14 by daampuru          #+#    #+#              #
#    Updated: 2023/05/23 00:02:41 by daampuru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########## VARIABLES ##########
BIN_PATH	:= ./bin
#NAME		:= $(BIN_PATH)/pipex
NAME		:= pipex
INCLUDE		:= ./include

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

SRC_PATH	:= ./src
SRC_INPUT_PATH := input
SRC_UTILS_PATH := utils
SRC			:= main.c \
				$(SRC_INPUT_PATH)/input.c \
				$(SRC_INPUT_PATH)/checking.c \
				$(SRC_INPUT_PATH)/path_parsing.c \
				$(SRC_UTILS_PATH)/cmdexec.c \
				$(SRC_UTILS_PATH)/redirect.c \
				pipex.c \
				here_doc.c

OBJ_PATH	:= ./obj
OBJ			:= $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

LIB_PATH	:= ./lib
LIB_H		:= $(LIB_PATH)/libft.h
LIB_A		:= $(LIB_PATH)/libft.a


########## RULES ##########
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -I $(INCLUDE) -I $(LIB_PATH) -c $^ -o $@

all: pipex bonus

re: fclean all

clean:
	rm -rf $(OBJ_PATH)
	rm -rf *.dSYM

fclean:	clean
	rm -rf $(BIN_PATH)
	rm -rf *.out

libft: | $(LIB_PATH)
	$(MAKE) -C ../../lvl0/Libft/src fclean
	$(MAKE) -C ../../lvl0/Libft/src all
	cp ../../lvl0/Libft/src/libft.a $(LIB_A)
	cp ../../lvl0/Libft/src/libft.h $(LIB_H)


# Binaries
pipex: $(NAME)

bonus: $(NAME)

$(NAME) : $(OBJ) | $(BIN_PATH)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIB_A)


# Debug
no_flag: CFLAGS :=
no_flag: $(NAME)

debug: CFLAGS := -g3 -g
debug: $(NAME)

fsanitize: CFLAGS := -g3 -fsanitize=address
fsanitize: $(NAME)

leaks: CFLAGS := -D LEAKS=1 -g3
leaks: $(NAME)


# tests
run: $(NAME)
	./bin/pipex ./tests/file_in.txt "ls -a" "wc -l" ./tests/file_out.txt
run_bonus: $(NAME)
	./bin/pipex here_doc fin "cat" "cat" ./tests/file_out.txt


# Create dirs
$(OBJ_PATH):
	mkdir -p $@
	mkdir -p $@/$(SRC_INPUT_PATH)
	mkdir -p $@/$(SRC_UTILS_PATH)

$(BIN_PATH):
	mkdir -p $@

$(LIB_PATH):
	mkdir -p $@

.PHONY: clean fclean leaks
