/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 13:35:28 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/19 14:51:24 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 25, 5), target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& _target) : AForm("ShrubberyCreationForm", 25, 5), target(_target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getTarget() const
{
	return (target);
}

void	ShrubberyCreationForm::printAsciiTrees(const std::string& target) const {

	std::ofstream	fileStream((target + "_shrubbery").c_str());
	
	if (fileStream.is_open() == false)
	{
		throw std::runtime_error("ShrubberyCreationForm: File creation failed " + target);
	}
	for (size_t i = 0; i < 3; ++i)
	{
		fileStream << "      _-_" << std::endl;
		fileStream << "   /~~   ~~\\" << std::endl;
		fileStream << " /~~     o  ~~\\" << std::endl;
		fileStream << "{      ~~       }" << std::endl;
		fileStream << " \\  o-     -_  /" << std::endl;
		fileStream << "	 ~  \\\\ //  ~" << std::endl;
		fileStream << "_- -   | | _- _" << std::endl;
		fileStream << "  _ -  | |   -_" << std::endl;
		fileStream << "     // \\\\" << std::endl;
	}
	fileStream.close();
	if (fileStream.fail()) {
		throw std::runtime_error("ShrubberyRequestForm: failed to close file properly " + target);
	}
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (getsignedStatus() == false)
	{
		throw FormNotSignedException();
	}
	if (executor.getGrade() > getgrade2Exec())
	{
		throw GradeTooLowException();
	}
	printAsciiTrees(getTarget());
}