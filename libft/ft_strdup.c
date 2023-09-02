/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghoch <sunghoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:25:10 by sunghoch          #+#    #+#             */
/*   Updated: 2023/03/26 15:41:49 by sunghoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcpy(char *result, char *src);

char	*ft_strdup(char *src)
{
	int		l;
	char	*result;

	l = ft_strlen(src);
	result = (char *) malloc (l + 1);
	if (result == 0)
		return (0);
	ft_strcpy(result, src);
	return (result);
}

static void	ft_strcpy(char *result, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		result[i] = src[i];
		i++;
	}
	result[i] = 0;
}
