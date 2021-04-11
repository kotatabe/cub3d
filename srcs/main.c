#include "../include/mlx.h"
#include "../include/cub3d.h"


void	my_mlx_pixel_put(t_game *g, int x, int y, int color)
{
	char *dst;

	dst = g->img_addr + (y * g->img_line_len + x * (g->img_bit_per_pix / 8));
	*(unsigned int*)dst = color;
}

void	update_pdata(t_game *g)
{
	double	new_px;
	double	new_py;
	double	move;

	g->player.pa += g->player.turn_dir * g->player.turn_speed;
	move = g->player.walk_dir * g->player.walk_speed;
	new_px = g->player.px + cos(g->player.pa) * move;
	new_py = g->player.py + sin(g->player.pa) * move;
	// ↓壁衝突判定
	g->player.px = new_px;
	g->player.py = new_py;
}

int map[10][10] = {
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 1, 1, 1, 1, 1, 0},
		{0, 1, 0, 0, 0, 0, 1, 0},
		{0, 1, 0, 0, 1, 0, 1, 0},
		{0, 1, 0, 0, 0, 0, 1, 0},
		{0, 1, 0, 0, 0, 0, 1, 0},
		{0, 1, 1, 1, 1, 1, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0}
};

void	put_map(t_game *g)
{
	int x = 0;
	int y = 0;

	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			if (map[y / GRID][x / GRID] == 1)
				my_mlx_pixel_put(g, x / SCALE, y / SCALE, WALL_COL);
			if (x % GRID == 0 || y % GRID == 0)
				my_mlx_pixel_put(g, x / SCALE, y / SCALE, SQUARE_COL);
			x += SCALE;
		}
		x = 0;
		y += SCALE;
	}
}

int		render(int key, t_game *g)
{
	draw_back_ground(g);
	key_player_move(key, g);
	update_pdata(g);
	// update_ray_data(g);
	put_map(g);
	put_fov(g);
	my_mlx_pixel_put(g, g->player.px, g->player.py, 0xFFFFFF);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_ptr, 0, 0);
	init_player_data(g);
	// printf("px = %f\n", g->player.px);
	// printf("py = %f\n", g->player.py);
	return(0);
}

void	ft_hooks(t_game *g)
{
	mlx_hook(g->win_ptr, 2, 0, render, g);
	mlx_hook(g->win_ptr, 17, 0, ft_exit, g);
	mlx_loop(g->mlx_ptr);
}

int main()
{
	printf("1\n");

	t_game g;

	init_game(&g);
	init_player_data(&g);
	ft_hooks(&g);

	return (0);
}
