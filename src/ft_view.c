/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:30:45 by nkarapet          #+#    #+#             */
/*   Updated: 2024/06/14 19:00:00 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	rotate_view(t_info *vars, double prevdir_x,
	double prevplane_x, double rotate)
{
	vars->user.dir_x = vars->user.dir_x * cos(rotate)
		- vars->user.dir_y * sin(rotate);
	vars->user.dir_y = prevdir_x * sin(rotate)
		+ vars->user.dir_y * cos(rotate);
	vars->user.plane_x = vars->user.plane_x * cos(rotate)
		- vars->user.plane_y * sin(rotate);
	vars->user.plane_y = prevplane_x * sin(rotate)
		+ vars->user.plane_y * cos(rotate);
}

void	change_view(t_info *vars, int side, double rotate)
{
	double	prevplane_x;
	double	prevdir_x;

	prevdir_x = vars->user.dir_x;
	prevplane_x = vars->user.plane_x;
	if (side == RARROW)
		rotate_view(vars, prevdir_x, prevplane_x, -rotate);
	else
		rotate_view(vars, prevdir_x, prevplane_x, rotate);
}

void	get_dir(t_info *vars)
{
	if (vars->user.dir_x <= 0 && vars->user.dir_y >= 0)
	{
		vars->user.dir_x = 1 - pow(vars->user.dir_x, 2);
		vars->user.dir_y = 1 - pow(vars->user.dir_y, 2);
	}
	else if (vars->user.dir_x >= 0 && vars->user.dir_y >= 0)
	{
		vars->user.dir_x = 1 - pow(vars->user.dir_x, 2);
		vars->user.dir_y = -(1 - pow(vars->user.dir_y, 2));
	}
	else if (vars->user.dir_x >= 0 && vars->user.dir_y <= 0)
	{
		vars->user.dir_x = -(1 - pow(vars->user.dir_x, 2));
		vars->user.dir_y = -(1 - pow(vars->user.dir_y, 2));
	}
	else
	{
		vars->user.dir_x = -(1 - pow(vars->user.dir_x, 2));
		vars->user.dir_y = 1 - pow(vars->user.dir_y, 2);
	}
}
