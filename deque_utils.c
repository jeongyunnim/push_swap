/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:19:03 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/26 14:38:19 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque	*lstnew(int num)
{
	t_deque	*link;

	link = (t_deque *)malloc(1 * sizeof(t_deque));
	if (link == NULL)
		return (NULL);
	link->num = num;
	link->previous = NULL;
	link->next = NULL;
	return (link);
}

t_deque	*pop_head(t_deque **head)
{
	t_deque	*pop;

	pop = *head;
	if (pop == NULL)
		return (NULL);
	if ((*head)->next != NULL)
	{
		*head = (*head)->next;
		(*head)->previous = NULL;
	}
	else
	{
		*head = NULL;
	}
	pop->next = NULL;
	pop->previous = NULL;
	return (pop);
}

t_deque	*pop_tail(t_deque **tail)
{
	t_deque	*pop;

	pop = *tail;
	if (pop == NULL)
		return (NULL);
	if ((*tail)->previous != NULL)
	{
		*tail = (*tail)->previous;
		(*tail)->next = NULL;
	}
	else
	{
		*tail = NULL;
	}
	pop->next = NULL;
	pop->previous = NULL;
	return (pop);
}

void	append_head(t_deque **head, t_deque **tail, t_deque *new)
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

void	append_tail(t_deque **head, t_deque **tail, t_deque *new)
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

void	print_deque(t_deque_edge *edge)
{
	t_deque	*temp_a;
	t_deque	*temp_b;

	int i;
	printf("============A============\t||\t============B============\n");
	i = 0;
	temp_a = edge->head_a;
	temp_b = edge->head_b;
	if (temp_a == NULL)
	{
		printf("deque a is EMPTY\t\t");
	}
	else
	{
		printf("\t\t\t\t||\t");
	}
	if (temp_b == NULL)
	{
		printf("deque b is EMPTY\n");
	}
	else
		printf("\n");
	while (1)
	{
		if (temp_a == NULL && temp_b == NULL)
			break ;
		if (temp_a != NULL)
		{
			printf("A[%d]: %d\t\t\t||\t", i, temp_a->num);
			temp_a = temp_a->next;
		}
		else
		{
			printf("\t\t\t\t||\t");
		}
		if (temp_b != NULL)
		{
			printf("B[%d]: %d", i, temp_b->num);
			temp_b = temp_b->next;
		}
		printf("\n");
		i++;
	}
	if (edge->head_a != NULL)
		printf("head_a: %d | tail_a: %d\n", edge->head_a->num, edge->tail_a->num);
	else
		printf("head_a: %p\n", edge->head_a);
	if (edge->head_b != NULL)
		printf("head_b: %d | tail_b: %d\n", edge->head_b->num, edge->tail_b->num);
	else
		printf("head_a: %p\n", edge->head_b);
}
