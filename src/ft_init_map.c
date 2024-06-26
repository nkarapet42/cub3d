/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:34:11 by nkarapet          #+#    #+#             */
/*   Updated: 2024/06/25 14:37:25 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	path_init(t_info *vars, char	**s, int i, int j)
{
	if (s[i][j] == 'N' && s[i][j + 1] == 'O' && check(s[i][j + 2]) == 1
		&& !vars->npath)
		vars->npath = path_cut(&s[i], "NO", s, 1);
	else if (s[i][j] == 'S' && s[i][j + 1] == 'O' && check(s[i][j + 2]) == 1
		&& !vars->spath)
		vars->spath = path_cut(&s[i], "SO", s, 1);
	else if (s[i][j] == 'E' && s[i][j + 1] == 'A' && check(s[i][j + 2]) == 1
		&& !vars->epath)
		vars->epath = path_cut(&s[i], "EA", s, 1);
	else if (s[i][j] == 'W' && s[i][j + 1] == 'E' && check(s[i][j + 2]) == 1
		&& !vars->wpath)
		vars->wpath = path_cut(&s[i], "WE", s, 1);
	else if (s[i][j] == 'F' && check(s[i][j + 1]) == 1 && !vars->fcolor)
		vars->fcolor = path_cut(&s[i], "F", s, 0);
	else if (s[i][j] == 'C' && check(s[i][j + 1]) == 1 && !vars->rcolor)
		vars->rcolor = path_cut(&s[i], "C", s, 0);
	else
		free_and_error(s, 1, "Something went wrong with path");
}

void	init_pathcolor(t_info *vars, char **s)
{
	int	i;
	int	j;

	i = 0;
	init_vars(&vars);
	while (s[i])
	{
		if (i == 6)
			break ;
		j = 0;
		while (check(s[i][j]) == 1)
			j++;
		path_init(vars, s, i, j);
		i++;
	}
	if (i != 6)
		free_and_error(s, 1, "Something went wrong with path");
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
	vars->map->r = NULL;
	if (mapi[6])
		ft_addstack(&vars->map, mapi);
	else
	{
		free(mapi);
		ft_free_vars(vars, 1, "There isn't map");
	}
}

void	init_map_info(char **map)
{
	t_info	vars;
	int		count;

	vars.maze = NULL;
	vars.wall = NULL;
	vars.map = NULL;
	init_pathcolor(&vars, map);
	init_map(&vars, map);
	free(map);
	got_color_floor(&vars, vars.fcolor);
	got_color_roof(&vars, vars.rcolor);
	change_tabs(&vars.map, &vars);
	count = 1;
	while (vars.map->next)
	{
		count++;
		vars.map = vars.map->next;
	}
	vars.maze = malloc(sizeof(char *) * (count + 1));
	if (!vars.maze)
		ft_free_vars(&vars, 1, "Malloc error");
	while (vars.map->prev)
		vars.map = vars.map->prev;
	map_validation(vars);
}
