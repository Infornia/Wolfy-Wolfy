# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/29 18:08:50 by mwilk             #+#    #+#              #
#    Updated: 2015/10/02 16:54:29 by mwilk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = wolf3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJ_PATH = ./obj/
SRC_PATH = ./

OBJ = $(SRC:.c=.o)
SRC = main.c\
	  Wolfy_map.c\

OBJS = $(addprefix $(OJB_PATH),$(OBJ))
SRCS = $(addprefix $(SRC_PATH),$(SRC))

FDF_H = -I ./

LIB_H = -I Libft/includes/
LIB_L = -LLibft -lft

SLD_H =  -lSDL2
SDL_L = `sdl2-config --cflags --libs`

all: makelib normal

makelib:
		@make -C Libft

makerelib:
		@make -C libft re

cleanlib:
		@make -C libft clean

fcleanlib:
		@make -C libft fclean

normal: $(NAME)

$(NAME):
	@gcc $(CFLAGS) $(LIB_H) $(FDF_H) $(SDL_H) -c $(SRCS) 
	@mkdir $(OBJ_PATH)
	@gcc -o $(NAME) $(OBJ) $(LIB_L) $(SDL_L)
	@mv $(OBJ) $(OBJ_PATH)
	@echo "\033[35m <(O.O<) WOW ! Very Fdf ! Amaze ! (>^o^)> \033[0m"

clean:
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\033[36mT.T Miss you object files T.T \033[0m"

fclean: clean
	@/bin/rm $(NAME)
	@echo "\033[36m X.x Bye Bye compiled files >_< \033[0m"

re: fclean all

.PHONY: all normal clean fclean re makelib makerelib cleanlib fcleanlib
