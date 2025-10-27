/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:17:00 by gbazin            #+#    #+#             */
/*   Updated: 2025/10/27 14:17:19 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	free_config(t_config *cfg)
{
	if (!cfg)
		return ;
	if (cfg->textures.north)
		free(cfg->textures.north);
	if (cfg->textures.south)
		free(cfg->textures.south);
	if (cfg->textures.east)
		free(cfg->textures.east);
	if (cfg->textures.west)
		free(cfg->textures.west);
	if (cfg->map.grid)
		free_split(cfg->map.grid);
}
