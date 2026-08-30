/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 06:21:51 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/29 18:16:23 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
 
Span::Span() : n(0) {}
 
Span::Span(unsigned int n) : n(n) {}
 
Span::Span(const Span &src) : n(src.n), numbers(src.numbers) {}
 
Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		n = rhs.n;
		numbers = rhs.numbers;
	}
	return (*this);
}
 
Span::~Span() {}
 
void	Span::addNumber(int x)
{
	if (numbers.size() >= static_cast<size_t>(n))
		throw SpanFullException();
	numbers.push_back(x);
}
 
unsigned int	Span::shortestSpan() const
{
	if (numbers.size() < 2)
		throw NoSpanException();
 
	std::vector<int>	sorted(numbers);
	std::sort(sorted.begin(), sorted.end());
 
	unsigned int	best;
	unsigned int	diff;
 
	best = static_cast<unsigned int>(sorted[1]) - static_cast<unsigned int>(sorted[0]);
	for (size_t i = 2; i < sorted.size(); ++i)
	{
		diff = static_cast<unsigned int>(sorted[i])
			- static_cast<unsigned int>(sorted[i - 1]);
		if (diff < best)
			best = diff;
	}
	return (best);
}
 
unsigned int	Span::longestSpan() const
{
	if (numbers.size() < 2)
		throw NoSpanException();
 
	std::vector<int>::const_iterator	minIt;
	std::vector<int>::const_iterator	maxIt;
 
	minIt = std::min_element(numbers.begin(), numbers.end());
	maxIt = std::max_element(numbers.begin(), numbers.end());
	return (static_cast<unsigned int>(*maxIt) - static_cast<unsigned int>(*minIt));
}
 
const char	*Span::SpanFullException::what() const throw()
{
	return ("Span is full: cannot store more numbers");
}
 
const char	*Span::NoSpanException::what() const throw()
{
	return ("Not enough numbers stored to compute a span");
}
