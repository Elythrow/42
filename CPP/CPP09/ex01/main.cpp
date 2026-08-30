#include "RPN.hpp"

#include <exception>
#include <iomanip>
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	try
	{
		RPN	rpn;

		/*
		** setprecision(15) keeps big integral results readable (a chain of
		** multiplications easily leaves the 6 significant digits printed by
		** default) while still printing 42 as "42" and not as "42.000000".
		*/
		std::cout << std::setprecision(15) << rpn.evaluate(argv[1])
			<< std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
