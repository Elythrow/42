/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:32:17 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/09 18:44:43 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal Default Constructor Called!" << std::endl;
}
Animal::Animal(std::string name)
{
	this->type = name;
	std::cout << "Animal Parameterized Constructor Called!" << std::endl;
}
Animal::Animal(const Animal &other)
{
	std::cout << "Animal Copy Constructor Called!" << std::endl;
	this->type = other.type;
}
Animal& Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor Called!" << std::endl;
}
void Animal::makeSound() const
{
	std::cout << "Animal Sound" << std::endl;
}

const std::string& Animal::getType() const
{
	return (this->type);
}