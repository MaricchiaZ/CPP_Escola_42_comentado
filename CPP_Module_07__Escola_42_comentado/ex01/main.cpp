/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:45:32 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/07 20:35:02 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int main(void) {

    std::cout << "Testing with CHAR array" << std::endl;
	char c[5] = {'a', 'b', 'c', 'd', 'e'};
	iter(c, 5, print);
	std::cout << std::endl;

    std::cout << "Testing with INT array" << std::endl;
	std::string arr[] = {"Ants", "Butterflys", "Bugs"};
	iter(arr, 3, print);
    std::cout << std::endl;

    std::cout << "Testing with INT array" << std::endl;
	int i[5] = {1, 2, 3, 4, 5};
	iter(i, 5, print);
    std::cout << std::endl;

    std::cout << "Testing with DOUBLE array" << std::endl;
	double d[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	iter(d, 5, print);
    std::cout << std::endl;
    
}
