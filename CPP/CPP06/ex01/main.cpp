/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 20:00:40 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/22 20:37:02 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{

	Data d;

	uintptr_t raw = Serializer::serialize(&d);
	Data* recovered = Serializer::deserialize(raw);

	std::cout << "Original pointer: " << &d << std::endl;
	std::cout << "Raw value: " << raw << std::endl;
	std::cout << "Recovered pointer: " << recovered << std::endl;

	d.id = 1;
	d.name = "Test";
	std::cout << "Data: " << d.id << " " << d.name << std::endl;
	raw = Serializer::serialize(&d);
	std::cout << "Raw: " << Serializer::deserialize(raw)->id << " " << Serializer::deserialize(raw)->name << std::endl;	
	return (0);
}