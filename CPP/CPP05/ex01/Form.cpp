/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 14:39:19 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/19 16:23:35 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("Default"), isSigned(false), grade2Sign(150),
	grade2Exec(150)
{
	if (grade2Sign > 150 ||  grade2Exec > 150) {
		throw (GradeTooLowException());
	}
	if (grade2Sign < 1 || grade2Exec < 1) {
		throw (GradeTooHighException());
	}
}

Form::Form(const std::string& name, const int grade2Sign,
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

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned),
	grade2Sign(other.grade2Sign), grade2Exec(other.grade2Exec) {}

Form&	Form::operator=(const Form& other) {
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return (*this);
}

Form::~Form() {}

const std::string&	Form::getName() const
{
	return (name);
}

bool	Form::getsignedStatus() const
{
	return (isSigned);
}

int	Form::getgrade2Sign() const
{
	return (grade2Sign);
}

int	Form::getgrade2Exec() const
{
	return (grade2Exec);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > grade2Sign) {
		throw GradeTooLowException();
	}
	isSigned = true;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Form: Grade is too high!");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Form: Grade is too low!");
}

std::ostream&	operator<<(std::ostream& os, const Form& form)
{
	std::string status;
	if (AForm.getsignedStatus())
		status = "signed";
	else
		status = "not signed";
	os << "Form name: " << form.getName() << ", signed: " << status << ", required grade to sign: " << form.getgrade2Sign() << ", required grade to execute: " << form.getgrade2Exec() << ".";
	return (os);
}


