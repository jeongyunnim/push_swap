/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:58:23 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/27 16:58:30 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_isspace(char c)
{
	if ((9 < c && c < 13) || c == ' ')
		return (0);
	else
		return (-1);
}

int	ft_isnum(char c)
{
	if ('0' <= c && c <= '9')
		return (0);
	else
		return (-1);
}

void	free_all(t_data *data, t_deque_edge *edge)
{
	t_deque	*temp;

	if (data->arr != NULL)
		free(data->arr);
	data->arr = NULL;
	if (data->arr_data != NULL)
		free(data->arr_data);
	data->arr_data = NULL;
	temp = edge->head_a;
	while (edge->head_a != NULL)
	{
		temp = pop_head(&(edge->head_a));
		free(temp);
	}
	temp = edge->head_b;
	while (edge->head_b != NULL)
	{
		temp = pop_head(&(edge->head_b));
		free(temp);
	}
	edge->tail_a = NULL;
	edge->tail_b = NULL;
}
