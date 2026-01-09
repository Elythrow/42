/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:26:45 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/09 12:46:45 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap*	claptrap = new ClapTrap();
	std::cout << std::endl;
    ClapTrap	trapclap("Marcel");
	std::cout << std::endl;
	ClapTrap	b4rb0t("Maurice");
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "---- ScavTrap constructor ----" << std::endl;
    ScavTrap 	st("Michel");
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "ClapTrap tests" << std::endl;
    claptrap->attack("enemy");
    claptrap->takeDamage(5);
    claptrap->beRepaired(5);
    claptrap->takeDamage(10);
    claptrap->beRepaired(5);
	delete claptrap;
	std::cout << std::endl;
	std::cout << "ClapTrap tests" << std::endl;
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
	std::cout << std::endl;
	std::cout << "---- ScavTrap tests ----" << std::endl;
	st.attack("the door");
	st.takeDamage(20);
	st.beRepaired(10);
	st.guardGate();
	std::cout << std::endl;
	std::cout << "---- ScavTrap delete test ----" << std::endl;
	ScavTrap*	bernard = new ScavTrap();
	bernard->guardGate();
	delete bernard;
	std::cout << std::endl;
	return (0);
}