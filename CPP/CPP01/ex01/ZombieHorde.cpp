/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:50:03 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/07 21:25:47 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde( int N, std::string name )
{
	int					i = 0;
	std::ostringstream	oss;
	Zombie*				horde = new Zombie[N];

	for (i = 0; i < N; i++)
	{
		oss.str("");
		oss << (i + 1);
		horde[i].give_name(name + oss.str());
	}
	return (horde);
}
