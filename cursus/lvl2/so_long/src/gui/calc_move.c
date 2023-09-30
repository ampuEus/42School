#include "so_long.h"
#include "mlx.h"

/* The return is the direction */
static char	get_newpos(\
	int keycode, unsigned int *x, unsigned int *y, char *direction)
{
	if (keycode == KEY_LEFT)
	{
		*x -= ASSETS_SIZE;
		*direction = 1;
	}
	else if (keycode == KEY_RIGHT)
	{
		*x += ASSETS_SIZE;
		*direction = 0;
	}
	else if (keycode == KEY_DOWN)
		*y += ASSETS_SIZE;
	else if (keycode == KEY_UP)
		*y -= ASSETS_SIZE;
	return (*direction);
}

// /* on wall -> can't move
// on enemy -> dead
// on exit -> go
// on free space -> move */
// static char	whatis()
// {

// }

/* Look which is the player's next action.
Return:
	0 - Can move
	1 - There is a wall can't move
	2 - The player has reached the end */
static char make_action(t_gui *gui, unsigned int x, unsigned int y)
{
	if (gui->map[y][x] == WALL)
		return (1);
	if (gui->map[y][x] == COLLECTABLE)
	{
		gui->map[y][x] = FREE_SPACE;
		gui->collected++;
	}
	if (gui->map[y][x] == EXIT)
		return (2);
	// if exit + all C -> end
	// if enemy -> player dead
	return (0);
}

/* Calculate the position and action of the next input's move.
NOTE:
direction = 0 -> the plaer look to the right
direction = 1 -> the plaer look to the left */
char	calc_move(int keycode, t_gui *gui)
{
	char			action;

	if (!gui->player_pos_x && !gui->player_pos_y)
	{
		find_coor(gui->map, &gui->player_pos_x, &gui->player_pos_y, START_POS);
		gui->player_pos_x *= ASSETS_SIZE;
		gui->player_pos_y *= ASSETS_SIZE;
		gui->player_prepos_x *= ASSETS_SIZE;
		gui->player_prepos_y *= ASSETS_SIZE;
	}
	gui->player_prepos_x = gui->player_pos_x;
	gui->player_prepos_y = gui->player_pos_y;
	get_newpos(keycode, &gui->player_pos_x, &gui->player_pos_y, &gui->player_direction);
	action = make_action(gui, gui->player_pos_x/ASSETS_SIZE, gui->player_pos_y/ASSETS_SIZE);
	if (action != 0)
	{
		gui->player_pos_x = gui->player_prepos_x;
		gui->player_pos_y = gui->player_prepos_y;
	}
	ft_printf("x=%i, y=%i, letter=%c ", gui->player_pos_x/ASSETS_SIZE, gui->player_pos_y/ASSETS_SIZE, gui->map[gui->player_pos_y/ASSETS_SIZE][gui->player_pos_x/ASSETS_SIZE]);
	return (1);
}
