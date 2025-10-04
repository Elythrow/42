/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:19:05 by gbazin            #+#    #+#             */
/*   Updated: 2025/02/26 14:22:04 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_valid(char *str);
static void	cleanup(char **split);
static int	get_sign(char *str);

static int	get_sign(char *str)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i ++;
	}
	return (sign);
}

static int	is_valid(char *str)
{
	int	i;

	i = 0;
	if (ft_countchr(str, '.') > 1)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i ++;
	if (ft_isdigit(str[i]))
		i ++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (0);
		i ++;
	}
	return (1);
}

static void	cleanup(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

double	ft_atod(char *str)
{
	int		i;
	int		sign;
	double	result;
	double	decimal;
	char	**nums;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (!is_valid(str + i))
		return (0);
	sign = get_sign(str + i);
	nums = ft_split(str, '.');
	if (!nums)
		return (0);
	result = ft_atoi(nums[0]);
	if (!nums[1])
		return (cleanup(nums), result);
	if (result < 0)
		result *= -1;
	i = -1;
	decimal = ft_atoi(nums[1]);
	while (++i < (int)ft_strlen(nums[1]))
		decimal = decimal / 10;
	return (cleanup(nums), sign * (result + decimal));
}
