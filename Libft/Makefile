# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roddavid <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 14:09:44 by roddavid          #+#    #+#              #
#    Updated: 2018/01/18 17:44:20 by clrichar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = 		ft_putchar.c			\
			ft_putchar_fd.c			\
	   		ft_strlen.c				\
	   		ft_putstr.c				\
	   		ft_strcmp.c				\
			ft_strncmp.c			\
	   		ft_strcpy.c				\
			ft_strdup.c				\
			ft_memset.c				\
			ft_bzero.c				\
			ft_memcpy.c				\
			ft_memccpy.c			\
			ft_memmove.c			\
			ft_memcmp.c				\
			ft_sqrt.c				\
			ft_strncpy.c			\
			ft_strcat.c				\
			ft_strcut_free.c		\
			ft_strcdup.c			\
			ft_strsub_free.c		\
			ft_strncat.c			\
			ft_strchr.c				\
			ft_strrchr.c			\
			ft_strstr.c				\
			ft_strjoinfree.c		\
			ft_strnstr.c			\
			ft_atoi.c				\
			ft_isalpha.c			\
			ft_isalnum.c			\
			ft_isdigit.c			\
			ft_isascii.c			\
			ft_isprint.c			\
			ft_toupper.c			\
			ft_tolower.c			\
			ft_memalloc.c			\
			ft_memdel.c				\
			ft_strnew.c				\
			ft_strdel.c				\
			ft_strclr.c				\
			ft_striter.c			\
			ft_strmap.c				\
			ft_strequ.c				\
			ft_strdup_free.c		\
			ft_strnequ.c			\
			ft_strsub.c				\
			ft_strjoin.c			\
			ft_strtrim.c			\
			ft_putendl.c			\
			ft_putstr_fd.c			\
			ft_putendl_fd.c			\
			ft_putnbr.c				\
			ft_putnbr_fd.c			\
			ft_striteri.c			\
			ft_strmapi.c			\
			ft_itoa.c				\
			ft_strsplit.c			\
			ft_memchr.c				\
			ft_int_len.c			\
			ft_word.c				\
			ft_len.c				\
			ft_start.c				\
			ft_swap.c				\
			ft_strlcat.c			\
			ft_lstnew.c				\
			ft_lstdelone.c			\
			ft_lstdel.c				\
			ft_lstadd.c				\
			ft_lstiter.c			\
			ft_lstmap.c				\
			ft_isupper.c			\
			ft_islower.c			\

INCLUDES =	-I ./					\

OBJ = 		$(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(INCLUDES) -Wall -Wextra -Werror -g3 -c $(SRCS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
