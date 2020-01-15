NAME = corewar

SRCS = ./srcs/vm/

SRC = $(SRCS)main.c check_args.c
SRCO = $(SRCS)main.o

all: $(NAME)

$(NAME):
	make -C libft all
	clang -Wall -Wextra -Werror -I libft/includes -c $(SRC)
	clang -o $(NAME) $(SRCO) -I libft/includes -L libft/ -lft

clean:
	rm -f *.o
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

gdb: fclean
	fclean && make -C libft all
	gcc -g $(SRC) -I libft/includes -L libft/ -lft -o debugg

re: fclean all
