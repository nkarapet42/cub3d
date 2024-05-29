/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:03:05 by nkarapet          #+#    #+#             */
/*   Updated: 2024/05/20 17:59:51 by nkarapet         ###   ########.fr       */
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

void	got_player_pos(t_info *vars)
{
	int		j;
	t_map	*map;

	map = vars->map;
	while (map)
	{
		j = 0;
		while (map->row[j])
		{
			if (map->row[j] == 'N' || map->row[j] == 'S'
				|| map->row[j] == 'E' || map->row[j] == 'W')
			{
				vars->pos.x = j;
				vars->pos.y = map->index;
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
