/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:53:50 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/26 21:42:53 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int argc, char **argv)
{
	t_deque_edge	edge;
	t_data			data;
	char			*temp;
	int				i;

	if (argc < 1)
		return (write(2, "ARGUMENT COUNT ERROR\n", 21));
	data.arr_data = (char *)ft_calloc(1, sizeof(char));
	i = 1;
	while (argv[i] != NULL)
	{
		temp = data.arr_data;
		if (argument_check(argv[i]) == ERROR)
			free_then_exit(&edge, &data);
		data.arr_data = ft_strjoin(data.arr_data, ft_strjoin(argv[i++], " "));
		free(temp);
	}
	ft_memset(&edge, 0, sizeof(edge));
	parsing_argument(&edge, &data);
	if (data.num > 5)
		a_to_b(&edge, data, data.num);
	else
		little_number_arrange(&edge, data);
	free_all(&data, &edge);
	return (0);
}
