// gcc tests.c -L ../lib/minilibx/minilibx_opengl/ -lmlx -framework OpenGL -framework AppKit && ./a.out
#include "../lib/minilibx/minilibx_opengl/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

# define GND1 "../assets_80x80/gnd/gnd_1.xpm"
# define GND2 "../assets_80x80/gnd/gnd_2.xpm"
# define GND3 "../assets_80x80/gnd/gnd_3.xpm"
# define GND4 "../assets_80x80/gnd/gnd_4.xpm"

# define PUT 100
# define REFRESH 700

typedef struct s_gui {
	void	*mlx;
	void	*win;
	void	**twelve_idle[14];
	void	**gnd[4];
}			t_gui;

char	end_gui(void *mlx, void *win)
{
	mlx_destroy_window(mlx, win);
	free(mlx);
	exit (0);
}

static void	refresh(t_gui *gui, unsigned int cicle, unsigned int frame_nbr, int x, int y)
{
	if (cicle == (REFRESH * frame_nbr + 1))
	{
		mlx_put_image_to_window(gui->mlx, gui->win, gui->gnd[0], PUT, PUT);
		mlx_put_image_to_window(gui->mlx, gui->win, gui->twelve_idle[frame_nbr], PUT, PUT);
	}
	return ;
}

static void	player_status(t_gui *gui)
{
	static unsigned int	cicle;
	char	is_refresh;

	cicle++;
	refresh(gui, cicle, 0, PUT, PUT);
	refresh(gui, cicle, 1, PUT, PUT);
	refresh(gui, cicle, 2, PUT, PUT);
	refresh(gui, cicle, 3, PUT, PUT);
	refresh(gui, cicle, 4, PUT, PUT);
	refresh(gui, cicle, 5, PUT, PUT);
	refresh(gui, cicle, 6, PUT, PUT);
	refresh(gui, cicle, 7, PUT, PUT);
	refresh(gui, cicle, 8, PUT, PUT);
	refresh(gui, cicle, 9, PUT, PUT);
	refresh(gui, cicle, 10, PUT, PUT);
	refresh(gui, cicle, 11, PUT, PUT);
	refresh(gui, cicle, 12, PUT, PUT);
	refresh(gui, cicle, 13, PUT, PUT);
	if (cicle == (REFRESH * 14))
		cicle = 0;
}

static void	key_hook(int keycode, t_gui *gui)
{
	printf("\n---------- ---------- key_hook ---------- ----------\n");
}

int	main(int argc, char *argv[])
{
	t_gui	gui;
	int		img_width;
	int		img_height;

	gui.mlx = mlx_init();
	gui.win = mlx_new_window(gui.mlx, 500, 500, "window");

	gui.twelve_idle[0] = mlx_xpm_file_to_image(gui.mlx, "../assets_80x80/Twelve_idle/frame_00_delay-0.08s.xpm", &img_width, &img_height);
	gui.twelve_idle[1] = mlx_xpm_file_to_image(gui.mlx, "../assets_80x80/Twelve_idle/frame_01_delay-0.08s.xpm", &img_width, &img_height);
	gui.twelve_idle[2] = mlx_xpm_file_to_image(gui.mlx, "../assets_80x80/Twelve_idle/frame_02_delay-0.08s.xpm", &img_width, &img_height);
	gui.twelve_idle[3] = mlx_xpm_file_to_image(gui.mlx, "../assets_80x80/Twelve_idle/frame_03_delay-0.08s.xpm", &img_width, &img_height);
	gui.twelve_idle[4] = mlx_xpm_file_to_image(gui.mlx, "../assets_80x80/Twelve_idle/frame_04_delay-0.08s.xpm", &img_width, &img_height);
	gui.twelve_idle[5] = mlx_xpm_file_to_image(gui.mlx, "../assets_80x80/Twelve_idle/frame_05_delay-0.08s.xpm", &img_width, &img_height);
	gui.twelve_idle[6] = mlx_xpm_file_to_image(gui.mlx, "../assets_80x80/Twelve_idle/frame_06_delay-0.08s.xpm", &img_width, &img_height);
	gui.twelve_idle[7] = mlx_xpm_file_to_image(gui.mlx, "../assets_80x80/Twelve_idle/frame_07_delay-0.08s.xpm", &img_width, &img_height);
	gui.twelve_idle[8] = mlx_xpm_file_to_image(gui.mlx, "../assets_80x80/Twelve_idle/frame_08_delay-0.08s.xpm", &img_width, &img_height);
	gui.twelve_idle[9] = mlx_xpm_file_to_image(gui.mlx, "../assets_80x80/Twelve_idle/frame_09_delay-0.08s.xpm", &img_width, &img_height);
	gui.twelve_idle[10] = mlx_xpm_file_to_image(gui.mlx, "../assets_80x80/Twelve_idle/frame_10_delay-0.08s.xpm", &img_width, &img_height);
	gui.twelve_idle[11] = mlx_xpm_file_to_image(gui.mlx, "../assets_80x80/Twelve_idle/frame_11_delay-0.08s.xpm", &img_width, &img_height);
	gui.twelve_idle[12] = mlx_xpm_file_to_image(gui.mlx, "../assets_80x80/Twelve_idle/frame_12_delay-0.08s.xpm", &img_width, &img_height);
	gui.twelve_idle[13] = mlx_xpm_file_to_image(gui.mlx, "../assets_80x80/Twelve_idle/frame_13_delay-0.08s.xpm", &img_width, &img_height);
	gui.gnd[0] = mlx_xpm_file_to_image(gui.mlx, GND1, &img_width, &img_height);
	gui.gnd[1] = mlx_xpm_file_to_image(gui.mlx, GND2, &img_width, &img_height);
	gui.gnd[2] = mlx_xpm_file_to_image(gui.mlx, GND3, &img_width, &img_height);
	gui.gnd[3] = mlx_xpm_file_to_image(gui.mlx, GND4, &img_width, &img_height);


	// gui.gnd2_img = mlx_xpm_file_to_image(gui.mlx, GND2, &img_width, &img_height);
	// gui.gnd3_img = mlx_xpm_file_to_image(gui.mlx, GND3, &img_width, &img_height);
	// gui.gnd4_img = mlx_xpm_file_to_image(gui.mlx, GND4, &img_width, &img_height);

	mlx_loop_hook(gui.mlx, player_status, &gui);
	mlx_key_hook(gui.win, key_hook, &gui);
	mlx_loop(gui.mlx);
	return (0);
}
