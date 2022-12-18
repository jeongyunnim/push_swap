/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_deque.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 20:42:38 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/17 22:36:32 by jeseo            ###   ########.fr       */
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
		if (num[1] < num[2])
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
	else if(num[1] < num[0] && num[1] < num[2])
	{
		if (num[0] < num[2])
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
			write(1, "rb\npa\nrrb\npa\npa\n", 16);
			rb(edge);
			pa(edge);
			rrb(edge);
			pa(edge);
			pa(edge);
		}
	}
	else if (num[2] < num[0] && num[2] < num[1])
	{
		if (num[0] < num[1])
		{
			write(1, "pa\nsb\npa\npa\n", 12);
			pa(edge);
			sb(edge);
			pa(edge);
			pa(edge);
		}
		else
		{
			write(1, "pa\npa\npa\n", 10);
			pa(edge);
			pa(edge);
			pa(edge);
		}
	return ;
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
		if (num[1] > num[2])
		{
			write(1, "ra\nsa\nrra\n", 11);
			ra(edge);
			sa(edge);
			rra(edge);
		}
	}
	else if(num[1] < num[0] && num[1] < num[2])
	{
		if (num[0] < num[2])
		{
			write(1, "sa\n", 3);
			sa(edge);
		}
		else
		{
			write(1, "ra\nsa\nrra\nsa\n", 13);
			ra(edge);
			sa(edge);
			rra(edge);
			sa(edge);
		}
	}
	else if (num[2] < num[0] && num[2] < num[1])
	{
		if (num[0] < num[1])
		{
			write(1, "sa\nra\nsa\nrra\n", 13);
			sa(edge);
			ra(edge);
			sa(edge);
			rra(edge);
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
	return ;
	}
}

void	B_to_A(t_deque_edge *edge, t_data data, int range)
{
	t_deque	*temp;
	int		big_index;
	int		small_index;
	int		middle_index;
	int		pivot_l;
	int		pivot_s;
	int		i;

	temp = edge->head_b;
	big_index = 0;
	small_index = 0;
	middle_index = 0;
	i = 0;
	if (range == 0)
	{
		return ;
	}
	if (range == 1)
	{
		write(1, "pa\n", 3);
		pa(edge);
		return ;
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
		return ;
	}
	else if (range == 3)
	{
		arrange_three_b(edge);
		return ;
	}
	define_pivot(edge->head_b, data, range, &pivot_l, &pivot_s);
	while (big_index + small_index + middle_index < range)
	{
		if (temp->num > pivot_l)
		{
			temp = temp->next;
			big_index++;
			write(1, "pa\n", 3);
			pa(edge);
		}
		else if (temp->num <= pivot_s)
		{
			temp = temp->next;
			small_index++;
			write(1, "rb\n", 3);
			rb(edge);
		}
		else
		{
			temp = temp->next;
			write(1, "pa\nra\n", 6);
			middle_index++;
			pa(edge);
			ra(edge);
		}
	}
	A_to_B(edge, data, big_index);
	while (i < middle_index || i < small_index)
	{
		if (i < middle_index && i < small_index)
		{
			write(1, "rrr\n", 4);
			rrr(edge);
		}
		else if (i < middle_index)
		{
			write(1, "rra\n", 4);
			rra(edge);
		}
		else if (i < small_index)
		{
			write(1, "rrb\n", 4);	
			rrb(edge);
		}
		i++;
	}
	A_to_B(edge, data, middle_index);
	B_to_A(edge, data, small_index);
}

void	A_to_B(t_deque_edge *edge, t_data data, int range)
{
	t_deque	*temp;
	int		big_index;
	int		middle_index;
	int		small_index;
	int		pivot_l;
	int		pivot_s;
	int		i;

	big_index = 0;
	small_index = 0;
	middle_index = 0;
	i = 0;
	if (range <= 1)
	{
		return ;
	}
	else if (range == 2)
	{
		if (edge->head_a->num > edge->head_a->next->num)
		{
			write(1, "sa\n", 3);
			sa(edge);
		}
		return ;
	}
	else if (range == 3)
	{
		arrange_three_a(edge);
		return ;
	}
	define_pivot(edge->head_a, data, range, &pivot_l, &pivot_s);
	temp = edge->head_a;
 	while (big_index + small_index + middle_index < range)
	{
		if (temp->num > pivot_l)
		{
			big_index++;
			temp = temp->next;
			write(1, "ra\n", 3);
			ra(edge);
		}
		else if (temp->num <= pivot_s)
		{
			small_index++;
			temp = temp->next;
			write(1, "pb\n", 3);
			pb(edge);
		}
		else
		{
			middle_index++;
			temp = temp->next;
			write(1, "pb\nrb\n", 6);
			pb(edge);
			rb(edge);
		}
	}
	while (i < big_index || i < middle_index)
	{
		if (i < big_index && i < middle_index)
		{
			write(1, "rrr\n", 4);
			rrr(edge);
		}
		else if (i < big_index)
		{
			write(1, "rra\n", 4);
			rra(edge);
		}
		else if (i < middle_index)
		{
			write(1, "rrb\n", 4);	
			rrb(edge);
		}
		i++;
	}
	A_to_B(edge, data, big_index);
	B_to_A(edge, data, middle_index);
	B_to_A(edge, data, small_index);
}
