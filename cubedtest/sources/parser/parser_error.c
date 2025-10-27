/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:15:24 by gbazin            #+#    #+#             */
/*   Updated: 2025/10/27 14:15:36 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	parse_error(const char *msg, t_parsing *ctx)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd((char *)msg, 2);
	ft_putstr_fd("\n", 2);
	if (ctx)
	{
		if (ctx->lines)
			free_split(ctx->lines);
		if (ctx->cfg)
			free_config(ctx->cfg);
	}
	exit(1);
}

void	parse_error_detail(const char *msg, const char *detail,
		t_parsing *ctx)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd((char *)msg, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd((char *)detail, 2);
	ft_putstr_fd("\n", 2);
	if (ctx)
	{
		if (ctx->lines)
			free_split(ctx->lines);
		if (ctx->cfg)
			free_config(ctx->cfg);
	}
	exit(1);
}
