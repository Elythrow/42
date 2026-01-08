/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:12:58 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/08 18:31:46 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::Fixed(int const value) : value(value  * (1 << fractionalBits))
{
}

Fixed::Fixed(float const value) : value(roundf(value * (1 << fractionalBits)))
{
}

Fixed::Fixed(Fixed const &src) : value(src.value)
{
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
	return (static_cast<float>(this->value) / (1 << fractionalBits));
}
		
int Fixed::toInt() const
{
	return (this->value / (1 << fractionalBits));
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

Fixed Fixed::operator+(const Fixed &nb1) const
{
    return (Fixed(this->toFloat() + nb1.toFloat()));

}

Fixed Fixed::operator-(const Fixed &nb1) const
{
    return (Fixed(this->toFloat() - nb1.toFloat()));

}

Fixed Fixed::operator*(const Fixed &nb1) const
{
	Fixed		result;
	long long 	temp;

	temp = (static_cast<long long>(this->value) * nb1.value) >> fractionalBits;
    result.setRawBits(static_cast<int>(temp));
    return (result);
}

Fixed Fixed::operator/(const Fixed &nb1) const
{
	Fixed		result;
	long long 	temp;

	if(nb1.value == 0)
	{
		std::cerr << "Error: Division by zero" << std::endl;
		return (result);
	}
	temp = (static_cast<long long>(this->value) << fractionalBits) / nb1.value;
    result.setRawBits(static_cast<int>(temp));
    return (result);
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
