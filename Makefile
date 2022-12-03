CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address
NAME	=	./push_swap
INC		=	./push_swap.h
SRC		=	./push_swap.c\
			./deque.c\
			
OBJ		=	$(SRC:%.c=%.o)
RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ)	:	$(SRC) $(INC)
	$(CC) $(CFLAGS)	-c $^ -I $(INC)

clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re