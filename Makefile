# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 14:35:48 by ajoliet           #+#    #+#              #
#    Updated: 2022/07/04 13:42:51 by ajoliet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCS = main.c
MLX = mlx_linux/
OBJS = $(SRCS:.c=.o)
RM = rm -rf
CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS) lib
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX)libmlx.a $(MLXFLAGS)

lib: 
	make -C $(MLX) 

clean:
	$(RM) $(OBJS) fractol
	make -C $(MLX) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(MLX) fclean
	$(RM) $(MLX)libmlx.a

re: fclean $(NAME)

.PHONY: all fclean clean re
