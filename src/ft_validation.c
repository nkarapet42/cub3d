/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:16:47 by nkarapet          #+#    #+#             */
/*   Updated: 2024/06/13 17:10:26 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	check_updown_walls(t_info vars)
{
	int		j;
	t_map	*map;

	map = vars.map;
	j = 0;
	while ((map->row[j] == '1' || check(map->row[j]) == 1)
		&& map->row[j])
		j++;
	if (map->row[j] != '\0')
		ft_free_vars(&vars, 1, "Wrong map");
	while (map->next)
		map = map->next;
	j = 0;
	while ((map->row[j] == '1' || check(map->row[j]) == 1)
		&& map->row[j])
		j++;
	if (map->row[j] != '\0')
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
		while (check(map->row[j]) == 1)
			j++;
		if (map->row[j] != '1')
			ft_free_vars(&vars, 1, "Wrong map");
		map = map->next;
	}
	map = vars.map;
	while (map)
	{
		j = map->len - 1;
		while (check(map->row[j]) == 1)
			j--;
		if (map->row[j] != '1')
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
		while (map->row[j])
		{
			if (map->row[j] == 'N' || map->row[j] == 'S'
				|| map->row[j] == 'E' || map->row[j] == 'W')
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
		while (map->row[j])
		{
			if (map->row[j] != '0' && map->row[j] != '1' && map->row[j] != 'N'
				&& map->row[j] != 'S' && map->row[j] != 'E'
				&& map->row[j] != 'W' && map->row[j] != 'D'
				&& check(map->row[j]) != 1)
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
	check_maze(vars);
	check_door(vars);
	check_color(vars);
	got_player_pos(&vars);
	get_maze(&vars);
	game_start(vars);
}
