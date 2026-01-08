/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:50:03 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/08 11:39:05 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	int					i = 0;
	Zombie*				horde = new Zombie[N];

	for (i = 0; i < N; i++)
	{
		horde[i].give_name(name);
	}
	return (horde);
}
