/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoubo <mkokubo@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:39:44 by mkokubo           #+#    #+#             */
/*   Updated: 2020/12/14 09:23:50 by mkoubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	valid_map_key(t_data *data)
{
	int i;

	i = 0;
	while (data->map.pre[i])
	{
		if (!is_news(data->map.pre[i]) &&
			data->map.pre[i] != '0' &&
			data->map.pre[i] != '1' &&
			data->map.pre[i] != '2' &&
			data->map.pre[i] != 32 &&
			data->map.pre[i] != 10)
		{
			my_exit("Invalid val", 1);
		}
		i++;
	}
}

void	hundle_map_status(char *line, t_data *data)
{
	int len;

	data->flg.map = 1;
	valid_input_order(data);
	len = ft_strlen(line);
	get_pre_map_array(line, data);
	if (data->map.num_cols < len)
		data->map.num_cols = len;
	data->map.num_rows++;
	valid_map_key(data);
}

void	get_pre_map_array(char *line, t_data *data)
{
	char *pre;

	if (data->map.pre == NULL)
		data->map.pre = ft_strdup("");
	pre = data->map.pre;
	data->map.pre = shape_pre_map_array(pre, line);
	free(pre);
	pre = NULL;
}

char	*shape_pre_map_array(char *pre, char *add)
{
	char *tmp;
	char *re;

	re = ft_strjoin(pre, add);
	tmp = re;
	re = ft_strjoin(re, "\n");
	free(tmp);
	tmp = NULL;
	return (re);
}

char	**get_map_from_pre_map(char *pre)
{
	char	**map;
	char	*tmp;
	int		i;

	i = 0;
	map = ft_split(pre, '\n');
	while (map[i])
	{
		tmp = map[i];
		map[i] = ft_strjoin(map[i], "\0");
		free(tmp);
		tmp = NULL;
		i++;
	}
	return (map);
}
