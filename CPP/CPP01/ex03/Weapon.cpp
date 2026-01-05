/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:00:56 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/05 17:57:48 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon()
{
}

void Weapon::setType(std::string type)
{
	this->type = type;
}

std::string const &Weapon::getType() const
{
	std::string const &ref = this->type;
	return (ref);
}

