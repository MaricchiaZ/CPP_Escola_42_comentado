/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:37:54 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/05 09:54:03 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

/* 
	test cases: 420, -4.25, 42.0f, 0, 2147483649, nan, -inf, string
*/

int main(int argc, char **argv) {
	if (argc == 2) {
		std::string input = argv[1];
		try{
				ScalarConverter conv(input);
				conv.printConversion();
		}
		catch (std::exception &e)
		{
			std::cout << "Error : " << e.what() << std::endl;
			return (1);
		}
	}
	else {
		std::cerr << "Incorrect number of parameters\n";
	}
}
