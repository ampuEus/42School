
#include "so_long.h"
#include "mlx.h"

char	render_img(t_gui *gui, char *filepath, int x, int y)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(gui->mlx, filepath, &img_width, &img_height);
	if (!img)
	{
		ft_putstr_fd("ERROR: See .xpm file\n", 2);
		end_gui(gui);
		return (-1);
	}
	mlx_put_image_to_window(gui->mlx, gui->win, img, x, y);
	return (0);
}
