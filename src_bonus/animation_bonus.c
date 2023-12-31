/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocastell <ocastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:58:11 by mgirardi          #+#    #+#             */
/*   Updated: 2023/04/29 18:06:48 by ocastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	distance_to_door(t_ncul *data)
{
	double	dx;
	double	dy;

	dx = data->pos.x - data->door.x;
	dy = data->pos.y - data->door.y;
	return (sqrt(dx * dx + dy * dy));
}

void	ft_door(t_ncul *data, int keycode)
{
	data->door_dist = distance_to_door(data);
	if (data->door_dist < 2.3
		&& data->map[(int)data->pos.y][(int)data->pos.x] != 'D')
	{
		if (keycode == KEY_SPACE)
		{
			if (data->door.open == 1)
				data->door.open = 0;
			else
				data->door.open = 1;
		}
	}
}

void	ft_init_door(t_ncul *data)
{
	int	i;
	int	j;

	data->door.open = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'D')
			{
				data->door.x = j;
				data->door.y = i;
			}
			j++;
		}
		i++;
	}
	data->door.timer = 400;
}
