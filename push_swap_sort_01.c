/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghoch <sunghoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:06:35 by sunghoch          #+#    #+#             */
/*   Updated: 2023/08/23 11:44:59 by sunghoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_cnt_b(t_ps *ps, int *a_min, int *b_min)
{
	t_node	*current;
	int		idx;
	int		a_cnt;
	int		b_cnt;

	idx = -1;
	*a_min = INF;
	*b_min = INF;
	current = ps->b.front;
	while (++idx < ps->b.size)
	{
		a_cnt = rotate_cnt_a(ps, current->n);
		b_cnt = idx;
		if (idx >= (ps->b.size + 1) / 2)
			b_cnt = -1 * (ps->b.size - idx);
		if (!idx || get_min_value(*a_min, *b_min, a_cnt, b_cnt))
		{
			*a_min = a_cnt;
			*b_min = b_cnt;
		}
		current = current->prev;
	}
	return ;
}

int	rotate_cnt_a(t_ps *ps, int cur)
{
	t_node	*current;
	int		idx;
	int		max_idx;
	int		min_idx;

	if (cur > get_max(&(ps->a), &max_idx))
		idx = max_idx + 1;
	else if (cur < get_min(&(ps->a), &min_idx))
		idx = min_idx;
	else
	{
		idx = 1;
		current = ps->a.front;
		while (current->prev)
		{
			if (current->n < cur && current->prev->n > cur)
				break ;
			current = current->prev;
			idx++;
		}
		if (idx >= (ps->a.size + 1) / 2)
			idx = -1 * (ps->a.size - idx);
	}
	return (idx);
}

int	get_min_value(int a_min, int b_min, int a_cnt, int b_cnt)
{
	if (a_min < 0)
		a_min *= -1;
	if (b_min < 0)
		b_min *= -1;
	if (a_cnt < 0)
		a_cnt *= -1;
	if (b_cnt < 0)
		b_cnt *= -1;
	return (a_min + b_min > a_cnt + b_cnt);
}

int	rotate_together(t_ps *ps, int *a_min, int *b_min)
{
	while (*a_min != 0 && *b_min != 0)
	{
		if (*a_min < 0 && *b_min < 0)
		{
			if (!call_method(ps, "rrr\n"))
				return (0);
			(*a_min)++;
			(*b_min)++;
		}
		else if (*a_min > 0 && *b_min > 0)
		{
			if (!call_method(ps, "rr\n"))
				return (0);
			(*a_min)--;
			(*b_min)--;
		}
		else
			break ;
	}
	return (1);
}

int	rotate_each(t_ps *ps, int *a_min, int *b_min)
{
	if (*a_min > 0)
	{
		while ((*a_min)-- != 0)
			if (!call_method(ps, "ra\n"))
				return (0);
	}
	else
	{
		while ((*a_min)++ != 0)
			if (!call_method(ps, "rra\n"))
				return (0);
	}
	if (*b_min > 0)
	{
		while ((*b_min)-- != 0)
			if (!call_method(ps, "rb\n"))
				return (0);
	}
	else
	{
		while ((*b_min)++ != 0)
			if (!call_method(ps, "rrb\n"))
				return (0);
	}
	return (1);
}
