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

t_list	*lstnew(int num)
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

// void	sa(t_list_edge *edge)
// {
// 	t_list	*swap_a;
// 	t_list	*swap_b;

// 	printf("do sa\n");
// 	swap_a = edge->head_a;
// 	swap_b = edge->head_a->next;
// 	swap_a->next = swap_b->next;
// 	swap_a->previous = swap_b;
// 	swap_b->next->previous = swap_a;
// 	swap_b->next = swap_a;
// 	swap_b->previous = NULL;
// 	edge->head_a = swap_b;
// }

void	sa(t_list_edge *edge)
{
	int	temp;

	if (edge->head_a == NULL)
		return ;
	temp = edge->head_a->next->num;
	edge->head_a->next->num = edge->head_a->num;
	edge->head_a->num = temp;
}

void	sb(t_list_edge *edge)
{
	int	temp;

	if (edge->head_b == NULL)
		return ;
	temp = edge->head_b->next->num;
	edge->head_b->next->num = edge->head_b->num;
	edge->head_b->num = temp;
}

void	ss(t_list_edge *edge)
{
	sa(edge);
	sb(edge);
}

void	pa(t_list_edge *edge)
{
	t_list	*target;

	if (edge->head_b == NULL)
		return ;
	target = pop_head(&(edge->head_b));
	append_head(&(edge->head_a), &(edge->head_a), target);
}

void	pb(t_list_edge *edge)
{
	t_list	*target;

	if (edge->head_a == NULL)
		return ;
	target = pop_head(&(edge->head_a));
	append_head(&(edge->head_b), &(edge->head_b), target);
}

void	ra(t_list_edge *edge)
{
	t_list	*target;

	if (edge->head_a == edge->tail_a)
		return ;
	target = pop_head(&(edge->head_a));
	append_tail(&(edge->head_a), &(edge->tail_a), target);
}

void	rb(t_list_edge *edge)
{
	t_list	*target;

	if (edge->head_b == edge->tail_b)
		return ;
	target = pop_head(&(edge->head_b));
	append_tail(&(edge->head_b), &(edge->tail_b), target);
}

void	rr(t_list_edge *edge)
{
	ra(edge);
	rb(edge);
}

void	rra(t_list_edge *edge)
{
	t_list	*target;

	target = pop_tail(&(edge->tail_a));
	append_head(&(edge->head_a), &(edge->head_a), target);
}

void	rrb(t_list_edge *edge)
{
	t_list	*target;

	target = pop_tail(&(edge->tail_b));
	append_head(&(edge->head_b), &(edge->head_b), target);
}

void	rrr(t_list_edge *edge)
{
	rra(edge);
	rrb(edge);
}

t_list	*pop_head(t_list **head)
{
	t_list	*pop;

	pop = *head;
	*head = (*head)->next;
	(*head)->previous = NULL;
	pop->next = NULL;
	pop->previous = NULL;
	return (pop);
}

t_list	*pop_tail(t_list **tail)
{
	t_list	*pop;

	pop = *tail;
	*tail = (*tail)->previous;
	(*tail)->next = NULL;
	pop->next = NULL;
	pop->previous = NULL;
	return (pop);
}

void	append_head(t_list **head, t_list **tail, t_list *new)
{
	if (*head == NULL)
	{
		*head = new;
		*tail = new;
	}
	else
	{
		(*head)->previous = new;
		new->next = *head;
		*head = new;
		(*head)->previous = NULL;
	}
}

void	append_tail(t_list **head, t_list **tail, t_list *new)
{
	if (*tail == NULL)
	{
		*head = new;
		*tail = new;
	}
	else
	{
		(*tail)->next = new;
		new->previous = *tail;
		*tail = new;
		(*tail)->next = NULL;
	}
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

	num = 0;
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
	data_set.arr = (int *)malloc(data_set.num * sizeof(int));
	if (data_set.arr == NULL)
		return (data_set);
	while (data && *data != '\0' && i < data_set.num)
	{
		(data_set.arr)[i++] = split_arg(&data);
	}
	return (data_set);
}

void	print_list(t_list_edge *edge)
{
	int i;
	t_list	*temp;
	
	i = 0;
	temp = edge->head_a;
	while (temp != NULL)
	{ 
		printf("%d번째 node: %d\n", i++, temp->num);
		temp = temp->next;
	}
	temp = edge->tail_a;
	printf("========================\n");
	i--;
	while (temp != NULL)
	{
		printf("%d번째 node: %d\n", i--, temp->num);
		temp = temp->previous;
	}
	printf("head_a: %d | tail: %d\n", edge->head_a->num, edge->tail_a->num);
}

void    arr_to_deque(t_data data, t_list_edge *edge)
{
	int 	i;
	t_list	*new;

	i = -1;
	while (++i < data.num)
	{
		new = lstnew(data.arr[i]);
		append_tail(&(edge->head_a), &(edge->tail_a), new);
	}
	print_list(edge);
	ra(edge);
	print_list(edge);
}

int	main(int argc, char **argv)
{
	t_list_edge edge;
	t_data		data;
	int 		i;

	if (argc < 2)
		return (write(2, "ARGUMENT COUNT ERROR\n", 21));
	data = parse_data(argv[1]);
	if (data.arr == NULL)
		return (write(2, "ALLOCATE ERROR\n", 15));
	i = -1;
	memset(&edge, 0, sizeof(edge));
	printf("data.num: %d\n", data.num);
	while (++i < data.num)
	{
		printf("arr[%d]: %d\n", i, (data.arr)[i]);
	}
    arr_to_deque(data, &edge);
	free(data.arr);
/*
	1. 덱 구현하기. - 배열의 요소를 덱에 넣어보기.
	2. push, reverse, swap 등 명령어 구현하기.
	3. 현재 스택의 리스트 출력하여 확인하기.
	4. 명령어 입력 받아서 수행하기... -> 명령어 대기?
*/
	return (0);
}
