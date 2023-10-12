/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:55:51 by daampuru          #+#    #+#             */
/*   Updated: 2023/10/12 18:35:06 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# include "libft.h"

/* ---------- Constants ---------- */
// keycodes MacOS

# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

// keycode Debian

# define KEY_ESC_L 65307
# define KEY_LEFT_L 65361
# define KEY_RIGHT_L 65363
# define KEY_DOWN_L 65364
# define KEY_UP_L 65362

// X11 events

# define EXPOSE 12
# define DESTROY_NOTIFY 17

// X11 mask

# define KEY_PRESS_MASK (1L << 0)
# define EXPOSURE_MASK (1L << 15)

// Map components

# define FREE_SPACE '0'
# define WALL '1'
# define START_POS 'P'
# define EXIT 'E'
# define COLLECTABLE 'C'

# define FREE_SPACE_AUX '-'
# define EXIT_AUX 'e'
# define COLLECTABLE_AUX 'c'

// Characters' states

# define IDLE 0
# define DEAD 1
# define BAD 2
# define GOOD 3

// Assets relative paths

# define WALL_NBR 2
# define WALL1 "./assets_80x80/wall/wall_1.xpm"
# define WALL2 "./assets_80x80/wall/wall_2.xpm"

# define GND_NBR 4
# define GND1 "./assets_80x80/gnd/gnd_1.xpm"
# define GND2 "./assets_80x80/gnd/gnd_2.xpm"
# define GND3 "./assets_80x80/gnd/gnd_3.xpm"
# define GND4 "./assets_80x80/gnd/gnd_4.xpm"

# define PLAYER_IDLE_NBR 14
# define PLAYER_IDLE_L00 "./assets_80x80/twelve/idle/frame00.xpm"
# define PLAYER_IDLE_L01 "./assets_80x80/twelve/idle/frame01.xpm"
# define PLAYER_IDLE_L02 "./assets_80x80/twelve/idle/frame02.xpm"
# define PLAYER_IDLE_L03 "./assets_80x80/twelve/idle/frame03.xpm"
# define PLAYER_IDLE_L04 "./assets_80x80/twelve/idle/frame04.xpm"
# define PLAYER_IDLE_L05 "./assets_80x80/twelve/idle/frame05.xpm"
# define PLAYER_IDLE_L06 "./assets_80x80/twelve/idle/frame06.xpm"
# define PLAYER_IDLE_L07 "./assets_80x80/twelve/idle/frame07.xpm"
# define PLAYER_IDLE_L08 "./assets_80x80/twelve/idle/frame08.xpm"
# define PLAYER_IDLE_L09 "./assets_80x80/twelve/idle/frame09.xpm"
# define PLAYER_IDLE_L10 "./assets_80x80/twelve/idle/frame10.xpm"
# define PLAYER_IDLE_L11 "./assets_80x80/twelve/idle/frame11.xpm"
# define PLAYER_IDLE_L12 "./assets_80x80/twelve/idle/frame12.xpm"
# define PLAYER_IDLE_L13 "./assets_80x80/twelve/idle/frame13.xpm"
# define PLAYER_DEAD_NBR 27
# define PLAYER_DEAD_L00 "./assets_80x80/twelve/dead/frame00.xpm"
# define PLAYER_DEAD_L01 "./assets_80x80/twelve/dead/frame01.xpm"
# define PLAYER_DEAD_L02 "./assets_80x80/twelve/dead/frame02.xpm"
# define PLAYER_DEAD_L03 "./assets_80x80/twelve/dead/frame03.xpm"
# define PLAYER_DEAD_L04 "./assets_80x80/twelve/dead/frame04.xpm"
# define PLAYER_DEAD_L05 "./assets_80x80/twelve/dead/frame05.xpm"
# define PLAYER_DEAD_L06 "./assets_80x80/twelve/dead/frame06.xpm"
# define PLAYER_DEAD_L07 "./assets_80x80/twelve/dead/frame07.xpm"
# define PLAYER_DEAD_L08 "./assets_80x80/twelve/dead/frame08.xpm"
# define PLAYER_DEAD_L09 "./assets_80x80/twelve/dead/frame09.xpm"
# define PLAYER_DEAD_L10 "./assets_80x80/twelve/dead/frame10.xpm"
# define PLAYER_DEAD_L11 "./assets_80x80/twelve/dead/frame11.xpm"
# define PLAYER_DEAD_L12 "./assets_80x80/twelve/dead/frame12.xpm"
# define PLAYER_DEAD_L13 "./assets_80x80/twelve/dead/frame13.xpm"
# define PLAYER_DEAD_L14 "./assets_80x80/twelve/dead/frame14.xpm"
# define PLAYER_DEAD_L15 "./assets_80x80/twelve/dead/frame15.xpm"
# define PLAYER_DEAD_L16 "./assets_80x80/twelve/dead/frame16.xpm"
# define PLAYER_DEAD_L17 "./assets_80x80/twelve/dead/frame17.xpm"
# define PLAYER_DEAD_L18 "./assets_80x80/twelve/dead/frame18.xpm"
# define PLAYER_DEAD_L19 "./assets_80x80/twelve/dead/frame19.xpm"
# define PLAYER_DEAD_L20 "./assets_80x80/twelve/dead/frame20.xpm"
# define PLAYER_DEAD_L21 "./assets_80x80/twelve/dead/frame21.xpm"
# define PLAYER_DEAD_L22 "./assets_80x80/twelve/dead/frame22.xpm"
# define PLAYER_DEAD_L23 "./assets_80x80/twelve/dead/frame23.xpm"
# define PLAYER_DEAD_L24 "./assets_80x80/twelve/dead/frame24.xpm"
# define PLAYER_DEAD_L25 "./assets_80x80/twelve/dead/frame25.xpm"
# define PLAYER_DEAD_L26 "./assets_80x80/twelve/dead/frame26.xpm"

# define COLLECT_NBR 33
# define COLLECT00 "./assets_80x80/peach/frame00.xpm"
# define COLLECT01 "./assets_80x80/peach/frame01.xpm"
# define COLLECT02 "./assets_80x80/peach/frame02.xpm"
# define COLLECT03 "./assets_80x80/peach/frame03.xpm"
# define COLLECT04 "./assets_80x80/peach/frame04.xpm"
# define COLLECT05 "./assets_80x80/peach/frame05.xpm"
# define COLLECT06 "./assets_80x80/peach/frame06.xpm"
# define COLLECT07 "./assets_80x80/peach/frame07.xpm"
# define COLLECT08 "./assets_80x80/peach/frame08.xpm"
# define COLLECT09 "./assets_80x80/peach/frame09.xpm"
# define COLLECT10 "./assets_80x80/peach/frame10.xpm"
# define COLLECT11 "./assets_80x80/peach/frame11.xpm"
# define COLLECT12 "./assets_80x80/peach/frame12.xpm"
# define COLLECT13 "./assets_80x80/peach/frame13.xpm"
# define COLLECT14 "./assets_80x80/peach/frame14.xpm"
# define COLLECT15 "./assets_80x80/peach/frame15.xpm"
# define COLLECT16 "./assets_80x80/peach/frame16.xpm"
# define COLLECT17 "./assets_80x80/peach/frame17.xpm"
# define COLLECT18 "./assets_80x80/peach/frame18.xpm"
# define COLLECT19 "./assets_80x80/peach/frame19.xpm"
# define COLLECT20 "./assets_80x80/peach/frame20.xpm"
# define COLLECT21 "./assets_80x80/peach/frame21.xpm"
# define COLLECT22 "./assets_80x80/peach/frame22.xpm"
# define COLLECT23 "./assets_80x80/peach/frame23.xpm"
# define COLLECT24 "./assets_80x80/peach/frame24.xpm"
# define COLLECT25 "./assets_80x80/peach/frame25.xpm"
# define COLLECT26 "./assets_80x80/peach/frame26.xpm"
# define COLLECT27 "./assets_80x80/peach/frame27.xpm"
# define COLLECT28 "./assets_80x80/peach/frame28.xpm"
# define COLLECT29 "./assets_80x80/peach/frame29.xpm"
# define COLLECT30 "./assets_80x80/peach/frame30.xpm"
# define COLLECT31 "./assets_80x80/peach/frame31.xpm"
# define COLLECT32 "./assets_80x80/peach/frame32.xpm"

# define Q_IDLE_NBR 22
# define Q_IDLE00 "./assets_80x80/q/idle/frame00.xpm"
# define Q_IDLE01 "./assets_80x80/q/idle/frame01.xpm"
# define Q_IDLE02 "./assets_80x80/q/idle/frame02.xpm"
# define Q_IDLE03 "./assets_80x80/q/idle/frame03.xpm"
# define Q_IDLE04 "./assets_80x80/q/idle/frame04.xpm"
# define Q_IDLE05 "./assets_80x80/q/idle/frame05.xpm"
# define Q_IDLE06 "./assets_80x80/q/idle/frame06.xpm"
# define Q_IDLE07 "./assets_80x80/q/idle/frame07.xpm"
# define Q_IDLE08 "./assets_80x80/q/idle/frame08.xpm"
# define Q_IDLE09 "./assets_80x80/q/idle/frame09.xpm"
# define Q_IDLE10 "./assets_80x80/q/idle/frame10.xpm"
# define Q_IDLE11 "./assets_80x80/q/idle/frame11.xpm"
# define Q_IDLE12 "./assets_80x80/q/idle/frame12.xpm"
# define Q_IDLE13 "./assets_80x80/q/idle/frame13.xpm"
# define Q_IDLE14 "./assets_80x80/q/idle/frame14.xpm"
# define Q_IDLE15 "./assets_80x80/q/idle/frame15.xpm"
# define Q_IDLE16 "./assets_80x80/q/idle/frame16.xpm"
# define Q_IDLE17 "./assets_80x80/q/idle/frame17.xpm"
# define Q_IDLE18 "./assets_80x80/q/idle/frame18.xpm"
# define Q_IDLE19 "./assets_80x80/q/idle/frame19.xpm"
# define Q_IDLE20 "./assets_80x80/q/idle/frame20.xpm"
# define Q_IDLE21 "./assets_80x80/q/idle/frame21.xpm"
# define Q_BAD_NBR 27
# define Q_BAD00 "./assets_80x80/q/bad/frame00.xpm"
# define Q_BAD01 "./assets_80x80/q/bad/frame01.xpm"
# define Q_BAD02 "./assets_80x80/q/bad/frame02.xpm"
# define Q_BAD03 "./assets_80x80/q/bad/frame03.xpm"
# define Q_BAD04 "./assets_80x80/q/bad/frame04.xpm"
# define Q_BAD05 "./assets_80x80/q/bad/frame05.xpm"
# define Q_BAD06 "./assets_80x80/q/bad/frame06.xpm"
# define Q_BAD07 "./assets_80x80/q/bad/frame07.xpm"
# define Q_BAD08 "./assets_80x80/q/bad/frame08.xpm"
# define Q_BAD09 "./assets_80x80/q/bad/frame09.xpm"
# define Q_BAD10 "./assets_80x80/q/bad/frame10.xpm"
# define Q_BAD11 "./assets_80x80/q/bad/frame11.xpm"
# define Q_BAD12 "./assets_80x80/q/bad/frame12.xpm"
# define Q_BAD13 "./assets_80x80/q/bad/frame13.xpm"
# define Q_BAD14 "./assets_80x80/q/bad/frame14.xpm"
# define Q_BAD15 "./assets_80x80/q/bad/frame15.xpm"
# define Q_BAD16 "./assets_80x80/q/bad/frame16.xpm"
# define Q_BAD17 "./assets_80x80/q/bad/frame17.xpm"
# define Q_BAD18 "./assets_80x80/q/bad/frame18.xpm"
# define Q_BAD19 "./assets_80x80/q/bad/frame19.xpm"
# define Q_BAD20 "./assets_80x80/q/bad/frame20.xpm"
# define Q_BAD21 "./assets_80x80/q/bad/frame21.xpm"
# define Q_BAD22 "./assets_80x80/q/bad/frame22.xpm"
# define Q_BAD23 "./assets_80x80/q/bad/frame23.xpm"
# define Q_BAD24 "./assets_80x80/q/bad/frame24.xpm"
# define Q_BAD25 "./assets_80x80/q/bad/frame25.xpm"
# define Q_BAD26 "./assets_80x80/q/bad/frame26.xpm"
# define Q_GOOD_NBR 17
# define Q_GOOD00 "./assets_80x80/q/good/frame00.xpm"
# define Q_GOOD01 "./assets_80x80/q/good/frame01.xpm"
# define Q_GOOD02 "./assets_80x80/q/good/frame02.xpm"
# define Q_GOOD03 "./assets_80x80/q/good/frame03.xpm"
# define Q_GOOD04 "./assets_80x80/q/good/frame04.xpm"
# define Q_GOOD05 "./assets_80x80/q/good/frame05.xpm"
# define Q_GOOD06 "./assets_80x80/q/good/frame06.xpm"
# define Q_GOOD07 "./assets_80x80/q/good/frame07.xpm"
# define Q_GOOD08 "./assets_80x80/q/good/frame08.xpm"
# define Q_GOOD09 "./assets_80x80/q/good/frame09.xpm"
# define Q_GOOD10 "./assets_80x80/q/good/frame10.xpm"
# define Q_GOOD11 "./assets_80x80/q/good/frame11.xpm"
# define Q_GOOD12 "./assets_80x80/q/good/frame12.xpm"
# define Q_GOOD13 "./assets_80x80/q/good/frame13.xpm"
# define Q_GOOD14 "./assets_80x80/q/good/frame14.xpm"
# define Q_GOOD15 "./assets_80x80/q/good/frame15.xpm"
# define Q_GOOD16 "./assets_80x80/q/good/frame16.xpm"

# define ENEMY_IDLE_NBR 14
# define ENEMY_IDLE00 "./assets_80x80/hugo_idle/frame00.xpm"
# define ENEMY_IDLE01 "./assets_80x80/hugo_idle/frame01.xpm"
# define ENEMY_IDLE02 "./assets_80x80/hugo_idle/frame02.xpm"
# define ENEMY_IDLE03 "./assets_80x80/hugo_idle/frame03.xpm"
# define ENEMY_IDLE04 "./assets_80x80/hugo_idle/frame04.xpm"
# define ENEMY_IDLE05 "./assets_80x80/hugo_idle/frame05.xpm"
# define ENEMY_IDLE06 "./assets_80x80/hugo_idle/frame06.xpm"
# define ENEMY_IDLE07 "./assets_80x80/hugo_idle/frame07.xpm"
# define ENEMY_IDLE08 "./assets_80x80/hugo_idle/frame08.xpm"
# define ENEMY_IDLE09 "./assets_80x80/hugo_idle/frame09.xpm"
# define ENEMY_IDLE10 "./assets_80x80/hugo_idle/frame10.xpm"
# define ENEMY_IDLE11 "./assets_80x80/hugo_idle/frame11.xpm"
# define ENEMY_IDLE12 "./assets_80x80/hugo_idle/frame12.xpm"
# define ENEMY_IDLE13 "./assets_80x80/hugo_idle/frame13.xpm"
# define ENEMY_WALK_NBR 58
# define ENEMY_WALK00 "./assets_80x80/elena_idle/frame00.xpm"
# define ENEMY_WALK01 "./assets_80x80/elena_idle/frame01.xpm"
# define ENEMY_WALK02 "./assets_80x80/elena_idle/frame02.xpm"
# define ENEMY_WALK03 "./assets_80x80/elena_idle/frame03.xpm"
# define ENEMY_WALK04 "./assets_80x80/elena_idle/frame04.xpm"
# define ENEMY_WALK05 "./assets_80x80/elena_idle/frame05.xpm"
# define ENEMY_WALK06 "./assets_80x80/elena_idle/frame06.xpm"
# define ENEMY_WALK07 "./assets_80x80/elena_idle/frame07.xpm"
# define ENEMY_WALK08 "./assets_80x80/elena_idle/frame08.xpm"
# define ENEMY_WALK09 "./assets_80x80/elena_idle/frame09.xpm"
# define ENEMY_WALK10 "./assets_80x80/elena_idle/frame10.xpm"
# define ENEMY_WALK11 "./assets_80x80/elena_idle/frame11.xpm"
# define ENEMY_WALK12 "./assets_80x80/elena_idle/frame12.xpm"
# define ENEMY_WALK13 "./assets_80x80/elena_idle/frame13.xpm"
# define ENEMY_WALK14 "./assets_80x80/elena_idle/frame14.xpm"
# define ENEMY_WALK15 "./assets_80x80/elena_idle/frame15.xpm"
# define ENEMY_WALK16 "./assets_80x80/elena_idle/frame16.xpm"
# define ENEMY_WALK17 "./assets_80x80/elena_idle/frame17.xpm"
# define ENEMY_WALK18 "./assets_80x80/elena_idle/frame18.xpm"
# define ENEMY_WALK19 "./assets_80x80/elena_idle/frame19.xpm"
# define ENEMY_WALK20 "./assets_80x80/elena_idle/frame20.xpm"
# define ENEMY_WALK21 "./assets_80x80/elena_idle/frame21.xpm"
# define ENEMY_WALK22 "./assets_80x80/elena_idle/frame22.xpm"
# define ENEMY_WALK23 "./assets_80x80/elena_idle/frame23.xpm"
# define ENEMY_WALK24 "./assets_80x80/elena_idle/frame24.xpm"
# define ENEMY_WALK25 "./assets_80x80/elena_idle/frame25.xpm"
# define ENEMY_WALK26 "./assets_80x80/elena_idle/frame26.xpm"
# define ENEMY_WALK27 "./assets_80x80/elena_idle/frame27.xpm"
# define ENEMY_WALK28 "./assets_80x80/elena_idle/frame28.xpm"
# define ENEMY_WALK29 "./assets_80x80/elena_idle/frame29.xpm"
# define ENEMY_WALK30 "./assets_80x80/elena_idle/frame30.xpm"
# define ENEMY_WALK31 "./assets_80x80/elena_idle/frame31.xpm"
# define ENEMY_WALK32 "./assets_80x80/elena_idle/frame32.xpm"
# define ENEMY_WALK33 "./assets_80x80/elena_idle/frame33.xpm"
# define ENEMY_WALK34 "./assets_80x80/elena_idle/frame34.xpm"
# define ENEMY_WALK35 "./assets_80x80/elena_idle/frame35.xpm"
# define ENEMY_WALK36 "./assets_80x80/elena_idle/frame36.xpm"
# define ENEMY_WALK37 "./assets_80x80/elena_idle/frame37.xpm"
# define ENEMY_WALK38 "./assets_80x80/elena_idle/frame38.xpm"
# define ENEMY_WALK39 "./assets_80x80/elena_idle/frame39.xpm"
# define ENEMY_WALK40 "./assets_80x80/elena_idle/frame40.xpm"
# define ENEMY_WALK41 "./assets_80x80/elena_idle/frame41.xpm"
# define ENEMY_WALK42 "./assets_80x80/elena_idle/frame42.xpm"
# define ENEMY_WALK43 "./assets_80x80/elena_idle/frame43.xpm"
# define ENEMY_WALK44 "./assets_80x80/elena_idle/frame44.xpm"
# define ENEMY_WALK45 "./assets_80x80/elena_idle/frame45.xpm"
# define ENEMY_WALK46 "./assets_80x80/elena_idle/frame46.xpm"
# define ENEMY_WALK47 "./assets_80x80/elena_idle/frame47.xpm"
# define ENEMY_WALK48 "./assets_80x80/elena_idle/frame48.xpm"
# define ENEMY_WALK49 "./assets_80x80/elena_idle/frame49.xpm"
# define ENEMY_WALK50 "./assets_80x80/elena_idle/frame50.xpm"
# define ENEMY_WALK51 "./assets_80x80/elena_idle/frame51.xpm"
# define ENEMY_WALK52 "./assets_80x80/elena_idle/frame52.xpm"
# define ENEMY_WALK53 "./assets_80x80/elena_idle/frame53.xpm"
# define ENEMY_WALK54 "./assets_80x80/elena_idle/frame54.xpm"
# define ENEMY_WALK55 "./assets_80x80/elena_idle/frame55.xpm"
# define ENEMY_WALK56 "./assets_80x80/elena_idle/frame56.xpm"
# define ENEMY_WALK57 "./assets_80x80/elena_idle/frame57.xpm"

// Assets size = 80x80 px
# define ASSETS_SIZE 80

// Refresh rate
# define REFRESH 700

/* ---------- Structs ---------- */
typedef struct s_dinamicItem {
	void			**left_imgs;
	void			**right_imgs;
	char			state;
	unsigned int	pos_x;
	unsigned int	pos_y;
	unsigned int	pre_pos_x;
	unsigned int	pre_pos_y;
	char			direction;
}			t_dinamicItem;

typedef struct s_listItem {
	void				**imgs;
	unsigned int		pos_x;
	unsigned int		pos_y;
	struct s_listItem	*next;
}			t_listItem;

typedef struct s_exit {
	void			**idle_imgs;
	void			**bad_imgs;
	void			**good_imgs;
	char			state;
	unsigned int	pos_x;
	unsigned int	pos_y;
}			t_exit;

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
	void			*exit_img;
	void			**collectable_imgs;
	t_listItem		*collectables;
	t_dinamicItem	*player;
	t_exit			*exit;
	unsigned int	total_collectables;
	unsigned int	collected_collectables;
	unsigned int	moved;
	unsigned int	total_moves;
}			t_gui;


/* ---------- Functions ---------- */
// Utils

char			find_coor(char **map, unsigned int *x, unsigned int *y, char c);

// List

t_listItem		*listnew(unsigned int	pos_x, unsigned int	pos_y, void	**imgs);
t_listItem		*listdel(t_listItem **lst, unsigned int	pos_x, unsigned int	pos_y);
void			listadd(t_listItem **lst, t_listItem *new);
void			listfree(t_listItem **lst);

// Parsing map

unsigned int	total_char(char **map, char c);

char			is_closed_walls(char **map);
char			valid_chars(char **map);
char			valid_path(char **map);
char			is_valid_map(char **map);
char			**get_map(char *filepath);

// GUI

int				frame(t_gui *gui);
void			init_imgs(t_gui *gui);
int				init_map(t_gui *gui);
int				render_map(t_gui *gui);
char			move(int keycode, t_gui *gui);
int				key_hook(int keycode, t_gui *gui);
int				end_gui(t_gui	*gui);
char			start_gui(t_gui *gui);

void			init_collect_imgs(t_gui *gui);
void			init_playerl_imgs(t_gui *gui);
void			init_exit_idle_imgs(t_gui *gui);
void			init_exit_bad_imgs(t_gui *gui);
void			init_exit_good_imgs(t_gui *gui);
#endif
