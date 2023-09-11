/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:10:05 by purple            #+#    #+#             */
/*   Updated: 2023/09/11 14:00:47 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

int init_the_game(t_data *data)
{
	ft_memset(&data->mlx, 0, sizeof(data->mlx));
	if (!(data->mlx.mlx_id = mlx_init()) || !(data->mlx.mlx_window = mlx_new_window(data->mlx.mlx_id, data->mlx.size.x,  data->mlx.size.y, "Cub3D")))
		return (MLX_ERROR);
	
	
	return (0);
		
}
void screen_size(t_data *data)
{
	int screen_width;
	int screen_height;

	mlx_get_screen_size(data->mlx.mlx_id, &screen_width, &screen_height);
	if (screen_width >= 1920)
		data->mlx.size.x = 1920;
	else
		data->mlx.size.x = 848;
	if (screen_height >= 1080)
		data->mlx.size.y = 1080;
	else
		data->mlx.size.y = 480;
}

void init_orientation(t_data *data)
{
	if (data->base_orient == 'S' || data->base_orient == 'N')
	{
		
	}
	else
	{
		
	}
}