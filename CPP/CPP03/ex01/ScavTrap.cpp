/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 23:36:17 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/09 14:54:22 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->name = "Default_ScavTrap";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap Default Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap " << this->name << " Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		this->set_name(other.get_name());
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << get_name() << " Destructor Called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->hit_points <= 0)
	{
		std::cout << "ScavTrap " << get_name() << " is dead he can't attack." << std::endl;
		return ;
	}
	else if (this->energy_points <= 0)
	{
		std::cout << "ScavTrap " << get_name() << " has no energy points left to attack." << std::endl;
		return ;
	}
	else if (this->energy_points > 0 && this->hit_points > 0)
	{
		this->energy_points--;
		std::cout << "ScavTrap " << get_name() << " viciously attacks " << target << " causing " << this->attack_damage << " damages." << std::endl;
		return ;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << get_name() << " is now in Gate keeper mode." << std::endl;
}
