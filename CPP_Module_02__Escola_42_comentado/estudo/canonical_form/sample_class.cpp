/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample_class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:15:31 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/03 21:13:49 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sample_class.hpp"

// FORMA CANONICA - CONSTRUTOR
Sample::Sample(void): _foo(0) {
    std::cout << "DEFAULT Constructor called" << std::endl;
    return;
}

Sample::Sample(int const n): _foo(n) {
    std::cout << "PARAMETRIC Constructor called" << std::endl;
    return;
}

// FORMA CANONICA - CÓPIA DO CONSTRUTOR
Sample::Sample(const Sample & src){
    std::cout << "COPY Constructor called" << std::endl;
    *this = src;
    return;
}

// FORMA CANONICA - DESTRUTOR
Sample::~Sample(){
    std::cout << "Destructor called" << std::endl;
    return;
}

int Sample::getFoo(void) const {
    return this->_foo;
}

// FORMA CANONICA - ATRIBUIÇÃO
Sample & Sample::operator=(Sample const & rhs){
    
    std::cout << "Assignation operator called" << std::endl;
    if (this != &rhs)
        this->_foo = rhs.getFoo();
    return *this;
}

std::ostream & operator<<(std::ostream & o, Sample const & rhs){
    o << "The value of _foo is: " << rhs.getFoo();
    return o;
}