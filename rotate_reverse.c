/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:24:56 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/22 15:42:56 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	rra(t_deque_edge *edge)
{
	t_deque	*target;

	if (edge->head_a == edge->tail_a)
		return ;
	target = pop_tail(&(edge->tail_a));
	append_head(&(edge->head_a), &(edge->head_a), target);
}

void	rrb(t_deque_edge *edge)
{
	t_deque	*target;

	if (edge->head_b == edge->tail_b)
		return ;
	target = pop_tail(&(edge->tail_b));
	append_head(&(edge->head_b), &(edge->head_b), target);
}

void	rrr(t_deque_edge *edge)
{
	rra(edge);
	rrb(edge);
}
