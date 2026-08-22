/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 20:23:29 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/22 21:07:53 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	A a;
	B b;
	C c;

	std::cout << "Base A par pointeur-> ";
	identify(&a);
	std::cout << "Base A par reference -> ";
	identify(a);
	std::cout << std::endl;

	std::cout << "Base B par pointeur -> ";
	identify(&b);
	std::cout << "Base B par reference -> ";
	identify(b);
	std::cout << std::endl;

	std::cout << "Base C par pointeur -> ";
	identify(&c);
	std::cout << "Base C par reference -> ";
	identify(c);
	std::cout << std::endl;

	srand(time(NULL));
	for (int i = 0; i < 5; i ++) {
		std::cout << "Test " << i + 1 << std::endl;
		Base* obj = generate();
		if (!obj) {
			continue;
		}
		std::cout << "Par pointeur: ";
		identify(obj);
		std::cout << "Par reference: ";
		identify(*obj);
		delete obj;
		std::cout << std::endl;
	}
	return (0);
}