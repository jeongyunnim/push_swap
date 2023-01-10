/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_error_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:58:56 by jeseo             #+#    #+#             */
/*   Updated: 2023/01/10 21:06:32 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
		write(2, "Error\n", 6);
		return (ERROR);
	}
	else
		return (0);
}
