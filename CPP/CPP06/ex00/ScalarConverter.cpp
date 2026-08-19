/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 21:43:08 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/19 23:32:26 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter () {}

ScalarConverter::~ScalarConverter () {}

ScalarConverter::ScalarConverter (const ScalarConverter& other)
{
    *this = other;
}


ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    if (this != &other)
    {
    }
    return (*this);
}

void print_char(std::string)
{

}

void print_int(std::string)
{

}

void print_float(std::string)
{

}

void print_double(std::string)
{

}

void convert(const std::string& literal)
{
    print_char(literal);
    print_int(literal);
    print_float(literal);
    print_double(literal);
}