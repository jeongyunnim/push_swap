/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_three_arrange_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:49:19 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/27 19:52:52 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	first_is_small_b(t_deque_edge *edge, int num_1, int num_2)
{
	if (num_1 < num_2)
	{
		write(1, "rb\nsb\npa\npa\nrrb\npa\n", 19);
		rb(edge);
		sb(edge);
		pa(edge);
		pa(edge);
		rrb(edge);
		pa(edge);
	}
	else
	{
		write(1, "rb\npa\npa\nrrb\npa\n", 16);
		rb(edge);
		pa(edge);
		pa(edge);
		rrb(edge);
		pa(edge);
	}
}

void	second_is_small_b(t_deque_edge *edge, int num_0, int num_2)
{
	if (num_0 < num_2)
	{
		write(1, "rb\nsb\npa\nrrb\npa\npa\n", 19);
		rb(edge);
		sb(edge);
		pa(edge);
		rrb(edge);
		pa(edge);
		pa(edge);
	}
	else
	{
		write(1, "pa\nsb\npa\npa\n", 12);
		pa(edge);
		sb(edge);
		pa(edge);
		pa(edge);
	}
}

void	third_is_small_b(t_deque_edge *edge, int num_0, int num_1)
{
	if (num_0 < num_1)
	{
		write(1, "sb\npa\npa\npa\n", 12);
		sb(edge);
		pa(edge);
		pa(edge);
		pa(edge);
	}
	else
	{
		write(1, "pa\npa\npa\n", 9);
		pa(edge);
		pa(edge);
		pa(edge);
	}
}

void	arrange_three_b(t_deque_edge *edge)
{
	t_deque	*temp;
	int		num[3];
	int		i;

	i = -1;
	temp = edge->head_b;
	while (++i < 3)
	{
		num[i] = temp->num;
		temp = temp->next;
	}
	if (num[0] < num[1] && num[0] < num[2])
	{
		first_is_small_b(edge, num[1], num[2]);
	}
	else if (num[1] < num[0] && num[1] < num[2])
	{
		second_is_small_b(edge, num[0], num[2]);
	}
	else if (num[2] < num[0] && num[2] < num[1])
	{
		third_is_small_b(edge, num[0], num[1]);
	}
}
