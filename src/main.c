/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:20:14 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/07 14:26:05 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"


int main(int ac, char **av)
{
	int	check_map;
	t_map	map;

	check_map = 0;
	if (ac > 2)
		send_error("Too many arguments.\n");
	else if (ac < 2)
		send_error("Too few arguments.\n");
	check_map = parsing(ac, av, &map);
	if (check_map >= 0)
	{
		printf("GAME START\n");
		//game_start();
	}
	return (0);
}
