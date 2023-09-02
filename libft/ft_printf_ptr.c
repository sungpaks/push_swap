/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghoch <sunghoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:00:35 by sunghoch          #+#    #+#             */
/*   Updated: 2023/08/19 20:03:33 by sunghoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(unsigned long long n);
static void		set_ptox(char *result, unsigned long long n, size_t size);

int	ft_ptox(unsigned long long n)
{
	char		*result;
	size_t		size;
	int			len;

	size = get_size(n);
	result = (char *)malloc(size + 1);
	if (!result)
		return (-1);
	result[0] = '0';
	result[1] = 'x';
	set_ptox(result, n, size);
	len = write(1, result, ft_strlen(result));
	free (result);
	return (len);
}

static size_t	get_size(unsigned long long n)
{
	size_t		size;

	size = 2;
	if (n == 0)
		return (size + 1);
	while (n > 0)
	{
		n /= 16;
		size++;
	}
	return (size);
}

static void	set_ptox(char *result, unsigned long long n, size_t size)
{
	if (n == 0)
		result[2] = '0';
	result[size--] = 0;
	while (n > 0)
	{
		if (n % 16 >= 10)
			result[size--] = 'a' + ((n % 16) - 10);
		else
			result[size--] = '0' + (n % 16);
		n /= 16;
	}
}
