/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:25:06 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/19 16:40:22 by gbazin           ###   ########.fr       */
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

AForm* Intern::makeForm(const std::string& name, const std::string& target) const
{
    std::string form_names[3] = {"shrubbery", "robotomy", "presidential"};

    for (int i = 0; i < 3; i++)
    {
        if (name.find(form_names[i]) != std::string::npos)
        {
            std::cout << "Intern creates " << name << std::endl;
            switch (i)
            {
                case 0:
                    return (new ShrubberyCreationForm(target));
                case 1:
                    return (new RobotomyRequestForm(target));
                case 2:
                    return (new PresidentialPardonForm(target));
            }
        }
    }
    throw Intern::InvalidForm();
    return (NULL);
}