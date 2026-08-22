/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:18:07 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/09 17:49:54 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal Default Constructor Called!" << std::endl;
}
WrongAnimal::WrongAnimal(std::string name)
{
	this->type = name;
	std::cout << "WrongAnimal Parameterized Constructor Called!" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	this->type = other.type;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		this->type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor Called!" << std::endl;
}
void WrongAnimal::makeSound() const
{
	std::cout << "Bonjour !!" << std::endl;
}

const std::string& WrongAnimal::getType() const
{
	return (this->type);
}