/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:05:31 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/27 09:47:38 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){
    std::cout << "Cure ⚕️ : AMmateria is created" << std::endl;
}

Cure::~Cure() {
    std::cout << "There is no cure: is destroyed  ⚕️☠️" << std::endl;
}

Cure::Cure(Cure const & src) : AMateria("cure") {
    *this = src;
    std::cout << "Cure: AMmateria is copied ⚕️⚕️" << std::endl;
}

Cure& Cure::operator=(const Cure &src) {
    if (this != &src)
        this->type = src.type;
    return *this;
}

AMateria* Cure::clone() const{
    return new Cure(*this);
}

void    Cure::use(ICharacter& target){
    std::cout << "Heals " << target.getName() << "'s wounds ⚕️🎵" << std::endl;
}
