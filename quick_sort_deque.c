/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_deque.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 20:42:38 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/26 14:42:46 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	define_pivot(t_deque *edge, t_data data, int range, int *big, int *sml)
{
	t_deque	*temp;
	int		i;
	int		max;

	i = 0;
	temp = edge;
	max = temp->num;
	while (temp != NULL && i < range)
	{
		if (temp->num > max)
		{
			max = temp->num;
		}
		temp = temp->next;
		i++;
	}
	i = 0;
	while (i++ < data.num)
	{
		if (data.arr[i] == max)
			break;
	}
	*big = data.arr[i - (range / 3)];
	*sml = data.arr[i - ((range / 3) * 2)];
}

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
			write(1, "pb\n", 3);
			pb(edge);
			if (edge->head_b->next != NULL)
			{
				write(1, "rb\n", 3);
				rb(edge);
			}
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

void	A_to_B(t_deque_edge *edge, t_data data, int range)
{
	t_pivot_index	a;

	ft_memset(&a, 0, sizeof(a));
	if (range <= 4)
		return (less_than_five_a(edge, range));
	define_pivot(edge->head_a, data, range, &a.pivot_l, &a.pivot_s);
	partition_a(edge, &a, range);
	reverse_partition_a(edge, &a);
	A_to_B(edge, data, a.big_index);
	B_to_A(edge, data, a.middle_index);
	B_to_A(edge, data, a.small_index);
}
