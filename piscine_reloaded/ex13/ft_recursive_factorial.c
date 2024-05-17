/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:29:04 by gbazin            #+#    #+#             */
/*   Updated: 2024/05/14 11:31:14 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0 || nb > 19)
		return (0);
	else if (nb == 0)
		return (1);
	else
		return (ft_recursive_factorial(nb - 1) * nb);
}
