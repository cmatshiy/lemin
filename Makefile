# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/23 15:15:36 by cmatshiy          #+#    #+#              #
#    Updated: 2018/09/25 09:00:24 by cmatshiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
LIBFT = libft/
GNL = gnl/get_next_line.c
SRCS = src/
CCFL = -Wall -Wextra -Werror -lncurses -ltermcap -L $(LIBFT) -lft

all: $(NAME)

$(NAME):
		@MAKE -C $(LIBFT) re 
		@gcc $(CCFL) $(SRCS)*.c $(GNL) -o $(NAME)

clean:
		@make -C $(LIBFT) clean

fclean:
		@make -C $(LIBFT) fclean
		@/bin/rm -rf $(NAME)

re: fclean all
