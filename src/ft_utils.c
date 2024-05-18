/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:08:36 by nkarapet          #+#    #+#             */
/*   Updated: 2024/05/18 13:59:37 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	*ft_bzero(void *s, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *) s)[i] = 0;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret_mem;

	if (count && size && count > (INT_MAX / size))
		return (NULL);
	ret_mem = malloc(count * size);
	if (!ret_mem)
		return (NULL);
	ft_bzero(ret_mem, count * size);
	return (ret_mem);
}

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	map_name_check(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i--] != 'b')
		return (1);
	if (str[i--] != 'u')
		return (1);
	if (str[i--] != 'c')
		return (1);
	if (str[i--] != '.')
		return (1);
	return (0);
}
