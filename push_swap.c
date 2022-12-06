/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:58:23 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/06 21:55:40 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_isspace(char	c)
{
	if ((9 < c && c < 13) || c == ' ')
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
	int	num;

	num = 0;
	while (**data != '\0' && ft_isspace(**data) == 0)
		(*data)++;
	while (*data != NULL && **data != '\0')
	{
		if ('0' <= **data && **data <= '9')
		{
			num *= 10;
			num += **data - '0';
		}
		else if (num != 0)
			break ;
		(*data)++;
	}
	return (num);
}

t_data parse_data(char *data)
{
	t_data data_set;
	int	i;

	i = 0;
	data_set.num = count_arg(data);
	data_set.arr = (int *)malloc(data_set.num * sizeof(int));
	if (data_set.arr == NULL)
		return (data_set);
	while (data && *data != '\0' && i < data_set.num)
	{
		(data_set.arr)[i++] = split_arg(&data);
	}
	return (data_set);
}

void	free_all(t_data *data, t_list_edge *edge)
{
	t_list	*temp;
	
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

void	sort_in_deque_a(t_list_edge *edge, int pa_index)
{
	int	i;

	i = 0;
	rrb(edge);
	while (i <= pa_index)
	{
		pb(edge);
	}
}

void	A_to_B(t_list_edge *edge, int range)
{
	t_list	*temp;
	int		ra_index;
	int		pa_index;
	int		pivot;
	int		i;

	temp = edge->head_a;
	ra_index = 0;
	pa_index = 0;

	while (ra_index + pa_index + 1 < range)
	{
		if (temp->num > pivot)
		{
			ra_index++;
			ra(edge);
		}
		else
		{
			pa_index++;
			pa(edge);
		}
		if (temp->num == pivot)
		{
			rb(edge);
		}
		temp = temp->next;
	}
	i = 0;
	while (i++ < ra_index)
	{
		rra(edge);
	}
	A_to_B(edge, pivot, ra_index);
	B_to_A(edge, pivot, pa_index);
}

void	quick_sort_deque(t_list_edge *edge, t_data data)
{
	int	pivot;

	pivot = data.arr[data.num / 2];
	quick_sort_recursion_deque(edge, pivot, 0, data.num);
}

int	partition(int *arr, int L, int R)
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
	int	i;

	i = L;
	printf("recursived: ");
	while (i < R)
		printf("%d ", arr[i++]);
	printf("\n");
	if (L < R)
	{
		pivot = partition(arr, L, R);
		quick_sort_recursive(arr, L, pivot - 1);
		quick_sort_recursive(arr, pivot + 1, R);
	}
}

void	quick_sort(int *arr, int length)
{
	quick_sort_recursive(arr, 0, length - 1);
}

int	main(int argc, char **argv)
{
	t_list_edge edge;
	t_data		data;
	int 		i;

	if (argc < 2)
		return (write(2, "ARGUMENT COUNT ERROR\n", 21));
	data = parse_data(argv[1]);
	if (data.arr == NULL)
		return (write(2, "ALLOCATE ERROR\n", 15));
	i = -1;
	memset(&edge, 0, sizeof(edge));
	printf("data.num: %d\n", data.num);
	while (++i < data.num)
	{
		printf("arr[%d]: %d\n", i, (data.arr)[i]);
	}
	quick_sort(data.arr, data.num);
	i = 0;
	while (++i < data.num)
	{
		printf("arr[%d]: %d\n", i, (data.arr)[i]);
	}
    arr_to_deque(data, &edge);
	free_all(&data, &edge);
	return (0);
}

/*
	a
*/