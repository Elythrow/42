/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 21:43:08 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/23 01:15:21 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
 
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}
 
ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}
 
ScalarConverter::~ScalarConverter() {}

bool isWhole(double value)
{
    return (value == std::floor(value));
}
 
void resetFloatFormat(int precision)
{
    std::cout.unsetf(std::ios::floatfield);
    std::cout << std::setprecision(precision);
}

void	printChar(double value)
{
	std::cout << "char: ";
	if (value < 0 || value > 127)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" <<static_cast<char>(value) << "'" << std::endl;
}
 
void	printInt(double value)
{
	std::cout << "int: ";
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}
 

void    printFloat(double value)
{
    float   f = static_cast<float>(value);
 
    std::cout << "float: ";
    if (value > std::numeric_limits<float>::max())
        std::cout << "+inff" << std::endl;
    else if (value < -std::numeric_limits<float>::max())
        std::cout << "-inff" << std::endl;
    else if (isWhole(f))
        std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    else
    {
        resetFloatFormat(FLT_DIG + 1);
        std::cout << f << "f" << std::endl;
    }
}
 
void    printDouble(double value)
{
    std::cout << "double: ";
    if (value > std::numeric_limits<double>::max())
        std::cout << "+inf" << std::endl;
    else if (value < -std::numeric_limits<double>::max())
        std::cout << "-inf" << std::endl;
    else if (isWhole(value))
        std::cout << std::fixed << std::setprecision(1) << value << std::endl;
    else
    {
        resetFloatFormat(DBL_DIG + 1);
        std::cout << value << std::endl;
    }
}

/* Affiche les quatre conversions d'une meme valeur. */
void	printAll(double value)
{
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
 
/* Pseudo litteraux : char et int sont toujours impossibles. */
void	printPseudo(const std::string &asFloat, const std::string &asDouble)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << asFloat << std::endl;
	std::cout << "double: " << asDouble << std::endl;
}
 
void	printImpossible(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}
 
 
void	ScalarConverter::convert(const std::string &literal)
{
	char	*end;
 
	if (literal == "nan" || literal == "nanf")
	{
		printPseudo("nanf", "nan");
		return;
	}
	if (literal == "+inf" || literal == "+inff"
		|| literal == "inf" || literal == "inff")
	{
		printPseudo("+inff", "+inf");
		return;
	}
	if (literal == "-inf" || literal == "-inff")
	{
		printPseudo("-inff", "-inf");
		return;
	}
 
	if (literal.length() == 1 && std::isprint(literal[0])
		&& !std::isdigit(literal[0]))
	{
		printAll(static_cast<double>(literal[0]));
		return;
	}

	long int i = std::strtol(literal.c_str(), &end, 10);
	if (*end == '\0' && end != literal.c_str() && i >= std::numeric_limits<int>::min() && i <= std::numeric_limits<int>::max())
	{
		printAll(static_cast<double>(i));
		return;
	}
 
	double f = std::strtod(literal.c_str(), &end);
	if ((*end == 'f' || *end == 'F') && *(end + 1) == '\0' && end != literal.c_str())
	{
		printAll(f);
		return;
	}
 
	double d = std::strtod(literal.c_str(), &end);
	if (*end == '\0' && end != literal.c_str())
	{
		if (d == HUGE_VAL)
		{
			printPseudo("+inff", "+inf");
			return;
		}
		printAll(d);
		return;
	}
	printImpossible();
}
