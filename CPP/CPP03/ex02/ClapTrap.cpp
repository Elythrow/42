/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:26:38 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/09 12:20:33 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->name = "Default ClapTrap";
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	std::cout << "Claptrap Default Constructor Called" << std::endl;
}	

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	std::cout << "Claptrap " << this->name << " Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "Claptrap " << this->name << " Copy Constructor Called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Claptrap " << this->name << " Destructor Called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is dead he can't attack." << std::endl;
		return ;
	}
	else if (this->energy_points <= 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy points left to attack." << std::endl;
		return ;
	}
	else if (this->energy_points > 0 && this->hit_points > 0)
	{
		this->energy_points--;
		std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->attack_damage << " damages." << std::endl;
		return ;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points <= 0)
	{
		std::cout << this->name << " is already dead." << std::endl;
		return ;
	}
	this->hit_points -= amount;
	if (this->hit_points < 0)
		this->hit_points = 0;
	std::cout << this->name << " takes " << amount << " points of damage. He now has: " << this->hit_points << " hit points." << std::endl;
	if (this->hit_points == 0)
		std::cout << this->name << " has died." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points <= 0)
	{
		std::cout << this->name << " is dead he can't repair." << std::endl;
		return ;
	}
	else if (this->energy_points <= 0)
	{
		std::cout << this->name << " has no energy points left to repair." << std::endl;
		return ;
	}
	this->hit_points += amount;
	this->energy_points--;
	std::cout << this->name << " repairs itself for " << amount << " hit points. He now has " << this->hit_points << " hit points and " << this->energy_points << " energy points remaining." << std::endl;
}

void	ClapTrap::set_name(std::string name)
{
	this->name = name;
}

std::string ClapTrap::get_name() const
{
    return (this->name);
}
