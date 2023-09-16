/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:05:12 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/27 09:47:05 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
    std::cout << "Ice 🧊: AMateria is created" << std::endl;
}

Ice::Ice(Ice const & src) : AMateria("ice"){
    *this = src;
    std::cout << "Ice: AMateria is copied 🧊🧊" << std::endl;
}

Ice & Ice::operator=(const Ice &src) {
    if (this != &src)
        this->type = src.type;
    return *this;
}

Ice::~Ice(){
    std::cout << "Ice has melted, it has been destroyed 🧊☠️" << std::endl;
}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void    Ice::use( ICharacter& target ) {
    std::cout << "I shoots an ice bolt at 🥶 " << target.getName() << std::endl;
}
