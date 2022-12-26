# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 16:10:17 by jeseo             #+#    #+#              #
#    Updated: 2022/12/25 16:46:36 by jeseo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	./push_swap

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address

INC		=	./push_swap.h

SRC		=	./push_swap.c\
			./deque.c\
			./quick_sort_deque.c\
			./b_to_a.c\
			./push.c\
			./swap.c\
			./reverse.c\
			./reverse_reverse.c\
			./ft_calloc.c\
			./ft_strjoin.c\
			./main.c\


OBJ		=	$(SRC:%.c=%.o)
RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ)	:	$(SRC) $(INC)
	$(CC) $(CFLAGS) -c $^ -I $(INC) \

clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re