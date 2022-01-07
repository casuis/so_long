# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asimon <asimon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 18:33:21 by asimon            #+#    #+#              #
#    Updated: 2022/01/07 18:50:09 by asimon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	clang

CFILE			=	gnl.c			\
				ft_atoi.c		\
				ft_isdigit.c	\
				ft_itoa.c		\
				ft_putchar.c	\
				ft_putstr.c		\
				ft_split.c		\
				ft_strlen.c		\

CFILE_DIR		=	./src/

SRC				=	$(addprefix $(CFILE_DIR),CFILE)

INCLUDE_DIR	=	./includes/

FLAG		=	-Wall -Wextra -Werror

INCLUDE		=	libft.h

OBJ			=	$(SRC,.c=.o)

.o: %.c
	$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
