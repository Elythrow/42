/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 20:36:20 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/24 02:18:20 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <string>
#include <cstddef>

template <typename T>
class Array
{
	private:
   		T				*array;
    	unsigned int	array_size;
		
	public:
    	Array();
    	Array(unsigned int size);
    	Array(const Array &other);
    	Array &operator=(const Array &other);
    	~Array();
		
    	T &operator[](std::size_t index);
		T &operator[](std::size_t index) const;
    	unsigned int size() const;
};

#include "Array.tpp"
