/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:55:51 by daampuru          #+#    #+#             */
/*   Updated: 2023/06/18 21:06:37 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# include "libft.h"

typedef struct s_gui {
	char			**map;
	int				height;
	int				width;
	void			*mlx;
	void			*win;
	void			*gnd1_img;
	void			*gnd2_img;
	void			*gnd3_img;
	void			*gnd4_img;
	void			*wall1_img;
	void			*wall2_img;
	void			*player_l_img;
	void			*player_r_img;
	void			*exit_img;
	void			*collectable_img;
	void			**wall_img[2];
	void			**gnd_img[4];
	//void			**player_l_img[14];
	//void			**player_r_img[14];
	unsigned int	player_pos_x;
	unsigned int	player_pos_y;
	char			player_direction;
	//void			**exit_img[27];
	//void			**collectable_img[32];
}			t_gui;

/* ---------- Constants ---------- */
// keycodes

# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

// Map components

# define FREE_SPACE '0'
# define WALL '1'
# define START_POS 'P'
# define EXIT 'E'
# define COLLECTABLE 'C'

# define FREE_SPACE_AUX '-'
# define EXIT_AUX 'e'
# define COLLECTABLE_AUX 'c'

// Assets relative paths

# define WALL_NBR 2
# define WALL1 "./assets_80x80/wall/wall_1.xpm"
# define WALL2 "./assets_80x80/wall/wall_2.xpm"

# define GND_NBR 4
# define GND1 "./assets_80x80/gnd/gnd_1.xpm"
# define GND2 "./assets_80x80/gnd/gnd_2.xpm"
# define GND3 "./assets_80x80/gnd/gnd_3.xpm"
# define GND4 "./assets_80x80/gnd/gnd_4.xpm"

# define PLAYER_L "./assets_80x80/Twelve_test.xpm"
# define PLAYER_R "./assets_80x80/Twelve_test.xpm"

# define PLAYER_IDLE_NBR 14
# define PLAYER_IDLE_L "./assets_80x80/Twelve_test.xpm"
# define PLAYER_IDLE_R "./assets_80x80/Twelve_test.xpm"
# define PLAYER_DEAD_NBR 14
# define PLAYER_DEAD_L "./assets_80x80/Twelve_test.xpm"
# define PLAYER_DEAD_R "./assets_80x80/Twelve_test.xpm"
# define COLLECT_NBR 32
# define COLLECT "./assets_80x80/peach_test.xpm"
# define Q_IDLE_NBR 27
# define Q_BAD_NBR 27
# define Q_GOOD_NBR 27
# define QUIT "./assets_80x80/q_test.xpm"
# define ENEMY_IDLE_NBR 27
# define ENEMY_WALK_NBR 27
# define ENEMY "./assets_80x80/grass_4.xpm"

// Assets size = 80x80 px
# define ASSETS_SIZE 80

/* ---------- Functions ---------- */
// Utils

char			find_coor(char **map, unsigned int *x, unsigned int *y, char c);

// Parsing map

unsigned int	total_char(char **map, char c);

char			is_closed_walls(char **map);
char			valid_chars(char **map);
char			valid_path(char **map);
char			is_valid_map(char **map);
char			**get_map(char *filepath);

// GUI

void			init_imgs(t_gui *gui);
char			render_map(t_gui *gui);
char			move(int keycode, t_gui *gui);
int				key_hook(int keycode, t_gui *gui);
int				end_gui(t_gui	*gui);
char			start_gui(t_gui *gui);
#endif
