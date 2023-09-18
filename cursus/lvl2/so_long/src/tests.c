// gcc tests.c -L ../lib/minilibx/minilibx_opengl/ -lmlx -framework OpenGL -framework AppKit && ./a.out
// gcc tests.c -L ../lib/minilibx/minilibx-linux/ -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz && ./a.out
//#include "../lib/minilibx/minilibx_opengl/mlx.h"
#include "../lib/minilibx/minilibx-linux/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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

# define PLAYER_IDLE_NBR 14
# define PLAYER_IDLE_L00 "../assets_80x80/twelve/idle/frame00.xpm"
# define PLAYER_IDLE_L01 "../assets_80x80/twelve/idle/frame01.xpm"
# define PLAYER_IDLE_L02 "../assets_80x80/twelve/idle/frame02.xpm"
# define PLAYER_IDLE_L03 "../assets_80x80/twelve/idle/frame03.xpm"
# define PLAYER_IDLE_L04 "../assets_80x80/twelve/idle/frame04.xpm"
# define PLAYER_IDLE_L05 "../assets_80x80/twelve/idle/frame05.xpm"
# define PLAYER_IDLE_L06 "../assets_80x80/twelve/idle/frame06.xpm"
# define PLAYER_IDLE_L07 "../assets_80x80/twelve/idle/frame07.xpm"
# define PLAYER_IDLE_L08 "../assets_80x80/twelve/idle/frame08.xpm"
# define PLAYER_IDLE_L09 "../assets_80x80/twelve/idle/frame09.xpm"
# define PLAYER_IDLE_L10 "../assets_80x80/twelve/idle/frame10.xpm"
# define PLAYER_IDLE_L11 "../assets_80x80/twelve/idle/frame11.xpm"
# define PLAYER_IDLE_L12 "../assets_80x80/twelve/idle/frame12.xpm"
# define PLAYER_IDLE_L13 "../assets_80x80/twelve/idle/frame13.xpm"

# define GND1 "../assets_80x80/gnd/gnd_1.xpm"
# define GND2 "../assets_80x80/gnd/gnd_2.xpm"
# define GND3 "../assets_80x80/gnd/gnd_3.xpm"
# define GND4 "../assets_80x80/gnd/gnd_4.xpm"

# define ASSETS_SIZE 80
# define PUT 100
# define REFRESH 700

typedef struct s_gui {
	void	*mlx;
	void	*win;
	unsigned int	x;
	unsigned int	y;
	void	**twelve_idle[14];
	void	**gnd[4];
}			t_gui;

char	end_gui(t_gui *gui)
{
	mlx_destroy_window(gui->mlx, gui->win);
	free(gui->mlx);
	exit (0);
}

static void	refresh(t_gui *gui, unsigned int cicle, unsigned int frame_nbr, int x, int y)
{
	if (cicle == (REFRESH * frame_nbr + 1))
	{
		mlx_put_image_to_window(gui->mlx, gui->win, gui->gnd[0], x, y);
		mlx_put_image_to_window(gui->mlx, gui->win, gui->twelve_idle[frame_nbr], x, y);
	}
	return ;
}

static void	player_status(t_gui *gui)
{
	static unsigned int	cicle;
	char	is_refresh;

	cicle++;
	refresh(gui, cicle, 0, gui->x, gui->y);
	refresh(gui, cicle, 1, gui->x, gui->y);
	refresh(gui, cicle, 2, gui->x, gui->y);
	refresh(gui, cicle, 3, gui->x, gui->y);
	refresh(gui, cicle, 4, gui->x, gui->y);
	refresh(gui, cicle, 5, gui->x, gui->y);
	refresh(gui, cicle, 6, gui->x, gui->y);
	refresh(gui, cicle, 7, gui->x, gui->y);
	refresh(gui, cicle, 8, gui->x, gui->y);
	refresh(gui, cicle, 9, gui->x, gui->y);
	refresh(gui, cicle, 10, gui->x, gui->y);
	refresh(gui, cicle, 11, gui->x, gui->y);
	refresh(gui, cicle, 12, gui->x, gui->y);
	refresh(gui, cicle, 13, gui->x, gui->y);
	if (cicle == (REFRESH * 14))
		cicle = 0;
	return ;
}

static char	get_newpos(\
	int keycode, unsigned int *x, unsigned int *y, char *direction)
{
	if (keycode == KEY_LEFT)
	{
		*x -= ASSETS_SIZE;
		*direction = 1;
	}
	else if (keycode == KEY_RIGHT)
	{
		*x += ASSETS_SIZE;
		*direction = 0;
	}
	else if (keycode == KEY_DOWN)
		*y += ASSETS_SIZE;
	else if (keycode == KEY_UP)
		*y -= ASSETS_SIZE;
	return (*direction);
}

char	move(int keycode, t_gui *gui)
{
	static char			direction;
	char				action;

	if (!gui->x && !gui->y)
	{
		gui->x *= ASSETS_SIZE;
		gui->y *= ASSETS_SIZE;
	}
	if (!direction)
		direction = 0;
	get_newpos(keycode, &gui->x, &gui->y, &direction);
	return (1);
}

int	key_hook(int keycode, t_gui *gui)
{
	static unsigned int	moves;
	int					is_move;

	is_move = 0;
	if (keycode == KEY_ESC || keycode == KEY_ESC_L)
		end_gui(gui);
	else if (keycode == KEY_LEFT || keycode == KEY_LEFT_L)
		is_move = move(KEY_LEFT, gui);
	else if (keycode == KEY_RIGHT || keycode == KEY_RIGHT_L)
		is_move = move(KEY_RIGHT, gui);
	else if (keycode == KEY_DOWN || keycode == KEY_DOWN_L)
		is_move = move(KEY_DOWN, gui);
	else if (keycode == KEY_UP || keycode == KEY_UP_L)
		is_move = move(KEY_UP, gui);
	else
		printf("No Hooked key = %i\n", keycode);
	if (!moves)
		moves = 0;
	if (is_move)
		printf("Total movement number %i\n", ++moves);
	return (keycode);
}

int	main(int argc, char *argv[])
{
	t_gui	gui;
	int		img_width;
	int		img_height;

	gui.mlx = mlx_init();
	gui.win = mlx_new_window(gui.mlx, 500, 500, "window");

	gui.twelve_idle[0] = mlx_xpm_file_to_image(gui.mlx, PLAYER_IDLE_L00, &img_width, &img_height);
	gui.twelve_idle[1] = mlx_xpm_file_to_image(gui.mlx, PLAYER_IDLE_L01, &img_width, &img_height);
	gui.twelve_idle[2] = mlx_xpm_file_to_image(gui.mlx, PLAYER_IDLE_L02, &img_width, &img_height);
	gui.twelve_idle[3] = mlx_xpm_file_to_image(gui.mlx, PLAYER_IDLE_L03, &img_width, &img_height);
	gui.twelve_idle[4] = mlx_xpm_file_to_image(gui.mlx, PLAYER_IDLE_L04, &img_width, &img_height);
	gui.twelve_idle[5] = mlx_xpm_file_to_image(gui.mlx, PLAYER_IDLE_L05, &img_width, &img_height);
	gui.twelve_idle[6] = mlx_xpm_file_to_image(gui.mlx, PLAYER_IDLE_L06, &img_width, &img_height);
	gui.twelve_idle[7] = mlx_xpm_file_to_image(gui.mlx, PLAYER_IDLE_L07, &img_width, &img_height);
	gui.twelve_idle[8] = mlx_xpm_file_to_image(gui.mlx, PLAYER_IDLE_L08, &img_width, &img_height);
	gui.twelve_idle[9] = mlx_xpm_file_to_image(gui.mlx, PLAYER_IDLE_L09, &img_width, &img_height);
	gui.twelve_idle[10] = mlx_xpm_file_to_image(gui.mlx, PLAYER_IDLE_L10, &img_width, &img_height);
	gui.twelve_idle[11] = mlx_xpm_file_to_image(gui.mlx, PLAYER_IDLE_L11, &img_width, &img_height);
	gui.twelve_idle[12] = mlx_xpm_file_to_image(gui.mlx, PLAYER_IDLE_L12, &img_width, &img_height);
	gui.twelve_idle[13] = mlx_xpm_file_to_image(gui.mlx, PLAYER_IDLE_L13, &img_width, &img_height);
	gui.gnd[0] = mlx_xpm_file_to_image(gui.mlx, GND1, &img_width, &img_height);
	gui.gnd[1] = mlx_xpm_file_to_image(gui.mlx, GND2, &img_width, &img_height);
	gui.gnd[2] = mlx_xpm_file_to_image(gui.mlx, GND3, &img_width, &img_height);
	gui.gnd[3] = mlx_xpm_file_to_image(gui.mlx, GND4, &img_width, &img_height);

	mlx_loop_hook(gui.mlx, player_status, &gui);
	mlx_key_hook(gui.win, key_hook, &gui);
	mlx_loop(gui.mlx);
	return (0);
}
