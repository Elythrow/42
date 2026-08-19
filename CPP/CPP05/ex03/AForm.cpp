/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 12:56:22 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/19 17:38:50 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("Default"), isSigned(false), grade2Sign(150),
	grade2Exec(150)
{
	if (grade2Sign > 150 ||  grade2Exec > 150) {
		throw (GradeTooLowException());
	}
	if (grade2Sign < 1 || grade2Exec < 1) {
		throw (GradeTooHighException());
	}
}

AForm::AForm(const std::string& name, const int grade2Sign,
	const int grade2Exec) :name(name), isSigned(false),
	grade2Sign(grade2Sign), grade2Exec(grade2Exec)
{
	if (grade2Sign > 150 ||  grade2Exec > 150) {
		throw (GradeTooLowException());
		}
	if (grade2Sign < 1 || grade2Exec < 1) {
		throw (GradeTooHighException());
	}
}

AForm::AForm(const AForm& other) : name(other.name), isSigned(other.isSigned),
	grade2Sign(other.grade2Sign), grade2Exec(other.grade2Exec) {}

AForm&	AForm::operator=(const AForm& other) {
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return (*this);
}

AForm::~AForm() {}

const std::string&	AForm::getName() const
{
	return (name);
}

bool	AForm::getsignedStatus() const
{
	return (isSigned);
}

int	AForm::getgrade2Sign() const
{
	return (grade2Sign);
}

int	AForm::getgrade2Exec() const
{
	return (grade2Exec);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > grade2Sign) {
		throw GradeTooLowException();
	}
	isSigned = true;
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Form: Grade is too high!");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Form: Grade is too low!");
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return ("Form: is not signed!");
}

std::ostream&	operator<<(std::ostream& os, const AForm& aForm)
{
	std::string status;
	if (aForm.getsignedStatus())
		status = "signed";
	else
		status = "not signed";
	os << "AForm name: " << aForm.getName() << ", signed: " << status << ", required grade to sign: " << aForm.getgrade2Sign() << ", required grade to execute: " << aForm.getgrade2Exec() << ".";
	return (os);
}


