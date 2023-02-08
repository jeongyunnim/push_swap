/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:53:50 by jeseo             #+#    #+#             */
/*   Updated: 2023/02/08 16:23:24 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	leak(void)
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	t_deque_edge	edge;
	t_data			data;

	atexit(leak);
	if (argc < 2)
		exit(EXIT_FAILURE);
	initialize_structure(&edge, &data, argv);
	parsing_argument(&edge, &data);
	if (data.num > 5)
		a_to_b(&edge, data, data.num);
	else
		little_number_arrange(&edge, data);
	free_all(&data, &edge);
	return (0);
}
