/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation_second_part.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:13:16 by nkarapet          #+#    #+#             */
/*   Updated: 2024/05/17 17:14:17 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
