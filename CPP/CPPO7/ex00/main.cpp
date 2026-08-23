/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 06:46:12 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/23 07:03:32 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main ()
{
	int a = 1;
	int b = 2;
	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "AVANT SWAP" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "APRES SWAP" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl; 
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << "AVANT SWAP" << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "APRES SWAP" << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl; 
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	return (0); 
	
}