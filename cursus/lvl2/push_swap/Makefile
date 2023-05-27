# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 20:45:38 by daampuru          #+#    #+#              #
#    Updated: 2023/05/27 20:44:11 by daampuru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########## VARIABLES ##########
BIN_PATH	:= ./bin
NAME		:= $(BIN_PATH)/push_swap
BONUS		:= $(BIN_PATH)/checker
INCLUDE		:= ./src/push_swap.h
UNAME		:= $(shell uname)

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

AR			:= ar
ARFLAGS		:= rsc

SRC_PATH	:= src
SORT_PATH	:= sort_algorithms
SRC			:= main.c \
				stack_limit.c \
				cost.c \
				$(SORT_PATH)/sort.c \
				$(SORT_PATH)/simple_sort.c \
				$(SORT_PATH)/nbr3_sort.c \
				$(SORT_PATH)/nbr5_sort.c \
				$(SORT_PATH)/insertion_sort.c
SRC			:= $(addprefix $(SRC_PATH)/, $(SRC))

MOVE_PATH	:= movements
SRC_BOTH	:=	input.c \
				stack.c \
				$(SORT_PATH)/is_sorted.c \
				$(MOVE_PATH)/swap.c \
				$(MOVE_PATH)/push.c \
				$(MOVE_PATH)/rotate.c \
				$(MOVE_PATH)/rrotate.c \
				$(MOVE_PATH)/move.c
SRC_BOTH	:= $(addprefix $(SRC_PATH)/, $(SRC_BOTH))

SRC_BONUS_PATH	:= src_bonus
SRC_BONUS		:= src_bonus/main.c

OBJ_PATH	:= ./obj
OBJ_OTHER_PATHS	:= $(OBJ_PATH)/$(SRC_BONUS_PATH) \
				$(OBJ_PATH)/$(SRC_PATH) \
				$(OBJ_PATH)/$(SRC_PATH)/$(MOVE_PATH) \
				$(OBJ_PATH)/$(SRC_PATH)/$(SORT_PATH)
OBJ			:= $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))
OBJ_BOTH	:= $(addprefix $(OBJ_PATH)/, $(SRC_BOTH:.c=.o))
OBJ_BONUS	:= $(addprefix $(OBJ_PATH)/, $(SRC_BONUS:.c=.o))

LIB_PATH	:= ./lib
LIB_H		:= $(LIB_PATH)/libft.h
LIB_A		:= $(LIB_PATH)/libft.a


########## RULES ##########
$(OBJ_PATH)/%.o: %.c | $(OBJ_PATH) $(OBJ_OTHER_PATHS)
	$(CC) $(CFLAGS) -c $^ -o $@

all: push_swap bonus

re: fclean all

clean:
	rm -rf $(OBJ_PATH)
	rm -rf *.dSYM

fclean:	clean
	rm -rf $(BIN_PATH)
	rm -rf *.out

libft:
	$(MAKE) -C ../../lvl0/Libft/src fclean
	$(MAKE) -C ../../lvl0/Libft/src all
	cp ../../lvl0/Libft/src/libft.a $(LIB_A)
	cp ../../lvl0/Libft/src/libft.h $(LIB_H)


# Binaries
push_swap: $(NAME)

$(NAME) : $(OBJ) $(OBJ_BOTH) | $(BIN_PATH)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_BOTH) -o $@ $(LIB_A)

bonus: $(BONUS)

$(BONUS): $(OBJ_BONUS) $(OBJ_BOTH) | $(BIN_PATH)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(OBJ_BOTH) -o $@ $(LIB_A)


# Debug

no_flag: $(CFLAGS) := -g3 -g
no_flag: push_swap

debug: $(CFLAGS) := -g3 -g
debug: push_swap | $(BIN_PATH)

debug_bonus: | $(BIN_PATH)
	$(CC) -g3 $(SRC_BONUS) $(SRC_BOTH) $(LIB_A)
	mv -v a.out* $(BIN_PATH)

fsanitize: $(CFLAGS) := -fsanitize=address -g3
fsanitize: push_swap

fsanitize_bonus:
	$(CC) -fsanitize=address -g3 $(SRC_BONUS) $(SRC_BOTH) $(LIB_A)
	mv -v a.out* $(BIN_PATH)

leaks: $(CFLAGS) := -D LEAKS=1 -g3
leaks: push_swap


# Tests
test_random: $(NAME)
	@echo Checker:
ifeq ($(UNAME), Linux)
	$(eval ARG=$(shell shuf -i 1-5000 -n 500 | tr '\n' ' '))
	@./bin/push_swap "$(ARG)" | ./checkers/checker_linux $(ARG)
	@./bin/push_swap $(ARG) | ./checkers/checker_linux $(ARG)
else
	$(eval ARG=$(shell jot -r 100 -1000 1000 | awk '!seen[$$0]++' | tr '\n' ' '))
	@./bin/push_swap "$(ARG)" | ./checkers/checker_Mac $(ARG)
	@./bin/push_swap $(ARG) | ./checkers/checker_Mac $(ARG)
endif
	@echo Instructions:
	@./bin/push_swap "$(ARG)" | wc -l | awk '{$$1=$$1;print}'

test_bonus: all
	@echo Checker:
ifeq ($(UNAME), Linux)
	$(eval ARG=$(shell shuf -i 1-5000 -n 500 | tr '\n' ' '))
	@./bin/push_swap "$(ARG)" | ./bin/checker $(ARG)
else
	$(eval ARG=$(shell jot -r 100 -1000 1000 | awk '!seen[$$0]++' | tr '\n' ' '))
	@./bin/push_swap "$(ARG)" | ./bin/checker $(ARG)
endif
	@echo Instructions:
	@./bin/push_swap "$(ARG)" | wc -l | awk '{$$1=$$1;print}'


# Create dirs
$(OBJ_PATH):
	mkdir -p $@

$(OBJ_OTHER_PATHS):
	mkdir -p $@

$(BIN_PATH):
	mkdir -p $@

.PHONY: clean fclean leaks
