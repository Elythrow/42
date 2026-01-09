/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:32:37 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/09 16:15:19 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog Default Constructor Called!" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog Copy Constructor Called!" << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << "Dog Assignment Operator Called!" << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor Called!" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl;
}
