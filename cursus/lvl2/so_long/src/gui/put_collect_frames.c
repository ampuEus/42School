#include "so_long.h"

static void	refresh_frame\
(t_gui *gui, unsigned int cicle, unsigned int frame_nbr, unsigned int x, unsigned int y)
{
	if (cicle == (REFRESH * frame_nbr + 1))
	{
		mlx_put_image_to_window(gui->mlx, gui->win, gui->gnd1_img, x, y);
		mlx_put_image_to_window(gui->mlx, gui->win, gui->collectable_img_[frame_nbr], x, y);
	}
	return ;
}

void	put_collect_frames(t_gui *gui, unsigned int x, unsigned int y)
{
	static unsigned int	cicle;
	static unsigned int	frame;
	char	is_refresh;

	cicle++;
	while (frame < COLLECT_NBR)
		refresh(gui, cicle, frame++, x, y);
	if (cicle == (REFRESH * 14))
		cicle = 0;
}
