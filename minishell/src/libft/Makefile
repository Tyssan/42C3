# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 13:10:24 by tbrunier          #+#    #+#              #
#    Updated: 2024/12/03 15:44:30 by tbrunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
## VARIABLES

NAME		= libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

INC_PATH	= include/
SRC_PATH	= .
OBJ_PATH	= obj/

################################################################################
## SOURCES

SRC_FILES	= ft_isspace.c ft_memcpy.c ft_putstr_fd.c ft_split.c ft_strdup.c \
			ft_strjoin.c ft_strlen.c ft_strncpy.c ft_strndup.c

SRCS		= $(addprefix $(SRC_PATH)/, $(SRC_FILES))
OBJS		= $(addprefix $(OBJ_PATH)/, $(SRC_FILES:.c=.o))

################################################################################
## RULES

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -I$(INC_PATH) -o $@ -c $<
$(OBJ_PATH) :
	mkdir -p $(OBJ_PATH)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re