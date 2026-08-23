/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 06:46:12 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/23 07:13:24 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void print(int i)
{
	std::cout << i << std::endl;
}

void increment(int &i)
{
	i++;
}

void doubledouble(int &i)
{
	i *= 2;
}


int main ()
{
	int		array[5] = {0, 1, 2, 3, 4};
	char	array2[] = "abcde";

	iter(array, 5, print);
	std::cout << std::endl;
	iter(array, 5, increment);
	iter(array, 5, print);
	std::cout << std::endl;
	iter(array, 5, doubledouble);
	iter(array, 5, print);
	std::cout << std::endl;
	iter(array2, 5, print);
	std::cout << std::endl;	

	return (0); 
	
}