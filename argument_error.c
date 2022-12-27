/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:58:56 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/27 17:12:27 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_then_exit(t_deque_edge *edge, t_data *data)
{
	free_all(data, edge);
	exit(EXIT_FAILURE);
}

int	argument_check(char *arg)
{
	int	flag;

	flag = 0;
	while (*arg != '\0')
	{
		if (ft_isspace(*arg) != 0 && ft_isnum(*arg) != 0 && *arg != '-')
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
