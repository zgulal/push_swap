NAME = push_swap
FLAGS = -Wall -Wextra -Werror
SRC = push_swap.c \
	ft_split.c \
	ft_atoi.c \
	control.c \
	swap_s.c \
	swap.c \
	swap_reverse.c \
	push.c \
	sorting.c \
	sort_partone.c \
	sort_partwo.c \
	radix.c \
	
CC = gcc

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)
	
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
