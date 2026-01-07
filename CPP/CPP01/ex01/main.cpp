/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:55:50 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/07 21:23:51 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	int			N = 5;
	std::string	name = "Zombie";
	Zombie* 	horde = zombieHorde(N, name);
	
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}