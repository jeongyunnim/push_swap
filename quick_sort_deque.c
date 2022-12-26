/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_deque.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 20:42:38 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/26 21:48:13 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	define_pivot(t_deque *edge, t_data data, int range, t_pivot_index *x)
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
			break ;
	}
	x->pivot_l = data.arr[i - (range / 3)];
	x->pivot_s = data.arr[i - ((range / 3) * 2)];
}

void	find_2_max_arg(int num[5], int *max_1, int *max_2, int range)
{
	int	i;

	i = 2;
	*max_1 = 0;
	*max_2 = 1;
	while (i < range)
	{
		if (num[*max_1] < num[i] || num[*max_2] < num[i])
		{
			if (num[*max_1] > num[*max_2])
				*max_2 = i;
			else
				*max_1 = i;
		}
		i++;
	}
}

void	find_2_min_arg(int num[5], int *min_1, int *min_2, int range)
{
	int	i;

	i = 2;
	*min_1 = 0;
	*min_2 = 1;
	while (i < range)
	{
		if (num[*min_1] > num[i] || num[*min_2] > num[i])
		{
			if (num[*min_1] < num[*min_2])
				*min_2 = i;
			else
				*min_1 = i;
		}
		i++;
	}
}

void	send_min_arg_to_b(t_deque_edge *edge, int idx_1, int idx_2, int range)
{
	int		i;
	int		ra_index;

	i = 0;
	ra_index = 0;
	while (i < range && (i <= idx_1 || i <= idx_2))
	{
		if (i == idx_1 || i == idx_2)
		{
			write(1, "pb\n", 3);
			pb(edge);
		}
		else
		{
			ra_index++;
			write(1, "ra\n", 3);
			ra(edge);
		}
		i++;
	}
	while (ra_index-- != 0 && edge->head_a->next->next != edge->tail_a)
	{
		write(1, "rra\n", 4);
		rra(edge);
	}
}

void	send_max_arg_to_a(t_deque_edge *edge, int idx_1, int idx_2, int range)
{
	int		i;
	int		rb_index;

	i = 0;
	rb_index = 0;
	while (i < range && (i <= idx_1 || i <= idx_2))
	{
		if (i == idx_1 || i == idx_2)
		{
			write(1, "pa\n", 3);
			pa(edge);
		}
		else
		{
			rb_index++;
			write(1, "rb\n", 3);
			rb(edge);
		}
		i++;
	}
	while (rb_index-- != 0 && edge->head_b->next->next != edge->tail_b)
	{
		write(1, "rrb\n", 4);
		rrb(edge);
	}
}
