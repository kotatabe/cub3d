/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoubo <mkokubo@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:39:44 by mkokubo           #+#    #+#             */
/*   Updated: 2020/12/11 23:58:11 by mkoubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		**conversion_c_map_to_i_map(char **c_map, t_data *data)
{
	int i;
	int **i_map;

	i_map = malloc(sizeof(int *) * data->map.num_cols);
	i = 0;
	while (c_map[i])
	{
		i_map[i] = cptoip(c_map[i]);
		i++;
	}
	return (i_map);
}

int		get_count_sprite(t_data *data)
{
	int		**map;
	int		i;
	int		j;
	int		count;

	map = data->map.map;
	count = 0;
	i = 0;
	while (i < data->map.num_rows)
	{
		j = 0;
		while (j < data->map.num_cols)
		{
			if (map[i][j] == SPRITE)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	set_texture_coordinate(t_data *data)
{
	int i;
	int j;
	int k;
	int count_sprite;

	count_sprite = get_count_sprite(data);
	data->sprite = malloc(sizeof(t_sprite) * count_sprite);
	k = 0;
	i = 0;
	while (i < data->map.num_rows)
	{
		j = 0;
		while (j < data->map.num_cols)
		{
			if (data->map.map[i][j] == SPRITE)
			{
				data->sprite[k].x = j * TILE_SIZE + TILE_SIZE / 2;
				data->sprite[k].y = i * TILE_SIZE + TILE_SIZE / 2;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	get_map(t_data *data)
{
	char **map;

	data->map.valid = 0;
	if (!data->map.pre)
		my_exit("NO Map\n", 1);
	map = get_map_from_pre_map(data->map.pre);
	serch_player_info(map, data);
	conversion_player_to_map_val(map, data);
	data->map.map = conversion_c_map_to_i_map(map, data);
	data->flg.no = 1;
	hundle_validate_map(data);
	if (data->map.valid == 1)
		my_exit("Map Error\n", 1);
	freecpop(map);
	free(map);
	map = NULL;
	data->map.height = data->map.num_rows * TILE_SIZE;
	data->map.width = data->map.num_cols * TILE_SIZE;
	set_texture_coordinate(data);
}
