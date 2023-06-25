# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 11:48:57 by khanhayf          #+#    #+#              #
#    Updated: 2023/04/13 14:51:20 by khanhayf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS = bonus
HEAD = so_long.h
HEAD_B = so_long_bonus.h
SRC = so_long.c map_checker.c so_long_utils.c so_long_utils1.c key_move.c get_next_line.c img.c
OBJ = so_long.o map_checker.o so_long_utils.o so_long_utils1.o key_move.o get_next_line.o img.o
SRC_B = xso_long_bonus.c xmap_checker_bonus.c so_long_utils.c xso_long_utils1_bonus.c xkey_move_bonus.c get_next_line.c ximg_bonus.c xanimation_bonus.c
OBJ_B = xso_long_bonus.o xmap_checker_bonus.o so_long_utils.o xso_long_utils1_bonus.o xkey_move_bonus.o get_next_line.o ximg_bonus.o xanimation_bonus.o
CC = cc
RM = rm -rf
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -lmlx -framework OpenGL -framework AppKit

$(BONUS) : 	$(OBJ_B) $(HEAD_B)
	$(CC) $(FLAGS) -o $(BONUS) $(OBJ_B) -lmlx -framework OpenGL -framework AppKit
	
%.o : %.c $(HEAD) $(HEAD_B)
	$(CC) $(FLAGS) -c $<
	
clean :
	$(RM) $(OBJ) $(OBJ_B)
fclean : clean
	$(RM) $(NAME) $(BONUS)
 
re : fclean all
