/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:32:27 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/09 18:44:53 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat Default Constructor Called!" << std::endl;
	brain = new Brain("Cat's ideas");
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat Copy Constructor Called!" << std::endl;
	this->brain = new Brain(*(other.brain));
}

Cat& Cat::operator=(const Cat &other)
{
    if (this != &other)
	{
        Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*(other.brain));
    }
    std::cout << "Cat Assignment Operator Called!" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat Destructor Called!" << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
    std::cout << "Miaou Miaou" << std::endl;
}

Brain* Cat::getBrain() const
{
	return brain;
}