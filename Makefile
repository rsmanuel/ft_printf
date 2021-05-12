NAME = libftprintf.a

SRCS =  ft_printf.c \
		char.c \
		ft_aux.c \
		ft_aux2.c \
		int.c \
		parse.c \
		print.c \
		string.c \
		struct.c \
		hex.c \
		uint.c \
		pointer.c \
		ft_bonus.c \

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

bonus : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf *.o
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
