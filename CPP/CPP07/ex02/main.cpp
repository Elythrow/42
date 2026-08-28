/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 17:57:48 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/24 19:25:10 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	std::cout << "--- array<int> ---" << std::endl;
	Array<int> test_int(10);
	for (unsigned int i = 0; i < test_int.size(); ++i) {
		test_int[i] = i * 5;
	}
	std::cout << std::endl;

	std::cout << "affichage array<int> :" << std::endl;
	for (unsigned int i = 0; i < test_int.size(); ++i) {
		std::cout << test_int[i] << " ";
	}
	std::cout << std::endl << std::endl;

	Array<int> copy_int(test_int);
	std::cout << "affichage copie array<int> :" << std::endl;
	for (unsigned int i = 0; i < copy_int.size(); ++i) {
		std::cout << copy_int[i] << " ";
	}
	std::cout << std::endl << std::endl;

	copy_int[0] = 1;
	std::cout << "affichage copie apres modification :" << std::endl;
	for (unsigned int i = 0; i < copy_int.size(); ++i) {
		std::cout << copy_int[i] << " ";
	}
	std::cout << std::endl << std::endl;
		
	std::cout << "affichage array<int> apres modification copie :" << std::endl;
	for (unsigned int i = 0; i < test_int.size(); ++i) {
		std::cout << test_int[i] << " ";
	}
	std::cout << std::endl << std::endl;

	Array<int> assign_int;
	assign_int = test_int;
	assign_int[1] = 555;
	std::cout << "--- affichage assign_int apres assignement :" << std::endl;
	for (unsigned int i = 0; i < assign_int.size(); ++i) {
		std::cout << assign_int[i] << " ";
	}
	std::cout << std::endl << std::endl;

	try {
		std::cout << "test index > size :" << std::endl;
		assign_int[100] = 42;
	} catch (const std::out_of_range& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << "--- array<string> ---"  << std::endl << std::endl;
	Array<std::string> test_string(3);
	test_string[0] = "gare";
	test_string[1] = "aux";
	test_string[2] = "soupeurs";

	std::cout << "affichage array<string> :" << std::endl;
	for (unsigned int i = 0; i < test_string.size(); ++i) {
		std::cout << test_string[i] << " ";
	}
	std::cout << std::endl << std::endl;

	Array<std::string> copy_string(test_string);
	std::cout << "affichage copie array<string> :" << std::endl;
	for (unsigned int i = 0; i < copy_string.size(); ++i) {
		std::cout << copy_string[i] << " ";
	}
	std::cout << std::endl << std::endl;

	copy_string[0] = "gloire";
	std::cout << "affichage copie apres modification :" << std::endl;
	for (unsigned int i = 0; i < copy_string.size(); ++i) {
		std::cout << copy_string[i] << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "affichage array<string> apres modification copie :" << std::endl;
	for (unsigned int i = 0; i < test_string.size(); ++i) {
		std::cout << test_string[i] << " ";
	}
	std::cout << std::endl << std::endl;

	// Test exception for out of bounds
	try {
		std::cout << "test index > size :" << std::endl;
		test_string[5] = "throw";
	} catch (const std::out_of_range& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << "test vide :" << std::endl;
	Array<int> vide;
	std::cout << "taille d'un tableau vide :" << vide.size() << std::endl;
	try {
		vide[0] = 1;
	} catch (const std::out_of_range& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
return (0);
}