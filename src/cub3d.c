/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:23:05 by nkarapet          #+#    #+#             */
/*   Updated: 2024/06/15 19:16:24 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (1 && printf("Must be given 1 argument \
---> was given %d\n", argc - 1));
	else
	{
		if (map_name_check(argv[1]) == 0)
		{
			fd = open(argv[1], O_RDONLY);
			if (fd == -1)
				exit(1 && printf("Can't open map\n"));
			start_parsing(fd);
		}
		else
			return (1 && printf("Invalid file name (.cub at the end)\n"));
	}
}
