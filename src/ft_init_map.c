/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:34:11 by nkarapet          #+#    #+#             */
/*   Updated: 2024/05/17 17:13:32 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	path_check(t_info *vars, char	**s, int i, int j)
{
	init_vars(&vars);
	if (s[i][j] == 'N' && s[i][j + 1] == 'O' && check(s[i][j + 2]) == 1)
		vars->npath = s[i];
	else if (s[i][j] == 'S' && s[i][j + 1] == 'O'
		&& check(s[i][j + 2]) == 1)
		vars->spath = s[i];
	else if (s[i][j] == 'E' && s[i][j + 1] == 'A'
		&& check(s[i][j + 2]) == 1)
		vars->epath = s[i];
	else if (s[i][j] == 'W' && s[i][j + 1] == 'E'
		&& check(s[i][j + 2]) == 1)
		vars->wpath = s[i];
	else if (s[i][j] == 'F' && check(s[i][j + 1]) == 1)
		vars->fcolor = s[i];
	else if (s[i][j] == 'C' && check(s[i][j + 1]) == 1)
		vars->rcolor = s[i];
	else
	{
		ft_free_vars(vars, 0, "");
		free_and_error(s, 1, "Something went wrong with path");
	}
}

void	init_pathcolor(t_info *vars, char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		if (i == 6)
			break ;
		j = 0;
		while (check(s[i][j]) == 1)
			j++;
		path_check(vars, s, i, j);
		i++;
	}
}

void	init_vars(t_info **vars)
{
	(*vars)->epath = NULL;
	(*vars)->npath = NULL;
	(*vars)->wpath = NULL;
	(*vars)->spath = NULL;
	(*vars)->fcolor = NULL;
	(*vars)->rcolor = NULL;
}

void	init_map(t_info *vars, char **mapi)
{
	vars->map = malloc(sizeof(t_map));
	if (!vars->map)
		free_and_error(mapi, 1, "There isn't map");
	vars->map->next = NULL;
	vars->map->prev = NULL;
	if (mapi[6])
		ft_addstack(&vars->map, mapi);
	else
	{
		ft_free_vars(vars, 0, "");
		free_and_error(mapi, 1, "There isn't map");
	}
}

void	init_map_info(char **map)
{
	t_info	vars;

	init_pathcolor(&vars, map);
	init_map(&vars, map);
	free(map);
	map_validation(vars);
}
