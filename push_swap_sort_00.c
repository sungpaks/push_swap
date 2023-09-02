/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_00.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghoch <sunghoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:11:47 by sunghoch          #+#    #+#             */
/*   Updated: 2023/09/02 13:55:22 by sunghoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	begin_sort(t_ps *ps)
{
	if (ps->a.size < 2)
		return (1);
	else if (ps->a.size == 2)
		return (two_sort(ps, 'a'));
	else if (ps->a.size == 3)
		return (three_sort(ps));
	else
	{
		if (!partition(ps))
			return (0);
		if (!greedy_like_sort(ps))
			return (0);
	}
	return (1);
}

int	partition(t_ps *ps)
{
	int				pivot1;
	int				pivot2;
	unsigned int	i;

	get_pivot(&(ps->a), &pivot1, &pivot2);
	i = ps->a.size;
	while (i--)
	{
		if (ps->a.front->n <= pivot2)
		{
			if (!call_method(ps, "pb\n"))
				return (0);
			if (ps->b.size > 1 && ps->b.front->n <= pivot1)
			{
				if (!call_method(ps, "rb\n"))
					return (0);
			}
		}
		else if (!call_method(ps, "ra\n"))
			return (0);
	}
	while (ps->a.size > 3)
		if (!call_method(ps, "pb\n"))
			return (0);
	return (three_sort(ps));
}

void	get_pivot(t_stack *a, int *pivot1, int *pivot2)
{
	t_node	*current_i;
	t_node	*current_j;
	int		cnt;

	*pivot1 = 0;
	*pivot2 = 0;
	current_i = a->front;
	while (current_i)
	{
		cnt = 0;
		current_j = a->front;
		while (current_j)
		{
			if (current_i->n > current_j->n)
				cnt++;
			current_j = current_j->prev;
		}
		if (cnt == a->size / 3)
			*pivot1 = cnt;
		if (cnt == 2 * (a->size / 3))
			*pivot2 = cnt;
		current_i = current_i->prev;
	}
}

int	two_sort(t_ps *ps, char c)
{
	if (c == 'a')
	{
		if (ps->a.front->n > ps->a.front->prev->n)
			return (call_method(ps, "sa\n"));
		else
			return (1);
	}
	if (c == 'b')
	{
		if (ps->b.front->n > ps->b.front->prev->n)
			return (call_method(ps, "sb\n"));
		else
			return (1);
	}
	return (0);
}

int	three_sort(t_ps *ps)
{
	t_node	*a_top;

	a_top = ps->a.front;
	if (a_top->n > a_top->prev->n && a_top->prev->n > a_top->prev->prev->n)
		return (call_method(ps, "sa\n") && call_method(ps, "rra\n"));
	else if (a_top->n > a_top->prev->n && a_top->n > a_top->prev->prev->n)
		return (call_method(ps, "ra\n"));
	else if (a_top->n > a_top->prev->n && a_top->n < a_top->prev->prev->n)
		return (call_method(ps, "sa\n"));
	else if (a_top->n < a_top->prev->n && a_top->prev->n > a_top->prev->prev->n)
	{
		if (a_top->n > a_top->prev->prev->n)
			return (call_method(ps, "rra\n"));
		else
			return (call_method(ps, "sa\n") && call_method(ps, "ra\n"));
	}
	else if (a_top->n < a_top->prev->n && a_top->prev->n < a_top->prev->prev->n)
		return (1);
	return (0);
}
