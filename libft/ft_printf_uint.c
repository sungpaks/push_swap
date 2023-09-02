/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghoch <sunghoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:12:12 by sunghoch          #+#    #+#             */
/*   Updated: 2023/08/19 20:03:37 by sunghoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_itou(char *result, unsigned int n, long long scale);

int	ft_itou(unsigned int n)
{
	long long	scale;
	int			size;
	char		*result;
	int			len;

	scale = 1;
	size = 1;
	while (n / scale > 0)
	{
		scale *= 10;
		size++;
	}
	scale /= 10;
	result = (char *)malloc(size + 1);
	if (!result)
		return (-1);
	set_itou(result, n, scale);
	len = write(1, result, ft_strlen(result));
	free(result);
	return (len);
}

static void	set_itou(char *result, unsigned int n, long long scale)
{
	int	i;

	i = 0;
	if (n == 0)
		result[i++] = '0';
	while (scale > 0)
	{
		result[i++] = (n / scale) + 48;
		n = n % scale;
		scale /= 10;
	}
	result[i] = 0;
}
