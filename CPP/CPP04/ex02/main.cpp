/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:32:42 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/09 18:46:58 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	//const Animal x;
	delete j;
	delete i;
	return (0);
}
