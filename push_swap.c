/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:58:23 by jeseo             #+#    #+#             */
/*   Updated: 2022/11/23 21:58:59 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_list	*ft_lstnew(int num)
{
	t_list	*link;

	link = (t_list *)malloc(1 * sizeof(t_list));
	if (link == NULL)
		return (NULL);
	link->num = num;
	link->previous = NULL;
	link->next = NULL;
	return (link);
}

void	initialize_edge(t_list_edge *edge)
{
	edge->head = (t_list *)malloc(sizeof(t_list) * 1);
	edge->tail = (t_list *)malloc(sizeof(t_list) * 1);
}

int	ft_isspace(char	c)
{
	if ((9 < c && c < 13) || c == ' ')
		return (0);
	else
		return (-1);
}

int	count_arg(char *data)
{
	int	cnt;
	int	flag;

	cnt = 0;
	flag = 0;
	while (data != NULL && *data !='\0')
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

int	split_arg(char **data)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (**data != '\0' && ft_isspace(**data) == 0)
		(*data)++;
	while (*data != NULL && **data != '\0')
	{
		if ('0' <= **data && **data <= '9')
		{
			num *= 10;
			num += **data - '0';
		}
		else if (num != 0)
			break ;
		(*data)++;
	}
	return (num);
}

t_data parse_data(char *data)
{
	t_data data_set;
	int	i;

	i = 0;
	data_set.num = count_arg(data);
	data_set.arr = (int *)calloc(data_set.num, sizeof(int));
	while (data && *data != '\0')
	{
		(data_set.arr)[i++] = split_arg(&data);
	}
	return (data_set);
}

int	main(int argc, char **argv)
{
	t_list_edge edge;
	t_data		data;
	int 		i;

	if (argc < 2)
		return (write(2, "ARGUMENT COUNT ERROR\n", 21));
	data = parse_data(argv[1]);
	initialize_edge(&edge);
	i = -1;
	printf("data.num: %d\n", data.num);
	while (++i < data.num)
	{
		printf("arr[%d]: %d\n", i, (data.arr)[i]);
	}
	free(data.arr);

/*
	1. 덱 구현하기. - 배열의 요소를 덱에 넣어보기.
	2. push, reverse, swap 등 명령어 구현하기.
	3. 현재 스택의 리스트 출력하여 확인하기.
	4. 명령어 입력 받아서 수행하기... -> 명령어 대기?
*/
	return (0);
}
