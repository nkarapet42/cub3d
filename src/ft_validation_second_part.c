/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation_second_part.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:13:16 by nkarapet          #+#    #+#             */
/*   Updated: 2024/06/15 19:09:35 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/get_next_line.h"

char	*path_cut(char **path, char *s, char **info, int flag)
{
	int		j;
	char	*tmp;

	j = 0;
	while (ft_ischar(path[0][j], " \t\n\v\f\r") == 1)
		j++;
	if (ft_ischar(path[0][j], &s[0]) == 1)
		j++;
	if (s[1] != '\0' && ft_ischar(path[0][j], &s[1]) == 1)
		j++;
	while (ft_ischar(path[0][j], " \t\n\v\f\r") == 1)
		j++;
	tmp = *path;
	*path = ft_strdup(*path + j);
	free(tmp);
	j = ft_strlen(*path) - 1;
	if (flag == 1)
	{
		if (j < 3 || !(path[0][j] == 'm' && path[0][j - 1] == 'p'
			&& path[0][j - 2] == 'x' && path[0][j - 3] == '.'))
			free_and_error(info, 1, "Invalid texture name (.xpm at the end)");
	}
	return (*path);
}

void	get_maze(t_info *vars)
{
	int	i;

	i = 0;
	vars->map_wd = 1000;
	vars->map_ht = 720;
	while (vars->map->next)
	{
		vars->maze[i] = vars->map->r;
		i++;
		vars->map = vars->map->next;
	}
	vars->maze[i++] = vars->map->r;
	vars->maze[i] = NULL;
	while (vars->map->prev)
		vars->map = vars->map->prev;
}

void	check_color(t_info vars)
{
	if (vars.f_color.r == 4242 || vars.f_color.g == 4242
		|| vars.f_color.b == 4242 || vars.r_color.r == 4242
		|| vars.r_color.g == 4242 || vars.r_color.b == 4242)
		ft_free_vars(&vars, 1, "The number isn't in range [0,255]");
}

void	check_door(t_info vars)
{
	int		j;
	t_map	*map;

	map = vars.map;
	map = map->next;
	while (map->next)
	{
		j = 1;
		if (j < map->len - 1)
		{
			while (map->r[j + 1])
			{
				if (map->r[j] == 'D'
					&& !(map->r[j - 1] == '1' && map->r[j + 1] == '1')
					&& !(map->prev->r[j] == '1' && map->next->r[j] == '1'))
					ft_free_vars(&vars, 1, "Door in wrong place");
				j++;
			}
		}
		map = map->next;
	}
}

void	check_maze(t_info vars, int j)
{
	t_map	*map;

	map = vars.map->next;
	while (map->next)
	{
		j = 1;
		if (j < map->len - 1)
		{
			while (map->r[j + 1])
			{
				if ((j > map->next->len - 1 || j > map->prev->len - 1)
					&& map->r[j] != '1' && check(map->r[j]) == 0)
					ft_free_vars(&vars, 1, "Wrong map");
				if (check(map->r[j]) == 1 || map->r[j] == '1')
					j++;
				else if (map->r[j] != '1' && check(map->r[j - 1]) == 0
					&& check(map->r[j + 1]) == 0 && check(map->next->r[j]) == 0
					&& check(map->prev->r[j]) == 0)
					j++;
				else
					ft_free_vars(&vars, 1, "Wrong map");
			}
		}
		map = map->next;
	}
}
