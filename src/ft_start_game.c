/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:02:25 by nkarapet          #+#    #+#             */
/*   Updated: 2024/06/14 21:50:48 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	re_draw(t_info *vars)
{
	mlx_destroy_image(vars->mlx.ptr, vars->img.img);
	create_image(vars);
	raycasting(vars);
	return (0);
}

void	init_img_info(t_info *vars)
{
	vars->img.img = NULL;
	vars->cdoor.img = NULL;
	vars->odoor.img = NULL;
	get_wall__textures(vars);
	get_door(&vars->cdoor, vars, "./textures/CloseDoor.xpm");
	get_door(&vars->odoor, vars, "./textures/OpenDoor.xpm");
	create_image(vars);
	vars->fc = create_trgb(0, vars->f_color.r,
			vars->f_color.g, vars->f_color.b);
	vars->rc = create_trgb(0, vars->r_color.r,
			vars->r_color.g, vars->r_color.b);
}

void	game_start(t_info vars)
{
	vars.mlx.ptr = mlx_init();
	vars.mlx.win = mlx_new_window(vars.mlx.ptr, vars.map_wd,
			vars.map_ht, "GAME");
	if (!vars.mlx.win)
		ft_free_vars(&vars, 1, "Can't open window");
	init_img_info(&vars);
	raycasting(&vars);
	mlx_hook(vars.mlx.win, 2, 0, &key_press, &vars);
	mlx_hook(vars.mlx.win, 6, 0, &mouse_move, &vars);
	mlx_loop_hook(vars.mlx.ptr, &re_draw, &vars);
	mlx_hook(vars.mlx.win, 17, 0, &press, &vars);
	mlx_loop(vars.mlx.ptr);
}
