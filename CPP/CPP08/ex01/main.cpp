/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 06:21:56 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/29 18:47:36 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <climits>

void	fillRandom(std::vector<int> &v, size_t count)
{
	v.clear();
	v.reserve(count);
	for (size_t i = 0; i < count; ++i)
		v.push_back(rand());
}

void	testBig(size_t count)
{
	std::cout << "--- " << count << " numbers ---" << std::endl;

	std::vector<int>	numbers;
	Span				sp(count);

	fillRandom(numbers, count);
	sp.addRange(numbers.begin(), numbers.end());
	std::cout << "petit: " << sp.shortestSpan() << std::endl;
	std::cout << "grand : " << sp.longestSpan() << std::endl;

	try
	{
		sp.addNumber(1);
		std::cout << "error : no throw" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "error ajout de trop: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int	main(void)
{
	srand(static_cast<unsigned int>(time(NULL)));

	std::cout << "--- sujet ---" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(7);
	sp.addNumber(42);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "(expected 1 and 14)" << std::endl << std::endl;


	std::cout << "--- ajout de trop ---" << std::endl;
	Span sp1(3);

	try
	{
		sp1.addNumber(1);
		sp1.addNumber(2);
		sp1.addNumber(3);
		std::cout << "3 ajoute, span est maintenant plein" << std::endl;
		sp1.addNumber(4);
		std::cout << "error : no throw" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "erreur: " << e.what() << std::endl;
	}
	std::cout << std::endl;



	std::cout << "--- span vide ou avec un seul element ---" << std::endl;

	Span	empty(10);
	Span	single(10);

	try
	{
		std::cout << empty.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "vide  -> caught: " << e.what() << std::endl;
	}
	single.addNumber(42);
	try
	{
		std::cout << single.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "un seul element -> caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "--- Span(0) ---" << std::endl;

	Span sp2(0);

	try
	{
		sp2.addNumber(1);
		std::cout << "error : no throw" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;



	
	std::cout << "--- duplicats ---" << std::endl;

	Span dup(4);

	dup.addNumber(7);
	dup.addNumber(7);
	dup.addNumber(100);
	std::cout << "shortest: " << dup.shortestSpan() << std::endl;
	std::cout << "longest : " << dup.longestSpan() << std::endl;

	std::cout << "--- max---" << std::endl;	
	Span extreme(2);
	extreme.addNumber(INT_MIN);
	extreme.addNumber(INT_MAX);
	std::cout << extreme.longestSpan() << " (expected 4294967295)" << std::endl << std::endl;


	std::cout << "--- addRange avec differents conteneurs ---" << std::endl;

	int					raw[] = {10, 4, 25, 7, 19};
	std::list<int>		lst;
	std::vector<int>	vec;
	lst.push_back(300);
	lst.push_back(150);
	lst.push_back(310);
	vec.push_back(-5);
	vec.push_back(-9);
	Span sp5(10);
	sp5.addRange(raw, raw + 5);
	sp5.addRange(lst.begin(), lst.end());
	sp5.addRange(vec.begin(), vec.end());
	std::cout << sp5.shortestSpan() << std::endl;
	std::cout << sp5.longestSpan() << std::endl;

	std::cout << "--- copie et assignation ---" << std::endl;
	Span original(5);
	original.addNumber(1);
	original.addNumber(50);
	Span copy(original);
	Span assigned(1);
	assigned = original;
	copy.addNumber(1000);
	assigned.addNumber(-1000);
	std::cout << "og : " << original.longestSpan() << std::endl;
	std::cout << "copie : " << copy.longestSpan() << std::endl;
	std::cout << "assignation " << assigned.longestSpan() << std::endl;
	std::cout << std::endl;	

	testBig(10000);
	testBig(100000);
	return (0);
}

