/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 06:52:48 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/29 18:56:29 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <string>
 
void	subjectExampleMutantStack(void)
{
	std::cout << "MUTANT" << std::endl;
 
	MutantStack<int> mstack;
 
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
 
	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();
 
	++ it;
	-- it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++ it;
	}
 
	std::stack<int> s(mstack);
	std::cout << "copied into a plain std::stack, size " << s.size() << std::endl;
}
 
void	subjectExampleList(void)
{
	std::cout << "LISTE" << std::endl;
 
	std::list<int> lst;
 
	lst.push_back(5);
	lst.push_back(17);
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
 
	std::list<int>::iterator	it = lst.begin();
	std::list<int>::iterator	ite = lst.end();
 
	++ it;
	-- it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++ it;
	}
 
	std::list<int> s(lst);
	std::cout << "copied into a plain std::stack, size " << s.size() << std::endl;
}
 
void	testEmpty(void)
{
	std::cout << "--- stack vide ---" << std::endl;
 
	MutantStack<int> empty;
 
	std::cout << "vide(): " << (empty.empty() ? "true" : "false") << std::endl;
	std::cout << "size(): " << empty.size() << std::endl;
	std::cout << "begin() == end(): "
		<< (empty.begin() == empty.end() ? "true" : "false") << std::endl;
 
	int count = 0;
	for (MutantStack<int>::iterator it = empty.begin(); it != empty.end(); ++it)
		++count;
	std::cout << "loop ran " << count << " times" << std::endl << std::endl;
}
 
void	testCopyAndAssign(void)
{
	std::cout << "--- copie et assignation ---" << std::endl;
 
	MutantStack<int> original;
 
	original.push(1);
	original.push(2);
 
	MutantStack<int> copy(original);
	MutantStack<int> assigned;
 
	assigned.push(999);
	assigned = original;
 
	copy.push(3);
	assigned.pop();
 
	std::cout << "ogc: " << original.size() << std::endl;
	std::cout << "copie : " << copy.size() << std::endl;
	std::cout << "assignation  " << assigned.size() << std::endl;
 
	std::cout << "original: ";
	for (MutantStack<int>::iterator it = original.begin(); it != original.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;
}
 
void	testOtherContainers(void)
{
	std::cout << "--- other underlying containers ---" << std::endl;
 
	MutantStack<int, std::list<int> > listStack;
 
	listStack.push(7);
	listStack.push(8);
	listStack.push(9);
	std::cout << "std::list: ";
	for (MutantStack<int, std::list<int> >::iterator it = listStack.begin();
		it != listStack.end(); ++it)
		std::cout << *it << " ";
	std::cout << "| top " << listStack.top() << std::endl;
 
	MutantStack<int, std::vector<int> > vectorStack;
 
	vectorStack.push(4);
	vectorStack.push(5);
	std::cout << "std::vector: ";
	for (MutantStack<int, std::vector<int> >::iterator it = vectorStack.begin();
		it != vectorStack.end(); ++it)
		std::cout << *it << " ";
	std::cout << "| top " << vectorStack.top() << std::endl;
 
	MutantStack<std::string> strStack;
 
	strStack.push("hello");
	strStack.push("mutant");
	strStack.push("world");
	std::cout << "std::string: ";
	for (MutantStack<std::string>::iterator it = strStack.begin();
		it != strStack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;
}
 
void	testStress(void)
{
	std::cout << "--- 100000 elements ---" << std::endl;
 
	MutantStack<int>	ms;
	long				sum = 0;
 
	for (int i = 0; i < 100000; ++i)
		ms.push(i);
	for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
		sum += *it;
	std::cout << "tqille : " << ms.size() << std::endl;
	std::cout << "somme : " << sum << " (normalement 4999950000)" << std::endl << std::endl;
}

int	main(void)
{
	subjectExampleMutantStack();
	subjectExampleList();
	std::cout << std::endl;
 
	testEmpty();
	testCopyAndAssign();
	testOtherContainers();
	testStress();
	return (0);
}
 
