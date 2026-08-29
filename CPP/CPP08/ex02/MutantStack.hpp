/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 06:51:59 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/29 06:53:07 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
 
#include <stack>
#include <deque>
 
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack();
		MutantStack(const MutantStack &src);
		MutantStack &operator=(const MutantStack &rhs);
		~MutantStack();
 
		typedef typename Container::iterator				iterator;
		typedef typename Container::const_iterator			const_iterator;
		typedef typename Container::reverse_iterator		reverse_iterator;
		typedef typename Container::const_reverse_iterator	const_reverse_iterator;
 
		iterator				begin();
		iterator				end();
		const_iterator			begin() const;
		const_iterator			end() const;
 
		reverse_iterator		rbegin();
		reverse_iterator		rend();
		const_reverse_iterator	rbegin() const;
		const_reverse_iterator	rend() const;
};
 
#include "MutantStack.tpp"
