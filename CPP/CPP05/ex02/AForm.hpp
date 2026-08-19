/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 12:56:34 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/19 14:42:40 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			grade2Sign;
		const int			grade2Exec;

	public:
	
		AForm();
		AForm(const std::string& name, const int grade2sign, const int grade2exec );
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		const std::string&	getName() const;
		bool				getsignedStatus() const;
		int					getgrade2Sign() const;
		int					getgrade2Exec() const;
		void				beSigned(const Bureaucrat& bureaucrat);
		virtual void		execute(Bureaucrat const & executor) const = 0;

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
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& o, const AForm& bureaucrat);

#endif