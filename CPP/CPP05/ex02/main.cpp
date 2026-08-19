/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 14:06:33 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/19 14:59:15 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


int	main(void) {

	srand(time(NULL));
	Bureaucrat	stagiaire;
	Bureaucrat	middle("Joseph", 25);
	Bureaucrat	superior("Superior", 1);

	std::cout << "--- Valides ---" << std::endl;

	AForm	*pardon = new PresidentialPardonForm("pardon");	
	AForm	*robotomy = new RobotomyRequestForm("robot");
	AForm	*shrubbery = new ShrubberyCreationForm("shrub");

	RobotomyRequestForm original("original");
	RobotomyRequestForm copy;
	copy = original;

	middle.signForm(*robotomy);
	middle.executeForm(*robotomy);
	std::cout << std::endl;

	superior.signForm(*pardon);
	superior.executeForm(*pardon);
	std::cout << std::endl;

	superior.signForm(*shrubbery);
	superior.executeForm(*shrubbery);

	superior.signForm(copy);
	superior.executeForm(copy);

	std::cout << std::endl;

	std::cout << "--- Invalides ---" << std::endl;

	AForm	*pardon2 = new PresidentialPardonForm("pardon2");
	AForm	*robotomy2 = new RobotomyRequestForm("robot2");
	AForm	*shrubbery2 = new ShrubberyCreationForm("shrub2");

	stagiaire.signForm(*robotomy2);
	stagiaire.executeForm(*robotomy2);
	superior.signForm(*robotomy2);
	stagiaire.executeForm(*robotomy2);
	std::cout << std::endl;

	stagiaire.signForm(*shrubbery2);
	stagiaire.executeForm(*shrubbery2);
	superior.signForm(*shrubbery2);
	stagiaire.executeForm(*shrubbery2);
	std::cout << std::endl;

	stagiaire.signForm(*pardon2);
	stagiaire.executeForm(*pardon2);
	superior.signForm(*pardon2);
	stagiaire.executeForm(*pardon2);

	delete robotomy;
	delete pardon;
	delete shrubbery;
	delete robotomy2;
	delete pardon2;
	delete shrubbery2;

	return (0);
}