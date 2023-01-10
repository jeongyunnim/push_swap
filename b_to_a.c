/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:16:49 by jeseo             #+#    #+#             */
/*   Updated: 2023/01/10 19:38:40 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	arrange_five_b(t_deque_edge *edge, int range)
{
	t_deque	*temp;
	int		num[5];
	int		max_1;
	int		max_2;
	int		i;

	i = -1;
	temp = edge->head_b;
	ft_memset(&num, 0, sizeof(num));
	while (++i < range)
	{
		num[i] = temp->num;
		temp = temp->next;
	}
	find_2_max_arg(num, &max_1, &max_2, range);
	send_max_arg_to_a(edge, max_1, max_2, range);
	less_than_five_a(edge, 2);
	if (range == 5)
	{
		arrange_three_b(edge);
	}
	if (range <= 4)
	{
		less_than_five_b(edge, range - 2);
	}
}

void	less_than_five_b(t_deque_edge *edge, int range)
{
	if (range == 1)
	{
		write(1, "pa\n", 3);
		pa(edge);
	}
	else if (range == 2)
	{
		if (edge->head_b->num < edge->head_b->next->num)
		{
			write(1, "sb\n", 3);
			sb(edge);
		}
		write(1, "pa\npa\n", 6);
		pa(edge);
		pa(edge);
	}
	else if (range == 3)
	{
		arrange_three_b(edge);
	}
	else
	{
		arrange_five_b(edge, range);
	}
}

void	partition_b(t_deque_edge *edge, t_pivot_index *b, int range)
{
	while (b->big_index + b->small_index + b->middle_index < range)
	{
		if (edge->head_b->num > b->pivot_l)
		{
			b->big_index++;
			write(1, "pa\n", 3);
			pa(edge);
		}
		else if (edge->head_b->num < b->pivot_s)
		{
			b->small_index++;
			write(1, "rb\n", 3);
			rb(edge);
		}
		else
		{
			write(1, "pa\nra\n", 6);
			b->middle_index++;
			pa(edge);
			ra(edge);
		}
	}
}

void	reverse_partition_b(t_deque_edge *edge, t_pivot_index *b)
{
	int	i;

	i = 0;
	while (i < b->middle_index || i < b->small_index)
	{
		if (i < b->middle_index && i < b->small_index)
		{
			write(1, "rrr\n", 4);
			rrr(edge);
		}
		else if (i < b->middle_index)
		{
			write(1, "rra\n", 4);
			rra(edge);
		}
		else if (i < b->small_index)
		{
			write(1, "rrb\n", 4);
			rrb(edge);
		}
		i++;
	}
}

void	b_to_a(t_deque_edge *edge, t_data data, int range)
{
	t_pivot_index	b;

	ft_memset(&b, 0, sizeof(b));
	if (range <= 5)
		return (less_than_five_b(edge, range));
	define_pivot(edge->head_b, data, range, &b);
	partition_b(edge, &b, range);
	a_to_b(edge, data, b.big_index);
	reverse_partition_b(edge, &b);
	a_to_b(edge, data, b.middle_index);
	b_to_a(edge, data, b.small_index);
}
