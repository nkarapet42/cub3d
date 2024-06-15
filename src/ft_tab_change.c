/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_change.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:56:23 by nkarapet          #+#    #+#             */
/*   Updated: 2024/06/15 19:08:35 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_strtablen(char *s)
{
	int	i;
	int	len;

	if (!s)
		return (0);
	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\t')
			len += 4;
		else
			len++;
		i++;
	}
	return (len);
}

int	cpy_line(char *res, char c, int l)
{
	int	k;

	k = 0;
	if (c == '\t')
	{
		k = -1;
		while (++k < 4)
			res[l++] = ' ';
	}
	else
	{
		res[l] = c;
		l++;
	}
	return (l);
}

char	*replace_tab(char *line)
{
	char	*res;
	int		l;
	int		j;

	j = 0;
	l = 0;
	res = malloc(sizeof(char) * (ft_strtablen(line) + 1));
	if (!res)
		return (NULL);
	while (line[j])
	{
		l = cpy_line(res, line[j], l);
		j++;
	}
	res[l] = '\0';
	free(line);
	return (res);
}

void	change_tabs(t_map **stack, t_info *vars)
{
	t_map	*map;
	int		i;
	int		k;

	map = *stack;
	i = 0;
	k = 0;
	while (map)
	{
		map->r = replace_tab(map->r);
		map->len = ft_strlen(map->r);
		if (!map->r)
			ft_free_vars(vars, 1, "Malloc error");
		map = map->next;
		i++;
	}
}
