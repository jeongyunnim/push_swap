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
	t_list	*head;
	t_list	*tail;
	char	hi[] = "HELLO WORLD\n";

	edge->hi = strdup(hi);
	edge->head = head;
	edge->tail = tail;
}

int	main(void)
{
	t_list_edge edge;
	int 		i;

/*
	값을 받으면 파싱해서 배열에 담아준다.
	입력받은 순서대로 덱큐를 만들어 줌.
*/
	edge.hi = "안녕 세상아\n";
	initialize_edge(&edge);
	printf("%s", edge.hi);
/*
	1. 덱 구현하기.
	2. push, reverse, swap 등 명령어 구현하기.
	3. 현재 스택의 리스트 출력하여 확인하기.
	4. 명령어 입력 받아서 수행하기... -> 명령어 대기?
*/
	return (0);
}
