/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 14:06:33 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/19 12:42:46 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << "--- declaration fomulaires valides ---" << std::endl << std::endl;
	
	Form	formA;
	std::cout << formA << std::endl;

	Form	formB("test", 50, 50);
	std::cout << formB << std::endl;

	Form	formC(formB);
	std::cout << formC << std::endl;

	std::cout << std::endl << "--- declaration fomulaires invalides ---" << std::endl << std::endl;

	try {
		Form	signtropbas("sign_trop_bas", 156, 22);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form	signtrophaut("sign_trop_haut", 0, 22);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form	exectropbas("exec_trop_bas", 22, 185);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form	exectrophaut("exec_trop_haut", 22, -12);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "--- signatures invalides ---" << std::endl << std::endl;

	Form		invalide("invalide", 20, 50);
	Bureaucrat	signeur("test1", 25);

	signeur.signForm(invalide);
	std::cout << invalide << std::endl;

	std::cout << std::endl << "--- signatures valides ---" << std::endl << std::endl;

	Form		valide("valide", 20, 50);
	Bureaucrat	signeur2("test2", 20);
	Bureaucrat	signeur3("test3", 15);

	std::cout << signeur2 << std::endl;
	std::cout << valide << std::endl;
	std::cout << std::endl;
	signeur2.signForm(valide);
	std::cout << valide << std::endl;
	std::cout << std::endl;
	std::cout << signeur3 << std::endl;
	signeur3.signForm(valide);
	std::cout << valide << std::endl;
	std::cout << std::endl;
	
	Form	copie;

	std::cout << copie << std::endl;
	std::cout << std::endl;
	copie = valide;
	std::cout << copie << std::endl;

	return (0);
}