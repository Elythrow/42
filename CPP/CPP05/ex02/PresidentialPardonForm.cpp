/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 13:35:12 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/19 14:51:45 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& _target) : AForm("PresidentialPardonForm", 25, 5), target(_target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string PresidentialPardonForm::getTarget() const
{
	return (target);
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (getsignedStatus() == false)
	{
		throw FormNotSignedException();
	}
	if (executor.getGrade() > getgrade2Exec())
	{
		throw GradeTooLowException();
	}
	std::cout << getTarget() << "has been paroned by Zaphod Beeblebrox." << std::endl;
}