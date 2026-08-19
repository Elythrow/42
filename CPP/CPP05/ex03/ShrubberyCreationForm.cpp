/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 13:35:28 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/19 15:36:15 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& _target) : AForm("ShrubberyCreationForm", 145, 137), target(_target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string& ShrubberyCreationForm::getTarget() const
{
	return (target);
}

void	ShrubberyCreationForm::printAsciiTrees(std::ofstream& file) const
{
    file << "        _^_ " << std::endl;
    file << "       /~~~\\ " << std::endl;
    file << "      /~~ ~~\\" << std::endl;
    file << "     /~~   ~~\\" << std::endl;
    file << "    /~~     ~~\\" << std::endl;
    file << "   /~~       ~~\\" << std::endl;
    file << "  /~~         ~~\\" << std::endl;
    file << " /______   ______\\" << std::endl;
    file << "        |||" << std::endl;
    file << "        |||" << std::endl;
    file << "~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl ;
}

void    ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!this->getsignedStatus())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getgrade2Exec())
        throw AForm::GradeTooLowException();
    std::ofstream file((this->target + "_shrubbery").c_str());
	if (!file.is_open())
	{
		std::cout << "Error: could not create " << this->target << "_shrubbery" << std::endl;
		return ;
	}
    for (int i = 0; i < 3; i ++)
        ShrubberyCreationForm::printAsciiTrees(file);
    file.close();
    std::cout << "file " << this->target << "_shrubbery created" << std::endl;
}