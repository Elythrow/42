/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:24:58 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/07 19:52:47 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

//fonction remplacement

//fonction ouverture fichier



int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: ./sed <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	sed	data;
	data.filename = av[1];
	data.s1 = av[2];
	data.s2 = av[3];
	return (0);
}