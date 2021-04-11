/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoubo <mkokubo@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 23:18:25 by mkoubo            #+#    #+#             */
/*   Updated: 2020/12/14 09:40:11 by mkoubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	valid_texture_duplicate(char *str, t_data *data)
{
	if (!ft_strncmp(str, "NO ", 3))
		data->flg.no++;
	else if (!ft_strncmp(str, "SO ", 3))
		data->flg.so++;
	else if (!ft_strncmp(str, "WE ", 3))
		data->flg.we++;
	else if (!ft_strncmp(str, "EA ", 3))
		data->flg.ea++;
	else if (!ft_strncmp(str, "S ", 2))
		data->flg.s++;
	if (data->flg.no > 1 || data->flg.so > 1
		|| data->flg.we > 1 || data->flg.ea > 1
		|| data->flg.s > 1)
		my_exit("Duplication key\n", 1);
}

void	set_texture_path(int i, char *file, t_data *data, char *str)
{
	if (!is_file(file))
		my_exit("Illegal Path", 1);
	valid_texture_duplicate(str, data);
	data->texture[i].ptr = mlx_xpm_file_to_image(
													data->mlx,
													file,
													&data->texture[i].width,
													&data->texture[i].height);
	if (data->texture[i].ptr == NULL)
		my_exit("picer\n", 1);
	data->texture[i].addr = mlx_get_data_addr(
											data->texture[i].ptr,
											&data->texture[i].bits_per_pixel,
											&data->texture[i].line_length,
											&data->texture[i].endian);
}

char	*format_texture_path(char *line)
{
	while (*line)
	{
		if (*line == '.')
			return (line);
		line++;
	}
	return (NULL);
}
