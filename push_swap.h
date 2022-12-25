/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:59:04 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/25 21:41:40 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdlib.h>

# define ERROR -1

typedef struct s_deque
{
	struct s_deque	*previous;
	struct s_deque	*next;
	int				num;
}	t_deque;

typedef struct s_deque_edge
{
	struct s_deque	*head_a;
	struct s_deque	*tail_a;
	struct s_deque	*head_b;
	struct s_deque	*tail_b;
}	t_deque_edge;

typedef struct s_pivot_index
{
	int		big_index;
	int		small_index;
	int		middle_index;
	int		pivot_l;
	int		pivot_s;
}	t_pivot_index;
typedef struct s_data
{
	int		*arr;
	char	*arr_data;
	int		num;
}	t_data;

void	*ft_calloc(size_t n, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memset(void *bytes, int value, size_t len);

t_deque	*lstnew(int num);
t_deque	*pop_head(t_deque **head);
t_deque	*pop_tail(t_deque **tail);
void	append_head(t_deque **head, t_deque **tail, t_deque *new);
void	append_tail(t_deque **head, t_deque **tail, t_deque *new);
void	sa(t_deque_edge *edge);
void	sb(t_deque_edge *edge);
void	ss(t_deque_edge *edge);
void	pa(t_deque_edge *edge);
void	pb(t_deque_edge *edge);
void	ra(t_deque_edge *edge);
void	rb(t_deque_edge *edge);
void	rr(t_deque_edge *edge);
void	rra(t_deque_edge *edge);
void	rrb(t_deque_edge *edge);
void	rrr(t_deque_edge *edge);
void	print_deque(t_deque_edge *edge);
void	print_deque_b(t_deque_edge *edge);
void	arr_to_deque(t_data data, t_deque_edge *edge);

void	arrange_five_a(t_deque_edge *edge, int range);
void	less_than_five_a(t_deque_edge *edge, int range);
void	arrange_three_a(t_deque_edge *edge);
void	find_2_min_arg(int num[5], int *min_1, int *min_2, int range);
void	find_2_max_arg(int num[5], int *max_1, int *max_2, int range);
void	send_min_arg_to_b(t_deque_edge *edge, int index_1, int index_2, int range);
void	less_than_five_b(t_deque_edge *edge, int range);

void	B_to_A(t_deque_edge *edge, t_data data, int range);
void	A_to_B(t_deque_edge *edge, t_data data, int range);
void	define_pivot(t_deque *edge, t_data data, int range, int *larg_p, int *sml_p);
void	arrange_three_a(t_deque_edge *edge);

#endif