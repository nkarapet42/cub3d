/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_trim_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:24:06 by nkarapet          #+#    #+#             */
/*   Updated: 2024/05/17 21:16:49 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	check_whitespaces(char **res)
{
	char	*temp;
	int		i;

	temp = NULL;
	i = 0;
	while (res[i])
	{
		temp = res[i];
		res[i] = ft_strtrim(res[i], " \t\n\v\f\r");
		free(temp);
		i++;
	}
	i--;
	if (res[i][0] == '\0')
	{
		while (i >= 0 && res[i][0] == '\0')
		{
			free(res[i]);
			res[i] = NULL;
			i--;
		}
		if (i == -1)
			free_and_error(res, 1, "Empty map");
	}
}

size_t	ft_check(char *set, char str)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == str)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	char	*res;
	size_t	i;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	while (end > 0 && ft_check(set, s1[end - 1]))
		end--;
	res = (char *)malloc(sizeof(char) * (end + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < end)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
