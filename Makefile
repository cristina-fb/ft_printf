# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crisfern <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/26 13:46:15 by crisfern          #+#    #+#              #
#    Updated: 2021/07/26 13:46:17 by crisfern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libftprintf.a

HEADER = srcs/ft_printf.h

LIBFT_DIR = ./libft/

LIBFT = libft.a

LIBFT_OBJ = $(LIBFT_DIR)*.o

CFLAGS = -Wall -Werror -Wextra

SRC = ft_printf.c argument.c get_variable1.c get_variable2.c manage_flags.c save_flags.c

OBJ = $(SRC:.c=.o)



all: make_libft $(NAME) 

$(NAME): $(OBJ) $(LIBFT_DIR)$(LIBFT)
	ar -r $(NAME) $(OBJ) $(LIBFT_OBJ)

make_libft:
	make -C $(LIBFT_DIR)

%.o: srcs/%.c $(HEADER)
	$(CC) $(FLAGS) -c $<

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean:	clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

bonus: all

re: fclean all

.PHONY: all clean fclean re bonus make_libft
