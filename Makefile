CC = gcc
NAME = libftprintf.a
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
FLAGS = -Wall -Werror -Wextra
SRCS = srcs/ft_printf.c srcs/argument.c srcs/get_variable1.c srcs/get_variable2.c srcs/manage_flags.c srcs/save_flags.c
OBJS = $(SRCS:.c:.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -r $(NAME) $(OBJS)

$(OBJS):
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	$(CC) $(FLAGS) -c $(OBJS) $(SRCS)

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean:	clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

bonus: all

re: fclean all

.PHONY: all clean fclean re bonus
