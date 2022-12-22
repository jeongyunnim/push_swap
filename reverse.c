/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:25:17 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/22 15:44:03 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ra(t_deque_edge *edge)
{
	t_deque	*target;

	if (edge->head_a == edge->tail_a)
		return ;
	target = pop_head(&(edge->head_a));
	append_tail(&(edge->head_a), &(edge->tail_a), target);
}

void	rb(t_deque_edge *edge)
{
	t_deque	*target;

	if (edge->head_b == edge->tail_b)
		return ;
	target = pop_head(&(edge->head_b));
	append_tail(&(edge->head_b), &(edge->tail_b), target);
}

void	rr(t_deque_edge *edge)
{
	ra(edge);
	rb(edge);
}
