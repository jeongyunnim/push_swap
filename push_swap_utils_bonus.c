/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:58:23 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/27 20:13:25 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

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

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		}
		i++;
	}
	return (0);
}
