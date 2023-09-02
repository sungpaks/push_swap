/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghoch <sunghoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 22:24:28 by sunghoch          #+#    #+#             */
/*   Updated: 2023/04/06 17:52:08 by sunghoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*copy;
	t_list	*copy_head;
	char	*tmp;

	copy_head = 0;
	while (lst)
	{
		tmp = (char *)f(lst->content);
		copy = ft_lstnew(tmp);
		if (!(copy))
		{
			ft_lstclear(&copy_head, del);
			del(tmp);
			break ;
		}
		ft_lstadd_back(&copy_head, copy);
		lst = lst->next;
	}
	return (copy_head);
}
