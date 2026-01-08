/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:13:01 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/08 18:41:37 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	Fixed c(5);
	Fixed d(10);
	std::cout << (c > d) << std::endl;   // 0
	std::cout << (c < d) << std::endl;   // 1
	std::cout << (c >= d) << std::endl;  // 0
	std::cout << (c <= d) << std::endl;  // 1
	std::cout << (c == d) << std::endl;  // 0
	std::cout << (c != d) << std::endl;  // 1

	// Test arithmetic
	std::cout << c + d << std::endl;     // 15
	std::cout << d - c << std::endl;     // 5
	std::cout << c * d << std::endl;     // 50
	std::cout << d / c << std::endl;     // 2
	std::cout << d / 0 << std::endl; 
	// Test min/max
	std::cout << Fixed::min(c, d) << std::endl; // 5
	std::cout << Fixed::max(c, d) << std::endl; // 10
	// Test with negative numbers
	Fixed neg(-5.5f);
	std::cout << neg << std::endl;       // -5.5

	// Test decrement
	Fixed e(1);
	std::cout << --e << std::endl;       // 0.996094
	std::cout << e-- << std::endl;       // 0.996094
	std::cout << e << std::endl;         // 0.992188
	return 0;
}