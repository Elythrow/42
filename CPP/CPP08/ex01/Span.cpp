/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 06:21:51 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/28 21:52:51 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n);
Span::Span(const Span &src);
Span &Span::operator=(const Span &rhs);
~Span();





unsigned int _n;
std::vector<int> _numbers;

void	addNumber(int n);
int		shortestSpan();
int		longestSpan();