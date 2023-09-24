#include "so_long.h"
#include "mlx.h"

static void	init_00(t_gui *gui)
{
	int	img_width;
	int	img_height;

	gui->collectable_img_[0] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT01, &img_width, &img_height);
	gui->collectable_img_[1] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT02, &img_width, &img_height);
	gui->collectable_img_[2] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT03, &img_width, &img_height);
	gui->collectable_img_[3] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT04, &img_width, &img_height);
	gui->collectable_img_[4] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT05, &img_width, &img_height);
	gui->collectable_img_[5] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT06, &img_width, &img_height);
	gui->collectable_img_[6] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT07, &img_width, &img_height);
	gui->collectable_img_[7] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT08, &img_width, &img_height);
	gui->collectable_img_[8] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT09, &img_width, &img_height);
	gui->collectable_img_[9] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT10, &img_width, &img_height);
}

static void	init_10(t_gui *gui)
{
	int	img_width;
	int	img_height;

	gui->collectable_img_[10] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT11, &img_width, &img_height);
	gui->collectable_img_[11] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT12, &img_width, &img_height);
	gui->collectable_img_[12] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT13, &img_width, &img_height);
	gui->collectable_img_[13] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT14, &img_width, &img_height);
	gui->collectable_img_[14] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT15, &img_width, &img_height);
	gui->collectable_img_[15] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT16, &img_width, &img_height);
	gui->collectable_img_[16] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT17, &img_width, &img_height);
	gui->collectable_img_[17] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT18, &img_width, &img_height);
	gui->collectable_img_[18] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT19, &img_width, &img_height);
	gui->collectable_img_[19] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT20, &img_width, &img_height);
}

static void	init_20(t_gui *gui)
{
	int	img_width;
	int	img_height;

	gui->collectable_img_[20] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT21, &img_width, &img_height);
	gui->collectable_img_[21] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT22, &img_width, &img_height);
	gui->collectable_img_[22] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT23, &img_width, &img_height);
	gui->collectable_img_[23] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT24, &img_width, &img_height);
	gui->collectable_img_[24] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT25, &img_width, &img_height);
	gui->collectable_img_[25] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT26, &img_width, &img_height);
	gui->collectable_img_[26] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT27, &img_width, &img_height);
	gui->collectable_img_[27] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT28, &img_width, &img_height);
	gui->collectable_img_[28] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT29, &img_width, &img_height);
	gui->collectable_img_[29] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT30, &img_width, &img_height);
}

static void	init_30(t_gui *gui)
{
	int	img_width;
	int	img_height;

	gui->collectable_img_[30] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT31, &img_width, &img_height);
	gui->collectable_img_[31] = mlx_xpm_file_to_image(\
		gui->mlx, COLLECT32, &img_width, &img_height);
}

void	init_collect_imgs(t_gui *gui)
{
	gui->collectable_img_ = malloc(COLLECT_NBR * sizeof(*gui->collectable_img_));
	init_00(gui);
	init_10(gui);
	init_20(gui);
	init_30(gui);
}
