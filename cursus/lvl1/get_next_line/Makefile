NAME = get_next_line.a
INCLUDES = get_next_line_bonus.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
AR			= ar
ARFLAGS		= rsc

SRC := get_next_line_bonus.c \
	get_next_line_utils_bonus.c

OBJ_PATH	= ./obj
OBJ = $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

# ---------- static pattern rules ----------
$(OBJ_PATH)/%.o: %.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $^ -o $@

# ---------- subject ----------
all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

clean:
	rm -rf *.o
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)


# Create dirs
$(OBJ_PATH):
	mkdir -p $@
