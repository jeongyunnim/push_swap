/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:58:23 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/14 18:11:08 by jeseo            ###   ########.fr       */
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

void	sort_in_deque_a(t_deque_edge *edge, int pa_index)
{
	int	i;

	i = 0;
	rrb(edge);
	while (i <= pa_index)
	{
		pb(edge);
	}
}

int	define_pivot_a(t_deque_edge *edge, t_data data, int range, int larg_p, int sml_p)
{
	t_deque	*temp;
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
	larg_p = data.arr[i - (range / 3)];
	sml_p = data.arr[i - ((range / 3) * 2)];
	return (pivot);
}

void	define_pivot_b(t_deque_edge *edge, t_data data, int range, int larg_p, int sml_p)
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
	larg_p = data.arr[i - (range / 3)];
	sml_p = data.arr[i - ((range / 3) * 2)];
	return ;
}

void	B_to_A(t_deque_edge *edge, t_data data, int range)
{
	t_deque	*temp;
	int		rb_index;
	int		pb_index;
	int		pivot_l;
	int		pivot_s;
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
		printf("pa\n");
		pa(edge);
		return ;
	}
	else if (range == 2)
	{
		if (edge->head_b->num < edge->head_b->next->num)
		{
			printf("sb\npa\npa\n");
			sb(edge);
			pa(edge);
			pa(edge);
			return ;
		}
	}
	else if (range == 3)
	{
		arrange_three(edge);
		return ;
	}
	define_pivot_b(edge, data, range, pivot_l, pivot_s);
	while (rb_index + pb_index < range)
	{
		if (temp->num < pivot_s)
		{
			rb_index++;
			temp = temp->next;
			printf("rb\n");
			rb(edge);
		}
		else
		{
			pb_index++;
			temp = temp->next;
			printf("pa\n");
			pa(edge);
		}
	}
	i = -1;
	while (++i < rb_index)
	{
		if (edge->head_b != edge->tail_b)
		{
			printf("rrb\n");
			rrb(edge);
		}
	}
	A_to_B(edge, data, pb_index);
	B_to_A(edge, data, rb_index);
}

void	A_to_B(t_deque_edge *edge, t_data data, int range)
{
	t_deque	*temp;
	int		ra_index;
	int		pa_index;
	int		pivot_l;
	int		pivot_s;
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
		{
			printf("sa\n");
			sa(edge);
		}
		return ;
	}
	else if (range == 3)
	{
		arrange_three(edge);
		return ;
	}
	define_pivot_a(edge, data, range, pivot_l, pivot_s);
 	while (ra_index + pa_index < range)
	{
		if (temp->num > pivot_l)
		{
			ra_index++;
			ra(edge);
		}
		else if (temp->num < pivot_s)
		{
			pa_index++;
			write(1, "pa\n", 3);
			pa(edge);
		}
		else
		{
			write(1, "pa\nrb\n", 6);
			pa(edge);
			rb(edge);
		}
	}
	while (i++ < ra_index)
	{
		write(1, "rra\n", 3);
		rra(edge);
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