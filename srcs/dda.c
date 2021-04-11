#include "../include/cub3d.h"

int g_map[10][10] = {
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 1, 1, 1, 1, 1, 0},
		{0, 1, 0, 0, 0, 0, 1, 0},
		{0, 1, 0, 0, 1, 0, 1, 0},
		{0, 1, 0, 0, 0, 0, 1, 0},
		{0, 1, 0, 0, 0, 0, 1, 0},
		{0, 1, 1, 1, 1, 1, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0}
};

double	normalize_angle(double angle)
{
	angle = remainder(angle, 2 * PI);
	if (angle < 0)
	{
		angle += 2 * PI;
	}
	return (angle);
}

void	dda(t_game *g)
{
	double	hor_angle;

	normalize_angle(g->player.pa);
	if ()
		hor_angle = 0;
}
