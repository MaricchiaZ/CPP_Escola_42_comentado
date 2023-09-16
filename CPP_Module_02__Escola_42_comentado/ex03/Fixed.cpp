/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:25:00 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/06 18:46:27 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_fractionalBits = 8;

// FORMA CANONICA - CONSTRUTOR
Fixed::Fixed(void) : _fixedPointValue(0) {
	return;
}

// FORMA CANONICA - CÓPIA DO CONSTRUTOR
Fixed::Fixed(const Fixed &src) {
	*this = src;
}

//  CONSTRUTOR PARAMÉTRICO	
Fixed::Fixed(const int nb) {
	this->_fixedPointValue = nb << _fractionalBits;
}

//  CONSTRUTOR PARAMÉTRICO	
Fixed::Fixed(const float nb) {
	this->_fixedPointValue = static_cast<int>(roundf(nb * (1 << this->_fractionalBits)));
}

// FORMA CANONICA - DESTRUTOR
Fixed::~Fixed(void) {
	return;
}

// dupla de acessors
void Fixed::setRawBits(int const bits) {
	this->_fixedPointValue = bits;
}

int Fixed::getRawBits(void) const {
	return (this->_fixedPointValue);
}

// FORMA CANONICA - ATRIBUIÇÃO
Fixed &Fixed::operator = (Fixed const &fixed) {
	this->setRawBits(fixed.getRawBits());
	return (*this);
}

// 6 operadores de comparação:  >,  <,  >=,  <=,  ==, !=
bool Fixed::operator< (Fixed const &fixed) const {
	return (this->getRawBits() < fixed.getRawBits());
}

bool Fixed::operator> (Fixed const &fixed) const {
	return (this->getRawBits() > fixed.getRawBits());
}

bool Fixed::operator>=(Fixed const &fixed) const {
	return (this->getRawBits() >= fixed.getRawBits());
}

bool Fixed::operator<=(Fixed const &fixed) const {
	return (this->getRawBits() <= fixed.getRawBits());
}

bool Fixed::operator==(Fixed const &fixed) const {
	return (this->getRawBits() == fixed.getRawBits());
}

bool Fixed::operator!=(Fixed const &fixed) const {
	return (this->getRawBits() != fixed.getRawBits());
}

// 4 operadores aritméticos:  +,  -,  * e  /
Fixed Fixed::operator+(Fixed const &fixed) const {
	Fixed ret = (this->toFloat() + fixed.toFloat());
	return (ret);
}

Fixed Fixed::operator-(Fixed const &fixed) const {
	Fixed ret = (this->toFloat() - fixed.toFloat());
	return (ret);
}

Fixed Fixed::operator*(Fixed const &fixed) const {
	Fixed ret = (this->toFloat() * fixed.toFloat());
	return (ret);
}

Fixed Fixed::operator/(Fixed const &fixed) const {
	Fixed ret = (this->toFloat() / fixed.toFloat());
	return (ret);
}

// pré-incremento (++)
Fixed &Fixed::operator++(void) {
	++this->_fixedPointValue;
	return (*this);
}

// pós-incremendo (++)
Fixed Fixed::operator++(int) {
	Fixed temp = *this; // criamos uma cópia do objeto atual (*this) para armazenar o valor original
	this->_fixedPointValue++; // incrementamos o original
	return (temp); // retornamos a cópia ainda não modificada
	//  Assim, o operador de pós-incremento permite que você utilize o valor original antes do incremento.
}

// pré-decremento (--)
Fixed &Fixed::operator--(void) {
	--this->_fixedPointValue;
	return (*this);
}

// pós-decremento (--)
Fixed Fixed::operator--(int) {
	Fixed temp = *this; // criamos uma cópia do objeto atual (*this) para armazenar o valor original
	this->_fixedPointValue--; // decrementamos o original
	return (temp); // retornamos a cópia ainda não modificada
	//  Assim, o operador de pós-incremento permite que você utilize o valor original antes do incremento)
}

// Funções  de  membro  sobrecarregadas
Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
	return (f1 < f2) ? f1 : f2;
}

const Fixed &Fixed::min(Fixed const &f1, Fixed const &f2) {
	return (f1 < f2) ? f1 : f2;
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
	return (f1 > f2) ? f1 : f2;
}

const Fixed &Fixed::max(Fixed const &f1, Fixed const &f2) {
	return (f1 > f2) ? f1 : f2;
}

int Fixed::toInt(void) const {
	return (this->_fixedPointValue >> this->_fractionalBits);
}

float Fixed::toFloat(void) const {
	return (static_cast <float>(this->_fixedPointValue) / (1 << this->_fractionalBits));
}

// encaminha a saída pra um fluxo de saída padrão
std::ostream &operator <<(std::ostream &out, Fixed const &f) {
	out << f.toFloat();
	return (out);
}
