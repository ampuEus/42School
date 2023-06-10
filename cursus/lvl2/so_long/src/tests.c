// gcc main.c -L ../lib/minilibx/minilibx_opengl/ -lmlx -framework OpenGL -framework AppKit
#include "../lib/minilibx/minilibx_opengl/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

# define GND1 "./assets_80x80/grass_1.xpm"
# define GND2 "./assets_80x80/grass_2.xpm"
# define GND3 "./assets_80x80/grass_3.xpm"
# define GND4 "./assets_80x80/grass_4.xpm"

# define PUT 100

typedef struct s_gui {
	void	*mlx;
	void	*win;
	void	*gnd1_img;
	void	*gnd2_img;
	void	*gnd3_img;
	void	*gnd4_img;
}			t_gui;

char	end_gui(void *mlx, void *win)
{
	mlx_destroy_window(mlx, win);
	free(mlx);
	exit (0);
}

static void	player_status(void *mlx, t_gui *gui)
{
	mlx_put_image_to_window(gui->mlx, gui->win, gui->gnd1_img, PUT, PUT);
	// static unsigned int	cicle;

	// cicle = 0;
	// if (cicle <= 50)
	// 	mlx_put_image_to_window(gui->mlx, gui->win, gui->gnd1_img, PUT, PUT);
	// else if (50 < cicle && 100 <= cicle)
	// 	mlx_put_image_to_window(gui->mlx, gui->win, gui->gnd2_img, PUT, PUT);
	// else if (100 < cicle && 150 <= cicle)
	// 	mlx_put_image_to_window(gui->mlx, gui->win, gui->gnd3_img, PUT, PUT);
	// else
	// {
	// 	mlx_put_image_to_window(gui->mlx, gui->win, gui->gnd4_img, PUT, PUT);
	// 	cicle = 0;
	// }
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

	gui.gnd1_img = mlx_xpm_file_to_image(gui.mlx, GND1, &img_width, &img_height);
	// gui.gnd2_img = mlx_xpm_file_to_image(gui.mlx, GND2, &img_width, &img_height);
	// gui.gnd3_img = mlx_xpm_file_to_image(gui.mlx, GND3, &img_width, &img_height);
	// gui.gnd4_img = mlx_xpm_file_to_image(gui.mlx, GND4, &img_width, &img_height);

	mlx_loop_hook(gui.mlx, player_status, &gui);
	mlx_key_hook(gui.win, key_hook, &gui);
	mlx_loop(gui.mlx);
	return (0);
}
