/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_deque.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 20:42:38 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/21 22:04:03 by jeseo            ###   ########.fr       */
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
	return ;
}

void	first_is_small_a(t_deque_edge *edge, int num_1, int num_2)
{
		if (num_1 > num_2)
		{
			write(1, "ra\nsa\nrra\n", 10);
			ra(edge);
			sa(edge);
			rra(edge);
		}
}

void	second_is_small_a(t_deque_edge *edge, int num_0, int num_2)
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

void	third_is_small_a(t_deque_edge *edge, int num_0, int num_1)
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
	{
		first_is_small_a(edge, num[1], num[2]);
	}
	else if(num[1] < num[0] && num[1] < num[2])
	{
		second_is_small_a(edge, num[0], num[2]);
	}
	else if (num[2] < num[0] && num[2] < num[1])
	{
		third_is_small_a(edge, num[0], num[1]);
	}
}

void	less_than_three_a(t_deque_edge *edge, int range)
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
}

void	partition_a(t_deque_edge *edge, t_pivot_index *a, int range)
{
	t_deque	*temp;

	temp = edge->head_a;
 	while (a->big_index + a->small_index + a->middle_index < range)
	{
		if (temp->num > a->pivot_l)
		{
			a->big_index++;
			temp = temp->next;
			write(1, "ra\n", 3);
			ra(edge);
		}
		else if (temp->num <= a->pivot_s)
		{
			a->small_index++;
			temp = temp->next;
			write(1, "pb\n", 3);
			pb(edge);
		}
		else
		{
			a->middle_index++;
			temp = temp->next;
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

void	A_to_B(t_deque_edge *edge, t_data data, int range)
{
	t_pivot_index	a;

	ft_memset(&a, 0, sizeof(a));
	if (range <= 3)
	{
		less_than_three_a(edge, range);
		return ;
	}
	define_pivot(edge->head_a, data, range, &a.pivot_l, &a.pivot_s);
	partition_a(edge, &a, range);
	reverse_partition_a(edge, &a);
	A_to_B(edge, data, a.big_index);
	B_to_A(edge, data, a.middle_index);
	B_to_A(edge, data, a.small_index);
}
