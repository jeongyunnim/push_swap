/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:58:23 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/15 16:12:03 by jeseo            ###   ########.fr       */
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

int parse_data(t_data *data, char *str)
{
	int		i;
	char	*temp;

	i = 0;
	data->num = count_arg(str);
	//printf("data->num: %d\n", data->num);
	data->arr = (int *)malloc(data->num * sizeof(int));
	if (data->arr == NULL)
		return (ERROR);
	temp = data->arr_data;
	while (str && *str != '\0' && i < data->num)
	{
		(data->arr)[i] = split_arg(&data->arr_data);
		//printf("arr[%d]: %d\n", i, (data->arr)[i]);
		usleep(3000);
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

void	sort_in_deque_a(t_deque_edge *edge, int small_index)
{
	int	i;

	i = 0;
	rrb(edge);
	while (i <= small_index)
	{
		pb(edge);
	}
}

void	define_pivot_a(t_deque_edge *edge, t_data data, int range, int *larg_p, int *sml_p)
{
	t_deque	*temp;
	int		i;
	int		max;

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
	*larg_p = data.arr[i - (range / 3)];
	*sml_p = data.arr[i - ((range / 3) * 2)];
	return ;
}

void	define_pivot_b(t_deque_edge *edge, t_data data, int range, int *larg_p, int *sml_p)
{
	t_deque	*temp;
	int		i;
	int		max;

	i = 0;
	temp = edge->head_b;
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
	*larg_p = data.arr[i - (range / 3)];
	*sml_p = data.arr[i - ((range / 3) * 2)];
	return ;
}

void	arrange_three(t_deque_edge *edge, char c)
{
	t_deque	*temp;
	int		arr[3];
	int		i;

	if (c == 'a')
	{
		temp = edge->head_a;
		i = 0;
		while (i < 3)
		{
			arr[i++] = temp->num;
			temp = temp->next;
		}
		if (arr[0] > arr[1] && arr[0] > arr[2])
		{
			
		}
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
	//else if (range == 3)
	//{
	//	arrange_three(edge);
	//	return ;
	//}
	define_pivot_b(edge, data, range, &pivot_l, &pivot_s);
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
	A_to_B(edge, data, big_index);
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
	//else if (range == 3)
	//{
	//	arrange_three(edge);
	//	return ;
	//}
	define_pivot_a(edge, data, range, &pivot_l, &pivot_s);
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

void	quick_sort_arr(int *arr, int length)
{
	quick_sort_recursive(arr, 0, length - 1);
}

int	main(int argc, char **argv)
{
	t_deque_edge edge;
	t_data		data;
	char		*temp;
	int 		i;

	if (argc < 1)
		return (write(2, "ARGUMENT COUNT ERROR\n", 21));
	data.arr_data = (char *)ft_calloc(1, sizeof(char));
	i = 1;
	while (argv[i] != NULL)
	{
		temp = data.arr_data;
		data.arr_data = ft_strjoin(data.arr_data, ft_strjoin(argv[i], " "));
		free(temp);
		//printf("%s\n", data.arr_data);
		i++;
	}
	if (parse_data(&data, data.arr_data) == -1)
		return (write(2, "PARSING ERROR\n", 14));
	//printf("%s\n", data.arr_data);
	if (data.arr == NULL)
		return (write(2, "ALLOCATE ERROR\n", 15));
	//i = -1;
	memset(&edge, 0, sizeof(edge));
	//printf("data.num: %d\n", data.num);
	//while (++i < data.num)
	//{
	//	printf("arr[%d]: %d\n", i, (data.arr)[i]);
	//}
    arr_to_deque(data, &edge);
	quick_sort_arr(data.arr, data.num);
	//i = -1;
	//while (++i < data.num)
	//{
	//	printf("arr[%d]: %d\n", i, (data.arr)[i]);
	//}
	//print_deque(&edge);
	A_to_B(&edge, data, data.num);
	//print_deque(&edge);
	free_all(&data, &edge);
	return (0);
}

/*
	a
*/