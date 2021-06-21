NAME = pipex

SRC = src/main.c

LIBFT = ./libft/libft.a

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C LIBFT
	@gcc $(OBJ) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJ)
	@make -C LIBFT clean

fclean: clean
	rm -f $(NAME)
	@make -C LIBFT fclean

re: fclean all