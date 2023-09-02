/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghoch <sunghoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:39:03 by sunghoch          #+#    #+#             */
/*   Updated: 2023/08/23 16:52:17 by sunghoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	remove_space(char *str);

int	ft_atoi(char *str)
{
	long long	cnt_minus;
	long long	result;

	cnt_minus = 1;
	remove_space(str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			cnt_minus *= -1;
		str++;
	}
	result = 0;
	while ('0' <= *str && *str <= '9')
	{
		result *= 10;
		result += (long long)(*str - 48);
		str++;
	}
	result *= cnt_minus;
	if (result < -2147483648 || result > 2147483647)
		return (0);
	return ((int)result);
}

static void	remove_space(char *str)
{
	while (*str)
	{
		if (*str == '\t' || *str == '\n' || *str == '\v' \
				|| *str == '\f' || *str == '\r' || *str == ' ')
			str++;
		else
			break ;
	}
}
