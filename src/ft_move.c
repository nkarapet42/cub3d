/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:15:03 by nkarapet          #+#    #+#             */
/*   Updated: 2024/06/13 20:52:05 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	key_press(int key, t_info *vars)
{
	if (key == ESC)
		ft_free_vars(vars, 2, "");
	else if (key == W)
		
	else if (key == A)
	else if (key == S)
	else if (key == D)
	return (0);
}
