/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:25:48 by nkarapet          #+#    #+#             */
/*   Updated: 2024/06/14 22:04:14 by nkarapet         ###   ########.fr       */
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
# define E 14
# define W 13
# define A 0
# define S 1
# define D 2
# define LARROW 123
# define RARROW 124

# define AROTATE 0.07
# define MROTATE 0.03
# define WSPEED 0.16 
# define SSPEED 0.1
# define ADSPEED 0.12

# define MAP_WIDTH 36
# define MAP_HEIGHT 11
# define TILE_SIZE 10

typedef struct s_img
{
	int		wd;
	int		ht;
	int		endian;
	int		line_length;
	int		bits_per_pixel;
	char	*addr;
	void	*img;
}	t_img;

typedef struct s_raycasting
{
	int		hit;
	int		side;
	double	ray_x;
	double	ray_y;
	double	camera_x;
	double	sdist_x;//side distance
	double	sdist_y;//side distance
	double	deltadist_x;
	double	deltadist_y;
	double	perp_wall_dist;
}	t_raycasting;

typedef struct s_draw
{
	int		tex_x;
	int		tex_y;
	int		draw_end;
	int		draw_start;
	int		line_height;
	double	step;
	double	tex_pos;
}	t_draw;

typedef struct s_user
{
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_user;

typedef struct s_xpm
{
	void	*ptr;
	void	*win;
}	t_xpm;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_map
{
	int				len;
	int				index;
	char			*row;
	struct s_map	*next;
	struct s_map	*prev;
}	t_map;

typedef struct s_info
{
	int				fc;//f_color
	int				rc;//r_color
	int				map_wd;
	int				map_ht;
	char			*npath;
	char			*spath;
	char			*wpath;
	char			*epath;
	char			**maze;
	char			*fcolor;
	char			*rcolor;
	t_xpm			mlx;
	t_user			user;
	t_img			img;
	t_img			cdoor;
	t_img			odoor;
	t_raycasting	ray;
	t_color			f_color;
	t_color			r_color;
	t_map			*map;
	t_img			*wall;
}	t_info;

//ft_utils.c
void			*ft_calloc(size_t count, size_t size);
int				ft_strlen(char *str);
int				map_name_check(char *str);

//ft_free.c
void			destroy_img(t_info *vars);
void			free_and_error(char **str, int flag, char *s);
void			ft_free_vars(t_info *vars, int flag, char *s);

//ft_parsing.c
int				check(char s);
void			ft_cpy(char **info, char **res, int i, int k);
void			ft_allocate(char **info, char **res);
char			**ft_spliting(char **res);
void			start_parsing(int fd);

//ft_util_split.c
int				ft_ischar(char const s, char *c);
char			**ft_split(char const *s, char *c);

//ft_util_trim_end.c
void			check_whitespaces(char **res);
size_t			ft_check(char *set, char str);
char			*ft_strtrim(char *s1, char *set);

//ft_init_map.c
void			path_init(t_info *vars, char	**s, int i, int j);
void			init_pathcolor(t_info *vars, char **s);
void			init_vars(t_info **vars);
void			init_map(t_info *vars, char **mapi);
void			init_map_info(char **map);

//ft_init_info.c
void			got_player_pos(t_info *vars);
void			got_color_floor(t_info *vars, char *color);
void			got_color_roof(t_info *vars, char *color);

//ft_validation.c
void			check_updown_walls(t_info vars);
void			check_side_walls(t_info vars);
void			check_position(t_info vars);
void			check_objects(t_info vars);
void			map_validation(t_info vars);

//ft_validation_second_part.c
char			*path_cut(char **path, char *s, char **info, int flag);
void			get_maze(t_info *vars);
void			check_color(t_info vars);
void			check_door(t_info vars);
void			check_maze(t_info vars);

//ft_util_atoi.c
int				ft_isdigit(int c);
int				ft_atoi(char *str);

//ft_util_trim.c
char			*ft_strtrim_all(char *s1, char *set);

//ft_util_list.c
void			ft_lstclear(t_map **lst);
t_map			*ft_lstnew(int len, char *row, int index);
void			ft_addstack(t_map	**stack, char **res);

//ft_view.c
void			rotate_view(t_info *vars, double prevdir_x,
					double prevplane_x, double rotate);
void			change_view(t_info *vars, int side, double rotate);
void			get_dir(t_info *vars);

//ft_minimap.c
void			draw_square(t_info *vars, int x, int y, int color);
int				draw_minimap(t_info *vars);

//ft_move.c
int				key_press(int key, t_info *vars);
void			move_right_left(t_info *vars, int key, double move);
void			move_s(t_info *vars, double move);
void			move_w(t_info *vars, double move);
int				mouse_move(int x, int y, t_info *vars);

//ft_start_game.c
int				re_draw(t_info *vars);
void			init_img_info(t_info *vars);
void			game_start(t_info vars);

//ft_game_exit.c
int				press(t_info *vars);

//ft_algoritms.c
int				calc_texture_x(t_info *vars);
void			dda_algorithm(t_info *vars);
void			ray_pos(t_info *vars, int w);
void			calc_draw_ends(t_info *vars, t_draw *tex);
void			step_dir(t_info *vars);

//ft_draw.c
int				create_trgb(int t, int r, int g, int b);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void			draw_texture(t_info *vars, int x, int tex_x);
t_img			*choose_texture(t_info *vars);
unsigned int	my_mlx_color_taker(t_img *data, int j, int i);

//ft_set_textures.c
void			open_close_door(t_info *vars);
void			get_door(t_img *door, t_info *vars, char *path);
void			create_image(t_info *vars);
void			set_wall_textures(t_info *vars);
void			get_wall__textures(t_info *vars);

//ft_raycasting.c
void			draw_floor(t_info *vars);
void			raycasting(t_info *vars);

#endif