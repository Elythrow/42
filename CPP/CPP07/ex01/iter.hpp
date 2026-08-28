/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 06:18:08 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/24 19:34:00 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstddef>

template <typename T, typename F>
void iter(T *array, std::size_t len, F f)
{
	for (std::size_t i = 0; i < len; i ++)
		f(array[i]);
}