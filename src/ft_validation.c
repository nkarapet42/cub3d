/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:16:47 by nkarapet          #+#    #+#             */
/*   Updated: 2024/06/15 19:08:35 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	check_updown_walls(t_info vars)
{
	int		j;
	t_map	*map;

	map = vars.map;
	j = 0;
	while ((map->r[j] == '1' || check(map->r[j]) == 1)
		&& map->r[j])
		j++;
	if (map->r[j] != '\0')
		ft_free_vars(&vars, 1, "Wrong map");
	while (map->next)
		map = map->next;
	j = 0;
	while ((map->r[j] == '1' || check(map->r[j]) == 1)
		&& map->r[j])
		j++;
	if (map->r[j] != '\0')
		ft_free_vars(&vars, 1, "Wrong map");
}

void	check_side_walls(t_info vars)
{
	int		j;
	t_map	*map;

	map = vars.map;
	while (map)
	{
		j = 0;
		while (check(map->r[j]) == 1)
			j++;
		if (map->r[j] != '1')
			ft_free_vars(&vars, 1, "Wrong map");
		map = map->next;
	}
	map = vars.map;
	while (map)
	{
		j = map->len - 1;
		while (check(map->r[j]) == 1)
			j--;
		if (map->r[j] != '1')
			ft_free_vars(&vars, 1, "Wrong map");
		map = map->next;
	}
}

void	check_position(t_info vars)
{
	int		count;
	int		j;
	t_map	*map;

	count = 0;
	map = vars.map;
	while (map)
	{
		j = 0;
		while (map->r[j])
		{
			if (map->r[j] == 'N' || map->r[j] == 'S'
				|| map->r[j] == 'E' || map->r[j] == 'W')
				count++;
			j++;
		}
		map = map->next;
	}
	if (count != 1)
		ft_free_vars(&vars, 1, "Something wrong with player");
}

void	check_objects(t_info vars)
{
	int		j;
	t_map	*map;

	map = vars.map;
	while (map)
	{
		j = 0;
		while (map->r[j])
		{
			if (map->r[j] != '0' && map->r[j] != '1' && map->r[j] != 'N'
				&& map->r[j] != 'S' && map->r[j] != 'E'
				&& map->r[j] != 'W' && map->r[j] != 'D'
				&& check(map->r[j]) != 1)
				ft_free_vars(&vars, 1, "Undefined object");
			j++;
		}
		map = map->next;
	}
}

void	map_validation(t_info vars)
{
	check_updown_walls(vars);
	check_side_walls(vars);
	check_objects(vars);
	check_position(vars);
	check_maze(vars, 1);
	check_door(vars);
	check_color(vars);
	got_player_pos(&vars);
	get_maze(&vars);
	game_start(vars);
}
