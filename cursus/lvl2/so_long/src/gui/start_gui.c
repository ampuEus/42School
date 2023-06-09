#include "so_long.h"
#include "mlx.h"

char	start_gui(t_gui *gui)
{
	gui->mlx = mlx_init();
	gui->win = mlx_new_window(gui->mlx, gui->height, gui->width, "Bicho Blanco");
	render_map(gui);

	void	*img;
	int		img_width;
	int		img_height;
	gui->player_img = mlx_xpm_file_to_image(gui->mlx, PLAYER, &img_width, &img_height);
	mlx_put_image_to_window(gui->mlx, gui->win, gui->player_img, 160, 80);
	int		done;
	done = mlx_destroy_image(gui->mlx, gui->player_img);
	if (!done)
	{
		ft_putstr_fd("ERROR: Can't delete image\n", 2);
		end_gui(gui);
		return (done);
	}

	mlx_key_hook(gui->win, key_hook, gui);
	mlx_hook(gui->win, 17, 1L<<0, end_gui, gui);
	mlx_loop(gui->mlx);
	return (0);
}
