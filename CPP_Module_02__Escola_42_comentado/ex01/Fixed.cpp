/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:25:00 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/25 14:51:44 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_fractionalBits = 8;

// FORMA CANONICA - CONSTRUTOR
Fixed::Fixed(void): _fixedPointValue(0) {
    std::cout << "Default Constructor called" << std::endl;
    return;
}

// FORMA CANONICA - CÓPIA DO CONSTRUTOR
Fixed::Fixed(const Fixed & src){
    std::cout << "Copy Constructor called" << std::endl;
    *this = src;
    return;
}

//  CONSTRUTOR PARAMÉTRICO	
Fixed::Fixed(const int nb) {
	std::cout << "Int Constructor called" << std::endl;
	_fixedPointValue = nb;
	_fixedPointValue <<= Fixed::_fractionalBits;
}

//  CONSTRUTOR PARAMÉTRICO	
Fixed::Fixed(const float nb) {
	std::cout << "Float Constructor called" << std::endl;
	this->_fixedPointValue = roundf(nb * (1 << Fixed::_fractionalBits));
}

// FORMA CANONICA - DESTRUTOR
Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
    return;
}

// FORMA CANONICA - ATRIBUIÇÃO
Fixed & Fixed::operator=(Fixed const & src){
    
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        this->setRawBits(src.getRawBits());
    return *this;
}

void Fixed::setRawBits(int const bits){
    //std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointValue = bits;
}

int Fixed::getRawBits(void) const {
    //std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

float	Fixed::toFloat(void) const {
	return (static_cast <float>(this->_fixedPointValue) / (1 << Fixed::_fractionalBits));
    // Este método converte o valor de ponto fixo para um valor de ponto flutuante 
    // (float). Primeiro, ele divide o _fixedPointValue (que é o valor inteiro de ponto f
    // ixo armazenado internamente na classe) pelo valor (1 << Fixed::_fractionalBits) para 
    // realizar a conversão correta de ponto fixo para ponto flutuante. O resultado é retornado
    //  como um valor de ponto flutuante.
    
    // se Fixed::_fractionalBits for igual a 8, a expressão 1 << Fixed::_fractionalBits será 
    // avaliada como 1 << 8, o que resulta em 256. Isso significa que 1 / 256 é o valor que 
    // representa a menor unidade (parte decimal) em um número de ponto fixo com 8 bits reservados 
    // para a parte fracionária.

    // 1 / 256 = 0.00390625
}

int	Fixed::toInt(void) const {
	return _fixedPointValue / (1 << Fixed::_fractionalBits);
    // mesma explicação do ex anterior
}

std::ostream & operator<<(std::ostream & o, Fixed const & fixed) {
	o << fixed.toFloat();
	return o;
}

