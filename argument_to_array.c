/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_to_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:52:40 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/26 21:37:09 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	count_arg(char *data)
{
	int	cnt;
	int	flag;

	cnt = 0;
	flag = 0;
	while (data != NULL && *data != '\0')
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

long long	split_arg(char **data)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	while (**data != '\0' && ft_isspace(**data) == 0)
		(*data)++;
	if (**data == '-' && (*data)++)
		sign *= -1;
	while (*data != NULL && **data != '\0' && ft_isspace(**data) != 0)
	{
		if (ft_isnum(**data) == 0)
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
	return (num * sign);
}

int	parse_data(t_data *data, char *str)
{
	int			i;
	long long	num;
	char		*temp;

	i = 0;
	data->num = count_arg(str);
	data->arr = (int *)malloc(data->num * sizeof(int));
	if (data->arr == NULL)
		return (ERROR);
	temp = data->arr_data;
	while (str && *str != '\0' && i < data->num)
	{
		num = split_arg(&data->arr_data);
		if (num < -2147483648 || num > 2147483647)
		{
			write(2, "ERROR\nINT OVERFLOW\n", 28);
			return (ERROR);
		}
		(data->arr)[i] = num;
		i++;
	}
	free(temp);
	data->arr_data = NULL;
	return (0);
}

void	arr_to_deque(t_data data, t_deque_edge *edge)
{
	int		i;
	t_deque	*new;

	i = -1;
	while (++i < data.num)
	{
		new = lstnew(data.arr[i]);
		append_tail(&(edge->head_a), &(edge->tail_a), new);
	}
}
