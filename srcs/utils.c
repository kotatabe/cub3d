#include "../include/cub3d.h"

void	draw_back_ground(t_game *g)
{
	int x = 0;
	int y = 0;

	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			my_mlx_pixel_put(g, x, y, BROWN);
			x++;
		}
		x = 0;
		y++;
	}
}