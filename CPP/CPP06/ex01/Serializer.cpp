/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 13:10:26 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/22 20:00:15 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer &copy)
{
    *this = copy;
}

Serializer &Serializer::operator=(const Serializer &copy)
{
    if (this != &copy)
    {
    }
    return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}