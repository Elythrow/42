/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 06:18:08 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/24 19:19:24 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
T max(T a, T b)
{
    if (b < a)
        return (a);
    return (b);
}

template <typename T>
T min(T a, T b)
{
    if (a < b)
        return (a);
    return (b);
}

template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}