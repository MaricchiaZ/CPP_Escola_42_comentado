/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:41:31 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/08 11:40:52 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>

int main(void) {
    
	std::cout << " ---------- TEST VECTOR ---------- " << std::endl;
    
	std::vector<int> v_test;

	for (int i = 0; i < 10; i++) {
		v_test.insert(v_test.begin(), i + 1);
	}
    std::cout << std::endl;
    
	std::cout << "1. Test valid numbers: " << std::endl;

	std::vector<int>::iterator it1 = easyfind(v_test, 1);
	std::cout << "Number found in vector : " << *it1 << std::endl;

	it1 = easyfind(v_test, 10);
	std::cout << "Number found in vector : " << *it1 << std::endl;
	std::cout << std::endl;
    
	std::cout << "2. Test valid numbers: " << std::endl;
	try {
		std::vector<int>::iterator it1 = easyfind(v_test, 11);
		std::cout << *it1 << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() ;
	}

	try {
		std::vector<int>::iterator it1 = easyfind(v_test, -1);
		std::cout << *it1 << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() ;
	}
    std::cout << std::endl;

	std::cout << " ----------- TEST LIST ----------- " << std::endl;
    
	std::list<int> l_test;

    for (int i = 0; i < 10; i++) {
    l_test.insert(l_test.begin(), i + 1);
	}
    std::cout << std::endl;

    std::cout << "3. Test valid numbers: " << std::endl;
    
	std::list<int>::iterator it2 = easyfind(l_test, 1);
	std::cout << "Number found in list : " << *it2  << std::endl;
    
	it2 = easyfind(l_test, 10);
	std::cout << "Number found in list : " << *it2  << std::endl;
	std::cout << std::endl;
    
	std::cout << "4. Test invalid numbers: " << std::endl;
    
	try {
		std::list<int>::iterator it2 = easyfind(l_test, 11);
		std::cout << *it2 << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() ;
	}

	try {
		std::list<int>::iterator it2 = easyfind(l_test, -1);
		std::cout << *it2 << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
