/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:18:17 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/09 16:23:41 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat Default Constructor Called!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "WrongCat Copy Constructor Called!" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    std::cout << "WrongCat Assignment Operator Called!" << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor Called!" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Wouf Wouf" << std::endl;
}