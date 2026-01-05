/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:56:00 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/05 14:54:33 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie()
{
    std::cout << name << " has been deleted\n";
}

void Zombie::announce()
{
	std::cout << this->name << ": Braiiiiiiinnnssss..." << std::endl;
}

void Zombie::give_name(std::string name)
{
	this->name = name;
}