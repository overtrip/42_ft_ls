# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/25 15:08:49 by jealonso          #+#    #+#              #
#    Updated: 2015/04/02 14:53:44 by jealonso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES:

.PHONY: all re clean fclean cleanlib cleanall fleme

INCPATH = includes

LFTPATH = libft

LIBFT = $(LFTPATH)/libft.a

LDFLAGS = -L $(LFTPATH) -lft

SRCSPATH = srcs

OBJSPATH = objs

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I $(INCPATH) -I $(LFTPATH)/$(INCPATH)

NAME = ft_ls

SRCS = \
		align_l.c \
		comp_tri.c \
		extention_1.c \
		extention_2.c \
		main.c \
		mask.c \
		sort_params.c \
		error.c \
		color.c

OBJS = $(patsubst %.c, $(OBJSPATH)/%.o, $(SRCS))

HFILES = ft_ls.h

HEAD = $(patsubst %.h, $(INCPATH)/%.h, $(HFILES))

all: $(OBJSPATH) $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJSPATH)/%.o: $(SRCSPATH)/%.c $(HAED)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(MAKE) -C $(LFTPATH) clean
	rm -rf $(OBJSPATH)

fclean: clean
	$(MAKE) -C $(LFTPATH) fclean
	rm -rf $(NAME)

cleanlib:
	$(MAKE) clean -C $(LFTPATH)

cleanall: clean cleanlib

re: fclean all

$(OBJSPATH):
	mkdir $@

$(LIBFT):
	$(MAKE) -C $(LFTPATH)

fleme:
	@$(MAKE) re > /dev/null
	@$(MAKE) cleanall > /dev/null
	@echo "YOUPI"

test:
	@echo "$(OBJS)"
