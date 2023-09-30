#include "so_long.h"
#include "mlx.h"

static void	delete_item(t_gui *gui, int x, int y)
{
	mlx_put_image_to_window(gui->mlx, gui->win, gui->gnd1_img, x, y);
}

static void	render_player(t_gui *gui)
{
	static unsigned int frame_nbr;

	delete_item(gui, gui->player_prepos_x, gui->player_prepos_y);
	delete_item(gui, gui->player_pos_x, gui->player_pos_y);
	if (gui->player_direction)
		mlx_put_image_to_window(gui->mlx, gui->win, gui->player_l_img[frame_nbr], \
			gui->player_pos_x, gui->player_pos_y);
	else
		mlx_put_image_to_window(gui->mlx, gui->win, gui->player_l_img[frame_nbr], \
			gui->player_pos_x, gui->player_pos_y); // TODO hay que poner el R no el L
	if (frame_nbr++ == PLAYER_IDLE_NBR - 1)
		frame_nbr = 0;
}

static void	render_collectable(t_gui *gui, int x, int y)
{
	static unsigned int frame_nbr;

	delete_item(gui, x, y);
	mlx_put_image_to_window(gui->mlx, gui->win, gui->collectable_img[frame_nbr], \
		x, y);
	if (frame_nbr++ == COLLECT_NBR - 1)
		frame_nbr = 0;
}

int	frame(t_gui *gui)
{

	//TODO dale una vuelta porque con algo parecido a render map puede quedar decente
	render_player(gui);
	render_collectable(gui, 80, 80);
	render_collectable(gui, 160, 80);
	render_collectable(gui, 240, 80);
	render_collectable(gui, 320, 80);
	render_collectable(gui, 400, 80);
	render_collectable(gui, 480, 80);
	render_collectable(gui, 560, 80);
	render_collectable(gui, 640, 80);
	return (0);
}
