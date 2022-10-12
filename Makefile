# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 14:35:48 by ajoliet           #+#    #+#              #
#    Updated: 2022/09/17 17:29:14 by ajoliet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCS = main.c \
	   events.c \
	   utils.c
MLX = mlx_linux/
LIB = mlx_linux/libmlx.a
OBJS = $(SRCS:.c=.o)
RM = rm -rf
CC = gcc
CFLAGS = -Wall -Werror -Wextra -O3
MLXFLAGS = -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS) $(LIB) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB) $(MLXFLAGS)

$(LIB): 
	make -C $(MLX) 

clean:
	$(RM) $(OBJS)
	make -C $(MLX) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(MLX)libmlx.a

re: fclean $(NAME)

.PHONY: all fclean clean re
