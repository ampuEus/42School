#include "so_long.h"
#include "mlx.h"

/* The return is the direction:
0 - Right
1 - Left */
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
		gui->collectables = listdel(&gui->collectables, x, y);
		gui->map[y][x] = FREE_SPACE;
		gui->collected_collectables++;
	}
	if (gui->exit->state == GOOD)
		end_gui(gui);
	if (gui->map[y][x] == EXIT && gui->exit->state == IDLE)
		return (2);
	if (gui->map[y][x] == EXIT && gui->exit->state != IDLE)
	{
		gui->exit->state = GOOD;
		return (3);
	}
	if (gui->collectables == NULL)
		gui->exit->state = BAD;
	// TODO if enemy -> player dead
	return (0);
}

/* Calculate the position and action of the next input's move.
NOTE:
direction = 0 -> the player look to the right
direction = 1 -> the player look to the left */
char	calc_move(int keycode, t_gui *gui)
{
	char			action;

	if (!gui->player->pos_x && !gui->player->pos_y)
	{
		find_coor(gui->map, &gui->player->pos_x, &gui->player->pos_y, START_POS);
		gui->player->pos_x *= ASSETS_SIZE;
		gui->player->pos_y *= ASSETS_SIZE;
		gui->player->pre_pos_x *= gui->player->pos_x;
		gui->player->pre_pos_y *= gui->player->pos_y;
	}
	gui->player->pre_pos_x = gui->player->pos_x;
	gui->player->pre_pos_y = gui->player->pos_y;
	get_newpos(keycode, &gui->player->pos_x, &gui->player->pos_y, &gui->player->direction);
	action = make_action(gui, gui->player->pos_x/ASSETS_SIZE, gui->player->pos_y/ASSETS_SIZE);
	if (action != 0)
	{
		gui->player->pos_x = gui->player->pre_pos_x;
		gui->player->pos_y = gui->player->pre_pos_y;
	}
	ft_printf("x=%i, y=%i, letter=%c ", gui->player->pos_x/ASSETS_SIZE, gui->player->pos_y/ASSETS_SIZE, gui->map[gui->player->pos_y/ASSETS_SIZE][gui->player->pos_x/ASSETS_SIZE]);
	return (1);
}
