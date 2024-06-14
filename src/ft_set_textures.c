/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:26:59 by nkarapet          #+#    #+#             */
/*   Updated: 2024/06/14 21:21:51 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	open_close_door(t_info *vars)
{
	int	x;
	int	y;

	x = (int)vars->user.pos_x;
	y = (int)vars->user.pos_y;
	if (vars->user.dir_x < -0.05)
		x = (int)vars->user.pos_x - 1;
	else if (vars->user.dir_x > 0.05)
		x = (int)vars->user.pos_x + 1;
	if (vars->user.dir_y < -0.05)
		y = (int)vars->user.pos_y - 1;
	else if (vars->user.dir_y > 0.05)
		y = (int)vars->user.pos_y + 1;
	if (vars->maze[x][y] == 'D')
		vars->maze[x][y] = 'O';
	else if (vars->maze[x][y] == 'O')
		vars->maze[x][y] = 'D';
}

void	get_door(t_img *door, t_info *vars, char *path)
{
	door->img = mlx_xpm_file_to_image(vars->mlx.ptr,
			path, &door->wd, &door->ht);
	if (!door->img)
		ft_free_vars(vars, 1, "Bad Images");
	door->addr = mlx_get_data_addr(door->img,
			&door->bits_per_pixel, &door->line_length,
			&door->endian);
	if (!door->addr)
		ft_free_vars(vars, 1, "ADDR error");
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

void	get_wall__textures(t_info *vars)
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
