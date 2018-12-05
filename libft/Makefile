# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/25 14:10:05 by cmatshiy          #+#    #+#              #
#    Updated: 2018/09/25 14:10:18 by cmatshiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = *.c

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRCS)
	@ar rc $(NAME) *.o
	@ranlib $(NAME)

clean:
	@/bin/rm -f ft_*.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
