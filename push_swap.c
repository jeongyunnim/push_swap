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

int **parse_data(char *data)
{
	int	**data_array;
	int	i;

	i = 0;
	while (data[i] != '\0')
	{
		//if data is white space convert ascii to int.
		//데이터가 arg[1] arg[2] 이런 식으로 들어오는 경우는 어떻게 하지?
		//파싱도 개 같구만..
	}
	return (data_array);
}

int	main(int argc, char **argv)
{
	t_list_edge edge;
	int 		i;

	if (argc < 2)
		return (write(2, "ARGUMENT COUNT ERROR\n", 21));
	parse_data(argv[1]);
/*
	값을 받으면 파싱해서 배열에 담아준다.
	입력받은 순서대로 덱큐를 만들어 줌.
*/
	initialize_edge(&edge);

/*
	1. 덱 구현하기.
	2. push, reverse, swap 등 명령어 구현하기.
	3. 현재 스택의 리스트 출력하여 확인하기.
	4. 명령어 입력 받아서 수행하기... -> 명령어 대기?
*/
	return (0);
}
