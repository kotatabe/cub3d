/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoubo <mkokubo@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 23:18:29 by mkoubo            #+#    #+#             */
/*   Updated: 2020/12/14 02:56:09 by mkoubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		val_omparison(int data, int max)
{
	if (data > max)
		return (max);
	return (data);
}

int		chst(int d)
{
	if (d < 0)
		my_exit("", 1);
	return (d);
}

void	check_valid(char **input)
{
	if (strpoplen(input) != 3)
		my_exit("window error\n", 1);
	if (!is_num(input[1]) || !is_num(input[2]))
		my_exit("", 1);
}

void	set_window_size_by_line(char *line, t_data *data)
{
	char	**input;
	int		width;
	int		max_width;
	int		height;
	int		max_height;

	input = ft_split(line, ' ');
	check_valid(input);
	width = chst(ft_atoi(input[1]));
	height = chst(ft_atoi(input[2]));
	if (!width || !height)
		my_exit("window erroe", 1);
	mlx_get_screen_size(data->mlx, &max_width, &max_height);
	width = val_omparison(width, max_width);
	height = val_omparison(height, max_height);
	data->window.width = width;
	data->window.height = height;
	if (data->flg.r == 0)
		data->flg.r = 1;
	else
		my_exit("Duplication res\n", 1);
	freecpop(input);
	free(input);
	input = NULL;
}
