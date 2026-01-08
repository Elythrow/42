/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:55:50 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/08 11:38:52 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

int main() {
	int					N = 5;
	std::string			name = "Zombie";
	Zombie* 			horde = zombieHorde(N, name);
	std::ostringstream	oss;
	
	for (int i = 0; i < N; i++)
	{
		oss.str("");
		oss << (i + 1);
		std::cout << oss.str() << ": ";
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}