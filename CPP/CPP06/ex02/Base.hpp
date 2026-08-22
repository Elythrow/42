/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 20:22:59 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/22 21:01:11 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <exception>

class Base
{
	public:
		virtual ~Base();
};

Base*	generate(void);
void	identify(Base* base);
void	identify(Base& base);

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif