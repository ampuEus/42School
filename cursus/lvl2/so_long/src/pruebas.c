// gcc main.c -L ../lib/minilibx/minilibx_opengl/ -lmlx -framework OpenGL -framework AppKit
#include "../lib/minilibx/minilibx_opengl/mlx.h"
#include <unistd.h>
#include <stdlib.h>

char	end_gui(void *mlx, void *win)
{
	mlx_destroy_window(mlx, win);
	free(mlx);
	exit (0);
}


int	main(int argc, char *argv[])
{
	void	*mlx;
	void	*win;

	void	*img;
	int		img_width;
	int		img_height;

	int		done;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "window");

	img = mlx_xpm_file_to_image(mlx, argv[1], &img_width, &img_height);
	if (!img)
	{
		write(1, "ERROR img\n", 10);
		end_gui(mlx, win);
	}

	mlx_put_image_to_window(mlx, win, img, 160, 80);
	mlx_destroy_image(mlx, img);
	mlx_put_image_to_window(mlx, win, img, 160, 160);

	mlx_loop(mlx);
	return (0);
}
