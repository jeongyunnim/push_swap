/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_range_less_than_five.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:55:45 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/26 15:57:09 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	first_is_small_a(t_deque_edge *edge, int num_1, int num_2)
{
		if (num_1 > num_2)
		{
			write(1, "sa\nra\n", 6);
			sa(edge);
			ra(edge);
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
			write(1, "ra\n", 3);
			ra(edge);
		}
}

static void	third_is_small_a(t_deque_edge *edge, int num_0, int num_1)
{
		if (num_0 < num_1)
		{
			write(1, "rra\n", 4);
			rra(edge);
		}
		else
		{
			write(1, "sa\nrra\n", 7);
			sa(edge);
			rra(edge);
		}
}

void	only_three_range(t_deque_edge *edge, int range)
{
	t_deque	*temp;
	int		num[3];
	int		i;

	if (range < 3)
	{
		less_than_five_a(edge, range);
		return ;
	}
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

void	little_number_arrange(t_deque_edge *edge, t_data data)
{
	t_deque	*temp;
	int		num[5];
	int		min_1;
	int		min_2;
	int		i;

	ft_memset(&num, 0, sizeof(num));
	i = 0;
	temp = edge->head_a;
	while (i < data.num)
	{
		num[i] = temp->num;
		temp = temp->next;
		i++;
	}
	if (data.num >= 4)
	{
		find_2_min_arg(num, &min_1, &min_2, data.num);
		send_min_arg_to_b(edge, min_1, min_2, data.num);
		only_three_range(edge, data.num - 2);
		less_than_five_b(edge, 2);
	}
	else
		only_three_range(edge, data.num);
}

void	send_min_arg_to_b(t_deque_edge *edge, int index_1, int index_2, int range)
{
	int		i;
	int		ra_index;

	i = 0;
	ra_index = 0;
	while (i < range && (i <= index_1 || i <= index_2))
	{
		if (i == index_1 || i == index_2)
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
	while (ra_index != 0 && edge->head_a->next->next != edge->tail_a)
	{
		write(1, "rra\n", 4);
		rra(edge);
		ra_index--;
	}
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
