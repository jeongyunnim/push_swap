/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:09:24 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/27 17:12:20 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	parsing_argument(t_deque_edge *edge, t_data *data)
{
	if (parse_data(data, data->arr_data) == -1)
	{
		write(2, "Error\nINT ARRAY ALLOCATE ERROR\n", 31);
		free_then_exit(edge, data);
	}
	if (arranged_check_arr(*data) == ERROR)
	{
		write(2, "Error\nDATA ARRANGED ALREADY\n", 28);
		free_then_exit(edge, data);
	}
	arr_to_deque(data, edge);
	quick_sort_arr(data);
	if (overlap_check(*data) == ERROR)
	{
		write(2, "Error\nARGUMENT OVERLAPPED\n", 26);
		free_then_exit(edge, data);
	}
}

void	initialize_structure(t_deque_edge *edge, t_data *data, char **argv)
{
	char	*temp;
	int		i;

	ft_memset(data, 0, sizeof(*data));
	ft_memset(edge, 0, sizeof(*edge));
	data->arr_data = (char *)ft_calloc(1, sizeof(char));
	if (data->arr_data == NULL)
	{
		write(2, "Erorr\nSTRING sALLOCATE ERROR\n", 29);
		free_then_exit(edge, data);
	}
	i = 1;
	while (argv[i] != NULL)
	{
		temp = data->arr_data;
		if (argument_check(argv[i]) == ERROR)
			free_then_exit(edge, data);
		data->arr_data = ft_strjoin(data->arr_data, ft_strjoin(argv[i++], " "));
		free(temp);
	}
}
