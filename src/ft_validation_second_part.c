/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation_second_part.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:13:16 by nkarapet          #+#    #+#             */
/*   Updated: 2024/05/18 15:24:25 by nkarapet         ###   ########.fr       */
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
		while (map->row[j + 1])
		{
			if (map->row[j] == 'D'
				&& !(map->row[j - 1] == '1' && map->row[j + 1] == '1')
				&& !(map->prev->row[j] == '1' && map->next->row[j] == '1'))
				ft_free_vars(&vars, 1, "Door in wrong place");
			j++;
		}
		map = map->next;
	}
}

void	check_maze(t_info vars)
{
	int		j;
	t_map	*map;

	map = vars.map;
	map = map->next;
	while (map->next)
	{
		j = 1;
		while (map->row[j + 1])
		{
			if ((j > map->next->len || j > map->prev->len)
				&& map->row[j] != '1' && check(map->row[j]) == 0)
				ft_free_vars(&vars, 1, "Wrong map");
			if (check(map->row[j]) == 1 || map->row[j] == '1')
				j++;
			else if (map->row[j] != '1' && check(map->row[j - 1]) == 0
				&& check(map->row[j + 1]) == 0 && check(map->next->row[j]) == 0
				&& check(map->prev->row[j]) == 0)
				j++;
			else
				ft_free_vars(&vars, 1, "Wrong map");
		}
		map = map->next;
	}
}
