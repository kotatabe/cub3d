/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoubo <mkokubo@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 23:18:16 by mkoubo            #+#    #+#             */
/*   Updated: 2020/12/11 21:16:23 by mkoubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_sprite_num(t_data *data)
{
	int i;

	data->sprite_num = 0;
	i = 0;
	while (data->map.pre[i])
	{
		if (data->map.pre[i] == '2')
			data->sprite_num++;
		i++;
	}
}
