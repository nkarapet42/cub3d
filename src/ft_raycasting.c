/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:57:58 by nkarapet          #+#    #+#             */
/*   Updated: 2024/06/25 15:09:29 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_floor(t_info *vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i < vars->map_ht / 2)
	{
		j = -1;
		while (++j < vars->map_wd)
			my_mlx_pixel_put(&vars->img, j, i, vars->rc);
	}
	while (++i < vars->map_ht - 1)
	{
		j = -1;
		while (++j < vars->map_wd)
			my_mlx_pixel_put(&vars->img, j, i, vars->fc);
	}
}

void	raycasting(t_info *vars)
{
	int		w;

	draw_floor(vars);
	w = -1;
	anim(vars);
	while (++w <= vars->map_wd)
	{
		ray_pos(vars, w);
		step_dir(vars);
		vars->ray.hit = 0;
		dda_algorithm(vars);
		draw_texture(vars, w, calc_texture_x(vars));
	}
	anim(vars);
	if (vars->hide_map == 1)
		draw_minimap(vars);
	mlx_put_image_to_window(vars->mlx.ptr, vars->mlx.win, vars->img.img, 0, 0);
}
