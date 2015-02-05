# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/25 15:08:49 by jealonso          #+#    #+#              #
#    Updated: 2015/02/05 18:51:40 by jealonso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean cleanlib cleanall fleme

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I libft/includes

NAME = ft_ls

SRCS = \
		align_l.c \
		comp_tri.c \
		extention_1.c \
		extention_2.c \
		main.c \
		mask.c \
		sort_params.c \
		error.c

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

fleme:
	@$(MAKE) re > /dev/null
	@$(MAKE) cleanall > /dev/null
	@echo "YOUPI"
