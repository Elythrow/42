/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 20:22:44 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/23 01:15:02 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {}

Base* generate ()
{
	int random = rand() % 3;
	if (random == 0)
		return (new A());
	else if (random == 1)
		return (new B());
	else
		return (new C());
}

void	identify(Base* base)
{
	if (!base)
	{
		return;
	}
	if (dynamic_cast<A*>(base))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(base))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(base))
		std::cout << "C" << std::endl;
}

void	identify(Base& base)
{
	try
	{
		A& a = dynamic_cast<A&>(base);
		std::cout << "A" << std::endl;
		(void)a;
	}
	catch (const std::exception& e)
	{
	}
	try
	{
		B& b = dynamic_cast<B&>(base);
		std::cout << "B" << std::endl;
		(void)b;
	}
	catch (const std::exception& e)
	{
	}
	try
	{
		C& c = dynamic_cast<C&>(base);
		std::cout << "C" << std::endl;
		(void)c;
	}
	catch (const std::exception& e)
	{
	}
}