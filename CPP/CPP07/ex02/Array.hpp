/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 20:36:20 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/24 18:40:07 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <cstddef>

template <typename T>
class Array
{
	private:
   		T			*array;
    	std::size_t	array_size;
		
	public:
    	Array();
    	Array(std::size_t size);
    	Array(const Array &other);
    	Array &operator=(const Array &other);
    	~Array();
		
    	T &operator[](std::size_t index);
		const T &operator[](std::size_t index) const;
    	std::size_t size() const;
};

#include "Array.tpp"
