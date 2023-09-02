/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_method.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghoch <sunghoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:05:59 by sunghoch          #+#    #+#             */
/*   Updated: 2023/08/23 20:04:42 by sunghoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	call_method(t_ps *ps, char *str)
{
	if (is_method(str, "pa\n", ps))
		return (p(&(ps->b), &(ps->a)));
	if (is_method(str, "pb\n", ps))
		return (p(&(ps->a), &(ps->b)));
	if (is_method(str, "ss\n", ps))
		return (s(&(ps->a)) && s(&(ps->b)));
	if (is_method(str, "sa\n", ps))
		return (s(&(ps->a)));
	if (is_method(str, "sb\n", ps))
		return (s(&(ps->b)));
	if (is_method(str, "rr\n", ps))
		return (r(&(ps->a)) && r(&(ps->b)));
	if (is_method(str, "ra\n", ps))
		return (r(&(ps->a)));
	if (is_method(str, "rb\n", ps))
		return (r(&(ps->b)));
	if (is_method(str, "rrr\n", ps))
		return (reverse_r(&(ps->a)) && reverse_r(&(ps->b)));
	if (is_method(str, "rra\n", ps))
		return (reverse_r(&(ps->a)));
	if (is_method(str, "rrb\n", ps))
		return (reverse_r(&(ps->b)));
	return (0);
}

int	p(t_stack *p_from, t_stack *p_to)
{
	if (p_from->size <= 0 || p_from->front == NULL)
		return (1);
	if (!push_front(pop_front(p_from), p_to))
		return (0);
	return (1);
}

int	s(t_stack *p_stack)
{
	t_node	*node1;
	t_node	*node2;
	int		flag;

	flag = 1;
	if (p_stack->size < 2)
		return (1);
	node1 = pop_front(p_stack);
	node2 = pop_front(p_stack);
	if (!push_front(node1, p_stack))
		flag = 0;
	if (!push_front(node2, p_stack))
		flag = 0;
	return (flag);
}

int	r(t_stack *p_stack)
{
	if (p_stack->size <= 0)
		return (1);
	if (!push_back(pop_front(p_stack), p_stack))
		return (0);
	return (1);
}

int	reverse_r(t_stack *p_stack)
{
	if (p_stack->size <= 0)
		return (1);
	if (!push_front(pop_back(p_stack), p_stack))
		return (0);
	return (1);
}
