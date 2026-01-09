/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:32:37 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/09 17:52:12 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog Default Constructor Called!" << std::endl;
	brain = new Brain("Dog's ideas");
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog Copy Constructor Called!" << std::endl;
	this->brain = new Brain(*(other.brain));
}

Dog& Dog::operator=(const Dog &other)
{
    if (this != &other)
	{
        Animal::operator=(other);
		this->brain = new Brain(*(other.brain));
    }
    std::cout << "Dog Assignment Operator Called!" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog Destructor Called!" << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl;
}
