/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghoch <sunghoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 12:48:41 by sunghoch          #+#    #+#             */
/*   Updated: 2023/03/30 21:02:11 by sunghoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*uc1;
	unsigned char	*uc2;

	uc1 = (unsigned char *)s1;
	uc2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*(uc1 + i) > *(uc2 + i))
			return (*(uc1 + i) - *(uc2 + i));
		else if (*(uc1 + i) < *(uc2 + i))
			return (*(uc1 + i) - *(uc2 + i));
		i++;
	}
	return (0);
}
