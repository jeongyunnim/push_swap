/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:14:55 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/27 21:02:12 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

int	execute_command(char *command, t_deque_edge *edge)
{
	if (ft_strcmp(command, "sa\n") == 0)
		sa(edge);
	else if (ft_strcmp(command, "sb\n") == 0)
		sb(edge);
	else if (ft_strcmp(command, "ss\n") == 0)
		ss(edge);
	else if (ft_strcmp(command, "pa\n") == 0)
		pa(edge);
	else if (ft_strcmp(command, "pb\n") == 0)
		pb(edge);
	else if (ft_strcmp(command, "ra\n") == 0)
		ra(edge);
	else if (ft_strcmp(command, "rb\n") == 0)
		rb(edge);
	else if (ft_strcmp(command, "rr\n") == 0)
		rr(edge);
	else if (ft_strcmp(command, "rra\n") == 0)
		rra(edge);
	else if (ft_strcmp(command, "rrb\n") == 0)
		rrb(edge);
	else if (ft_strcmp(command, "rrr\n") == 0)
		rrr(edge);
	else
		return (ERROR);
	return (0);
}

int	arranged_check_deque(t_deque_edge *edge)
{
	t_deque	*temp;
	int		target;
	int		flag;

	flag = 0;
	temp = edge->head_a;
	while (temp->next != NULL)
	{
		target = temp->num;
		if (target >= temp->next->num)
			flag = 1;
		temp = temp->next;
	}
	if (edge->head_b != NULL)
		flag = 1;
	if (flag == 0)
		return (0);
	else
		return (ERROR);
}

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
			break ;
		if (execute_command(buffer, &edge) == ERROR)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
	}
	if (arranged_check_deque(&edge) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(&data, &edge);
	return (0);
}
