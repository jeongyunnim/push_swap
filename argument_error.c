/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:58:56 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/26 20:37:56 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_then_exit(t_deque_edge *edge, t_data *data)
{
	free_all(data, edge);
	exit(EXIT_FAILURE);
}

void	parsing_argument(t_deque_edge *edge, t_data *data)
{
	if (parse_data(data, data->arr_data) == -1)
	{
		write(2, "ALLOCATE ERROR\n", 15);
		free_then_exit(edge, data);
	}
	if (data->arr == NULL)
	{
		write(2, "ALLOCATE ERROR\n", 15);
		free_then_exit(edge, data);
	}
	if (arranged_check_arr(*data) == ERROR)
	{
		write(2, "DATA ARRANGED ALREADY\n", 22);
		free_then_exit(edge, data);
	}
	arr_to_deque(*data, edge);
	quick_sort_arr(data);
	if (overlap_check(*data) == ERROR)
	{
		write(2, "ARGUMENT OVERLAPPED\n", 20);
		free_then_exit(edge, data);
	}
}

int	argument_check(char *arg)
{
	int	flag;

	flag = 0;
	while (*arg != '\0')
	{
		if (ft_isspace(*arg) != 0 && ft_isnum(*arg) != 0 && *arg != '-')
		{
			return (ERROR);
		}
		else if ('0' <= *arg && *arg <= '9')
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
