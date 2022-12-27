/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:25:22 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/22 15:25:47 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	sa(t_deque_edge *edge)
{
	int	temp;

	if (edge->head_a == NULL)
		return ;
	temp = edge->head_a->next->num;
	edge->head_a->next->num = edge->head_a->num;
	edge->head_a->num = temp;
}

void	sb(t_deque_edge *edge)
{
	int	temp;

	if (edge->head_b == NULL)
		return ;
	temp = edge->head_b->next->num;
	edge->head_b->next->num = edge->head_b->num;
	edge->head_b->num = temp;
}

void	ss(t_deque_edge *edge)
{
	sa(edge);
	sb(edge);
}
