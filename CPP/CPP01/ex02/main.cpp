/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:38:39 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/05 15:56:54 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "string address: " << &str << std::endl;
	std::cout << "stringPTR hold address: " << stringPTR << std::endl;
	std::cout << "stringREF hold address: " << &stringREF << std::endl << std::endl << std::endl;

	std::cout << "string value: " << str << std::endl;
	std::cout << "stringPTR value: " << *stringPTR << std::endl;
	std::cout << "stringREF value: " << stringREF << std::endl;
	
	return (0);
}