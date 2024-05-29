/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:02:25 by nkarapet          #+#    #+#             */
/*   Updated: 2024/05/23 19:06:16 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	key_press(int key, t_info *vars)
{
	if (key == ESC)
		ft_free_vars(vars, 2, "");
	return (0);
}

void	game_start(t_info vars)
{
	int	i;

	i = 0;
	vars.ray.wd = 1000;
	vars.ray.ht = 720;
	while (vars.map->next)
	{
		vars.maze[i] = vars.map->row;
		i++;
		vars.map = vars.map->next;
	}
	vars.maze[i++] = vars.map->row;
	vars.maze[i] = NULL;
	while(vars.map->prev)
		vars.map = vars.map->prev;
	vars.xpm.mlx = mlx_init();
	vars.xpm.win = mlx_new_window(vars.xpm.mlx, vars.ray.wd,
			vars.ray.ht, "GAME");
	mlx_hook(vars.xpm.win, 2, 0, &key_press, &vars);
	//raycasting(&vars);
	mlx_hook(vars.xpm.win, 17, 0, &press, &vars);
	mlx_loop(vars.xpm.mlx);
}
