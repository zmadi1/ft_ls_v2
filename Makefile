# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmadi <zmadi@student.wethinkcode.co.za>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 13:56:40 by zmadi             #+#    #+#              #
#    Updated: 2019/09/03 14:08:48 by zmadi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = main.c

#-Wall -Werror -Wextra
FLAGS = -I libft/ -I ./

all: $(NAME)

$(NAME):
	make re -C libft
	gcc $(SRC) $(FLAGS) -L libft -lft -o $(NAME)

clean:
	make clean -C libft
	rm -fr $(NAME)
	
re: clean all