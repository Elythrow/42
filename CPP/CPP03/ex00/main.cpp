/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:26:45 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/08 22:25:54 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

# include "ClapTrap.hpp"

int main(void)
{
    ClapTrap*	claptrap = new ClapTrap();
    ClapTrap	trapclap("trapclap");
	ClapTrap	b4rb0t("b4r-b0t");

    claptrap->attack("enemy");
    claptrap->takeDamage(5);
    claptrap->beRepaired(5);
    claptrap->takeDamage(10);
    claptrap->beRepaired(5);
	delete claptrap;
    trapclap.attack("enemy");
	b4rb0t.takeDamage(1);
    trapclap.attack("enemy");
	b4rb0t.takeDamage(1);
	trapclap.attack("enemy");
	b4rb0t.takeDamage(1);
	trapclap.attack("enemy");
	b4rb0t.takeDamage(1);
	trapclap.attack("enemy");
	b4rb0t.takeDamage(1);
	trapclap.attack("enemy");
	b4rb0t.takeDamage(1);
	trapclap.attack("enemy");
	b4rb0t.takeDamage(1);
	trapclap.attack("enemy");
	b4rb0t.takeDamage(1);
	trapclap.attack("enemy");
	b4rb0t.takeDamage(1);
	trapclap.attack("enemy");
	b4rb0t.takeDamage(1);
	trapclap.attack("enemy");
	b4rb0t.takeDamage(1);
	return (0);
}