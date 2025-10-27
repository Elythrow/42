/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:33:45 by gbazin            #+#    #+#             */
/*   Updated: 2025/10/27 17:34:26 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parse.h"

static void	print_config(t_config *cfg)
{
	int	i;

	ft_printf("=== Configuration ===\n");
	ft_printf("North texture: %s\n", cfg->textures.north);
	ft_printf("South texture: %s\n", cfg->textures.south);
	ft_printf("East texture: %s\n", cfg->textures.east);
	ft_printf("West texture: %s\n", cfg->textures.west);
	ft_printf("Floor color: %d\n", cfg->floor_color);
	ft_printf("Ceiling color: %d\n", cfg->ceiling_color);
	ft_printf("\n=== Map ===\n");
	ft_printf("Width: %d, Height: %d\n", cfg->map.width, cfg->map.height);
	ft_printf("Player pos: (%d, %d) dir: %c\n",
		cfg->player.pos.x, cfg->player.pos.y, cfg->player.dir);
	ft_printf("\nMap grid:\n");
	i = 0;
	while (i < cfg->map.height)
	{
		ft_printf("%s\n", cfg->map.grid[i]);
		i ++;
	}
}

int	main(int argc, char **argv)
{
	t_config	config;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./cub3d <map.cub>\n", 2);
		return (1);
	}
	parse_file(argv[1], &config);
	print_config(&config);
	free_config(&config);
	ft_printf("\n✓ Parsing successful!\n");
	return (0);
}
