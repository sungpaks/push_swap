/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghoch <sunghoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:48:31 by sunghoch          #+#    #+#             */
/*   Updated: 2023/04/05 17:25:02 by sunghoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > 0 && ft_strchr(set, s1[end]))
		end--;
	if (end == 0)
		result = (char *)malloc(1);
	else
		result = (char *)malloc(end - start + 2);
	if (!result)
		return (0);
	i = 0;
	s1 += start;
	while (end > 0 && i < end - start + 1)
		result[i++] = *(s1++);
	result[i] = 0;
	return (result);
}
