/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:32:42 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/09 17:51:25 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
    Animal *animal[10];
    for (int i = 0; i < 10; i++)
    {
        std::cout << "---------" << i << "----------" << std::endl;
        if (i % 2 == 0)
            animal[i] = new Dog();
        else
            animal[i] = new Cat();
        std::cout << "---------------------" << std::endl;
        animal[i]->makeSound();
        std::cout << std::endl;
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout << "---------" << i << "----------" << std::endl;
        delete animal[i];
        std::cout << std::endl;
    }

    std::cout << std::endl << "test deep copy" << std::endl;

    const Animal* x = new Cat();
    {
        const Animal* z(x);
        z->makeSound();
        const Animal* y = x;
        y->makeSound();
    }
    x->makeSound();
    std::cout << std::endl << std::endl;
    delete x;
    return (0);
}
