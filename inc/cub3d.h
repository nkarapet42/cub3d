/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:25:48 by nkarapet          #+#    #+#             */
/*   Updated: 2024/05/17 17:09:15 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
# include "../mlx/mlx.h"

typedef struct s_map
{
	char			*row;
	int				len;
	struct s_map	*next;
	struct s_map	*prev;
}	t_map;

typedef struct s_info
{
	char	*fcolor;
	char	*rcolor;
	char	*npath;
	char	*spath;
	char	*wpath;
	char	*epath;
	t_map	*map;
}	t_info;

//ft_utils.c
void	*ft_calloc(size_t count, size_t size);
int		ft_strlen(char *str);
int		map_name_check(char *str);

//ft_free.c
void	free_and_error(char **str, int flag, char *s);
void	ft_free_vars(t_info *vars, int flag, char *s);

//ft_parsing.c
int		check(char s);
void	ft_cpy(char **info, char **res, int i, int k);
void	ft_allocate(char **info, char **res);
char	**ft_spliting(char **res);
void	start_parsing(int fd);

//ft_util_split.c
char	**ft_split(char const *s, char *c);

//ft_util_trim.c
void	check_whitespaces(char **res);
size_t	ft_check(char *set, char str);
char	*ft_strtrim(char *s1, char *set);

//ft_init_map.c
void	path_check(t_info *vars, char	**s, int i, int j);
void	init_pathcolor(t_info *vars, char **s);
void	init_vars(t_info **vars);
void	init_map(t_info *vars, char **mapi);
void	init_map_info(char **map);

//ft_validation.c
void	check_updown_walls(t_info vars);
void	check_side_walls(t_info vars);
void	check_position(t_info vars);
void	check_objects(t_info vars);
void	map_validation(t_info vars);

//ft_validation_second_part.c
void	check_maze(t_info vars);

//ft_util_list.c
void	ft_lstclear(t_map **lst);
t_map	*ft_lstnew(int len, char *row);
void	ft_addstack(t_map	**stack, char **res);

#endif