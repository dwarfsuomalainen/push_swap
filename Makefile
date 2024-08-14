# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbogoudi <rbogoudi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 13:29:18 by rbogoudi          #+#    #+#              #
#    Updated: 2024/08/13 14:55:48 by rbogoudi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
ARCHIVE = push_swap.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -O2 
MAKE_LIB = ar -rcs

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

all : $(NAME)
	
$(NAME) : $(ARCHIVE)
	$(CC) $< -o $@ $(LIBFT)

$(ARCHIVE) : $(OBJS)
	$(MAKE_LIB)  $(ARCHIVE)  $^
	
	
	@make -C libft
%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ 	

clean :
	rm -f $(OBJS) $(ARCHIVE)
	make clean -C libft

fclean : clean
	@rm -f $(NAME)
	@rm -f libft/libft.a
	
re : fclean all

.PHONY : all clean fclea re