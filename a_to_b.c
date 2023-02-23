/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:44:11 by jeseo             #+#    #+#             */
/*   Updated: 2023/02/23 14:32:18 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	arrange_five_a(t_deque_edge *edge, int range)
{
	t_deque	*temp;
	int		num[5];
	int		min_1;
	int		min_2;
	int		i;

	i = -1;
	temp = edge->head_a;
	ft_memset(&num, 0, sizeof(num));
	while (++i < range)
	{
		num[i] = temp->num;
		temp = temp->next;
	}
	find_2_min_arg(num, &min_1, &min_2, range);
	send_min_arg_to_b(edge, min_1, min_2, range);
	less_than_five_a(edge, range - 2);
	less_than_five_b(edge, 2);
}

void	less_than_five_a(t_deque_edge *edge, int range)
{
	if (range == 2)
	{
		if (edge->head_a->num > edge->head_a->next->num)
		{
			write(1, "sa\n", 3);
			sa(edge);
		}
	}
	else if (range == 3)
	{
		arrange_three_a(edge);
	}
	else if (range >= 4)
	{
		arrange_five_a(edge, range);
	}
}	

void	partition_a(t_deque_edge *edge, t_pivot_index *a, int range)
{
	while (a->big_index + a->small_index + a->middle_index < range)
	{
		if (edge->head_a->num > a->pivot_l)
		{
			a->big_index++;
			write(1, "ra\n", 3);
			ra(edge);
		}
		else if (edge->head_a->num <= a->pivot_s)
		{
			a->small_index++;
			write(1, "pb\n", 3);
			pb(edge);
		}
		else
		{
			a->middle_index++;
			write(1, "pb\nrb\n", 6);
			pb(edge);
			rb(edge);
		}
	}
}

void	reverse_partition_a(t_deque_edge *edge, t_pivot_index *a)
{
	int	i;

	i = 0;
	while (i < a->big_index || i < a->middle_index)
	{
		if (i < a->big_index && i < a->middle_index)
		{
			write(1, "rrr\n", 4);
			rrr(edge);
		}
		else if (i < a->big_index)
		{
			write(1, "rra\n", 4);
			rra(edge);
		}
		else if (i < a->middle_index)
		{
			write(1, "rrb\n", 4);
			rrb(edge);
		}
		i++;
	}
}

void	first_partion(t_deque_edge *edge, t_pivot_index *a, int range)
{
	while (a->big_index + a->small_index + a->middle_index < range)
	{
		if (edge->head_a->num > a->pivot_l)
		{
			a->big_index++;
			write(1, "ra\n", 3);
			ra(edge);
		}
		else if (edge->head_a->num <= a->pivot_s)
		{
			a->small_index++;
			write(1, "pb\nrb\n", 6);
			pb(edge);
			rb(edge);
		}
		else
		{
			a->middle_index++;
			write(1, "pb\n", 3);
			pb(edge);
		}
	}
}

void	a_to_b(t_deque_edge *edge, t_data data, int range)
{
	t_pivot_index	a;

	ft_memset(&a, 0, sizeof(a));
	if (range <= 5)
		return (less_than_five_a(edge, range));
	define_pivot(edge->head_a, data, range, &a);
	if (range == data.num)
		first_partion(edge, &a, range);
	else
	{
		partition_a(edge, &a, range);
		reverse_partition_a(edge, &a);
	}
	a_to_b(edge, data, a.big_index);
	b_to_a(edge, data, a.middle_index);
	b_to_a(edge, data, a.small_index);
}
