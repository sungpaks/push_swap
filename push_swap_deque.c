/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_deque.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghoch <sunghoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:51:46 by sunghoch          #+#    #+#             */
/*   Updated: 2023/08/22 20:50:02 by sunghoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_back(t_node *new_node, t_stack *p_stack)
{
	if (!new_node)
		return (0);
	if (contain(p_stack, new_node->n))
	{
		free(new_node);
		return (0);
	}
	if (p_stack->size == 0)
	{
		new_node->prev = NULL;
		new_node->next = NULL;
		p_stack->front = new_node;
		p_stack->back = new_node;
	}
	else
	{
		new_node->prev = NULL;
		new_node->next = p_stack->back;
		p_stack->back->prev = new_node;
		p_stack->back = new_node;
	}
	p_stack->size++;
	return (1);
}

int	push_front(t_node *new_node, t_stack *p_stack)
{
	if (!new_node)
		return (0);
	if (contain(p_stack, new_node->n))
		return (0);
	if (p_stack->size == 0)
	{
		new_node->prev = NULL;
		new_node->next = NULL;
		p_stack->front = new_node;
		p_stack->back = new_node;
	}
	else
	{
		new_node->next = NULL;
		new_node->prev = p_stack->front;
		p_stack->front->next = new_node;
		p_stack->front = new_node;
	}
	p_stack->size++;
	return (1);
}

t_node	*pop_back(t_stack *p_stack)
{
	t_node	*return_value;

	if (p_stack->back == NULL || p_stack->size == 0)
		return (NULL);
	return_value = p_stack->back;
	if (p_stack->size == 1)
	{
		p_stack->front = NULL;
		p_stack->back = NULL;
	}
	else
	{
		p_stack->back = p_stack->back->next;
		p_stack->back->prev = NULL;
	}
	return_value->next = NULL;
	p_stack->size--;
	return (return_value);
}

t_node	*pop_front(t_stack *p_stack)
{
	t_node	*return_value;

	if (p_stack->front == NULL || p_stack->size == 0)
		return (NULL);
	return_value = p_stack->front;
	if (p_stack->size == 1)
	{
		p_stack->front = NULL;
		p_stack->back = NULL;
	}
	else
	{
		p_stack->front = p_stack->front->prev;
		p_stack->front->next = NULL;
	}
	return_value->prev = NULL;
	p_stack->size--;
	return (return_value);
}

int	contain(t_stack *p_stack, int num)
{
	t_node	*current;

	current = p_stack->front;
	while (current)
	{
		if (current->n == num)
			return (1);
		current = current->prev;
	}
	return (0);
}
