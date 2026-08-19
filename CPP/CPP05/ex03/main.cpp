/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 14:06:33 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/19 17:34:42 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	srand(time(NULL));
	Bureaucrat	bureaucrat1("Joseph", 25);
	Bureaucrat	bureaucrat2("Superior", 1);
	AForm		*robotomy = NULL;
	AForm		*pardon = NULL;
	AForm		*shrubbery = NULL;
	AForm		*robotomy2 = NULL;
	AForm		*pardon2 = NULL;
	AForm		*shrubbery2 = NULL;

	std::cout << "--- VALIDE ---" << std::endl;
	std::cout << std::endl;

	Intern	intern;

	try {
		robotomy = intern.makeForm("robotomy request", "Bender");
		bureaucrat1.signForm(*robotomy);
		bureaucrat1.executeForm(*robotomy);
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		pardon = intern.makeForm("presidential pardon", "Joe");
		bureaucrat2.signForm(*pardon);
		bureaucrat2.executeForm(*pardon);
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		shrubbery = intern.makeForm("shrubbery creation", "test");
		bureaucrat2.signForm(*shrubbery);
		bureaucrat2.executeForm(*shrubbery);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--- INVALIDE ---" << std::endl;
	std::cout << std::endl;

	try {
		robotomy2 = intern.makeForm("bobotomy", "Aie");
		std::cout << "Unexpected success: " << robotomy2 << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		shrubbery2 = intern.makeForm("shrubberie", "non");
		std::cout << "Unexpected success: " << shrubbery2 << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	try {
		pardon2 = intern.makeForm("parrdon", "");
		std::cout << "Unexpected success: " << pardon2 << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	delete robotomy;
	delete pardon;
	delete shrubbery;
	delete robotomy2;
	delete pardon2;
	delete shrubbery2;
	
	return (0);
}