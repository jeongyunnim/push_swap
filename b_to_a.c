#include "./push_swap.h"

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
			write(1, "pa\npa\npa\n", 9);
			pa(edge);
			pa(edge);
			pa(edge);
		}
	}
}

void	less_than_three_b(t_deque_edge *edge, int range)
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
	if (range <= 3)
	{
		less_than_three_b(edge, range);
		return ;
	}
	define_pivot(edge->head_b, data, range, &b.pivot_l, &b.pivot_s);
	partition_b(edge, &b, range);
	A_to_B(edge, data, b.big_index);
	reverse_partition_b(edge, &b);
	A_to_B(edge, data, b.middle_index);
	B_to_A(edge, data, b.small_index);
}