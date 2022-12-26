/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:58:23 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/25 22:26:30 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_isspace(char c)
{
	if ((9 < c && c < 13) || c == ' ')
		return (0);
	else
		return (-1);
}

int	ft_isnum(char c)
{
	if ('0' <= c && c <= '9')
		return (0);
	else
		return (-1);
}

int	count_arg(char *data)
{
	int	cnt;
	int	flag;

	cnt = 0;
	flag = 0;
	while (data != NULL && *data !='\0')
	{
		if (flag == 1 && ft_isspace(*data) == 0)
		{
			flag = 0;
			cnt++;
		}
		else if ('0' <= *data && *data <= '9')
			flag = 1;
		data++;
	}
	if (*data == '\0' && flag == 1) 
		cnt++;
	return (cnt);
}

int	split_arg(char **data)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	while (**data != '\0' && ft_isspace(**data) == 0)
		(*data)++;
	while (*data != NULL && **data != '\0' && ft_isspace(**data) != 0)
	{
		if (**data == '-')
			sign *= -1;
		else if ('0' <= **data && **data <= '9')
		{
			num *= 10;
			num += **data - '0';
		}
		else
		{
			write(2, "ERROR\nINVALID ARGUMENT\n", 23);
			exit(EXIT_FAILURE);
		}
		(*data)++;
	}
	if (num * sign < -2147483648 || num * sign > 2147483647)
	{
		write(2, "ERROR\nOCCURRED INT OVERFLOW\n", 28);
		exit(EXIT_FAILURE);
	}
	return (num * sign);
}

int parse_data(t_data *data, char *str)
{
	int		i;
	char	*temp;

	i = 0;
	data->num = count_arg(str);
	data->arr = (int *)malloc(data->num * sizeof(int));
	if (data->arr == NULL)
		return (ERROR);
	temp = data->arr_data;
	while (str && *str != '\0' && i < data->num)
	{
		(data->arr)[i] = split_arg(&data->arr_data);
		i++;
	}
	free(temp);
	data->arr_data = NULL;
	return (0);
}

void	free_all(t_data *data, t_deque_edge *edge)
{
	t_deque	*temp;

	if (data->arr != NULL)
		free(data->arr);
	data->arr = NULL;
	temp = edge->head_a;
	while (temp != NULL)
	{
		temp = pop_head(&(edge->head_a));
		free(temp);
	}
	while (temp != NULL)
	{
		temp = pop_head(&(edge->head_b));
		free(temp);
	}
	edge->tail_a = NULL;
	edge->tail_b = NULL;
}

void	swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

int	define_pivot_arr(int *arr, int L, int R)
{
	int pivot;
	int	i;
	int	j;

	pivot = arr[R];
	i = L;
	j = L;
	while (j < R)
	{
		if (arr[j] < pivot)
		{
			swap(&arr[i], &arr[j]);
			i++;
		}
		j++;
	}
	swap(&arr[i], &arr[R]);
	return (i);
}

void	quick_sort_recursive(int *arr, int L, int R)
{
	int	pivot;

	if (L < R)
	{
		pivot = define_pivot_arr(arr, L, R);
		quick_sort_recursive(arr, L, pivot - 1);
		quick_sort_recursive(arr, pivot + 1, R);
	}
}

void	quick_sort_arr(int *arr, int length)
{
	quick_sort_recursive(arr, 0, length - 1);
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
		if (num[1] > num[2])
		{
			write(1, "sa\nra\n", 6);
			sa(edge);
			ra(edge);
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
			write(1, "ra\n", 3);
			ra(edge);
		}
	}
	else if (num[2] < num[0] && num[2] < num[1])
	{
		if (num[0] < num[1])
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

void	little_number_arrange(t_deque_edge *edge, t_data data)
{
	int	num[5];
	int min_1;
	int	min_2;
	int	i;

	ft_memset(&num, 0, sizeof(num));
	i = 0;
	while (i < data.num)
	{
		num[i] = data.arr[i];
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

int	argument_check(char *arg)
{
	int	flag;

	flag = 0;
	while (*arg != '\0')
	{
		if (ft_isspace(*arg) != 0 && ft_isnum(*arg) != 0)
		{
			return (ERROR);
		}
		if ('0' <= *arg && *arg <= '9')
		{
			flag = 1;
		}
		arg++;
	}
	if (flag == 0)
		return (ERROR);
	else
		return (0);
}

int	arranged_check_arr(t_data data)
{
	int	target;
	int	flag;
	int	i;

	i = 0;
	flag = 1;
	while (i < data.num - 1)
	{
		target = *(data.arr);
		(data.arr)++;
		if (target > *(data.arr))
			flag = 0;
		i++;
	}
	if (flag == 1)
		return (ERROR);
	else
		return (0);
}

int	overlap_check(t_data data)
{
	int	temp;
	int	i;

	i = 0;
	while (i < data.num - 1)
	{
		temp = data.arr[i];
		if (temp == data.arr[i + 1])
		{
			return (ERROR);
		}
		i++;
	}
	return (0);
}


