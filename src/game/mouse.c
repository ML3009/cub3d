/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:22:03 by mvautrot          #+#    #+#             */
/*   Updated: 2023/10/11 18:29:35 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void	mouse_pov(t_data *data)
{
	int	pos_x;
	int	pos_y;

	mlx_mouse_get_pos(data->mlx.mlx_id, \
	data->mlx.mlx_window, &pos_x, &pos_y);
	if (pos_x <= ((int)data->mlx.size.x / 3) \
	&& (pos_y >= data->mlx.size.y / 10))
		data->key.vleft = 1;
	else if (pos_x >= (((int)data->mlx.size.x / 3) * 2) \
	&& (pos_y >= data->mlx.size.y / 10))
		data->key.vright = 1;
	else
	{
		data->key.vleft = 0;
		data->key.vright = 0;
	}
	return ;
}