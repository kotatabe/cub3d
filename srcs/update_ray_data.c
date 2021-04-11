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

// void	put_horizon_line(t_game *g)
// {
// 	double	ray_x;
// 	double	ray_y;
// 	double	angle;

// }

void	put_ray_in_range(double angle, t_game *g, int color, t_circle *c)
{
	int i = 1;
	double	ray_x;
	double	ray_y;

	ray_x = c->x;
	ray_y = c->y;
	while (i++ < c->range)
	{
		if (ray_y > HEIGHT / SCALE || ray_x > WIDTH / SCALE || 0 > ray_x|| 0 > ray_y)
			break ;
		ray_x = cos(angle) * i + c->x;
		ray_y = sin(angle) * i + c->y;
		my_mlx_pixel_put(g, ray_x, ray_y, color);
	}
}

void	put_circle(t_game *g, double x, double y, int range)
{
	double		start_angle;
	int			i;
	t_circle	c;

	c.range = range;
	c.x = x;
	c.y = y;
	i = 0;
	start_angle = PI;
	while (i < 360)
	{
		put_ray_in_range(start_angle, g, RED, &c);
		start_angle += PI / 180;
		i++;
	}
}

void	put_pa(t_game *g, int color)
{
	int		range = 1;
	double	ray_x;
	double	ray_y;

	ray_x = g->player.px;
	ray_y = g->player.py;
	while (range++)
	{
		if (ray_y > (HEIGHT / SCALE) || ray_x > (WIDTH / SCALE) || 0 > ray_x|| 0 > ray_y)
			break ;
		ray_x = cos(g->player.pa) * range + g->player.px;
		ray_y = sin(g->player.pa) * range + g->player.py;
		if ((int)ray_x % (GRID / SCALE) == 0 || (int)ray_y % (GRID / SCALE) == 0)
			put_circle(g, ray_x, ray_y, 3);
		else
		my_mlx_pixel_put(g, ray_x, ray_y, color);
	}
}

void	put_ray(double angle, t_game *g, int color)
{
	int range = 1;
	double	ray_x;
	double	ray_y;

	ray_x = g->player.px;
	ray_y = g->player.py;
	while (range++)
	{
		if (g_map[(int)ray_y / (GRID / SCALE)][(int)ray_x / (GRID / SCALE)] != 0 || ray_y > HEIGHT / SCALE || ray_x > WIDTH / SCALE || 0 > ray_x|| 0 > ray_y)
			break ;
		ray_x = cos(angle) * range + g->player.px;
		ray_y = sin(angle) * range + g->player.py;
		my_mlx_pixel_put(g, ray_x, ray_y, color);
	}
}
// FOV:60°　ラジアン＝PI / 3
void	put_fov(t_game *g)
{
	double	ray_angle;
	int		num_rays;
	int		i;

	ray_angle = g->player.pa - (FOV / 2);
	num_rays = g->width;
	i = 0;
	while (i < num_rays)
	{
		if (i == 0 || i == num_rays - 1)
			put_ray(ray_angle, g, DARK_GREEN);
		else
			put_ray(ray_angle, g, GREEN);
		ray_angle += FOV / num_rays;
		i++;
	}
	put_ray(g->player.pa, g, DARK_GREEN);
	// put_ray(0, g, DARK_GREEN);
	// put_ray(PI, g, DARK_GREEN);
	// put_ray(g->player.pa - (PI / 4), g, DARK_GREEN);
	put_pa(g, RED);
}