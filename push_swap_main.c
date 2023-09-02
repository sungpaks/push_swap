/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghoch <sunghoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:12:20 by sunghoch          #+#    #+#             */
/*   Updated: 2023/09/02 13:56:49 by sunghoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc < 2)
		exit(0);
	ps_init(&ps);
	if (!ps_parse_argument(&ps, argc - 1, argv + 1))
		free_and_exit(&ps, 1);
	if (is_sorted(&ps))
	{
		if (!final_rotate(&ps))
			free_and_exit(&ps, 1);
		else
			free_and_exit(&ps, 0);
	}
	if (!begin_sort(&ps))
		free_and_exit(&ps, 1);
	free_and_exit(&ps, 0);
}

void	ps_init(t_ps *ps)
{
	ps->cnt = 0;
	ps->a.size = 0;
	ps->b.size = 0;
	ps->a.front = NULL;
	ps->b.front = NULL;
}

int	ps_parse_argument(t_ps *ps, int argc, char **argv)
{
	int	num;

	while (argc--)
	{
		while (**argv && *argv)
		{
			num = 0;
			ps_remove_space(argv);
			if (!**argv)
				break ;
			*argv = ps_atoi(*argv, &num);
			if (!*argv)
				return (0);
			if (!push_back(get_new_node(num), &(ps->a)))
				return (0);
		}
		argv++;
	}
	return (1);
}

char	*ps_atoi(char *str, int *num)
{
	long long	cnt_minus;
	long long	result;

	cnt_minus = 1;
	if (!*str)
		return (str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			cnt_minus *= -1;
		if (!*(++str))
			return (str);
	}
	result = 0;
	while (('0' <= *str && *str <= '9') && result < 10e12)
	{
		result *= 10;
		result += (long long)(*str - 48);
		str++;
	}
	result *= cnt_minus;
	if (result < -2147483648 || result > 2147483647)
		return (NULL);
	*num = result;
	return (str);
}

void	ps_remove_space(char **str)
{
	while (**str)
	{
		if (**str == '\t' || **str == '\n' || **str == '\v' \
				|| **str == '\f' || **str == '\r' || **str == ' ')
			(*str)++;
		else
			break ;
	}
}
