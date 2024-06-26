NAME = cub3d

CC = cc

CFLAGS = -Wall -Wextra -Werror -I mlx #-g3 -fsanitize=address
LDFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

HEADERS = inc/get_next_line.h inc/cub3d.h

SRCS_DIR = src/

OBJS_DIR = objs/

SRCS_NAME = cub3d.c \
			ft_utils.c \
			ft_parsing.c \
			ft_util_split.c \
			ft_util_list.c \
			ft_util_atoi.c \
			ft_util_trim.c \
			ft_util_trim_end.c \
			ft_init_map.c \
			ft_init_info.c \
			ft_validation.c \
			ft_validation_second_part.c \
			ft_tab_change.c \
			ft_start_game.c \
			ft_move.c \
			ft_view.c \
			ft_anim.c \
			ft_minimap.c \
			ft_raycasting.c \
			ft_algoritms.c \
			ft_draw.c \
			ft_set_textures.c \
			ft_game_exit.c \
			ft_free.c \
			get_next_line.c \
			get_next_line_utils.c \

OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))
OBJS_NAME = $(SRCS_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re