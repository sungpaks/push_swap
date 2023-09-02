/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_etc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghoch <sunghoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 22:34:17 by sunghoch          #+#    #+#             */
/*   Updated: 2023/08/19 20:03:24 by sunghoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_itoa_print(int n)
{
	char	*converted;
	int		len;

	converted = ft_itoa(n);
	if (!converted)
		return (-1);
	len = write(1, converted, ft_strlen(converted));
	free (converted);
	return (len);
}

int	ft_str_print(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	ft_char_print(int c)
{
	return (write(1, &c, 1));
}
