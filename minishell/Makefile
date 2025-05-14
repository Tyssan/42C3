# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 14:02:32 by tbrunier          #+#    #+#              #
#    Updated: 2024/12/03 16:01:47 by tbrunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
## VARIABLES

NAME = minishell

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror #-g -O0#valgrind_debug_flags
RL_FLAG		= -lreadline

INCLUDE		= include/
SRC_PATH	= src/
OBJ_PATH	= obj/
LIBFT_PATH	= src/libft
LIBFT_LIB	= $(LIBFT_PATH)/libft.a

################################################################################
## SOURCES

SRC_FILES	=	main.c
SRCS		=	$(addprefix $(SRC_PATH),$(SRC_FILES))
OBJS		=	$(addprefix $(OBJ_PATH),$(SRC_FILES:.c=.o))

################################################################################
## RULES

all: libft $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(RL_FLAG) -L$(LIBFT_PATH) -lft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

libft:
	make -C $(LIBFT_PATH)

clean:
	rm -rf $(OBJ_PATH)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re libft
