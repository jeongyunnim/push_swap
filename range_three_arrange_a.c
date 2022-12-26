/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_three_arrange.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:02:27 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/26 21:39:36 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	first_is_small_a(t_deque_edge *edge, int num_1, int num_2)
{
	if (num_1 > num_2)
	{
		write(1, "ra\nsa\nrra\n", 10);
		ra(edge);
		sa(edge);
		rra(edge);
	}
}

static void	second_is_small_a(t_deque_edge *edge, int num_0, int num_2)
{
	if (num_0 < num_2)
	{
		write(1, "sa\n", 3);
		sa(edge);
	}
	else
	{
		write(1, "sa\nra\nsa\nrra\n", 13);
		sa(edge);
		ra(edge);
		sa(edge);
		rra(edge);
	}
}

static void	third_is_small_a(t_deque_edge *edge, int num_0, int num_1)
{
	if (num_0 < num_1)
	{
		write(1, "ra\nsa\nrra\nsa\n", 13);
		ra(edge);
		sa(edge);
		rra(edge);
		sa(edge);
	}
	else
	{
		write(1, "sa\nra\nsa\nrra\nsa\n", 16);
		sa(edge);
		ra(edge);
		sa(edge);
		rra(edge);
		sa(edge);
	}
}

void	arrange_three_a(t_deque_edge *edge)
{
	t_deque	*temp;
	int		num[3];
	int		i;

	i = -1;
	temp = edge->head_a;
	while (++i < 3)
	{
		num[i] = temp->num;
		temp = temp->next;
	}
	if (num[0] < num[1] && num[0] < num[2])
		first_is_small_a(edge, num[1], num[2]);
	else if (num[1] < num[0] && num[1] < num[2])
		second_is_small_a(edge, num[0], num[2]);
	else if (num[2] < num[0] && num[2] < num[1])
		third_is_small_a(edge, num[0], num[1]);
}
