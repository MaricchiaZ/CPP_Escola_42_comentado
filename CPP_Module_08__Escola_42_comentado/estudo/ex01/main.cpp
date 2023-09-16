/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:12:01 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/08 11:40:58 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "Span.hpp"

int main() 
{
    std::cout << "SIMPLE TEST - 6,3,17,9,11" << std::endl;
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span: " <<  sp.shortestSpan() << std::endl;
    std::cout << "Longest  span: " << sp.longestSpan() << std::endl;
    std::cout << std::endl;


    std::cout << "SIMPLE TEST - 1 element" << std::endl;
    Span sp1 = Span(1);

	sp1.addNumber(1);
    std::cout << "Try add one more number" << std::endl;
	try {
		sp1.addNumber(1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}
    std::cout << std::endl;


    std::cout << "BIG TEST - 100.00 elements" << std::endl;
	Span sp2 = Span(10000);

    // fill list of 100.000 elements
	int space = 10000;

    int begin = 0;
    int end = 9999;

	if (end - begin > space)
		throw std::out_of_range("Span::addNumber: list is full");
	while (begin < space) {
		sp2.addNumber(begin);
		begin++;
 	}

	std::cout << "Span size: " << sp2.getVector()->size() << std::endl;
    std::cout << "Shortest span: " <<  sp2.shortestSpan() << std::endl;
    std::cout << "Longest  span: " << sp2.longestSpan() << std::endl;
    std::cout << std::endl;
    
	std::cout << "EXTRA BIG TEST - 100.00 elements" << std::endl;
	Span sp3 = Span(100000);

	std::vector<int> vec;
	for (int i = 0; i < 100000; i++)
	{
		vec.push_back(i + 1);
	}

	sp3.addNumber(vec.begin(), vec.end());

	std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
	std::cout << "Longest  span: "<< sp3.longestSpan() << std::endl;
    
    return 0; 
}
