/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:14:55 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/27 18:41:18 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

int	main(int argc, char **argv)
{
	char			*buffer;
	t_deque_edge	edge;
	t_data			data;

	if (argc < 2)
		exit(EXIT_FAILURE);
	initialize_structure(&edge, &data, argv);
	parsing_argument(&edge, &data);
	while (1)
	{
		buffer = get_next_line(STDIN_FILENO);
		if (buffer == NULL)
		{
			break ; //ctl + d
		}
		execute
	}
	
	return (0);
}
