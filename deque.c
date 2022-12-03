/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:19:03 by jeseo             #+#    #+#             */
/*   Updated: 2022/12/03 15:24:24 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_list	*pop_head(t_list **head)
{
	t_list	*pop;

	pop = *head;
	if (pop == NULL)
		return (NULL);
	*head = (*head)->next;
	if (*head == NULL)
		return (NULL);
	(*head)->previous = NULL;
	pop->next = NULL;
	pop->previous = NULL;
	return (pop);
}

t_list	*pop_tail(t_list **tail)
{
	t_list	*pop;

	pop = *tail;
	if (pop == NULL)
		return (NULL);
	*tail = (*tail)->previous;
	if (*tail == NULL)
		return (NULL);
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
	append_head(&(edge->head_a), &(edge->tail_a), target);
}

void	pb(t_list_edge *edge)
{
	t_list	*target;

	if (edge->head_a == NULL)
		return ;
	target = pop_head(&(edge->head_a));
	append_head(&(edge->head_b), &(edge->tail_b), target);
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

void	print_list_a(t_list_edge *edge)
{
	t_list	*temp;
	int i;
	
	printf("============A===========\n");
	i = 0;
	temp = edge->head_a;
	if (temp == NULL)
	{
		printf("EMPTY\n");
		return ;
	}
	while (temp != NULL)
	{ 
		printf("A[%d]: %d\n", i++, temp->num);
		temp = temp->next;
	}
	temp = edge->tail_a;
	printf("========================\n");
	i--;
	while (temp != NULL)
	{
		printf("A[%d]: %d\n", i--, temp->num);
		temp = temp->previous;
	}
	printf("head_a: %d | tail_a: %d\n", edge->head_a->num, edge->tail_a->num);
}

void	print_list_b(t_list_edge *edge)
{
	t_list	*temp;
	int i;
	
	printf("============B===========\n");
	i = 0;
	temp = edge->head_b;
	if (temp == NULL)
	{
		printf("EMPTY\n");
		return ;
	}
	while (temp != NULL)
	{ 
		printf("B[%d]: %d\n", i++, temp->num);
		temp = temp->next;
	}
	temp = edge->tail_b;
	printf("========================\n");
	i--;
	while (temp != NULL)
	{
		printf("B[%d]: %d\n", i--, temp->num);
		temp = temp->previous;
	}
	printf("head_b: %d | tail_b: %d\n", edge->head_b->num, edge->tail_b->num);
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
	//print_list_a(edge);
	//print_list_b(edge);
	//pb(edge);
	//pb(edge);
	//pb(edge);
	//sb(edge);
	//print_list_a(edge);
	//print_list_b(edge);
}
