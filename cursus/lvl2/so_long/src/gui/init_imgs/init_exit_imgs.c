#include "so_long.h"
#include "mlx.h"

/* TODO
Sería recomendable chequear si se ha cargado bien la imagen*/

static void	init_00(t_gui *gui)
{
	int	img_width;
	int	img_height;

	gui->exit->idle_imgs[0] = mlx_xpm_file_to_image(\
		gui->mlx, Q_IDLE00, &img_width, &img_height);
	gui->exit->idle_imgs[1] = mlx_xpm_file_to_image(\
		gui->mlx, Q_IDLE01, &img_width, &img_height);
	gui->exit->idle_imgs[2] = mlx_xpm_file_to_image(\
		gui->mlx, Q_IDLE02, &img_width, &img_height);
	gui->exit->idle_imgs[3] = mlx_xpm_file_to_image(\
		gui->mlx, Q_IDLE03, &img_width, &img_height);
	gui->exit->idle_imgs[4] = mlx_xpm_file_to_image(\
		gui->mlx, Q_IDLE04, &img_width, &img_height);
	gui->exit->idle_imgs[5] = mlx_xpm_file_to_image(\
		gui->mlx, Q_IDLE05, &img_width, &img_height);
	gui->exit->idle_imgs[6] = mlx_xpm_file_to_image(\
		gui->mlx, Q_IDLE06, &img_width, &img_height);
	gui->exit->idle_imgs[7] = mlx_xpm_file_to_image(\
		gui->mlx, Q_IDLE07, &img_width, &img_height);
	gui->exit->idle_imgs[8] = mlx_xpm_file_to_image(\
		gui->mlx, Q_IDLE08, &img_width, &img_height);
	gui->exit->idle_imgs[9] = mlx_xpm_file_to_image(\
		gui->mlx, Q_IDLE09, &img_width, &img_height);
}

static void	init_10(t_gui *gui)
{
	int	img_width;
	int	img_height;

	gui->exit->idle_imgs[10] = mlx_xpm_file_to_image(\
		gui->mlx, Q_IDLE10, &img_width, &img_height);
	gui->exit->idle_imgs[11] = mlx_xpm_file_to_image(\
		gui->mlx, Q_IDLE11, &img_width, &img_height);
	gui->exit->idle_imgs[12] = mlx_xpm_file_to_image(\
		gui->mlx, Q_IDLE12, &img_width, &img_height);
	gui->exit->idle_imgs[13] = mlx_xpm_file_to_image(\
		gui->mlx, Q_IDLE13, &img_width, &img_height);
	gui->exit->idle_imgs[14] = mlx_xpm_file_to_image(\
		gui->mlx, Q_IDLE14, &img_width, &img_height);
	gui->exit->idle_imgs[15] = mlx_xpm_file_to_image(\
		gui->mlx, Q_IDLE15, &img_width, &img_height);
	gui->exit->idle_imgs[16] = mlx_xpm_file_to_image(\
		gui->mlx, Q_IDLE16, &img_width, &img_height);
	gui->exit->idle_imgs[17] = mlx_xpm_file_to_image(\
		gui->mlx, Q_IDLE17, &img_width, &img_height);
	gui->exit->idle_imgs[18] = mlx_xpm_file_to_image(\
		gui->mlx, Q_IDLE18, &img_width, &img_height);
	gui->exit->idle_imgs[19] = mlx_xpm_file_to_image(\
		gui->mlx, Q_IDLE19, &img_width, &img_height);
}

static void	init_20(t_gui *gui)
{
	int	img_width;
	int	img_height;

	gui->exit->idle_imgs[20] = mlx_xpm_file_to_image(\
		gui->mlx, Q_IDLE20, &img_width, &img_height);
	gui->exit->idle_imgs[21] = mlx_xpm_file_to_image(\
		gui->mlx, Q_IDLE21, &img_width, &img_height);
}

void	init_exit_imgs(t_gui *gui)
{
	gui->exit = malloc(sizeof(*gui->exit));
	gui->exit->idle_imgs = malloc(Q_IDLE_NBR * sizeof(*gui->exit->idle_imgs));
	init_00(gui);
	init_10(gui);
	init_20(gui);
}
