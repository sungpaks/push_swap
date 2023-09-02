/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghoch <sunghoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:58:37 by sunghoch          #+#    #+#             */
/*   Updated: 2023/04/01 21:28:00 by sunghoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_itoa(char *result, long long lln, int n, long long scale);

char	*ft_itoa(int n)
{
	long long	scale;
	long long	lln;
	int			size;
	char		*result;

	scale = 1;
	size = 0;
	lln = n;
	if (lln <= 0)
	{
		size++;
		lln = (long long)n * -1;
	}
	while (lln / scale > 0)
	{
		scale *= 10;
		size++;
	}
	scale /= 10;
	result = (char *)malloc(size + 1);
	if (!result)
		return (0);
	set_itoa(result, lln, n, scale);
	return (result);
}

static void	set_itoa(char *result, long long lln, int n, long long scale)
{
	int	i;

	i = 0;
	if (n == 0)
		result[i++] = '0';
	if (n < 0)
		result[i++] = '-';
	while (scale > 0)
	{
		result[i++] = (lln / scale) + 48;
		lln = lln % scale;
		scale /= 10;
	}
	result[i] = 0;
}
