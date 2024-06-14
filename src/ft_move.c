/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:15:03 by nkarapet          #+#    #+#             */
/*   Updated: 2024/06/14 21:21:39 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	key_press(int key, t_info *vars)
{
	if (key == ESC)
		ft_free_vars(vars, 2, "");
	else if (key == LARROW)
		change_view(vars, LARROW, AROTATE);
	else if (key == RARROW)
		change_view(vars, RARROW, AROTATE);
	else if (key == E)
		open_close_door(vars);
	else if (key == W)
		move_w(vars, WSPEED);
	else if (key == S)
		move_s(vars, SSPEED);
	else if (key == A || key == D)
		move_right_left(vars, key, ADSPEED);
	return (0);
}

void	move_right_left(t_info *vars, int key, double move)
{
	double	prev_x;
	double	prev_y;

	prev_x = vars->user.dir_x;
	prev_y = vars->user.dir_y;
	get_dir(vars);
	if (key == D)
		move_w(vars, move);
	else if (key == A)
		move_s(vars, move);
	vars->user.dir_x = prev_x;
	vars->user.dir_y = prev_y;
}

void	move_s(t_info *vars, double move)
{
	if (vars->maze[(int)(vars->user.pos_x - vars->user.dir_x * move)]
		[(int)(vars->user.pos_y)] == '0'
		|| vars->maze[(int)(vars->user.pos_x
		- vars->user.dir_x * move)][(int)(vars->user.pos_y)] == 'O')
		vars->user.pos_x -= vars->user.dir_x * move;
	if (vars->maze[(int)(vars->user.pos_x)][(int)(vars->user.pos_y
		- vars->user.dir_y * move)] == '0'
		|| vars->maze[(int)(vars->user.pos_x)][(int)(vars->user.pos_y
		- vars->user.dir_y * move)] == 'O')
		vars->user.pos_y -= vars->user.dir_y * move;
}

void	move_w(t_info *vars, double move)
{
	if (vars->maze[(int)(vars->user.pos_x + vars->user.dir_x * move)]
		[(int)(vars->user.pos_y)] == '0'
		|| vars->maze[(int)(vars->user.pos_x
		+ vars->user.dir_x * move)][(int)(vars->user.pos_y)] == 'O')
		vars->user.pos_x += vars->user.dir_x * move;
	if (vars->maze[(int)(vars->user.pos_x)][(int)(vars->user.pos_y
		+ vars->user.dir_y * move)] == '0'
		|| vars->maze[(int)(vars->user.pos_x)][(int)(vars->user.pos_y
		+ vars->user.dir_y * move)] == 'O')
		vars->user.pos_y += vars->user.dir_y * move;
}

int	mouse_move(int x, int y, t_info *vars)
{
	static int	prevx;

	(void)y;
	if (x < prevx)
		change_view(vars, LARROW, MROTATE * abs(x - prevx));
	else if (x > prevx)
		change_view(vars, RARROW, MROTATE * abs(x - prevx));
	prevx = x;
	return (0);
}
