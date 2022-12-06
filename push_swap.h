/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:59:04 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/06 21:29:30 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_list
{
	struct s_list	*previous;
	struct s_list	*next;
	int				index;
	int				num;
}	t_list;

typedef struct	s_list_edge
{
	struct s_list	*head_a;
	struct s_list	*tail_a;
	struct s_list	*head_b;
	struct s_list	*tail_b;
}	t_list_edge;

typedef struct	s_data
{
	int	*arr;
	int	num;
}	t_data;

t_list	*lstnew(int num);
t_list	*pop_head(t_list **head);
t_list	*pop_tail(t_list **tail);
void	append_head(t_list **head, t_list **tail, t_list *new);
void	append_tail(t_list **head, t_list **tail, t_list *new);
void	sa(t_list_edge *edge);
void	sb(t_list_edge *edge);
void	ss(t_list_edge *edge);
void	pa(t_list_edge *edge);
void	pb(t_list_edge *edge);
void	ra(t_list_edge *edge);
void	rb(t_list_edge *edge);
void	rr(t_list_edge *edge);
void	rra(t_list_edge *edge);
void	rrb(t_list_edge *edge);
void	rrr(t_list_edge *edge);
void	print_list_a(t_list_edge *edge);
void	print_list_b(t_list_edge *edge);
void    arr_to_deque(t_data data, t_list_edge *edge);

#endif