#include "../include/cub3d.h"

void	init_game(t_game *g)
{
	g->height = HEIGHT;
	g->width = WIDTH;

	g->player.px  = 200;
	g->player.py = 200;
	g->player.pa = 0;

	g->mlx_ptr = mlx_init();
	g->win_ptr = mlx_new_window(g->mlx_ptr, g->width, g->height, "cub3d");
	g->img_ptr = mlx_new_image(g->mlx_ptr, g->width, g->height);
	g->img_addr = mlx_get_data_addr(g->img_ptr, &g->img_bit_per_pix, &g->img_line_len, &g->img_endian);
}

void	init_player_data(t_game *g)
{
	g->player.turn_dir = 0;
	g->player.walk_dir = 0;
	g->player.walk_speed = 6;
	g->player.turn_speed = 5 * (PI / 180);
}
