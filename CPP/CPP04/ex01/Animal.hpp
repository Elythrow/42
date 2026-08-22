/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:32:20 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/09 18:30:16 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string name);
		Animal(const Animal &other);
		Animal& operator=(const Animal &other);		
		virtual ~Animal();
		virtual void makeSound() const;
		virtual const std::string& getType() const;
};

#endif