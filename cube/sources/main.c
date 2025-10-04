/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:51:19 by gbazin            #+#    #+#             */
/*   Updated: 2025/10/04 20:59:05 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	if (argc != 2)
	{
		printf("Error\nUsage: ./cub3d <map_file.cub>\n");
		return (1);
	}
	parse_file(av[1]);
	exec();
	cleanup();
	return (0);
}
