/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:47:27 by nkarapet          #+#    #+#             */
/*   Updated: 2024/05/17 20:14:50 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
	ft_lstclear(&vars->map);
	free(vars->map);
	vars->npath = NULL;
	vars->wpath = NULL;
	vars->epath = NULL;
	vars->spath = NULL;
	vars->fcolor = NULL;
	vars->rcolor = NULL;
	if (flag == 1)
		exit(1 && printf("%s\n", s));
}
