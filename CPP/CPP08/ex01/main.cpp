/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 06:21:56 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/29 06:28:05 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <climits>

static void	fillRandom(std::vector<int> &v, size_t count)
{
	v.clear();
	v.reserve(count);
	for (size_t i = 0; i < count; ++i)
		v.push_back(rand());
}

static void	subjectExample(void)
{
	std::cout << "===== subject example =====" << std::endl;

	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "(expected 2 and 14)" << std::endl << std::endl;
}

static void	testFullSpan(void)
{
	std::cout << "===== adding one too many =====" << std::endl;

	Span sp(3);

	try
	{
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		std::cout << "3 numbers added, span is now full" << std::endl;
		sp.addNumber(4);
		std::cout << "ERROR: no exception thrown" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void	testNoSpan(void)
{
	std::cout << "===== empty and single-element spans =====" << std::endl;

	Span	empty(10);
	Span	single(10);

	try
	{
		std::cout << empty.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "empty  -> caught: " << e.what() << std::endl;
	}

	single.addNumber(42);
	try
	{
		std::cout << single.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "single -> caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void	testZeroCapacity(void)
{
	std::cout << "===== Span(0) =====" << std::endl;

	Span sp(0);

	try
	{
		sp.addNumber(1);
		std::cout << "ERROR: no exception thrown" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void	testDuplicatesAndNegatives(void)
{
	std::cout << "===== duplicates and negative numbers =====" << std::endl;

	Span dup(4);

	dup.addNumber(7);
	dup.addNumber(-3);
	dup.addNumber(7);
	dup.addNumber(100);
	std::cout << "shortest: " << dup.shortestSpan() << " (expected 0)" << std::endl;
	std::cout << "longest : " << dup.longestSpan() << " (expected 103)" << std::endl;

	Span extreme(2);

	extreme.addNumber(INT_MIN);
	extreme.addNumber(INT_MAX);
	std::cout << "INT_MIN..INT_MAX longest: " << extreme.longestSpan()
		<< " (expected 4294967295)" << std::endl << std::endl;
}

static void	testIteratorRange(void)
{
	std::cout << "===== addRange with different containers =====" << std::endl;

	int					raw[] = {10, 4, 25, 7, 19};
	std::list<int>		lst;
	std::vector<int>	vec;

	lst.push_back(300);
	lst.push_back(150);
	lst.push_back(310);

	vec.push_back(-5);
	vec.push_back(-9);

	Span sp(10);

	sp.addRange(raw, raw + 5);
	sp.addRange(lst.begin(), lst.end());
	sp.addRange(vec.begin(), vec.end());
	std::cout << "10 numbers added from an array, a list and a vector" << std::endl;
	std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "longest : " << sp.longestSpan() << std::endl;

	Span small(3);
	std::vector<int> tooBig(5, 1);

	try
	{
		small.addRange(tooBig.begin(), tooBig.end());
		std::cout << "ERROR: no exception thrown" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "range too big -> caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void	testCopy(void)
{
	std::cout << "===== copy constructor and assignment =====" << std::endl;

	Span original(5);

	original.addNumber(1);
	original.addNumber(50);

	Span copy(original);
	Span assigned(1);

	assigned = original;

	copy.addNumber(1000);
	assigned.addNumber(-1000);

	std::cout << "original longest: " << original.longestSpan() << " (expected 49)" << std::endl;
	std::cout << "copy longest    : " << copy.longestSpan() << " (expected 999)" << std::endl;
	std::cout << "assigned longest: " << assigned.longestSpan() << " (expected 1050)" << std::endl;
	std::cout << std::endl;
}

static void	testBig(size_t count)
{
	std::cout << "===== " << count << " numbers =====" << std::endl;

	std::vector<int>	numbers;
	Span				sp(count);
	clock_t				start;

	fillRandom(numbers, count);

	start = clock();
	sp.addRange(numbers.begin(), numbers.end());
	std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "longest : " << sp.longestSpan() << std::endl;
	std::cout << "took " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC
		<< "s" << std::endl;

	try
	{
		sp.addNumber(1);
		std::cout << "ERROR: no exception thrown" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "adding one more -> caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int	main(void)
{
	srand(static_cast<unsigned int>(time(NULL)));

	subjectExample();
	testFullSpan();
	testNoSpan();
	testZeroCapacity();
	testDuplicatesAndNegatives();
	testIteratorRange();
	testCopy();
	testBig(10000);
	testBig(100000);
	return (0);
}


