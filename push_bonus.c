/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:44:43 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/22 15:45:02 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	pb(t_deque_edge *edge)
{
	t_deque	*target;

	if (edge->head_a == NULL)
		return ;
	target = pop_head(&(edge->head_a));
	if (edge->head_a == NULL)
	{
		edge->tail_a = NULL;
	}
	append_head(&(edge->head_b), &(edge->tail_b), target);
}

void	pa(t_deque_edge *edge)
{
	t_deque	*target;

	if (edge->head_b == NULL)
		return ;
	target = pop_head(&(edge->head_b));
	if (edge->head_b == NULL)
	{
		edge->tail_b = NULL;
	}
	append_head(&(edge->head_a), &(edge->tail_a), target);
}
