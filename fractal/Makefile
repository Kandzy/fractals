# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/24 17:03:46 by dkliukin          #+#    #+#              #
#    Updated: 2017/12/24 17:03:50 by dkliukin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = a_fractol.c b_run_fractal_julia.c b_run_fractal_mdb.c \
c_initiate_fractal_params.c d_key_hooks.c d_mouse_hooks.c e_color_sets.c\
e_zoom.c f_pthread_params.c g_burningship.c g_fractal_body.c g_julia.c\
g_mandelbrot.c


OBJ = $(SRC:%.c=%.o)
INC = fractol.h
NAME = fractol
CFLAG = -Werror -Wextra -Wall -O2
FRAMEWORK = -lmlx -framework OpenGL -framework AppKit
LIBDIR = ./libft
CC = gcc

%.o: %.c $(INC)
		@$(CC) $(CFLAG) -c $< -I $(LIBDIR)

all: $(NAME)

$(NAME): $(OBJ)
		@make -C $(LIBDIR)
		@$(CC) $(CFLAG) $(FRAMEWORK) -lpthread -o $(NAME) $(OBJ) $(LIBDIR)/libft.a

clean:
		@make clean -C $(LIBDIR)
		@rm -f $(OBJ)

fclean: clean
		@make fclean -C $(LIBDIR)
		@rm -f $(NAME)

re: fclean all
