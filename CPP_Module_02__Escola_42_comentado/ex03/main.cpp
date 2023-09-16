/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:42:25 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/06 19:01:11 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"
#include <sstream>

int main(void) {
	Point a;
	Point b;
	Point c;
	Point point_check;
	std::stringstream ss;
  	std::string s;
  	std::string parameter;
 	float x;
 	float y;

// coordenadas do ponto a
	std::cout << "Enter coordenates point a:" << std::endl;
	std::cout << "x: ";
	std::cin >> parameter;
	s = parameter;
	ss << s;
	ss >> x;
	ss.clear();
	parameter.clear();
	std::cout << "y: ";
	std::cin >> parameter;
	s = parameter;
	ss << s;
	ss >> y;
	ss.clear();
	parameter.clear();
	a.setX(Fixed(x));
	a.setY(Fixed(y));
	std::cout << std::endl;

// coordenadas do ponto b
	std::cout << "Enter coordenates point b:" << std::endl;
	std::cout << "x: ";
	std::cin >> parameter;
	s = parameter;
	ss << s;
	ss >> x;
	ss.clear();
	parameter.clear();
	std::cout << "y: ";
	std::cin >> parameter;
	s = parameter;
	ss << s;
	ss >> y;
	ss.clear();
	parameter.clear();
	b.setX(Fixed(x));
	b.setY(Fixed(y));
	std::cout << std::endl;

// coordenadas do ponto c
	std::cout << "Enter coordenates point c:" << std::endl;
	std::cout << "x: ";
	std::cin >> parameter;
	s = parameter;
	ss << s;
	ss >> x;
	ss.clear();
	parameter.clear();
	std::cout << "y: ";
	std::cin >> parameter;
	s = parameter;
	ss << s;
	ss >> y;
	ss.clear();
	parameter.clear();
	c.setX(Fixed(x));
	c.setY(Fixed(y));
	std::cout << std::endl;

// coordenadas do ponto questionado
	std::cout << "Enter the coordinates of the point to be checked:" << std::endl;
	std::cout << "x: ";
	std::cin >> parameter;
	s = parameter;
	ss << s;
	ss >> x;
	ss.clear();
	parameter.clear();
	std::cout << "y: ";
	std::cin >> parameter;
	s = parameter;
	ss << s;
	ss >> y;
	ss.clear();
	parameter.clear();
	point_check.setX(Fixed(x));
	point_check.setY(Fixed(y));
	std::cout << std::endl;

	if (bsp(a, b, c, point_check))
		std::cout << "Point is in triangle" << std::endl;
	else
		std::cout << "Point is not in triangle" << std::endl;
	return (0);
}