#include "so_long.h"
#include "mlx.h"

static void	init_00(t_gui *gui)
{
	int	img_width;
	int	img_height;

	gui->collectable_img[0] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT00, &img_width, &img_height);
	gui->collectable_img[1] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT01, &img_width, &img_height);
	gui->collectable_img[2] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT02, &img_width, &img_height);
	gui->collectable_img[3] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT03, &img_width, &img_height);
	gui->collectable_img[4] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT04, &img_width, &img_height);
	gui->collectable_img[5] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT05, &img_width, &img_height);
	gui->collectable_img[6] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT06, &img_width, &img_height);
	gui->collectable_img[7] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT07, &img_width, &img_height);
	gui->collectable_img[8] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT08, &img_width, &img_height);
	gui->collectable_img[9] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT09, &img_width, &img_height);
}

static void	init_10(t_gui *gui)
{
	int	img_width;
	int	img_height;

	gui->collectable_img[10] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT10, &img_width, &img_height);
	gui->collectable_img[11] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT11, &img_width, &img_height);
	gui->collectable_img[12] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT12, &img_width, &img_height);
	gui->collectable_img[13] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT13, &img_width, &img_height);
	gui->collectable_img[14] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT14, &img_width, &img_height);
	gui->collectable_img[15] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT15, &img_width, &img_height);
	gui->collectable_img[16] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT16, &img_width, &img_height);
	gui->collectable_img[17] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT17, &img_width, &img_height);
	gui->collectable_img[18] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT18, &img_width, &img_height);
	gui->collectable_img[19] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT19, &img_width, &img_height);
}

static void	init_20(t_gui *gui)
{
	int	img_width;
	int	img_height;

	gui->collectable_img[20] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT20, &img_width, &img_height);
	gui->collectable_img[21] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT21, &img_width, &img_height);
	gui->collectable_img[22] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT22, &img_width, &img_height);
	gui->collectable_img[23] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT23, &img_width, &img_height);
	gui->collectable_img[24] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT24, &img_width, &img_height);
	gui->collectable_img[25] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT25, &img_width, &img_height);
	gui->collectable_img[26] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT26, &img_width, &img_height);
	gui->collectable_img[27] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT27, &img_width, &img_height);
	gui->collectable_img[28] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT28, &img_width, &img_height);
	gui->collectable_img[29] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT29, &img_width, &img_height);
}

static void	init_30(t_gui *gui)
{
	int	img_width;
	int	img_height;

	gui->collectable_img[30] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT30, &img_width, &img_height);
	gui->collectable_img[31] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT31, &img_width, &img_height);
	gui->collectable_img[32] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT32, &img_width, &img_height);
}

void	init_collect_imgs(t_gui *gui)
{
	gui->collectable_img = malloc(COLLECT_NBR * sizeof(*gui->collectable_img));
	init_00(gui);
	init_10(gui);
	init_20(gui);
	init_30(gui);
}
