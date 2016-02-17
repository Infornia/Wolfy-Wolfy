# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/09 16:17:56 by mwilk             #+#    #+#              #
#    Updated: 2016/02/17 19:50:56 by mwilk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


## PROJECT

NAME = wolf3d

LIBFT = libft

## COMPILATEUR

OS = $(shell uname -s)
CC = clang
FLAGS = -Wall -Wextra -Werror

## FILES

SRC = main.c\
	    wolfy_draw.c\
	    wolfy_events.c\
	    wolfy_init.c\
	    wolfy_ray.c\
	    wolfy_utils.c\
	    wolfy_wall3d.c\

INC =  -I ./
INC += -I ./libft/includes/
INC += -I minilibx/

OBJ = $(SRC:.c=.o)

LIB =  -L libft -lft
LIB += -L minilibx/ -lmlx -framework OpenGl -framework Appkit

## RULES

all: ml $(NAME)

update:
	git pull
	git submodule update --init --recursive
	git submodule foreach git pull origin master

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(INC) $(LIB) -o $(NAME) $(SRC)
	@echo "\033[35m <(O.O<) WOW ! Very Fractol ! Amaze ! (>^o^)> \033[0m"

clean: mcl
	rm -rf $(OBJ)
	@echo "\033[36mT.T Miss you Frac object files T.T \033[0m"

fclean: mfl clean
	rm -rf $(NAME)
	@echo "\033[36m X.x Bye Bye compiled files >_< \033[0m"

%.o:%.c
	$(CC) $(FLAGS) $(INC) -c $< -o $@

ml:
		make -C libft

mcl:
		make -C libft clean

mfl:
		make -C libft fclean

mrl:
		make -C libft re

re: fclean all

.PHONY: all normal clean fclean re makelib makerelib cleanlib fcleanlib

