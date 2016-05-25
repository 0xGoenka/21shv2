# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/10 14:43:47 by eleclet           #+#    #+#              #
#    Updated: 2016/05/24 12:35:54 by eleclet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sh
CFLAGS = -Werror -Wall -Wextra -g

SRC = main.c lst.c key.c defterm.c outc.c sys.c debug.c cursor.c quote.c history.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft/
	gcc $(OBJ)  $(CFLAGS) -ltermcap -Llibft -lft -o $(NAME)
	@echo "$(NAME) built"

%.o: %.c
	gcc -c $(CFLAGS) $<

clean :
	rm -rf $(OBJ)
	@make -C libft/ clean
fclean : clean
	@rm -f $(NAME)
	@make -C libft/ fclean
re : fclean all
