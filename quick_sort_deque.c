/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_deque.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 20:42:38 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/24 17:56:36 by jeseo            ###   ########.fr       */
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

//void	fourth_to_bottom(t_deque_edge *edge, int four_location)
//{
//	int	i;

//	i = 0;
//	while (i < 3)
//	{
//		if (four_location <= i)
//		{
//			write(1, "sa\n", 3);
//			sa(edge);
//		}
//		write(1, "ra\n", 3);
//		ra(edge);
//		i++;
//	}
//	i = 0;
//	while (i < 3)
//	{
//		write(1, "rra\n", 4);
//		rra(edge);
//		i++;
//	}
//}

void	send_min_to_b(t_deque_edge *edge, int num[5], int range)
{
	int	i;
	int	min_1;
	int	min_2;

	i = 2;
	min_1 = 0;
	min_2 = 1;
	while (i < range)
	{
		if (num[min_1] > num[i] || num[min_2] > num[i])
		{
			if (num[min_1] < num[min_2])
				min_2 = i;
			else
				min_1 = i;
		}
		i++;
	}
	if (range == 4)
	{
		if (num[min_2] < num[min_1])
			min_1 = min_2;
		else
			min_2 = min_1;
	}

}

// 여기 수정 해야 함

void	arrange_five_a(t_deque_edge *edge, int range)
{
	t_deque	*temp;
	int		num[5];
	int min_1;
	int	min_2;
	int		i;

	i = -1;
	temp = edge->head_a;
	ft_memset(&num, 0, sizeof(num));
	while (++i < range)
	{
		num[i] = temp->num;
		temp = temp->next;
	}
	find_2_min_arg(num[5], &min_1, &min_2);
	send_min_to_b(edge, num, range);
	if (range == 5)
	{
		arrange_three_a(edge);
	}
	if (range <= 4)
	{
		less_than_five_a(edge, range - 2);
	}
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
		arrange_five_a(edge);
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
	if (range <= 4)
	{
		less_than_five_a(edge, range);
		return ;
	}
	define_pivot(edge->head_a, data, range, &a.pivot_l, &a.pivot_s);
	partition_a(edge, &a, range);
	reverse_partition_a(edge, &a);
	A_to_B(edge, data, a.big_index);
	B_to_A(edge, data, a.middle_index);
	B_to_A(edge, data, a.small_index);
}
