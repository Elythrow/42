/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 14:06:33 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/19 16:22:58 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
    std::cout << "--- signer sans le rang ---" << std::endl;
	std::cout << std::endl;

	Bureaucrat  bureaucrat("bureaucrat", 150);
	std::cout << bureaucrat << std::endl;
	ShrubberyCreationForm shrubbery("home");
	bureaucrat.signForm(shrubbery);
	bureaucrat.executeForm(shrubbery);

	std::cout << std::endl;
	std::cout << "--- executer sans le rang ---" << std::endl;
	std::cout << std::endl;

	Bureaucrat  bureaucrat2("bureaucrat2", 140);
	std::cout << bureaucrat2 << std::endl;
	bureaucrat2.signForm(shrubbery);
	bureaucrat2.executeForm(shrubbery);

	std::cout << std::endl;
    std::cout << "--- executer sans signer ---" << std::endl;
	std::cout << std::endl;

	Bureaucrat  bureaucrat3("bureaucrat3", 145);
	ShrubberyCreationForm shrubbery3("home");
	bureaucrat3.executeForm(shrubbery3);

	std::cout << std::endl;
    std::cout << "--- shrubbery bon rang ---" << std::endl;
	std::cout << std::endl;

	Bureaucrat  bureaucrat4("bureaucrat4", 1);
	std::cout << bureaucrat4 << std::endl;
	ShrubberyCreationForm shrubbery4("home");
	bureaucrat4.signForm(shrubbery4);
	bureaucrat4.executeForm(shrubbery4);

	std::cout << std::endl;
    std::cout << "--- robotomy bon rang ---" << std::endl;
	std::cout << std::endl;

	Bureaucrat  bureaucrat5("bureaucrat5", 1);
	std::cout << bureaucrat5 << std::endl;
	RobotomyRequestForm robotomy("home");
	bureaucrat5.signForm(robotomy);
	bureaucrat5.executeForm(robotomy);

	std::cout << std::endl;
    std::cout << "--- pardon bon rang ---" << std::endl;
	std::cout << std::endl;

	Bureaucrat  bureaucrat6("bureaucrat6", 1);
	std::cout << bureaucrat6 << std::endl;
	PresidentialPardonForm presidential("home");
	bureaucrat6.signForm(presidential);	
	bureaucrat6.executeForm(presidential);

	std::cout << std::endl;
    std::cout << "--- poly ---" << std::endl;
	std::cout << std::endl;

	Bureaucrat  bureaucrat7("bureaucrat7", 1);
	AForm* forms[3];
	forms[0] = new ShrubberyCreationForm("home");
	forms[1] = new RobotomyRequestForm("home");
	forms[2] = new PresidentialPardonForm("home");
	for (int i = 0; i < 3; i++)
	{
		std::cout << *forms[i] << std::endl;		
		bureaucrat7.signForm(*forms[i]);
		bureaucrat7.executeForm(*forms[i]);
	}
	std::cout << *forms[2] << std::endl;
	for (int i = 0; i < 3; i++)
	{
		delete forms[i];
	}
	
	return (0);
}