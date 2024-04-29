NAME = push_swap
SRCS = push_swap_utills.c push_swap.c
OBJS = $(SRCS:.c=.o)
CC = cc
FLAGS = -Wall -Wextra -Werror
INCLUDES = push_swap.h

all: $(NAME)
$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(OBJS) -o $(NAME)
%.o: %.c $(INCLUDES)
		$(CC) $(FLAGS) -c $< -o $@
clean: 
		rm -f $(OBJS)
fclean: clean
		rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
