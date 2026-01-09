/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:32:42 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/09 16:31:05 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* a = new Animal();
	std::cout << std::endl;
	const Animal* d = new Dog();
	std::cout << std::endl;
	const Animal* c = new Cat();
	std::cout << std::endl;
    const WrongAnimal* w = new WrongCat();
	std::cout << std::endl;
	const WrongAnimal* wa = new WrongAnimal();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Types" << std::endl;
	std::cout << d->getType() << " " << std::endl;
	std::cout << c->getType() << " " << std::endl;
	std::cout << w->getType() << " " << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Sounds" << std::endl;
	std::cout << d->getType() << " sounds like ";
	d->makeSound();
	std::cout << std::endl;
	std::cout << c->getType() << " sounds like ";
	c->makeSound();
	std::cout << std::endl;
	std::cout << w->getType() << " sounds like ";
	w->makeSound();
	std::cout << std::endl;
	std::cout << wa->getType() << " sounds like ";
	wa->makeSound();
	std::cout << std::endl;
	std::cout << a->getType() << " sounds like ";
	a->makeSound();
	std::cout << std::endl;
	std::cout << "Destructors" << std::endl;
	delete a;
	std::cout << std::endl;
	delete d;
	std::cout << std::endl;
	delete c;
	std::cout << std::endl;
	delete w;
	std::cout << std::endl;
	delete wa;
	return (0);
}