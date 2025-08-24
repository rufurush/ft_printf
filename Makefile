# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rufurush <rufurush@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/09 14:18:52 by rufurush          #+#    #+#              #
#    Updated: 2025/08/24 12:21:25 by rufurush         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRC		= ft_printf.c ft_print_d.c ft_print_p.c ft_print_str.c \
		  ft_print_u.c ft_print_x.c ft_print_lx.c ft_strlen.c \
		  ft_print_c.c ft_strdup.c

OBJ		= $(SRC:.c=.o)

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
