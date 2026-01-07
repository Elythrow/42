/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:37:29 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/07 20:54:12 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <unistd.h>

int main(int ac, char **av)
{
    Harl harl;

    if (ac == 2)
    {
        harl.complain(av[1]);
		return (0);
    }
	std::cout << "Usage: ./harl <level> (DEBUG, INFO, WARNING, ERROR)" << std::endl;
    return (0);
}