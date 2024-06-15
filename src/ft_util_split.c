/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:09:38 by nkarapet          #+#    #+#             */
/*   Updated: 2024/06/15 19:17:21 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_res(char **res, int i)
{
	while (i >= 0)
	{
		free(res[i]);
		i--;
	}
	free(res);
	res = NULL;
	exit(1 && printf("Malloc error\n"));
}

int	ft_ischar(char const s, char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (s == c[i])
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_wordcount(char const *s, char *c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (ft_ischar(s[i], c) == 1
			|| (ft_ischar(s[i], c) == 0 && s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	*ft_getword(char const **s, char *c)
{
	size_t	i;
	size_t	j;
	size_t	start;
	char	*word;

	i = 0;
	while (ft_ischar((*s)[i], c) != 1 && (*s)[i])
		i++;
	word = malloc((i + 2) * sizeof(char));
	if (!word)
		return (NULL);
	start = i + 1;
	j = 0;
	while (j < i)
	{
		word[j] = (*s)[j];
		j++;
	}
	word[j] = '\n';
	word[j + 1] = '\0';
	*s = *s + start;
	return (word);
}

char	**ft_split(char const *s, char *c)
{
	size_t	i;
	size_t	len;
	char	**res;

	if (!s)
		return (NULL);
	len = ft_wordcount(s, c);
	res = (char **)malloc(sizeof(char *) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = ft_getword(&s, c);
		if (!res[i])
			free_res(res, i);
		i++;
	}
	res[i] = NULL;
	return (res);
}
