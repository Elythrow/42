/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 05:36:43 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/28 06:01:24 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>

int main()
{
	std::cout << "--- vector ---" << std::endl;

	std::vector<int> vec;

	for (int i = 0; i < 10; i++)
		vec.push_back(i);

	try
	{
		std::cout << "Trouve: " << *easyfind(vec, 3) << std::endl;
		std::cout << "Trouve: " << *easyfind(vec, 100) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "pas trouve" << std::endl;
	}

	std::cout << "--- deque ---" << std::endl;

	std::deque<int> deq;

	for (int i = 0; i < 10; i++)
		deq.push_back(i);

	try
	{
		std::cout << "Trouve: " << *easyfind(deq, 3) << std::endl;
		std::cout << "Trouve: " << *easyfind(deq, 100) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "pas trouve" << std::endl;
	}

	return (0);
}