# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 11:52:35 by daampuru          #+#    #+#              #
#    Updated: 2022/11/07 21:25:20 by daampuru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDES = libft.h

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror #-fsanitize=address
AR			= ar
ARFLAGS		= rsc

OBJ_PATH		= ./obj
EXTENDED_PATH	= extended
OBJ_EXT_PATH	= $(OBJ_PATH)/$(EXTENDED_PATH)
OBJ_GNL			= $(shell find ../../../lvl1/get_next_line/obj/*.o)
OBJ_PRINTF		= $(shell find ../../../lvl1/printf/obj/*.o)

#MANDATORY_SRC := $(shell find . \( -name '*.c' -a -not -name '*_bonus.c' -a -not -name 'main.c' \))
MANDATORY_SRC := ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_tolower.c ft_toupper.c \
	ft_bzero.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	ft_atoi.c ft_calloc.c \
	ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
	ft_strdup.c ft_striteri.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_substr.c

MANDATORY_OBJ = $(addprefix $(OBJ_PATH)/, $(MANDATORY_SRC:.c=.o))

#ALL_SRC := $(shell find . \( -name '*.c' -a -not -name 'main.c' \))
BONUS_SRC := ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
	ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
BONUS_OBJ = $(addprefix $(OBJ_PATH)/, $(BONUS_SRC:.c=.o))

EXTENDED_SRC := ft_putchar.c ft_puts.c \
	ft_abs.c \
	ft_putnbr_base.c ft_putunbr_base.c ft_putulnbr_base.c ft_putnchar_fd.c ft_nbrlen.c ft_unbrlen.c \
	ft_max.c
EXTENDED_SRC := $(addprefix $(EXTENDED_PATH)/, $(EXTENDED_SRC))
EXTENDED_OBJ := $(addprefix $(OBJ_PATH)/, $(EXTENDED_SRC:.c=.o))




# ---------- static pattern rules ----------
$(OBJ_PATH)/%.o: %.c | $(OBJ_PATH) $(OBJ_EXT_PATH)
	$(CC) $(CFLAGS) -c $^ -o $@

# ---------- subject ----------
all: $(NAME) bonus extended 42projects

$(NAME): $(MANDATORY_OBJ) $(INCLUDES)
	$(AR) $(ARFLAGS) $(NAME) $(MANDATORY_OBJ)

clean:
	rm -rf *.o
	rm -rf extended/*.o
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

bonus: $(BONUS_OBJ) $(MANDATORY_OBJ) $(INCLUDES)
	$(AR) $(ARFLAGS) $(NAME) $(BONUS_OBJ) $(MANDATORY_OBJ)

extended: $(EXTENDED_OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(EXTENDED_OBJ)

42projects:
	$(MAKE) -C ../../../lvl1/get_next_line all
	$(AR) $(ARFLAGS) $(NAME) $(OBJ_GNL)
	$(MAKE) -C ../../../lvl1/printf all
	$(AR) $(ARFLAGS) $(NAME) $(OBJ_PRINTF)

# Create dirs
$(OBJ_PATH):
	mkdir -p $@
$(OBJ_EXT_PATH):
	mkdir -p $@

# ---------- Other ----------
norminette:
	norminette -R CheckForbiddenSourceHeader | grep Error

# ---------- Testers  ----------
libftTester:
	make -iC ../tests/libftTester LIBFT_PATH=../../src/


.PHONY: all clean fclean re bonus
