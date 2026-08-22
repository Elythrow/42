/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 21:43:01 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/22 21:27:42 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// void runTest(const std::string& input) {
// 	std::cout << input << std::endl;
// 	ScalarConverter::convert(input);
// 	std::cout << std::endl;
// }

// int main(void)
// {
// 	runTest("a");
// 	runTest("Z");
// 	runTest("!");
// 	runTest("7");
// 	runTest("0");
// 	runTest("42");
// 	runTest("-42");
// 	runTest("127");
// 	runTest("128");
// 	runTest("2147483647");
// 	runTest("-2147483648");
// 	runTest("2147483648");
// 	runTest("-2147483649");
// 	runTest("42.0f");
// 	runTest("3.14f");
// 	runTest("-0.5f");
// 	runTest("42.0");
// 	runTest("3.1415926535");
// 	runTest("-0.0000001");
// 	runTest("340282346638528859811704183484516925440.0f");
// 	runTest("1e39f");
// 	runTest("1e309");
// 	runTest("nan");
// 	runTest("nanf");
// 	runTest("inf");
// 	runTest("+inf");
// 	runTest("-inf");
// 	runTest("+inff");
// 	runTest("-inff");
// }

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error! Usage: convert <value>" << std::endl;
		return (EXIT_FAILURE);
	}
	ScalarConverter::convert(av[1]);
	return (EXIT_SUCCESS);
}