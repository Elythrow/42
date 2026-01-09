/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:23:15 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/09 14:58:54 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->name = "Default_FragTrap";
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap Default Constructor Called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap " << this->name << " Constructor Called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
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

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << get_name() << " Destructor Called" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (this->hit_points <= 0)
	{
		std::cout << "FragTrap " << get_name() << " is dead he can't attack." << std::endl;
		return ;
	}
	else if (this->energy_points <= 0)
	{
		std::cout << "FragTrap " << get_name() << " has no energy points left to attack." << std::endl;
		return ;
	}
	else if (this->energy_points > 0 && this->hit_points > 0)
	{
		this->energy_points--;
		std::cout << "FragTrap " << get_name() << " fiercely attacks " << target << " causing " << this->attack_damage << " damages." << std::endl;
		return ;
	}
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << get_name() << " is requesting a high five !!!" << std::endl;
}
