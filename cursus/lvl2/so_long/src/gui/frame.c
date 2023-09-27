#include "so_long.h"
#include "mlx.h"

static void	delete_item(t_gui *gui)
{
	mlx_put_image_to_window(gui->mlx, gui->win, gui->gnd1_img, \
	gui->player_pos_x, gui->player_pos_y);
}

static void	render_player(t_gui *gui, unsigned int cicle, char direction)
{
	unsigned int frame_nbr;

	frame_nbr = cicle % (PLAYER_IDLE_NBR - 1);
	if (cicle == (REFRESH * frame_nbr + 1))
	{
		delete_item(gui);
		if (direction)
			mlx_put_image_to_window(gui->mlx, gui->win, gui->player_l_img[frame_nbr], \
				gui->player_pos_x, gui->player_pos_y);
		else
			mlx_put_image_to_window(gui->mlx, gui->win, gui->player_l_img[frame_nbr], \
				gui->player_pos_x, gui->player_pos_y); // TODO hay que poner el R no el L
	}
}

	// char c;

	// c = gui->map[x / ASSETS_SIZE][y / ASSETS_SIZE];
	// if (cicle == (REFRESH * frame_nbr + 1))
	// {

	// 	mlx_put_image_to_window(gui->mlx, gui->win, gui->collectable_img_[frame_nbr], x, y);
	// 	if (c == COLLECTABLE)
	// 		c = 0;
	// }

int	frame(t_gui *gui)
{
	static unsigned int	cicle;

	cicle++;
	render_player(gui, cicle, 1);
	if (cicle == REFRESH)
		cicle = 0;
	return (0);
}
