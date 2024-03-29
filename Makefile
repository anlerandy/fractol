# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerandy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/12 12:43:59 by alerandy          #+#    #+#              #
#    Updated: 2018/02/12 09:52:11 by alerandy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC_PATH = srcs/
OBJ_PATH = objects/
SRC_NAME = main.c ft_input.c ft_strint.c ft_recur.c ft_fractal2.c \
		   ft_fractal.c ft_mouse.c usage.c

OBJ_NAME = $(SRC_NAME:.c=.o)
CC = gcc $(FLAG)
FLAG = -Wall -Werror -Wextra -g
FRAME = -framework OpenGL -framework AppKit
LIB = -Lminilibx_macos/ -lmlx -Llibft/ -lft
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all : $(NAME)

$(NAME) : libft minilibx $(OBJ)
	@$(CC) $(LIB) $(FRAME) $(OBJ) -o $(NAME)

libft :
	@$(MAKE) -C libft/

minilibx :
	@$(MAKE) -C minilibx_macos/

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) -Iminilibx_macos -Iincludes -Ilibft/includes -o $@ -c $<

clean :
	@rm -rf $(OBJ_PATH)
	@$(MAKE) -C minilibx_macos/ clean
	@printf "\033[2A\r\033[K""\033[1;30mLib mlx détruite.\033[0m\n"
	@$(MAKE) -C libft/ clean

fclean :
	@rm -f $(NAME)
	@rm -rf $(OBJ_PATH)
	@$(MAKE) -C minilibx_macos/ clean
	@printf "\033[2A\r\033[K""\033[1;30mLib mlx détruite.\033[0m\n"
	@$(MAKE) -C libft/ fclean
	@rm -f minilibx_macos/libmlx.a

re : fclean $(NAME)
	@printf "\033[9A\r\033[K""\033[32mLibrairie mlx compilé avec succès.\033[0m\n"

norm :
	@clear
	@norminette srcs/ includes/

norml :
	@clear
	@norminette libft/srcs/ libft/includes/

normall :
	@clear
	@norminette srcs/ includes/
	@norminette libft/srcs/ libft/includes/

.PHONY : fclean clean re norm success minilibx libft norml norm normall all
