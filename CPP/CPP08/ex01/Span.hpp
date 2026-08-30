/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 06:21:48 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/29 18:15:29 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <cstddef>

class Span
{
	private:
		unsigned int		n;
		std::vector<int>	numbers;
 
		Span();
 
	public:
		Span(unsigned int n);
		Span(const Span &src);
		Span &operator=(const Span &rhs);
		~Span();
 
		void			addNumber(int x);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
 
    	template <typename Iterator>
    	void addRange(Iterator begin, Iterator end);
 
		class SpanFullException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
 
		class NoSpanException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

template <typename Iterator>
void	Span::addRange(Iterator begin, Iterator end)
{
	size_t	count;

	count = static_cast<size_t>(std::distance(begin, end));
	if (count > n - numbers.size())
		throw SpanFullException();
	numbers.insert(numbers.end(), begin, end);
}