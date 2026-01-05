/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:55:50 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/05 14:27:45 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie* zombie1 = newZombie("Zombie1");
	zombie1->announce();
	delete zombie1;
	randomChump("Zombie2");
	return (0);
}