/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:55:51 by daampuru          #+#    #+#             */
/*   Updated: 2023/06/10 21:33:41 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# include "libft.h"

typedef struct s_gui {
	char	**map;
	int		height;
	int		width;
	void	*mlx;
	void	*win;
	void	*wall1_img;
	void	*wall2_img;
	void	*gnd1_img;
	void	*gnd2_img;
	void	*gnd3_img;
	void	*gnd4_img;
	void	*player_l_img;
	void	*player_r_img;
	void	*exit_img;
	void	*collectable_img;
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

# define WALL1 "./assets_80x80/border_1.xpm"
# define WALL2 "./assets_80x80/border_2.xpm"
# define GND1 "./assets_80x80/grass_1.xpm"
# define GND2 "./assets_80x80/grass_2.xpm"
# define GND3 "./assets_80x80/grass_3.xpm"
# define GND4 "./assets_80x80/grass_4.xpm"

# define PLAYER_L "./assets_80x80/Twelve_test.xpm"
# define PLAYER_R "./assets_80x80/Twelve_test.xpm"
# define COLLECT "./assets_80x80/peach_test.xpm"
# define QUIT "./assets_80x80/q_test.xpm"
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
char			end_gui(t_gui	*gui);
char			start_gui(t_gui *gui);
#endif
