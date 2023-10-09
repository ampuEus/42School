#include "so_long.h"
#include "mlx.h"

static void	delete_item(t_gui *gui, int x, int y)
{
	mlx_put_image_to_window(gui->mlx, gui->win, gui->gnd1_img, x, y);
}

static void	render_player(t_gui *gui)
{
	static unsigned int	frame_nbr;

	delete_item(gui, gui->player->pre_pos_x, gui->player->pre_pos_y);
	delete_item(gui, gui->player->pos_x, gui->player->pos_y);
	if (gui->player->direction)
		mlx_put_image_to_window(gui->mlx, gui->win, gui->player->left_imgs[frame_nbr], \
			gui->player->pos_x, gui->player->pos_y);
	else
		mlx_put_image_to_window(gui->mlx, gui->win, gui->player->left_imgs[frame_nbr], \
			gui->player->pos_x, gui->player->pos_y); // TODO hay que poner el R no el L
	if (frame_nbr++ == PLAYER_IDLE_NBR - 1)
		frame_nbr = 0;
}

static void	render_exit(t_gui *gui)
{
	static unsigned int	frame_nbr;

	delete_item(gui, gui->exit->pos_x, gui->exit->pos_y);
	// if state = idle
	mlx_put_image_to_window(gui->mlx, gui->win, gui->exit->idle_imgs[frame_nbr], \
		gui->exit->pos_x, gui->exit->pos_y);
	// TODO:
	// else if state = good
	// else if state = bad
	if (frame_nbr++ == Q_IDLE_NBR - 1)
		frame_nbr = 0;
}

static void	render_collectable(t_gui *gui)
{
	static unsigned int	frame_nbr;
	t_listItem			*lst;

	lst = gui->collectables;
	while (lst)
	{
		delete_item(gui, lst->pos_x, lst->pos_y);
		mlx_put_image_to_window(gui->mlx, gui->win, lst->imgs[frame_nbr], \
			lst->pos_x, lst->pos_y);
		if (frame_nbr++ == COLLECT_NBR - 1)
			frame_nbr = 0;
		lst = lst->next;
	}
}

int	frame(t_gui *gui)
{
	static unsigned int cicle;

	if (!cicle)
	{
		render_player(gui);
		render_exit(gui);
		render_collectable(gui);
		gui->moved = 1;
	}
	cicle++;
	if (cicle == REFRESH)
		cicle = 0;

	return (0);
}
