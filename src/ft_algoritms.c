/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoritms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:41:04 by nkarapet          #+#    #+#             */
/*   Updated: 2024/06/14 21:10:33 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	dda_algorithm(t_info *vars)
{
	while (vars->ray.hit == 0)
	{
		if (vars->ray.sdist_x < vars->ray.sdist_y)
		{
			vars->ray.sdist_x += vars->ray.deltadist_x;
			vars->user.map_x += vars->user.step_x;
			vars->ray.side = 0;
		}
		else
		{
			vars->ray.sdist_y += vars->ray.deltadist_y;
			vars->user.map_y += vars->user.step_y;
			vars->ray.side = 1;
		}
		if (vars->maze[vars->user.map_x][vars->user.map_y] == '1')
			vars->ray.hit = 1;
		else if (vars->maze[vars->user.map_x][vars->user.map_y] == 'D')
			vars->ray.hit = 2;
		else if (vars->maze[vars->user.map_x][vars->user.map_y] == 'O')
			vars->ray.hit = 3;
	}
	if (vars->ray.side == 0)
		vars->ray.perp_wall_dist = (vars->ray.sdist_x - vars->ray.deltadist_x);
	else
		vars->ray.perp_wall_dist = (vars->ray.sdist_y - vars->ray.deltadist_y);
}

void	ray_pos(t_info *vars, int w)
{
	vars->ray.camera_x = 2.0 * w / (double)vars->map_wd - 1.0;
	vars->ray.ray_x = vars->user.dir_x
		+ vars->user.plane_x * vars->ray.camera_x;
	vars->ray.ray_y = vars->user.dir_y
		+ vars->user.plane_y * vars->ray.camera_x;
	vars->user.map_x = (int)vars->user.pos_x;
	vars->user.map_y = (int)vars->user.pos_y;
	if (vars->ray.ray_x == 0)
		vars->ray.deltadist_x = 1e30;
	else
		vars->ray.deltadist_x = fabs(1 / vars->ray.ray_x);
	if (vars->ray.ray_y == 0)
		vars->ray.deltadist_y = 1e30;
	else
		vars->ray.deltadist_y = fabs(1 / vars->ray.ray_y);
}

void	calc_draw_ends(t_info *vars, t_draw *tex)
{
	tex->line_height = (int)(vars->map_ht / vars->ray.perp_wall_dist);
	tex->draw_start = -tex->line_height / 2 + vars->map_ht / 2;
	if (tex->draw_start < 0)
		tex->draw_start = 0;
	tex->draw_end = tex->line_height / 2 + vars->map_ht / 2;
	if (tex->draw_end >= vars->map_ht)
		tex->draw_end = vars->map_ht - 1;
	tex->step = 1.0 * 64 / tex->line_height;
	tex->tex_pos = (tex->draw_start - vars->map_ht / 2 + tex->line_height / 2)
		* tex->step;
}

int	calc_texture_x(t_info *vars)
{
	int		tex_x;
	double	wall_x;

	wall_x = vars->user.pos_x + vars->ray.perp_wall_dist * vars->ray.ray_x;
	if (vars->ray.side == 0)
		wall_x = vars->user.pos_y + vars->ray.perp_wall_dist * vars->ray.ray_y;
	wall_x -= floor((wall_x));
	tex_x = (int)(wall_x * (double)(64));
	if ((vars->ray.side == 0 && vars->ray.ray_x > 0)
		|| (vars->ray.side == 1 && vars->ray.ray_y < 0))
		tex_x = 64 - tex_x - 1;
	return (tex_x);
}

void	step_dir(t_info *vars)
{
	if (vars->ray.ray_x < 0)
	{
		vars->user.step_x = -1;
		vars->ray.sdist_x = (vars->user.pos_x - vars->user.map_x)
			* vars->ray.deltadist_x;
	}
	else
	{
		vars->user.step_x = 1;
		vars->ray.sdist_x = (vars->user.map_x + 1.0 - vars->user.pos_x)
			* vars->ray.deltadist_x;
	}
	if (vars->ray.ray_y < 0)
	{
		vars->user.step_y = -1;
		vars->ray.sdist_y = (vars->user.pos_y - vars->user.map_y)
			* vars->ray.deltadist_y;
	}
	else
	{
		vars->user.step_y = 1;
		vars->ray.sdist_y = (vars->user.map_y + 1.0 - vars->user.pos_y)
			* vars->ray.deltadist_y;
	}
}
