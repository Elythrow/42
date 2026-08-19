/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:25:06 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/19 17:46:43 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	if (this != &other) {}
	return *this;
}

Intern::~Intern() {}

const char	*Intern::InvalidForm::what() const throw() {
	return ("Intern: Invalid form type");
}

AForm* Intern::makeShrubbery(const std::string& t) const { return (new ShrubberyCreationForm(t)); }
AForm* Intern::makeRobotomy(const std::string& t) const { return (new RobotomyRequestForm(t)); }
AForm* Intern::makePresidential(const std::string& t) const { return (new PresidentialPardonForm(t)); }

AForm* Intern::makeForm(const std::string& name, const std::string& target) const
{
	typedef AForm* (Intern::*FormMaker)(const std::string&) const;

	const std::string	names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	const FormMaker		makers[3] = {&Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePresidential};

	for (int i = 0; i < 3; i++)
	{
		if (name == names[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return ((this->*makers[i])(target));
		}
	}
	throw Intern::InvalidForm();
}
