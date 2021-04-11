#ifndef CUB3D_H
# define CUB3D_H

#include "../include/mlx.h"
#include "../include/cub3d.h"
# include <stdio.h>
# include <unistd.h>
# include <math.h>
#include <stdlib.h>

# define HEIGHT		512
# define WIDTH		512
# define PI 		3.14159265
# define FOV		1.04719755
# define BROWN		0xc2af96
# define GREEN		0x00FF00
# define RED		0xFF0000
# define DARK_GREEN	0x005000
# define WALL_COL	0x727272
# define SQUARE_COL	0xFFFFFF
# define KEY_W		13
# define KEY_S		1
# define KEY_A		0
# define KEY_D		2
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_ESC	53
# define GRID		64
# define SCALE		1


typedef struct s_player
{
	double	turn_dir;
	double	turn_speed;
	double	walk_dir;
	double	walk_speed;
	double		px;
	double		py;
	double		pa;
	
}				t_player;

typedef struct	s_circle
{
	double	x;
	double	y;
	int		range;
}				t_circle;

typedef struct		s_directions {
	int				up;
	int				down;
	int				left;
	int				right;
}					t_directions;

typedef struct	s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	void			*img_addr;

	int				img_bit_per_pix;
	int				img_endian;
	int				img_line_len;


	t_player		player;
	t_directions	dir;

	int			height;
	int			width;
	int			*g_map;
}				t_game;

void	init_player_data(t_game *g);
int		ft_exit(int key, t_game *g);
int		key_player_move(int key, t_game *g);
void	init_game(t_game *g);
void	draw_back_ground(t_game *g);
void	my_mlx_pixel_put(t_game *g, int x, int y, int color);
void	put_ray(double angle, t_game *g, int color);
void	put_fov(t_game *g);



#endif