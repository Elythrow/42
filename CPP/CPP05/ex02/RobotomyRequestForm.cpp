/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 13:35:20 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/19 14:51:28 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 25, 5), target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& _target) : AForm("RobotomyRequestForm", 25, 5), target(_target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string RobotomyRequestForm::getTarget() const
{
	return (target);
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{

	if (getsignedStatus() == false)
	{
			throw FormNotSignedException();
	}
	if (executor.getGrade() > getgrade2Exec())
	{
			throw GradeTooLowException();
	}
	std::cout << "Makes some drilling noises..." << std::endl;
	if (rand() % 2 == 0)
	{
		std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
	}
	else
	{
			std::cout << getTarget() << ": robotomy failed!" << std::endl;
	}
}