/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:12:58 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/08 15:35:52 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::Fixed(int const value)
{
	this->value = value << fractionalBits;
}

Fixed::Fixed(float const value)
{
	this->value = roundf(value * (1 << fractionalBits));
}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->value = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits() const
{
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat() const
{
	return ((float)this->value / (1 << fractionalBits));
}
		
int Fixed::toInt() const
{
	return (this->value >> fractionalBits);
}

Fixed &Fixed::min(Fixed &nb1, Fixed &nb2)
{
	if (nb1.getRawBits() < nb2.getRawBits())
		return (nb1);
	return (nb2);
}

const Fixed &Fixed::min(const Fixed &nb1, const Fixed &nb2)
{
	if (nb1.getRawBits() < nb2.getRawBits())
		return (nb1);
	return (nb2);
}

Fixed &Fixed::max(Fixed &nb1, Fixed &nb2)
{
	if (nb1.getRawBits() > nb2.getRawBits())
		return (nb1);
	return (nb2);
}

const Fixed &Fixed::max(const Fixed &nb1, const Fixed &nb2)
{
	if (nb1.getRawBits() > nb2.getRawBits())
		return (nb1);
	return (nb2);
}

bool Fixed::operator>(const Fixed &nb1)
{
	return (this->value > nb1.getRawBits());
}

bool Fixed::operator<(const Fixed &nb1)
{
	return (this->value < nb1.getRawBits());

}
bool Fixed ::operator>=(const Fixed &nb1)
{
	return (this->value >= nb1.getRawBits());
}

bool Fixed::operator<=(const Fixed &nb1)
{
	return (this->value <= nb1.getRawBits());
}

bool Fixed::operator==(const Fixed &nb1)
{
	return (this->value == nb1.getRawBits());
}

bool Fixed::operator!=(const Fixed &nb1)
{
	return (this->value != nb1.getRawBits());
}

Fixed Fixed::operator+(const Fixed &nb1)
{
    return (Fixed(this->toFloat() + nb1.toFloat()));

}

Fixed Fixed::operator-(const Fixed &nb1)
{
    return (Fixed(this->toFloat() - nb1.toFloat()));

}

Fixed Fixed::operator*(const Fixed &nb1)
{
    return (Fixed(this->toFloat() * nb1.toFloat()));
}

Fixed Fixed::operator/(const Fixed &nb1)
{
    return (Fixed(this->toFloat() / nb1.toFloat()));
}

Fixed &Fixed::operator++()
{
	this->value ++;
	return (*this);

}
Fixed Fixed::operator++(int)
{
	Fixed temp = *this;

	this->value ++;
	return (temp);
}

Fixed &Fixed::operator--()
{
	this->value --;
	return (*this);

}
Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	
	this->value --;
	return (temp);
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}
