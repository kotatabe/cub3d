/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoubo <mkokubo@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:56:26 by mkokubo           #+#    #+#             */
/*   Updated: 2020/12/13 20:11:12 by mkoubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_rotation_angle(char c, t_data *data)
{
	if (c == 'E')
		data->player.rotation_angle = 0 * PI / 180;
	if (c == 'S')
		data->player.rotation_angle = 90 * PI / 180;
	if (c == 'W')
		data->player.rotation_angle = 180 * PI / 180;
	if (c == 'N')
		data->player.rotation_angle = 270 * PI / 180;
}

void	set_player_coordinate(t_data *data)
{
	int x;
	int y;

	x = TILE_SIZE * data->map.x + TILE_SIZE / 2;
	y = TILE_SIZE * data->map.y + TILE_SIZE / 2;
	data->player.x = x;
	data->player.y = y;
}

int		is_news(char c)
{
	if (c == 'N' || c == 'S' ||
			c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	serch_player_info(char **map, t_data *data)
{
	int i;
	int j;
	int cnt_player;

	cnt_player = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_news(map[i][j]))
			{
				data->map.x = j;
				data->map.y = i;
				cnt_player++;
				if (cnt_player > 1)
					my_exit("Duplicate Player", 1);
				set_player_coordinate(data);
				set_player_rotation_angle(map[i][j], data);
			}
			j++;
		}
		i++;
	}
}

void	conversion_player_to_map_val(char **map, t_data *data)
{
	int x;
	int y;

	x = data->map.x;
	y = data->map.y;
	map[y][x] = '0';
}
