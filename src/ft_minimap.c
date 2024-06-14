/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 21:25:25 by nkarapet          #+#    #+#             */
/*   Updated: 2024/06/14 22:07:55 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_square(t_info *vars, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			my_mlx_pixel_put(&vars->img, y + i, x + j, color);
			j++;
		}
		i++;
	}
}

int	draw_minimap(t_info *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->maze[y])
	{
		x = 0;
		while (vars->maze[y][x])
		{
			if (vars->maze[y][x] == '1')
				draw_square(vars, y * TILE_SIZE, x * TILE_SIZE, 0xFFFFFF);
			else if (vars->maze[y][x] == '0')
				draw_square(vars, y * TILE_SIZE, x * TILE_SIZE, 0x000000);
			else if (vars->maze[y][x] == 'D')
				draw_square(vars, y * TILE_SIZE, x * TILE_SIZE, 0xFF0000);
			else if (vars->maze[y][x] == 'O')
				draw_square(vars, y * TILE_SIZE, x * TILE_SIZE, 0x008000);
			x++;
		}
		y++;
	}
	draw_square(vars, (int)vars->user.pos_x * TILE_SIZE,
		(int)vars->user.pos_y * TILE_SIZE, 0x0000FF);
	return (0);
}
