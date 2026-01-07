/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:37:29 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/07 21:01:44 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <unistd.h>

int main(int ac, char **av)
{
    Harl	harl;
	int		i = 0;

	if (ac == 1)
	{
		std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
		while (i < 20)
		{
			harl.complain(levels[i % 4]);
			std::cout << std::endl;
			usleep(100000);
			i ++;
		}
		return (0);
	}
    if (ac == 2)
    {
        harl.complain(av[1]);
		return (0);
    }
	std::cout << "Usage: ./harl for a lot of noise or ./harl <level> (DEBUG, INFO, WARNING, ERROR)" << std::endl;
    return (0);
}