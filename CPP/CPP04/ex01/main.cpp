/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:32:42 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/09 18:35:12 by gbazin           ###   ########.fr       */
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

    std::cout << std::endl << "===== DEEP COPY TESTS =====" << std::endl;

    std::cout << std::endl << "--- Dog copy constructor ---" << std::endl;
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "aboyer");
    
    Dog copyDog(originalDog);
    
    std::cout << "Original brain addr: " << originalDog.getBrain() << std::endl;
    std::cout << "Copy brain addr:     " << copyDog.getBrain() << std::endl;
    std::cout << "Original idea[0]: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy idea[0]:     " << copyDog.getBrain()->getIdea(0) << std::endl;
    
    copyDog.getBrain()->setIdea(0, "mordre");
    std::cout << "After modifying copy:" << std::endl;
    std::cout << "Original idea[0]: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy idea[0]:     " << copyDog.getBrain()->getIdea(0) << std::endl;

    std::cout << std::endl << "--- Cat assignment operator ---" << std::endl;
    Cat cat1;
    Cat cat2;
    cat1.getBrain()->setIdea(0, "dormir!");
    
    cat2 = cat1;
    
    std::cout << "Cat1 brain addr: " << cat1.getBrain() << std::endl;
    std::cout << "Cat2 brain addr: " << cat2.getBrain() << std::endl;
    std::cout << "Cat1 idea[0]: " << cat1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat2 idea[0]: " << cat2.getBrain()->getIdea(0) << std::endl;
    return (0);
}
