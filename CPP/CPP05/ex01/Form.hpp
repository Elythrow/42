/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 14:39:23 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/18 16:00:06 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			grade2Sign;
		const int			grade2Exec;

	public:
	
		Form();
		Form(const std::string& name, const int grade2sign, const int grade2exec );
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		const std::string&	getName() const;
		bool				getsignedStatus() const;
		int					getgrade2Sign() const;
		int					getgrade2Exec() const;
		void				beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& o, const Form& bureaucrat);

#endif