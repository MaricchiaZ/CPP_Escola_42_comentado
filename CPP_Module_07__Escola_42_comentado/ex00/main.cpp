/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:38:54 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/07 20:42:53 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.hpp"
#include <iostream>

int main( void ) {
	int a = 2;
	int b = 3;
	
	
	std::cout << "Value a = " << a << ", Value b = " << b << std::endl;
	::swap( a, b );
	std::cout << "🔃 Swap values a and : b"<< std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << std::endl;
	
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "Value c = " << c << ", Value d = " << d << std::endl;
	::swap(c, d);
	std::cout << "🔃 Swap values c and d: "<< std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}
