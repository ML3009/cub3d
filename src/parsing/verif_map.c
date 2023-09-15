/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:39:43 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/15 15:18:38 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

static void atypic_wall(t_data *data, char **map, int y, int x);
static int	check_again(t_data *data, char **map, int y, int x);

int	check_map(t_data *map)
{
	char	**map_cp;
	int	y;
	int	x;
	printf ("row : %i\n", map->row);
	printf ("col : %i\n", map->col);
	for (int k = 0; map->map[k]; k++)
		printf("map : %s\n", map->map[k]);

	map_cp = NULL;
	y = -1;
	map_cp = copy_map(map);
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
			if (map->map[y][x] == 'N' || map->map[y][x] == 'S' || map->map[y][x] == 'E' || map->map[y][x] == 'O')
				break;
		if (map->map[y][x] == 'N' || map->map[y][x] == 'S' || map->map[y][x] == 'E' || map->map[y][x] == 'O')
				break;
	}
	printf ("map : %c\n", map->map[y][x]);
	if (check_wall(map, map_cp, y, x) == ERROR_WALL)
		return (printf("Wall does not ok.\n"), ERROR_WALL);

	return (0);
}

int	check_wall(t_data *map, char **map_cp, int y, int x)
{
	atypic_wall(map, map_cp, y, x);
	if (map->wallOk > 0)
		return (ERROR_WALL);
	return (0);
}


static void	atypic_wall(t_data *data, char **map, int y, int x)
{
	map[y][x] = 'Y';
	if (!check_again(data, map, y, x) && map[y][x] && map[y + 1][x] == '0')
		atypic_wall(data, map, y + 1, x);
	if (!check_again(data, map, y, x) && map[y][x] && map[y - 1][x] == '0')
		atypic_wall(data,map, y - 1, x);
	if (!check_again(data, map, y, x) && map[y][x] && map[y][x + 1] == '0')
		atypic_wall(data, map, y, x + 1);
	if (!check_again(data, map, y, x) && map[y][x] && map[y][x - 1] == '0')
		atypic_wall(data, map, y, x - 1);
	return ;
}

static int	check_again(t_data *data, char **map, int y, int x)
{
	if (map[y + 1] == NULL || map[y + 1][x] == ' ' || map[y + 1][x] == '\0' || map[y + 1][x] == '\t'|| map[y + 1][x] == '\n')
		return (data->wallOk++, -1);
	else if (map[y - 1] == NULL || map[y - 1][x] == ' '  || map[y - 1][x] == '\0' || map[y - 1][x] == '\t' || map[y - 1][x] == '\n')
		return (data->wallOk++, -1);
	else if (map[y][x + 1] == ' '  || map[y][x + 1] == '\0' || map[y][x + 1] == '\t' || map[y][x + 1] == '\n')
		return (data->wallOk++, -1);
	else if (map[y][x - 1] == ' '  || map[y][x - 1] == '\0' || map[y][x - 1] == '\t' || map[y][x - 1] == '\n')
		return (data->wallOk++, -1);
	else
		return (0);
}