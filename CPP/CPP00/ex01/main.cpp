/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:18:14 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/05 00:34:05 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


int	main(void)
{
	PhoneBook	phonebook;
	std::string	command;

	std::cout << "Welcome to your PhoneBook!" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;

	while (true)
	{
		std::cout << "> ";
		if (!std::getline(std::cin, command))
		{
			std::cout << std::endl;
			break;
		}
		if (command == "ADD")
			phonebook.add_contact();
		else if (command == "SEARCH")
			phonebook.search_contact();
		else if (command == "EXIT")
			break;
	}
	return (0);
}
