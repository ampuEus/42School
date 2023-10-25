# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 15:26:14 by daampuru          #+#    #+#              #
#    Updated: 2023/10/20 21:36:50 by daampuru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########## VARIABLES ##########
BIN_PATH	:= ./bin
NAME		:= $(BIN_PATH)/philo
NAME_BONUS	:= $(BIN_PATH)/philo_bonus
INCLUDE		:= ./inc
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -pthread

# Sources dir
STATEMACHINE_PATH := statemachine

SRC_PATH	:= src
SRC			:= main.c \
				input.c \
				locks.c \
				threads.c \
				routine.c \
				get_rules.c \
				end.c \
				utils.c \
				$(STATEMACHINE_PATH)/thinking.c \
				$(STATEMACHINE_PATH)/eating.c \
				$(STATEMACHINE_PATH)/sleeping.c \
				$(STATEMACHINE_PATH)/dead.c

SRC_BONUS_PATH	:= ./src_bonus
SRC_BONUS	:= main.c \
				input.c \
				semaphores.c \
				process.c \
				routine.c \
				get_rules.c \
				utils.c \
				$(STATEMACHINE_PATH)/thinking.c \
				$(STATEMACHINE_PATH)/eating.c \
				$(STATEMACHINE_PATH)/sleeping.c \
				$(STATEMACHINE_PATH)/dead.c

# Objects dir
OBJ_PATH	:= ./obj
OBJ			:= $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

OBJ_BONUS_PATH	:= ./obj_bonus
OBJ_BONUS	:= $(addprefix $(OBJ_BONUS_PATH)/, $(SRC_BONUS:.c=.o))


########## RULES ##########
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $^ -o $@

$(OBJ_BONUS_PATH)/%.o: $(SRC_BONUS_PATH)/%.c | $(OBJ_BONUS_PATH)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $^ -o $@

all: philo

re: fclean all

clean:
	rm -rf $(OBJ_PATH)
	rm -rf $(OBJ_BONUS_PATH)
	rm -rf *.dSYM

fclean:	clean
	rm -rf $(BIN_PATH)
	rm -rf *.out


# Binaries
philo: $(NAME)

$(NAME) : $(OBJ) | $(BIN_PATH)
	$(CC) $(CFLAGS) $(OBJ) -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS) | $(BIN_PATH)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $@


# Debug
no_flag: CFLAGS := -pthread
no_flag_bonus: CFLAGS := -pthread
no_flag: $(NAME)
no_flag_bonus: $(NAME_BONUS)

debug: CFLAGS := -g3 -g -D DEBUG=1 -pthread
debug_bonus: CFLAGS := -g3 -g -D DEBUG=1 -pthread
debug: $(NAME)
debug_bonus: $(NAME_BONUS)

faddress: CFLAGS := -g3 -fsanitize=address -pthread
faddress_bonus: CFLAGS := -g3 -fsanitize=address -pthread
faddress: $(NAME)
faddress_bonus: $(NAME_BONUS)

fthread: CFLAGS := -g3 -pthread -fsanitize=thread
fthread_bonus: CFLAGS := -g3 -pthread -fsanitize=thread
fthread: $(NAME)
fthread_bonus: $(NAME_BONUS)


# tests
run: $(NAME)
	$(NAME) 5 800 200 200

run_opt: $(NAME)
	$(NAME) 3 10 10 10 5

run_bonus: $(NAME_BONUS)
	$(NAME_BONUS) 3 10 10 10

run_opt_bonus: $(NAME_BONUS)
	$(NAME_BONUS) 3 10 10 10 5


# Create dirs
$(OBJ_PATH):
	mkdir -p $@
	mkdir -p $@/$(STATEMACHINE_PATH)

$(OBJ_BONUS_PATH):
	mkdir -p $@
	mkdir -p $@/$(STATEMACHINE_PATH)

$(BIN_PATH):
	mkdir -p $@

.PHONY: clean fclean
