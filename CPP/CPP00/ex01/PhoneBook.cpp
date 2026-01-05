/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:18:19 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/05 10:34:34 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->NbContacts = 0;
	this->OldestIndex = 0;
}

std::string PhoneBook::truncate_str(std::string str) const
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

static std::string get_input(std::string prompt)
{
	std::string input;

	while (input.empty())
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl;
			return "";
		}
		if (input.empty())
			std::cout << "Field cannot be empty. Please try again." << std::endl;
	}
	return input;
}

void PhoneBook::add_contact()
{
	std::string fn, ln, nn, pn, ds;
	int			index;

	fn = get_input("Enter first name: ");
	if (fn.empty()) return;
	ln = get_input("Enter last name: ");
	if (ln.empty()) return;
	nn = get_input("Enter nickname: ");
	if (nn.empty()) return;
	pn = get_input("Enter phone number: ");
	if (pn.empty()) return;
	ds = get_input("Enter darkest secret: ");
	if (ds.empty()) return;

	if (this->NbContacts < 8)
	{
		index = this->NbContacts;
		this->NbContacts++;
	}
	else
	{
		index = this->OldestIndex;
		this->OldestIndex = (this->OldestIndex + 1) % 8;
	}
	this->Contacts[index].set_contact(fn, ln, nn, pn, ds);
	std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::display_contacts() const
{
	std::cout << "|" << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;

	for (int i = 0; i < this->NbContacts; i++)
	{
		std::cout << "|" << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncate_str(this->Contacts[i].get_FirstName()) << "|";
		std::cout << std::setw(10) << truncate_str(this->Contacts[i].get_LastName()) << "|";
		std::cout << std::setw(10) << truncate_str(this->Contacts[i].get_Nickname()) << "|" << std::endl;
	}
}

void PhoneBook::display_contact(int index) const
{
	std::cout << "First Name: " << this->Contacts[index].get_FirstName() << std::endl;
	std::cout << "Last Name: " << this->Contacts[index].get_LastName() << std::endl;
	std::cout << "Nickname: " << this->Contacts[index].get_Nickname() << std::endl;
	std::cout << "Phone Number: " << this->Contacts[index].get_PhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->Contacts[index].get_DarkestSecret() << std::endl;
}

void PhoneBook::search_contact()
{
	std::string	input;
	int			index;

	if (this->NbContacts == 0)
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return;
	}
	display_contacts();
	std::cout << "Enter index to display: ";
	if (!std::getline(std::cin, input))
	{
		std::cout << std::endl;
		return;
	}
	if (input.length() != 1 || input[0] < '0' || input[0] > '7')
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}
	index = input[0] - '0';
	if (index >= this->NbContacts)
	{
		std::cout << "Index out of range." << std::endl;
		return;
	}
	display_contact(index);
}
