/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:21:54 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/03 12:46:41 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "integer_class.hpp"

Integer::Integer(int const n) : _n(n) {
    
    std::cout << "Constructor called with value " << this->_n << std::endl;
    return ;
}

Integer::~Integer(void) {

    std::cout << "Destructor called with value " << this->_n << std::endl;
    return ;
}

int     Integer::getValue(void) const {
    return this->_n;
}

Integer &   Integer::operator=(Integer const & rhs) {
    
    std::cout << "Assignment operator called from " << this->_n;
    std::cout << " to " << rhs.getValue() << std::endl;
    
    this->_n = rhs.getValue(); // Esta linha realiza a atribuição do valor do objeto rhs para o objeto atual (this->_n).
    
    return *this; // Essa linha retorna uma referência ao objeto atual (*this), por isso tem o * na frente.
}

Integer     Integer::operator+(Integer const & rhs) const {
    
    std::cout << "Addition operator called with " << this->_n;
    std::cout << " and " << rhs.getValue() << std::endl;
    
    return Integer(this->_n + rhs.getValue());
}

std::ostream &  operator<<(std::ostream & o, Integer const & rhs) {
    o << rhs.getValue();
    return o;
}
