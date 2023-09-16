/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:47:40 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/06 18:56:53 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// CONSTRUTOR - Forma canônica
Point::Point(void) {
	const_cast<Fixed &>(this->x) = 0; // iniciamos as variáveis com 0
	const_cast<Fixed &>(this->y) = 0; // iniciamos as variáveis com 0
}

// DESTRUTOR - Forma Canônica
Point::~Point(void) {
}

// CÓPIA DO CONSTRUTOR - Forma Canônica
Point::Point(Point const &p) {
	*this = p;
}

// Construtor parametrizado
Point::Point(float const x, float const y) {
	const_cast<Fixed &>(this->x) = x;
	const_cast<Fixed &>(this->y) = y;
}

// OPERADOR DE ATRIBUIÇÃO - Forma Canônica
Point &Point::operator=(const Point &p) {
	const_cast<Fixed  &>(this->x) = p.getX();
	const_cast<Fixed  &>(this->y) = p.getY();
	return (*this);
}

// acessores
Fixed const Point::getX(void) const {
	return (this->x);
}

Fixed const Point::getY(void) const {
	return (this->y);
}

void	Point::setX(Fixed const x) {
	const_cast<Fixed &> (this->x) = x;
}

void	Point::setY(Fixed const y) {
	const_cast<Fixed &> (this->y) = y;
}
