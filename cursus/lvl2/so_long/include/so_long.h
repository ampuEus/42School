#ifndef PIPEX_H

#include "libft.h"

typedef struct	s_gui {
	char	**map;
	int		height;
	int		width;
	void	*mlx;
	void	*win;
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

# define PLAYER "./assets_80x80/Twelve_test.xpm"

// Assets size = 80x80 px
# define ASSETS_SIZE 80


/* ---------- Functions ---------- */
// Parsing map

unsigned int	total_char(char **map, char c);

char			is_closed_walls(char **map);
char			valid_chars(char **map);
char			valid_path(char **map);
char			is_valid_map(char **map);
char			**get_map(char *filepath);

// GUI

char			render_img(t_gui *gui, char *filepath, int x, int y);
char			render_map(t_gui *gui);
int				key_hook(int keycode, t_gui *gui);
char			end_gui(t_gui	*gui);
char			start_gui(t_gui *gui);
#endif
