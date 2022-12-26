/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:53:50 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/26 18:21:57 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int argc, char **argv)
{
	t_deque_edge	edge;
	t_data			data;
	char			*temp;
	int 			i;

	if (argc < 1)
		return (write(2, "ARGUMENT COUNT ERROR\n", 21));
	data.arr_data = (char *)ft_calloc(1, sizeof(char));
	i = 1;
	while (argv[i] != NULL)
	{
		temp = data.arr_data;
		if (argument_check(argv[i]) == ERROR)
			print_error_exit(&edge, &data);
		data.arr_data = ft_strjoin(data.arr_data, ft_strjoin(argv[i], " "));
		free(temp);
		i++;
	}
	error_check(&edge, &data);
	ft_memset(&edge, 0, sizeof(edge));
    arr_to_deque(data, &edge);
	quick_sort_arr(data.arr, data.num); // 정렬 한 다음에 같은 게 있는지 찾아보자.
	if (overlap_check(data) == ERROR)
		return (write(2, "ARGUMENT OVERLAPPED\n", 20));
	if (data.num > 5)
	{
		A_to_B(&edge, data, data.num);
	}
	else
	{
		little_number_arrange(&edge, data);
	}
	free_all(&data, &edge);
	return (0);
}