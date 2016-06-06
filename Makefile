# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/25 17:48:33 by ifranc-r          #+#    #+#              #
#    Updated: 2016/02/29 17:38:36 by ifranc-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fract_ol

HEAD = includes/minilibx_macos/

LIB = -L ./libft/ -lft -L ./includes/minilibx_macos/ -lmlx -framework OpenGL\
	  -framework AppKit

SRC = ./srcs/main.c\
	  srcs/mlx/mlx.c\
	  srcs/key_hook/key_hook.c\
	  srcs/key_hook/funct_key.c\
	  srcs/mandelbrot/mandelbrot.c\
	  srcs/julia/julia.c\
	  srcs/burningship/burningship.c\
	  srcs/yolo/yolo.c\
	  srcs/shiva/shiva.c\
	  srcs/hotblood/hotblood.c\
	  srcs/goldenratio/goldenratio.c\
	  srcs/tricorn/tricorn.c\


FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)
OBJS = $(notdir $(OBJ))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc $(FLAGS) -c $(SRC) -I libft/ -I includes/ -I includes/minilibx_macos/
	@gcc -o $(NAME) $(OBJS) $(LIB)

nar:
	@gcc $(FLAGS) -c $(SRC) -I libft/ -I includes/ -I includes/minilibx_macos/
	@gcc -o $(NAME) $(OBJS) $(LIB)

clean:
	@rm -rf $(OBJS)
	@make clean -C libft/

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft/

re: fclean all
	@make re -C libft/
