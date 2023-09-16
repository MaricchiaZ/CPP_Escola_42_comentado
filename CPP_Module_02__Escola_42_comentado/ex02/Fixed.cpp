/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:25:00 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/04 21:38:59 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_fractionalBits = 8;

// FORMA CANONICA - CONSTRUTOR
Fixed::Fixed(void): _fixedPointValue(0) {
    return;
}

// FORMA CANONICA - CÓPIA DO CONSTRUTOR
Fixed::Fixed(const Fixed & src){
    *this = src;
    return;
}

//  CONSTRUTOR PARAMÉTRICO	
Fixed::Fixed(const int nb) {
	_fixedPointValue = nb;
	_fixedPointValue <<= Fixed::_fractionalBits;
}

//  CONSTRUTOR PARAMÉTRICO	
Fixed::Fixed(const float nb) {
	this->_fixedPointValue = roundf(nb * (1 << Fixed::_fractionalBits));
}

// FORMA CANONICA - DESTRUTOR
Fixed::~Fixed(){
    return;
}

// dupla de acessors
void Fixed::setRawBits(int const bits){
    this->_fixedPointValue = bits;
}

int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

// FORMA CANONICA - ATRIBUIÇÃO
Fixed & Fixed::operator=(Fixed const & src){

    if (this != &src)
        this->setRawBits(src.getRawBits());
    return *this;
}

// 6 operadores de comparação:  >,  <,  >=,  <=,  ==, !=
bool	Fixed::operator>(Fixed const & src) const {
	return _fixedPointValue > src.getRawBits();
}

bool	Fixed::operator<(Fixed const & src) const {
	return _fixedPointValue < src.getRawBits();
}

bool	Fixed::operator>=(Fixed const & src) const {
	return _fixedPointValue >= src.getRawBits();
}

bool	Fixed::operator<=(Fixed const & src) const {
	return _fixedPointValue <= src.getRawBits();
}

bool	Fixed::operator==(Fixed const & src) const {
	return _fixedPointValue == src.getRawBits();
}

bool	Fixed::operator!=(Fixed const & src) const {
	return _fixedPointValue != src.getRawBits();
}

// 4 operadores aritméticos:  +,  -,  * e  /
Fixed	Fixed::operator+(Fixed const & src) const {
	Fixed	result;

	result.setRawBits(_fixedPointValue + src.getRawBits());

	return result;
}

Fixed	Fixed::operator-(Fixed const & src) const {
	Fixed	result;

	result.setRawBits(_fixedPointValue - src.getRawBits());

	return result;
}

Fixed	Fixed::operator*(Fixed const & src) const {
	return Fixed(toFloat() * src.toFloat());
}

Fixed	Fixed::operator/(Fixed const & src) const {
	return Fixed(toFloat() / src.toFloat());
}

// pré-incremento (++)
Fixed &	Fixed::operator++(void) {
	this->_fixedPointValue += 1;
	return *this;
}

// pós-incremendo (++)
Fixed	Fixed::operator++(int) {
	Fixed	result(*this);	// criamos uma cópia do objeto atual (*this) para armazenar o valor original
	++(*this);				// incrementamos o original
	return result;			// retornamos a cópia ainda não modificada
    //  Assim, o operador de pós-incremento permite que você utilize o valor original antes do incremento.
}

// pré-decremento (--)
Fixed &	Fixed::operator--(void) {
	this->_fixedPointValue -= 1;
	return *this;
}

// pós-decremento (--)
Fixed	Fixed::operator--(int) {
	Fixed	result(*this);	// criamos uma cópia do objeto atual (*this) para armazenar o valor original
	--(*this);				// idecrementamos o original
	return result;			// retornamos a cópia ainda não modificada
    //  Assim, o operador de pós-incremento permite que você utilize o valor original antes do incremento)
}

// Funções  de  membro  sobrecarregadas
Fixed &	Fixed::min(Fixed & f1, Fixed & f2) {
	return (f1 < f2) ? f1 : f2;
}

Fixed const & Fixed::min(Fixed const & f1, Fixed const & f2) {
	return (f1 < f2) ? f1 : f2;
}

Fixed &	Fixed::max(Fixed & f1, Fixed & f2) {
	return (f1 > f2) ? f1 : f2;
}

Fixed const & Fixed::max(Fixed const & f1, Fixed const & f2) {
	return (f1 > f2) ? f1 : f2;
}

float	Fixed::toFloat(void) const {
	return (float) _fixedPointValue / (1 << Fixed::_fractionalBits);
}

int	Fixed::toInt(void) const {
	return _fixedPointValue / (1 << Fixed::_fractionalBits);
}

std::ostream & operator<<(std::ostream & o, Fixed const & fixed) {
	o << fixed.toFloat();
	return o;
}