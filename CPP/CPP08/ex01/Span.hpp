/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 06:21:48 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/29 06:05:00 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
	private:
		unsigned int		_n;
		std::vector<int>	_numbers;
 
		Span();
 
	public:
		Span(unsigned int n);
		Span(const Span &src);
		Span &operator=(const Span &rhs);
		~Span();
 
		void			addNumber(int n);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
 
		template <typename InputIt>
		void			addRange(InputIt first, InputIt last);
 
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
 
#include "Span.tpp"
