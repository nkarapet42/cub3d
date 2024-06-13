/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:02:25 by nkarapet          #+#    #+#             */
/*   Updated: 2024/06/13 22:41:10 by nkarapet         ###   ########.fr       */
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

void	create_image(t_info *vars)
{
	vars->img.img = mlx_new_image(vars->mlx.ptr,
			vars->map_wd, vars->map_ht);
	if (!vars->img.img)
		ft_free_vars(vars, 1, "Can't create image");
	vars->img.addr = mlx_get_data_addr(vars->img.img,
			&vars->img.bits_per_pixel, &vars->img.line_length,
			&vars->img.endian);
	if (!vars->img.addr)
		ft_free_vars(vars, 1, "ADDR error");
	vars->img.wd = vars->map_wd;
	vars->img.ht = vars->map_ht;
}

void	set_wall_textures(t_info *vars)
{
	vars->wall = malloc(sizeof(t_img) * 4);
	if (!vars->wall)
		ft_free_vars(vars, 1, "Malloc error");
	vars->wall[0].img = mlx_xpm_file_to_image(vars->mlx.ptr,
			vars->wpath, &vars->wall[0].wd, &vars->wall[0].ht);
	vars->wall[1].img = mlx_xpm_file_to_image(vars->mlx.ptr,
			vars->spath, &vars->wall[1].wd, &vars->wall[1].ht);
	vars->wall[2].img = mlx_xpm_file_to_image(vars->mlx.ptr,
			vars->npath, &vars->wall[2].wd, &vars->wall[2].ht);
	vars->wall[3].img = mlx_xpm_file_to_image(vars->mlx.ptr,
			vars->epath, &vars->wall[3].wd, &vars->wall[3].ht);
}

void	get_wall_textures(t_info *vars)
{
	int	i;

	set_wall_textures(vars);
	if (!vars->wall[0].img || !vars->wall[1].img
		|| !vars->wall[2].img || !vars->wall[3].img
		|| vars->wall[0].wd != vars->wall[1].wd
		|| vars->wall[0].ht != vars->wall[1].ht
		|| vars->wall[0].wd != vars->wall[2].wd
		|| vars->wall[0].ht != vars->wall[2].ht
		|| vars->wall[0].wd != vars->wall[3].wd
		|| vars->wall[0].ht != vars->wall[3].ht)
		ft_free_vars(vars, 1, "Bad Images");
	i = -1;
	while (++i < 4)
	{
		vars->wall[i].addr = mlx_get_data_addr(vars->wall[i].img,
				&vars->wall[i].bits_per_pixel, &vars->wall[i].line_length,
				&vars->wall[i].endian);
		if (!vars->wall[i].addr)
			ft_free_vars(vars, 1, "ADDR error");
	}
}

void	game_start(t_info vars)
{
	vars.mlx.ptr = mlx_init();
	vars.mlx.win = mlx_new_window(vars.mlx.ptr, vars.map_wd,
			vars.map_ht, "GAME");
	if (!vars.mlx.win)
		ft_free_vars(&vars, 1, "Can't open window");
	vars.img.img = NULL;
	get_wall_textures(&vars);
	create_image(&vars);
	vars.fc = create_trgb(0, vars.f_color.r, vars.f_color.g, vars.f_color.b);
	vars.rc = create_trgb(0, vars.r_color.r, vars.r_color.g, vars.r_color.b);
	raycasting(&vars);
	mlx_hook(vars.mlx.win, 2, 0, &key_press, &vars);
	mlx_loop_hook(vars.mlx.ptr, &re_draw, &vars);
	mlx_hook(vars.mlx.win, 17, 0, &press, &vars);
	mlx_loop(vars.mlx.ptr);
}
