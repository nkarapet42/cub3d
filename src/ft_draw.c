/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:59:36 by nkarapet          #+#    #+#             */
/*   Updated: 2024/06/14 21:15:37 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

unsigned int	my_mlx_color_taker(t_img *data, int j, int i)
{
	char			*dst;

	if (j >= 0 && j < data->wd && i >= 0 && i < data->ht)
	{
		dst = data->addr + (i * data->line_length
				+ j * (data->bits_per_pixel / 8));
		return (*(unsigned int *)dst);
	}
	return (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_img	*choose_texture(t_info *vars)
{
	if (vars->ray.hit == 2)
		return (&vars->cdoor);
	else if (vars->ray.hit == 3)
		return (&vars->odoor);
	else if (vars->ray.side == 1 && vars->ray.ray_y <= 0)
		return (vars->wall);
	else if (vars->ray.side == 0 && vars->ray.ray_x > 0)
		return (vars->wall + 1);
	else if (vars->ray.side == 0 && vars->ray.ray_x <= 0)
		return (vars->wall + 2);
	return (vars->wall + 3);
}

void	draw_texture(t_info *vars, int x, int tex_x)
{
	t_draw			tex;
	int				y;

	if (vars->ray.perp_wall_dist < 0.000001)
		vars->ray.perp_wall_dist = 0.000001;
	calc_draw_ends(vars, &tex);
	y = tex.draw_start - 1;
	while (++y < tex.draw_end)
	{
		tex.tex_y = (int)tex.tex_pos & (63);
		tex.tex_pos += tex.step;
		my_mlx_pixel_put(&vars->img, x, y,
			my_mlx_color_taker(choose_texture(vars), tex_x, tex.tex_y));
	}
}
