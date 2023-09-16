/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:57:40 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/08 11:41:35 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <stack>

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	std::list<int> list;

	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	list.push_back(5);
	list.push_back(17);
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	list.pop_back();
	mstack.pop();
	
	MutantStack<int>::iterator mstack_it = mstack.begin();
	MutantStack<int>::iterator mstack_ite = mstack.end();
	std::list<int>::iterator list_it = list.begin();
	std::list<int>::iterator list_ite = list.end();

	++mstack_it;
	--mstack_it;

	std::cout << "MutantStack numbers: "<< std::endl;
	while (mstack_it != mstack_ite)
	{
		std::cout << *mstack_it << std::endl;
		++mstack_it;
	}
    std::cout << std::endl;

	std::cout << "List numbers: "<< std::endl;
	while (list_it != list_ite)
	{
		std::cout << *list_it << std::endl;
		++list_it;
	}
    std::cout << std::endl;

    std::cout << "MutantStack char: "<< std::endl;
    MutantStack<char>	mstack_char;
    MutantStack<char>::iterator iter_char;
	
	for(char i='a'; i<='z'; i++)
		mstack_char.push(i);
	for(iter_char = mstack_char.begin(); iter_char != mstack_char.end(); iter_char++)
		std::cout << *iter_char << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "List char: "<< std::endl;
    std::list<char>	list_char;
    std::list<char>::iterator list_char_it;
	
	for(char i='a'; i<='z'; i++)
		list_char.push_back(i);
	for(list_char_it = list_char.begin(); list_char_it != list_char.end(); list_char_it++)
		std::cout << *list_char_it << " ";
    std::cout << std::endl;

}
