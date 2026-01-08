/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:12:54 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/08 14:58:47 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int 				value;
		static int const	fractionalBits = 8;
	public:
		Fixed();
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const &src);
		Fixed &operator=(const Fixed &other);
		~Fixed();
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;
		static Fixed &min(Fixed &nb1, Fixed &nb2);
        static const Fixed &min(const Fixed &nb1, const Fixed &nb2);
        static Fixed &max(Fixed &nb1, Fixed &nb2);
        static const Fixed &max(const Fixed &nb1, const Fixed &nb2);
        bool operator>(const Fixed &nb1);
        bool operator<(const Fixed &nb1);
        bool operator>=(const Fixed &nb1);
        bool operator<=(const Fixed &nb1);
        bool operator==(const Fixed &nb1);
        bool operator!=(const Fixed &nb1);
        Fixed operator+(const Fixed &nb1);
        Fixed operator-(const Fixed &nb1);
        Fixed operator*(const Fixed &nb1);
        Fixed operator/(const Fixed &nb1);
        Fixed &operator++();
        Fixed operator++(int);
        Fixed &operator--();
        Fixed operator--(int);
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);

#endif