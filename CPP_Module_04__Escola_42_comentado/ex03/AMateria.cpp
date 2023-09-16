/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:58:39 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/27 09:54:37 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ) : type("") {
    std::cout << "AMateria: raw materia is created 🧱" << std::endl;
}

AMateria::~AMateria( void ) {
    std::cout << "AMateria 🧱" << this->type << " destroyed ☠️" << std::endl;
}

AMateria::AMateria( AMateria const & src ) {
    *this = src;
}
 
AMateria & AMateria::operator=(AMateria const &src){  
	(void) src;
	return *this;
}

AMateria::AMateria( std::string const & type ) : type(type) {
    //std::cout << "AMateria " << this->type << " created" << std::endl;
}

std::string const & AMateria::getType() const {
    return this->type;
}

AMateria* AMateria::clone() const {
    return (AMateria*)this;
}

void    AMateria::use(ICharacter & target ) {
    std::cout << "AMateria " << this->type << " used on " << target.getName() << std::endl;
}
