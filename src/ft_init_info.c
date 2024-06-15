/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:03:05 by nkarapet          #+#    #+#             */
/*   Updated: 2024/06/15 19:08:35 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	got_position(char *color)
{
	int	i;

	i = 0;
	while (check(color[i]))
		i++;
	while (ft_isdigit(color[i]))
		i++;
	while (check(color[i]))
		i++;
	return (i);
}

void	set_dir(t_info *vars, char c)
{
	vars->user.dir_x = 0;
	vars->user.dir_y = 0;
	vars->user.plane_x = 0;
	vars->user.plane_y = 0;
	if (c == 'N')
	{
		vars->user.dir_x = -1;
		vars->user.plane_y = 0.66;
	}
	else if (c == 'S')
	{
		vars->user.dir_x = 1;
		vars->user.plane_y = -0.66;
	}
	else if (c == 'E')
	{
		vars->user.dir_y = 1;
		vars->user.plane_x = 0.66;
	}
	else if (c == 'W')
	{
		vars->user.dir_y = -1;
		vars->user.plane_x = -0.66;
	}
}

void	got_player_pos(t_info *vars)
{
	int		j;
	t_map	*map;

	map = vars->map;
	while (map)
	{
		j = 0;
		while (map->r[j])
		{
			if (map->r[j] == 'N' || map->r[j] == 'S'
				|| map->r[j] == 'E' || map->r[j] == 'W')
			{
				vars->user.pos_y = j + 0.5;
				vars->user.pos_x = map->index + 0.5;
				set_dir(vars, map->r[j]);
				map->r[j] = '0';
				return ;
			}
			j++;
		}
		map = map->next;
	}
}

void	got_color_floor(t_info *vars, char *color)
{
	int	i;

	i = 0;
	if (ft_isdigit(color[i]) == 0)
		ft_free_vars(vars, 1, "Wrong color argument");
	vars->f_color.r = ft_atoi(color);
	i = got_position(color);
	if (color[i] != ',')
		ft_free_vars(vars, 1, "Something wrong with color");
	i++;
	vars->f_color.g = ft_atoi(color + i);
	i += got_position(color + i);
	if (color[i] != ',')
		ft_free_vars(vars, 1, "Something wrong with color");
	i++;
	vars->f_color.b = ft_atoi(color + i);
	i += got_position(color + i);
	if (color[i] != '\0')
		ft_free_vars(vars, 1, "Something wrong with color");
}

void	got_color_roof(t_info *vars, char *color)
{
	int	i;

	i = 0;
	if (ft_isdigit(color[i]) == 0)
		ft_free_vars(vars, 1, "Wrong color argument");
	vars->r_color.r = ft_atoi(color);
	while (ft_isdigit(color[i]) == 1 || check(color[i]) == 1)
		i++;
	if (color[i] != ',')
		ft_free_vars(vars, 1, "There is no comma's");
	i++;
	vars->r_color.g = ft_atoi(color + i);
	while (ft_isdigit(color[i]) == 1 || check(color[i]) == 1)
		i++;
	if (color[i] != ',')
		ft_free_vars(vars, 1, "There is no comma's");
	i++;
	vars->r_color.b = ft_atoi(color + i);
	while (ft_isdigit(color[i]) == 1 || check(color[i]) == 1)
		i++;
	if (color[i] != '\0')
		ft_free_vars(vars, 1, "Something wrong with color");
}
