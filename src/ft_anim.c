/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:57:05 by nkarapet          #+#    #+#             */
/*   Updated: 2024/06/25 15:10:06 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	anim(t_info *vars)
{
	static int	i;
	static int	count;

	if (count % 5 == 0)
	{
		print_gun(vars, i);
		i++;
		if (i == 5)
			i = 0;
	}
	count++;
	if (count >= 150000)
		count = 0;
}

void	print_gun(t_info *vars, int i)
{
	int	x;
	int	y;
	int	px;
	int	py;

	px = 0;
	x = vars->img.wd / 2 - vars->gun[i].wd / 2 - 1;
	while (++x < vars->img.wd / 2 + vars->gun[i].wd / 2)
	{
		y = vars->img.ht - vars->gun[i].ht - 1;
		py = 0;
		while (++y < vars->img.ht)
		{
			my_mlx_pixel_put(&vars->img, x, y,
				my_mlx_color_taker(&vars->gun[i], px, py));
			py++;
		}
		px++;
	}
}
