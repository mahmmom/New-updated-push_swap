NAME = push_swap

SRC = push_swap.c stack_utils.c args_handle.c error_handle.c init_stack.c \
      rule_push.c rule_swap.c rule_rotate.c rule_rrotate.c \
      sort_two_three.c sort_four_five.c \
      radix_sort.c radix_sort_utils.c \

OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) | libft
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

libft:
	make -C libft

clean:
	$(RM) $(OBJS)
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re libft
