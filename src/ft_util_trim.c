/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_trim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:17:07 by nkarapet          #+#    #+#             */
/*   Updated: 2024/05/18 14:05:26 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_check_set(char const *set, char const str)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == str)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_startlen(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && ft_check_set(set, s1[i]))
		i++;
	while (s1[i] != '\n' && i > 0)
		i--;
	return (i);
}

int	ft_size(int start, int end)
{
	int	size;

	size = 0;
	size = end - start;
	return (size);
}

char	*ft_strtrim_all(char *s1, char *set)
{
	char	*res;
	int		i;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = ft_startlen(s1, set);
	end = ft_strlen((char *)s1);
	while (end > start && ft_check_set(set, s1[end - 1]))
		end--;
	res = (char *)malloc(sizeof(char) * (ft_size(start, end) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < ft_size(start, end))
	{
		res[i] = s1[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
