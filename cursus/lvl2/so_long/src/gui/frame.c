#include "so_long.h"
#include "mlx.h"

static void	refresh(t_gui *gui, unsigned int cicle, unsigned int frame_nbr, int x, int y)
{
	char c;

	c = gui->map[x / ASSETS_SIZE][y / ASSETS_SIZE];
		mlx_put_image_to_window(gui->mlx, gui->win, gui->gnd1_img, x, y);
		mlx_put_image_to_window(gui->mlx, gui->win, gui->player_l_img[frame_nbr], x, y);
	if (cicle == (REFRESH * frame_nbr + 1))
	{

		mlx_put_image_to_window(gui->mlx, gui->win, gui->collectable_img_[frame_nbr], x, y);
		if (c == COLLECTABLE)
			c = 0;
	}
}

int	frame(t_gui *gui)
{
	static unsigned int	cicle;

	cicle++;
	refresh(gui, cicle, cicle, gui->player_pos_x, gui->player_pos_y);
	//mlx_put_image_to_window(gui->mlx, gui->win, gui->collectable_img_[cicle], 160, 240);
	//if (cicle == (REFRESH * 14))
	if (cicle == PLAYER_IDLE_NBR)
		cicle = 0;
	return (0);
}
