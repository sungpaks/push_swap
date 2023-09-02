/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghoch <sunghoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:10:26 by sunghoch          #+#    #+#             */
/*   Updated: 2023/04/05 17:24:57 by sunghoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	i;
	unsigned int	l;

	if (ft_strlen(s) <= start)
		l = 0;
	else if (ft_strlen(s + start) > len)
		l = len;
	else
		l = ft_strlen(s + start);
	result = (char *)malloc(sizeof(char) * (l + 1));
	if (!result)
		return (0);
	i = 0;
	while (i < l)
	{
		*(result + i) = *(s + start + i);
		i++;
	}
	*(result + i) = 0;
	return (result);
}
