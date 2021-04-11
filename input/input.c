/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoubo <mkokubo@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:18:22 by mkokubo           #+#    #+#             */
/*   Updated: 2020/12/14 03:00:17 by mkoubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_texture_comparison_string(char *line)
{
	char *str;

	str = malloc(sizeof(char) * 4);
	str = ft_memcpy(str, line, 3);
	str[4] = '\n';
	return (str);
}

void	hundle_input_elm(char *line, char *str, t_data *data)
{
	if (*line == 'R')
		set_window_size_by_line(line, data);
	else if (*line == ' ' || *line == '1' || *line == '0')
		hundle_map_status(line, data);
	else if (line[0] == 'F' && line[1] == ' ')
		data->color.floor = hundle_input_color(line, data);
	else if (line[0] == 'C' && line[1] == ' ')
		data->color.ceiling = hundle_input_color(line, data);
	else if (!ft_strncmp(str, "NO ", 3))
		set_texture_path(TEXTURE_NO, format_texture_path(line), data, str);
	else if (!ft_strncmp(str, "SO ", 3))
		set_texture_path(TEXTURE_SO, format_texture_path(line), data, str);
	else if (!ft_strncmp(str, "WE ", 3))
		set_texture_path(TEXTURE_WE, format_texture_path(line), data, str);
	else if (!ft_strncmp(str, "EA ", 3))
		set_texture_path(TEXTURE_EA, format_texture_path(line), data, str);
	else if (!ft_strncmp(str, "S ", 2))
		set_texture_path(TEXTURE_S, format_texture_path(line), data, str);
	else
		my_exit("Invalid Key\n", 1);
}

void	hundle_input(char *line, t_data *data)
{
	char	*str;

	if (*line == 0 && data->flg.map == 0)
		return ;
	str = get_texture_comparison_string(line);
	hundle_input_elm(line, str, data);
	free(str);
	str = NULL;
}

void	input_file(char *file_path, t_data *data)
{
	int		fd;
	char	*line;

	data->map.num_rows = 0;
	fd = open(file_path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		hundle_input(line, data);
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
	get_map(data);
	get_sprite_num(data);
}
