/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:56:03 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/05 14:54:01 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
	private :
		std::string name;
	public :
	    Zombie();
		~Zombie();
		void announce();
        void give_name(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif