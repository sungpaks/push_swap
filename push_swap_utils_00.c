/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_00.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghoch <sunghoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:11:06 by sunghoch          #+#    #+#             */
/*   Updated: 2023/09/02 13:57:05 by sunghoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_method(char *s1, char *s2, t_ps *ps)
{
	if (ft_strncmp(s1, s2, ft_strlen(s2)) == 0)
	{
		ft_printf("%s", s2);
		ps->cnt++;
		return (1);
	}
	return (0);
}

t_node	*get_new_node(int n)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

int	is_sorted(t_ps *ps)
{
	int		start;
	int		cnt;
	t_node	*current;

	get_min(&(ps->a), &start);
	cnt = 0;
	current = go_to_min_pos(&(ps->a), start);
	while (++cnt < ps->a.size)
	{
		if (current->prev)
		{
			current = current->prev;
			if (current->n < current->next->n)
				return (0);
		}
		else
		{
			current = ps->a.front;
			if (current->n < ps->a.back->n)
				return (0);
		}
	}
	return (1);
}

t_node	*go_to_min_pos(t_stack *p_stack, int min_idx)
{
	t_node	*current;

	if (min_idx > 0)
	{
		current = p_stack->front;
		while (min_idx--)
			current = current->prev;
	}
	else if (min_idx < 0)
	{
		current = p_stack->back;
		while (++min_idx)
		current = current->next;
	}
	else
		current = p_stack->front;
	return (current);
}

void	free_and_exit(t_ps *ps, int isError)
{
	if (isError)
		ft_printf("Error\n");
	while (ps->a.front)
		free(pop_front(&(ps->a)));
	while (ps->b.front)
		free(pop_front(&(ps->b)));
	exit(0);
}
