# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/23 11:27:10 by roddavid          #+#    #+#              #
#    Updated: 2018/04/20 13:53:24 by roddavid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =          fractol

LIBFTNAME =     libft.a
LIBFTDIR =      Libft/
LIBFT =         $(addprefix $(LIBFTDIR), $(LIBFTNAME))

MLXNAME =       libmlx.a
MLXDIR =        minilibx_macos/
MLX =           $(addprefix $(MLXDIR), $(MLXNAME))

SRCDIR =        Srcs/
SRCNAME =       main.c						\
				ft_init.c					\
				ft_gere_hook.c				\
				ft_hook.c					\
				ft_hook2.c					\
				mlx_pixel_put_to_image.c	\
				ft_burning_ship.c			\
				ft_julia.c					\
				ft_mandelbrot.c				\
				ft_tricorn.c				\
				ft_egg.c					\
				other.c						\

SRC =           $(addprefix $(SRCDIR), $(SRCNAME))

OBJDIR =        Obj/
OBJNAME =       $(SRCNAME:.c=.o)
	OBJ =           $(addprefix $(OBJDIR), $(OBJNAME))

HEADER_PATH =   Includes/
HEADER_NAME =   fractol.h
HEADER =        $(addprefix $(HEADER_PATH), $(HEADER_NAME))

FLAGS =         -Werror -Wextra -Wall -O2
LFLAGS =        -lpthread -D_REENTRANT -framework OpenGL -framework Appkit

CC =            gcc

all:            $(NAME)

$(OBJDIR)%.o:	$(SRCDIR)%.c
	$(CC) $(FLAGS) -o $@ -c $<

createdir:
	make -C $(LIBFTDIR)
	make -C $(MLXDIR)
	mkdir -p $(OBJDIR) 2> /dev/null || true

$(NAME):createdir $(OBJ)
	$(CC) $(LFLAGS) $(LIBFT) $(MLX) $(SRC) -o $@

clean:
	make clean -C $(LIBFTDIR)
	make clean -C $(MLXDIR)
	rm -f $(OBJ)

fclean:	clean
	rm -rf $(NAME)
	rm -rf $(OBJDIR)
	make fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all opti createdir clean fclean re
