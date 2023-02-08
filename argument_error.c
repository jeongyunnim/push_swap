/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:58:56 by jeseo             #+#    #+#             */
/*   Updated: 2023/02/08 16:19:38 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_then_exit(t_deque_edge *edge, t_data *data)
{
	free_all(data, edge);
	exit(EXIT_FAILURE);
}

int	sign_check(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
	{
		if (ft_isnum(arg[i + 1]) != 0)
			return (ERROR);
	}
	else
		return (ERROR);
	return (0);
}

int	argument_check(char *arg)
{
	int	flag;

	flag = 0;
	while (*arg != '\0')
	{
		if (ft_isspace(*arg) != 0 && ft_isnum(*arg) != 0 \
		&& sign_check(arg) != 0)
		{
			flag = 0;
			break ;
		}
		else if (ft_isnum(*arg) == 0)
		{
			flag = 1;
		}
		arg++;
	}
	if (flag == 0)
	{
		write(2, "Error\nINVALID ARGUMENT\n", 23);
		return (ERROR);
	}
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

int	overlap_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->num - 1)
	{
		j = i + 1;
		while (j < data->num)
		{
			if (data->arr[i] == data->arr[j])
				return (ERROR);
			j++;
		}
		i++;
	}
	return (0);
}
