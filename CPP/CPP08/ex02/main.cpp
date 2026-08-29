/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 06:52:48 by gbazin            #+#    #+#             */
/*   Updated: 2026/08/29 06:53:04 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <string>
 
static void	subjectExampleMutantStack(void)
{
	std::cout << "<<<MUTANT" << std::endl;
 
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
 
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
 
	std::stack<int> s(mstack);
	std::cout << "copied into a plain std::stack, size " << s.size() << std::endl;
	std::cout << "MUTANT" << std::endl;
}
 
static void	subjectExampleList(void)
{
	std::cout << "<<<LIST" << std::endl;
 
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
 
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
 
	std::list<int> s(lst);
	std::cout << "copied into a plain std::stack, size " << s.size() << std::endl;
	std::cout << "LIST" << std::endl;
}
 
/* ************************************************************************** */
 
static void	testEmpty(void)
{
	std::cout << "===== empty stack =====" << std::endl;
 
	MutantStack<int> empty;
 
	std::cout << "empty(): " << (empty.empty() ? "true" : "false") << std::endl;
	std::cout << "size(): " << empty.size() << std::endl;
	std::cout << "begin() == end(): "
		<< (empty.begin() == empty.end() ? "true" : "false") << std::endl;
 
	int count = 0;
	for (MutantStack<int>::iterator it = empty.begin(); it != empty.end(); ++it)
		++count;
	std::cout << "loop ran " << count << " times" << std::endl << std::endl;
}
 
static void	testReverse(void)
{
	std::cout << "===== reverse iteration (top to bottom) =====" << std::endl;
 
	MutantStack<int> ms;
 
	for (int i = 1; i <= 5; ++i)
		ms.push(i * 10);
 
	std::cout << "forward: ";
	for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
 
	std::cout << "reverse: ";
	for (MutantStack<int>::reverse_iterator rit = ms.rbegin(); rit != ms.rend(); ++rit)
		std::cout << *rit << " ";
	std::cout << std::endl << std::endl;
}
 
static void	printConst(const MutantStack<int> &ms)
{
	std::cout << "const iteration: ";
	for (MutantStack<int>::const_iterator it = ms.begin(); it != ms.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
 
	std::cout << "const reverse  : ";
	for (MutantStack<int>::const_reverse_iterator rit = ms.rbegin(); rit != ms.rend(); ++rit)
		std::cout << *rit << " ";
	std::cout << std::endl;
}
 
static void	testConst(void)
{
	std::cout << "===== const iterators =====" << std::endl;
 
	MutantStack<int> ms;
 
	ms.push(1);
	ms.push(2);
	ms.push(3);
	printConst(ms);
	std::cout << std::endl;
}
 
static void	testWriteThroughIterator(void)
{
	std::cout << "===== writing through an iterator =====" << std::endl;
 
	MutantStack<int> ms;
 
	ms.push(1);
	ms.push(2);
	ms.push(3);
	for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
		*it *= 100;
 
	std::cout << "after *it *= 100: ";
	for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "top() is still consistent: " << ms.top() << std::endl << std::endl;
}
 
static void	testCopyAndAssign(void)
{
	std::cout << "===== copy constructor and assignment =====" << std::endl;
 
	MutantStack<int> original;
 
	original.push(1);
	original.push(2);
 
	MutantStack<int> copy(original);
	MutantStack<int> assigned;
 
	assigned.push(999);
	assigned = original;
 
	copy.push(3);
	assigned.pop();
 
	std::cout << "original size: " << original.size() << " (expected 2)" << std::endl;
	std::cout << "copy size    : " << copy.size() << " (expected 3)" << std::endl;
	std::cout << "assigned size: " << assigned.size() << " (expected 1)" << std::endl;
 
	std::cout << "original: ";
	for (MutantStack<int>::iterator it = original.begin(); it != original.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;
}
 
static void	testOtherContainers(void)
{
	std::cout << "===== other underlying containers =====" << std::endl;
 
	MutantStack<int, std::list<int> > listStack;
 
	listStack.push(7);
	listStack.push(8);
	listStack.push(9);
	std::cout << "backed by std::list: ";
	for (MutantStack<int, std::list<int> >::iterator it = listStack.begin();
		it != listStack.end(); ++it)
		std::cout << *it << " ";
	std::cout << "| top " << listStack.top() << std::endl;
 
	MutantStack<int, std::vector<int> > vectorStack;
 
	vectorStack.push(4);
	vectorStack.push(5);
	std::cout << "backed by std::vector: ";
	for (MutantStack<int, std::vector<int> >::iterator it = vectorStack.begin();
		it != vectorStack.end(); ++it)
		std::cout << *it << " ";
	std::cout << "| top " << vectorStack.top() << std::endl;
 
	MutantStack<std::string> strStack;
 
	strStack.push("hello");
	strStack.push("mutant");
	strStack.push("world");
	std::cout << "of std::string: ";
	for (MutantStack<std::string>::iterator it = strStack.begin();
		it != strStack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;
}
 
static void	testStress(void)
{
	std::cout << "===== 100000 elements =====" << std::endl;
 
	MutantStack<int>	ms;
	long				sum = 0;
 
	for (int i = 0; i < 100000; ++i)
		ms.push(i);
	for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
		sum += *it;
	std::cout << "size: " << ms.size() << std::endl;
	std::cout << "sum : " << sum << " (expected 4999950000)" << std::endl << std::endl;
}
 
int	main(void)
{
	subjectExampleMutantStack();
	subjectExampleList();
	std::cout << std::endl;
 
	testEmpty();
	testReverse();
	testConst();
	testWriteThroughIterator();
	testCopyAndAssign();
	testOtherContainers();
	testStress();
	return (0);
}
 
