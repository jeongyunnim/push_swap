/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:58:23 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/08 18:00:53 by jeseo            ###   ########.fr       */
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

int	define_pivot_a(t_list_edge *edge, t_data data, int range)
{
	t_list	*temp;
	int		i;
	int		max;
	int		pivot;

	i = 0;
	temp = edge->head_a;
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
	pivot = data.arr[i - (range / 2)];
	return (pivot);
}

int	define_pivot_b(t_list_edge *edge, t_data data, int range)
{
	t_list	*temp;
	int		i;
	int		max;
	int		pivot;

	i = 0;
	temp = edge->head_b;
	max = temp->num;
	if (temp != NULL && i < range)
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
	pivot = data.arr[i - (range / 2)];
	return (pivot);
}

void	B_to_A(t_list_edge *edge, t_data data, int range)
{
	t_list	*temp;
	int		rb_index;
	int		pb_index;
	int		pivot;
	int		i;

	temp = edge->head_b;
	rb_index = 0;
	pb_index = 0;
	if (range == 0)
	{
		return ;
	}
	if (range == 1)
	{
		pb(edge);
		return ;
	}
	else if (range == 2)
	{
		if (edge->head_b->num < edge->head_b->next->num)
			sb(edge);
	}
	pivot = define_pivot_b(edge, data, range);
	printf("BtoA pivot: %d\n", pivot);
	while (rb_index + pb_index < range)
	{
		if (temp->num < pivot)
		{
			rb_index++;
			temp = temp->next;
			//printf("===Do rb===\n");
			rb(edge);
			//print_list(edge);
		}
		else
		{
			pb_index++;
			temp = temp->next;
			//printf("===Do pb===\n");
			pb(edge);
			//print_list(edge);
		}
	}
	i = -1;
	while (++i < rb_index)
	{
		//printf("===Do rrb===\n");
		rrb(edge);
		//print_list(edge);
	}
	A_to_B(edge, data, pb_index);
	B_to_A(edge, data, rb_index);
}

void	A_to_B(t_list_edge *edge, t_data data, int range)
{
	t_list	*temp;
	int		ra_index;
	int		pa_index;
	int		pivot;
	int		i;

	temp = edge->head_a;
	ra_index = 0;
	pa_index = 0;
	if (range <= 1)
	{
		return ;
	}
	else if (range == 2)
	{
		if (edge->head_a->num > edge->head_a->next->num)
			sa(edge);
		return ;
	}
	pivot = define_pivot_a(edge, data, range);
	printf("AtoB pivot: %d\n", pivot);
 	while (ra_index + pa_index < range)
	{
		if (temp->num > pivot)
		{
			ra_index++;
			temp = temp->next;
			//printf("ra\n");
			ra(edge);
			//print_list(edge);
		}
		else
		{
			pa_index++;
			temp = temp->next;
			//printf("pa\n");
			pa(edge);
			//print_list(edge);
		}
	}
	i = -1;
	while (++i < ra_index)
	{
		//printf("rra\n");
		//printf("range:%d ra_index:%d\n", range, ra_index);
		rra(edge);
		//print_list(edge);

	}
	A_to_B(edge, data, ra_index);
	B_to_A(edge, data, pa_index);
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
	i = 0;
	while (argv[i] != NULL)
		data = parse_data(argv[i++]);
	if (data.arr == NULL)
		return (write(2, "ALLOCATE ERROR\n", 15));
	//i = -1;
	memset(&edge, 0, sizeof(edge));
	//printf("data.num: %d\n", data.num);
	//while (++i < data.num)
	//{
	//	printf("arr[%d]: %d\n", i, (data.arr)[i]);
	//}
	quick_sort(data.arr, data.num);
	//i = -1;
	//while (++i < data.num)
	//{
	//	printf("arr[%d]: %d\n", i, (data.arr)[i]);
	//}
    arr_to_deque(data, &edge);
	//print_list(&edge);
	A_to_B(&edge, data, data.num);
	//print_list(&edge);
	free_all(&data, &edge);
	return (0);
}

/*
	a
*/