/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 06:18:08 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/23 07:07:13 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T, typename F>
void iter(T *array, size_t len, F f)
{
	for (size_t i = 0; i < len; i ++)
		f(array[i]);
}