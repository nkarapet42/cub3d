/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:47:27 by nkarapet          #+#    #+#             */
/*   Updated: 2024/06/13 22:30:33 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	destroy_img(t_info *vars)
{
	if (vars->wall[0].img)
		mlx_destroy_image(vars->mlx.ptr, vars->wall[0].img);
	else if (vars->wall[1].img)
		mlx_destroy_image(vars->mlx.ptr, vars->wall[1].img);
	else if (vars->wall[2].img)
		mlx_destroy_image(vars->mlx.ptr, vars->wall[2].img);
	else if (vars->wall[3].img)
		mlx_destroy_image(vars->mlx.ptr, vars->wall[3].img);
	else if (vars->img.img)
		mlx_destroy_image(vars->mlx.ptr, vars->img.img);
	free(vars->wall);
}

void	free_and_error(char **str, int flag, char *s)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
	}
	free(str);
	if (flag == 1)
		exit(1 && printf("%s\n", s));
}

void	ft_free_vars(t_info *vars, int flag, char *s)
{
	free(vars->npath);
	free(vars->wpath);
	free(vars->spath);
	free(vars->epath);
	free(vars->fcolor);
	free(vars->rcolor);
	if (vars->wall)
		destroy_img(vars);
	if (vars->map)
		ft_lstclear(&vars->map);
	if (vars->maze)
		free(vars->maze);
	free(vars->map);
	vars->npath = NULL;
	vars->wpath = NULL;
	vars->epath = NULL;
	vars->spath = NULL;
	vars->fcolor = NULL;
	vars->rcolor = NULL;
	if (flag == 1)
		exit(1 && printf("%s\n", s));
	else if (flag == 2)
		exit(0);
}
