/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoubo <mkokubo@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:12:59 by mkokubo           #+#    #+#             */
/*   Updated: 2020/12/14 03:05:35 by mkoubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		change_hex_color(t_color_buf *color)
{
	int output;

	output = color->b;
	output += color->g << 8;
	output += color->r << 16;
	return (output);
}

void	get_input_color(t_color_buf *color, char **buf)
{
	if (!is_num(buf[0]) || !is_num(buf[1]) || !is_num(buf[2]))
		my_exit("", 1);
	color->r = ft_atoi(buf[0]);
	color->g = ft_atoi(buf[1]);
	color->b = ft_atoi(buf[2]);
	if (color->r < 0 || 255 < color->r)
		my_exit("Illegal range of color", 1);
	if (color->g < 0 || 255 < color->g)
		my_exit("Illegal range of color", 1);
	if (color->b < 0 || 255 < color->b)
		my_exit("Illegal range of color", 1);
}

int		hundle_input_color(char *line, t_data *data)
{
	t_color_buf		color;
	char			**buf;
	int				buf_len;

	if (*line == 'F' && data->flg.f == 0)
		data->flg.f = 1;
	else if (*line == 'F' && data->flg.f == 1)
		my_exit("Dupilication Color", 1);
	if (*line == 'C' && data->flg.c == 0)
		data->flg.c = 1;
	else if (*line == 'C' && data->flg.c == 1)
		my_exit("Dupilication Color", 1);
	line++;
	while (!ft_isdigit(*line))
		line++;
	buf = ft_split(line, ',');
	buf_len = ft_strlenpop(buf);
	if (buf_len != 3)
		my_exit("Illegal amount of color elm\n", 1);
	get_input_color(&color, buf);
	freecpop(buf);
	free(buf);
	buf = NULL;
	return (change_hex_color(&color));
}
