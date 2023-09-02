/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghoch <sunghoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:13:30 by sunghoch          #+#    #+#             */
/*   Updated: 2023/08/19 20:03:30 by sunghoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_cases(const char param, va_list ap)
{
	if (param == 'c')
		return (ft_char_print(va_arg(ap, int)));
	else if (param == 's')
		return (ft_str_print(va_arg(ap, char *)));
	else if (param == 'p')
		return (ft_ptox((unsigned long long)va_arg(ap, void *)));
	else if (param == 'd')
		return (ft_itoa_print(va_arg(ap, int)));
	else if (param == 'i')
		return (ft_itoa_print(va_arg(ap, int)));
	else if (param == 'u')
		return (ft_itou(va_arg(ap, unsigned int)));
	else if (param == 'x')
		return (ft_itox(va_arg(ap, unsigned int), 0));
	else if (param == 'X')
		return (ft_itox(va_arg(ap, unsigned int), 1));
	else if (param == '%')
		return (write(1, "%", 1));
	else
		return (0);
}

int	ft_printf_loop(const char *format, va_list ap)
{
	int	i;
	int	len;
	int	tmp;

	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			tmp = ft_printf_cases(format[++i], ap);
			if (tmp == -1)
				return (-1);
			if (tmp >= 0)
				len += tmp;
		}
		else
		{
			if (write(1, &format[i], 1) == -1)
				return (-1);
			len++;
		}
		i++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = ft_printf_loop(format, ap);
	va_end(ap);
	return (len);
}
