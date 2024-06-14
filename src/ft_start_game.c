/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:02:25 by nkarapet          #+#    #+#             */
/*   Updated: 2024/06/14 23:33:42 by nkarapet         ###   ########.fr       */
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

void	set_gun_textures(t_info *vars)
{
	vars->gun = malloc(sizeof(t_img) * 5);
	if (!vars->gun)
		ft_free_vars(vars, 1, "Malloc error");
	vars->gun[0].img = mlx_xpm_file_to_image(vars->mlx.ptr,
			"./textures/00_frame.xpm", &vars->gun[0].wd,
			&vars->gun[0].ht);
	vars->gun[1].img = mlx_xpm_file_to_image(vars->mlx.ptr,
			"./textures/01_frame.xpm", &vars->gun[1].wd,
			&vars->gun[1].ht);
	vars->gun[2].img = mlx_xpm_file_to_image(vars->mlx.ptr,
			"./textures/02_frame.xpm", &vars->gun[2].wd,
			&vars->gun[2].ht);
	vars->gun[3].img = mlx_xpm_file_to_image(vars->mlx.ptr,
			"./textures/03_frame.xpm", &vars->gun[3].wd,
			&vars->gun[3].ht);
	vars->gun[4].img = mlx_xpm_file_to_image(vars->mlx.ptr,
			"./textures/04_frame.xpm", &vars->gun[4].wd,
			&vars->gun[4].ht);
}

void	get_gun_textures(t_info *vars)
{
	int	i;

	set_gun_textures(vars);
	if (!vars->gun[0].img || !vars->gun[1].img
		|| !vars->gun[2].img || !vars->gun[3].img
		|| !vars->gun[4].img)
		ft_free_vars(vars, 1, "Bad Images");
	i = -1;
	while (++i < 5)
	{
		vars->gun[i].addr = mlx_get_data_addr(vars->gun[i].img,
				&vars->gun[i].bits_per_pixel, &vars->gun[i].line_length,
				&vars->gun[i].endian);
		if (!vars->gun[i].addr)
			ft_free_vars(vars, 1, "ADDR error");
	}
}

void	init_img_info(t_info *vars)
{
	vars->wall = NULL;
	vars->gun = NULL;
	vars->img.img = NULL;
	vars->cdoor.img = NULL;
	vars->odoor.img = NULL;
	get_wall__textures(vars);
	get_gun_textures(vars);
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
