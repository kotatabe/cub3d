#include "../include/cub3d.h"

int	key_player_move(int key, t_game *g)
{
	printf("key = %d\n", key);
	if (key == KEY_W)
		g->player.walk_dir = 1;
	if (key == KEY_S)
		g->player.walk_dir = -1;
	if (key == KEY_LEFT)
	{
		g->player.turn_dir--;
		printf("pa = %f\n", (g->player.pa / PI) * 180);
	}
	if (key == KEY_RIGHT)
	{
		g->player.turn_dir++;
		printf("pa = %f\n", (g->player.pa / PI) * 180);
	}
	if (key == KEY_ESC)
		exit(0);
	return(0);
}

int		ft_exit(int key, t_game *g)
{
	(void)g;
	printf("key = %d\n", key);
	exit(0);
	return (0);
}