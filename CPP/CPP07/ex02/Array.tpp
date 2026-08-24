/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 20:36:17 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/24 18:09:23 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
Array<T>::Array(void) : array(NULL), array_size(0) {}

template <typename T>
Array<T>::Array(std::size_t size) : array(new T[size]), array_size(size) {}

template <typename T>
Array<T>::Array(const Array<T>& other) : array(new T[other.array_size]), array_size(other.array_size)
{
	for (std::size_t i = 0; i < array_size; ++i) {
		array[i] = other.array[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T>& other)
{
	if (this != &other) {
		T *temp = new T[other.array_size];
		for (std::size_t i = 0; i < other.array_size; ++i) {
			temp[i] = other.array[i];
		}
		delete[] array;
		array = temp;
		array_size = other.array_size;
	}
	return (*this);
}

template <typename T>
Array<T>::~Array(void)
{
	delete[] array;
}

template <typename T>
T &Array<T>::operator[](std::size_t pos)
{
	if (pos >= array_size) {
		throw std::out_of_range("Index out of array range");
	}
	return (array[pos]);
}

template <typename T>
const T &Array<T>::operator[](std::size_t pos) const
{
	if (pos >= array_size) {
		throw std::out_of_range("Index out of array range");
	}
	return (array[pos]);
}

template <typename T>
std::size_t Array<T>::size(void) const
{
	return array_size;
}

