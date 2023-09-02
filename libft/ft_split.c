/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghoch <sunghoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 21:11:16 by sunghoch          #+#    #+#             */
/*   Updated: 2023/04/06 17:59:05 by sunghoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_strndup(char const *s, int size);
static int	ft_cnt_split(char const *s, char c);
static int	get_size(char const *s, char c);
static int	failed_to_alloc(char **result, int index);

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		size;
	int		cnt;

	cnt = ft_cnt_split(s, c);
	result = (char **) malloc ((cnt + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < cnt)
	{
		while (*s == c)
			++s;
		size = get_size(s, c);
		result[i] = ft_strndup((char *)s, size);
		if (!result[i])
			cnt = failed_to_alloc(result, i);
		i++;
		s += size;
	}
	if (cnt == -1)
		return (0);
	result[i] = 0;
	return (result);
}

static int	get_size(char const *s, char c)
{
	int	size;

	size = 0;
	while (s[size] && s[size] != c)
		size++;
	return (size);
}

static char	*ft_strndup(char const *s, int size)
{
	int		i;
	char	*result;

	result = (char *) malloc (size + 1);
	if (!result)
		return (0);
	i = 0;
	while (s[i] && i < size)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

static int	ft_cnt_split(char const *s, char c)
{
	int	cnt;
	int	flag;

	cnt = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!flag)
				cnt++;
			flag = 1;
		}
		else
			flag = 0;
		s++;
	}
	return (cnt);
}

static int	failed_to_alloc(char **result, int index)
{
	int	i;

	i = 0;
	while (i <= index)
		free(result[i++]);
	free(result);
	return (-1);
}
