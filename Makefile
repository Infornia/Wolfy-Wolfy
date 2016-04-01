# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/09 16:17:56 by mwilk             #+#    #+#              #
#    Updated: 2016/04/01 22:32:14 by mwilk            ###   ########.fr        #
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
	    tt_wolfy.c\
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
	@$(CC) $(FLAGS) $(INC) $(LIB) -o $(NAME) $(SRC)
	@echo "\033[35m <(O.O<) WOW ! Very $(NAME) ! Amaze ! (>^o^)> \033[0m"
	@mkdir -p ./obj; mv $(OBJ) ./obj

clean: mcl
	rm -rf $(OBJ)
	@echo "\033[36mT.T Miss you $(NAME)-object files T.T \033[0m"

fclean: mfl
	rm -rf $(OBJ)
	@echo "\033[36mT.T Miss you $(NAME)-object files T.T \033[0m"
	rm -rf $(NAME)
	@echo "\033[36m X.x Bye Bye $(NAME)-compiled files >_< \033[0m"

%.o:%.c
	@echo "<(O.o)>\t\t$@\t\t<(o.O)>"
	@$(CC) $(FLAGS) $(INC) -c $< -o $@

ml:
		make -C libft

mcl:
		make -C libft clean

mfl:
		make -C libft fclean

re: fclean all

.PHONY: all normal clean fclean re makelib ml mcl mfl

