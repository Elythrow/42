/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 14:06:33 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/18 15:39:18 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << std::endl << "--- Declaration ---" << std::endl;
	
	Bureaucrat	stagiaire;
	Bureaucrat	random("Middl", 100);
	Bureaucrat	over("xsilas", 1);
	Bureaucrat	under("siraik", 150);
	Bureaucrat	copy("Clone", 42);

	std::cout << stagiaire << std::endl;
	std::cout << random << std::endl;
	std::cout << over << std::endl;
	std::cout << under << std::endl;
	std::cout << copy << std::endl;

	std::cout << std::endl << "--- Incremente et Decremente Middl ---" << std::endl;
	
	try
	{
		random.incrementGrade();
		std::cout << random << std::endl;
		random.decrementGrade();
		std::cout << random << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "--- Incremente xsilas (rang 1) ---" << std::endl;

	try
	{
		over.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "--- Decremente siraik (rang 150) ---" << std::endl;

	try
	{
		under.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "--- Creation rang 151 ---" << std::endl;

	try
	{
		Bureaucrat invalidLow("Nullos", 151);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "--- Creation rang 0 ---" << std::endl;

	try
	{
		Bureaucrat invalidHigh("TropFort", 0);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "---  Assignement ---" << std::endl;

	std::cout << "before: " << copy << std::endl;
	copy = stagiaire;
	std::cout << "after:  " << copy << std::endl;
	std::cout << "source: " << stagiaire << std::endl;
	
	return (0);
}