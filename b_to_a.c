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

void	send_min_arg_to_a(t_deque_edge *edge, int index_1, int index_2, int range)
{
	t_deque	*temp;
	int		i;
	int		ra_index;

	temp = edge->head_a;
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

void	send_max_arg_to_a(t_deque_edge *edge, int index_1, int index_2, int range)
{
	t_deque	*temp;
	int		i;
	int		rb_index;

	temp = edge->head_a;
	i = 0;
	rb_index = 0;
	while (i < range && (i <= index_1 || i <= index_2))
	{
		if (i == index_1 || i == index_2)
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
	while (rb_index != 0 && edge->head_b->next->next != edge->tail_b)
	{
		write(1, "rrb\n", 4);
		rrb(edge);
		rb_index--;
	}
}

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
	t_deque	*temp;

	temp = edge->head_b;
	while (b->big_index + b->small_index + b->middle_index < range)
	{
		if (temp->num > b->pivot_l)
		{
			temp = temp->next;
			b->big_index++;
			write(1, "pa\n", 3);
			pa(edge);
		}
		else if (temp->num < b->pivot_s)
		{
			temp = temp->next;
			b->small_index++;
			write(1, "rb\n", 3);
			rb(edge);
		}
		else
		{
			temp = temp->next;
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

void	B_to_A(t_deque_edge *edge, t_data data, int range)
{
	t_pivot_index	b;

	ft_memset(&b, 0, sizeof(b));
	if (range <= 5)
	{
		less_than_five_b(edge, range);
		return ;
	}
	define_pivot(edge->head_b, data, range, &b.pivot_l, &b.pivot_s);
	partition_b(edge, &b, range);
	A_to_B(edge, data, b.big_index);
	reverse_partition_b(edge, &b);
	A_to_B(edge, data, b.middle_index);
	B_to_A(edge, data, b.small_index);
}