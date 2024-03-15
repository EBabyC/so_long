# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabeaude <pabeaude@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 11:47:53 by pabeaude          #+#    #+#              #
#    Updated: 2023/09/05 11:48:33 by pabeaude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### INCLUDES ###

INCLUDES	= includes/so_long.h

LIBS		= -L./mlx -lmlx_Linux -lXext -lX11 -lm -lz

### SOURCES ###

FILES = main.c char_is_valid.c check_flood.c check_map.c flood_fill.c display.c key_control.c map_is_valid.c stock_map.c ft_printf.c

### MACROS ###

DIRPATH =	$(sh pwd)
SRCPATH	=	$(DIRPATH)src/
SRCBPATH	=	$(DIRPATH)src_bonus/
SRC	=	$(addprefix $(SRCPATH), $(FILES))
SRC_B	=	$(addprefix $(SRCBPATH), $(FILES_B))

LIBFT = libft/libft.a
MLX = mlx/libmlx_Linux.a
NAME 	= so_long
OBJ	= $(SRC:.c=.o)

CC = cc

CFLAGS = -g3 -Wall -Werror -Wextra

### RULES ###

all : $(NAME)

$(NAME) : $(MLX) $(OBJ) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

$(MLX) :
	git clone https://github.com/42Paris/minilibx-linux.git mlx
	make -C mlx

clean:
	rm $(OBJ)

fclean:
	rm -rf mlx
	rm $(NAME) $(NAME_B) $(OBJ)

re: fclean all

.PHONY: clean fclean re
