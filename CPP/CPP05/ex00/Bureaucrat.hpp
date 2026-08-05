/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 19:48:23 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/05 20:20:36 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat{
	private :
		const std::string name;
		int grade;
	
	public :
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Bureaucrat grade is too high (less than 1).";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Bureaucrat grade is too low (greater than 150).";
        }
    };
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& bureaucrat);

#endif