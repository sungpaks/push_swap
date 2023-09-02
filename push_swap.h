/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghoch <sunghoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:57:08 by sunghoch          #+#    #+#             */
/*   Updated: 2023/09/02 13:37:47 by sunghoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# ifndef INF
#  define INF 2147483647
# endif
# ifndef NINF
#  define NINF -2147483648
# endif

typedef struct s_node {
	int				n;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack {
	int		size;
	t_node	*front;
	t_node	*back;
}	t_stack;

typedef struct s_push_swap {
	unsigned int	cnt;
	t_stack			a;
	t_stack			b;
}	t_ps;

int		push_back(t_node *new_node, t_stack *p_stack);
int		push_front(t_node *new_node, t_stack *p_stack);
t_node	*pop_back(t_stack *p_stack);
t_node	*pop_front(t_stack *p_stack);
int		contain(t_stack *p_stack, int num);

void	ps_init(t_ps *ps);
int		ps_parse_argument(t_ps *ps, int argc, char **argv);
void	ps_remove_space(char **str);
char	*ps_atoi(char *str, int *num);

int		call_method(t_ps *ps, char *str);
int		r(t_stack *p_stack);
int		s(t_stack *p_stack);
int		p(t_stack *p_from, t_stack *p_to);
int		reverse_r(t_stack *p_stack);

int		two_sort(t_ps *ps, char c);
int		three_sort(t_ps *ps);
void	get_pivot(t_stack *a, int *pivot1, int *pivot2);
int		partition(t_ps *ps);
int		begin_sort(t_ps *ps);

int		rotate_cnt_a(t_ps *ps, int cur);
void	rotate_cnt_b(t_ps *ps, int *a_min, int *b_min);
int		rotate_each(t_ps *ps, int *a_min, int *b_min);
int		rotate_together(t_ps *ps, int *a_min, int *b_min);
int		get_min_value(int a_min, int b_min, int a_cnt, int b_cnt);

int		greedy_like_sort(t_ps *ps);
int		final_rotate(t_ps *ps);
int		get_min(t_stack *p_stack, int *min_idx);
int		get_max(t_stack *p_stack, int *max_idx);

int		is_method(char *s1, char *s2, t_ps *ps);
t_node	*get_new_node(int n);
int		is_sorted(t_ps *ps);
t_node	*go_to_min_pos(t_stack *p_stack, int min_idx);
void	free_and_exit(t_ps *ps, int isError);

#endif