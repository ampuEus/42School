
#include "so_long.h"
#include "mlx.h"

#include <stdio.h>

int	delete_img(t_gui *gui, void *img)
{
	int		done;

	done = mlx_destroy_image(gui->mlx, img);
	if (!done)
	{
		ft_putstr_fd("ERROR: Can't delete image\n", 2);
		printf("img = %p", img);
		end_gui(gui);
		return (done);
	}
	return (done);
}

void	*render_img(t_gui *gui, char *filepath, int x, int y)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(gui->mlx, filepath, &img_width, &img_height);
	if (!img)
	{
		ft_putstr_fd("ERROR: See .xpm file\n", 2);
		end_gui(gui);
		return (img);
	}
	mlx_put_image_to_window(gui->mlx, gui->win, img, x, y);
	return (img);
}
