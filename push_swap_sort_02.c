/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_02.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghoch <sunghoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:04:54 by sunghoch          #+#    #+#             */
/*   Updated: 2023/08/23 11:47:11 by sunghoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	greedy_like_sort(t_ps *ps)
{
	int	a_min;
	int	b_min;

	while (ps->b.size)
	{
		rotate_cnt_b(ps, &a_min, &b_min);
		if ((a_min < 0 && b_min < 0) || (a_min > 0 && b_min > 0))
		{
			if (!rotate_together(ps, &a_min, &b_min))
				return (0);
		}
		if (!rotate_each(ps, &a_min, &b_min))
			return (0);
		if (!call_method(ps, "pa\n"))
			return (0);
	}
	return (final_rotate(ps));
}

int	final_rotate(t_ps *ps)
{
	int		min;
	int		min_idx;

	min = get_min(&(ps->a), &min_idx);
	if (min_idx > 0)
	{
		while (min_idx-- != 0)
		{
			if (!call_method(ps, "ra\n"))
				return (0);
		}
	}
	else
	{
		while (min_idx++ != 0)
		{
			if (!call_method(ps, "rra\n"))
				return (0);
		}
	}
	return (1);
}

int	get_min(t_stack *p_stack, int *min_idx)
{
	int		min;
	int		idx;
	t_node	*current;

	min = p_stack->front->n;
	current = p_stack->front;
	idx = 0;
	*min_idx = 0;
	while (current)
	{
		if (min > current->n)
		{
			min = current->n;
			*min_idx = idx;
		}
		current = current->prev;
		idx++;
	}
	if (*min_idx >= (p_stack->size + 1) / 2)
		*min_idx = -1 * (p_stack->size - *min_idx);
	return (min);
}

int	get_max(t_stack *p_stack, int *max_idx)
{
	int		max;
	int		idx;
	t_node	*current;

	max = p_stack->front->n;
	current = p_stack->front;
	idx = 0;
	*max_idx = 0;
	while (current)
	{
		if (max < current->n)
		{
			max = current->n;
			*max_idx = idx;
		}
		current = current->prev;
		idx++;
	}
	if (*max_idx >= (p_stack->size + 1) / 2)
		*max_idx = -1 * (p_stack->size - *max_idx);
	return (max);
}
