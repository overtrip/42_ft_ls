# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/25 15:08:49 by jealonso          #+#    #+#              #
#    Updated: 2015/01/29 17:07:29 by jealonso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#.SUFFIXES:

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I libft/includes

NAME = ft_ls

SRCS = \
		align_l.c \
		comp_tri.c \
		extention_1.c \
		extention_2.c \
		main.c \
		mask.c

OBJS = $(SRCS:.c=.o)

HEAD = ft_ls.h

all: $(NAME)

$(NAME): $(OBJS) $(HEAD)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L libft -lft

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

cleanlib:
	$(MAKE) clean -C libft

cleanall: clean cleanlib

re: fclean all
