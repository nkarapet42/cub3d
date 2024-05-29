/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:25:48 by nkarapet          #+#    #+#             */
/*   Updated: 2024/05/23 18:35:04 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include "../mlx/mlx.h"

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define LARROW 123
# define RARROW 124

typedef struct s_ray
{
	int		wd;
	int		ht;
	int		**buffer;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
}	t_ray;


typedef struct s_user
{
	double	x;
	double	y;
}	t_user;

typedef struct s_img
{
	void	*mlx;
	void	*win;
}	t_img;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_map
{
	char			*row;
	int				len;
	int				index;
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
	void	*mlx;
	t_color	f_color;
	t_color	r_color;
	t_map	*map;
	char	**maze;
	t_img	xpm;
	t_ray	ray;
	t_user	pos;
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
int		ft_ischar(char const s, char *c);
char	**ft_split(char const *s, char *c);

//ft_util_trim_end.c
void	check_whitespaces(char **res);
size_t	ft_check(char *set, char str);
char	*ft_strtrim(char *s1, char *set);

//ft_init_map.c
void	path_init(t_info *vars, char	**s, int i, int j);
void	init_pathcolor(t_info *vars, char **s);
void	init_vars(t_info **vars);
void	init_map(t_info *vars, char **mapi);
void	init_map_info(char **map);

//ft_init_info.c
void	got_player_pos(t_info *vars);
void	got_color_floor(t_info *vars, char *color);
void	got_color_roof(t_info *vars, char *color);

//ft_validation.c
void	check_updown_walls(t_info vars);
void	check_side_walls(t_info vars);
void	check_position(t_info vars);
void	check_objects(t_info vars);
void	map_validation(t_info vars);

//ft_validation_second_part.c
char	*path_cut(char **path, char *s, char **info, int flag);
void	check_color(t_info vars);
void	check_door(t_info vars);
void	check_maze(t_info vars);

//ft_util_atoi.c
int		ft_isdigit(int c);
int		ft_atoi(char *str);

//ft_util_trim.c
char	*ft_strtrim_all(char *s1, char *set);

//ft_util_list.c
void	ft_lstclear(t_map **lst);
t_map	*ft_lstnew(int len, char *row, int index);
void	ft_addstack(t_map	**stack, char **res);

//ft_start_game.c
void	game_start(t_info vars);

//ft_game_exit.c
int		press(t_info *vars);

#endif