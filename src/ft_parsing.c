/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:24:15 by nkarapet          #+#    #+#             */
/*   Updated: 2024/06/13 22:41:00 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/get_next_line.h"

int	check(char s)
{
	if (s == ' ' || s == '\t' || s == '\r'
		|| s == '\n' || s == '\v' || s == '\f')
		return (1);
	return (0);
}

void	ft_cpy(char **info, char **res, int i, int k)
{
	int	j;

	info[k] = malloc((ft_strlen(res[i]) + 1) * sizeof(char));
	if (!info[k])
	{
		free_and_error(info, 0, "");
		free_and_error(res, 1, "Malloc error\n");
	}
	j = 0;
	while (res[i][j])
	{
		info[k][j] = res[i][j];
		j++;
	}
	info[k][j] = '\0';
}

void	ft_allocate(char **info, char **res)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (res[i])
	{
		if (res[i][0] == '\0' && k > 6)
		{
			free_and_error(info, 0, "");
			free_and_error(res, 1, "New line in map");
		}
		if (res[i][0] == '\0')
			i++;
		else
		{
			ft_cpy(info, res, i, k);
			k++;
			i++;
		}
	}
	info[k] = NULL;
}

char	**ft_spliting(char **res)
{
	int		i;
	int		count;
	char	**info;

	i = 0;
	count = 0;
	while (res[i])
	{
		if (res[i][0] == '\0')
			i++;
		else
		{
			count++;
			i++;
		}
	}
	info = ft_calloc(count + 1, sizeof(char *));
	if (!info)
		exit (1 && printf("Malloc error\n"));
	ft_allocate(info, res);
	free_and_error(res, 0, "");
	return (info);
}

void	start_parsing(int fd)
{
	char	**res;
	char	*temp;
	char	*join;
	char	*tmp1;

	join = ft_strdup("");
	if (!join)
		exit (1 && printf("Malloc error\n"));
	temp = get_next_line(fd);
	while (temp)
	{
		tmp1 = join;
		join = ft_strjoin(join, temp);
		free(tmp1);
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
	res = ft_split(join, "\n");
	free (join);
	if (!res[0])
		exit (1 && printf("Empty map\n"));
	check_whitespaces(res);
	res = ft_spliting(res);
	init_map_info(res);
}
