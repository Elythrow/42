/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 06:21:48 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/28 07:21:26 by gbazin           ###   ########.fr       */
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
		unsigned int _n;
		std::vector<int> _numbers;
	
	public:
		Span(unsigned int n);
		Span(const Span &src);
		Span &operator=(const Span &rhs);
		~Span();

		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();
};