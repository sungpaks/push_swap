/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghoch <sunghoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:14:36 by sunghoch          #+#    #+#             */
/*   Updated: 2023/08/19 20:03:23 by sunghoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(unsigned int n);
static void		set_itox(char *result, unsigned int n, size_t size, int is_up);

int	ft_itox(unsigned int n, int is_up)
{
	char		*result;
	size_t		size;
	int			len;

	size = get_size(n);
	result = (char *)malloc(size + 1);
	if (!result)
		return (-1);
	set_itox(result, n, size, is_up);
	len = write(1, result, ft_strlen(result));
	free (result);
	return (len);
}

static size_t	get_size(unsigned int n)
{
	size_t		size;

	size = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		size++;
	}
	return (size);
}

static void	set_itox(char *result, unsigned int n, size_t size, int is_up)
{
	if (n == 0)
		result[0] = '0';
	result[size--] = 0;
	while (n > 0)
	{
		if (n % 16 >= 10)
		{
			if (is_up == 1)
				result[size--] = 'A' + ((n % 16) - 10);
			else
				result[size--] = 'a' + ((n % 16) - 10);
		}
		else
			result[size--] = '0' + (n % 16);
		n /= 16;
	}
}
