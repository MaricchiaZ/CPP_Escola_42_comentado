/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 08:19:09 by maclara-          #+#    #+#             */
/*   Updated: 2023/06/26 18:53:10 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

    Weapon::Weapon(std::string Type){
        this->_type = Type;
    }
    
    Weapon::~Weapon(){
    }
    
    void    Weapon::setType(std::string other_Type){
        this->_type = other_Type;
    }
    
    std::string Weapon::getType() const{
        return (this->_type);
    }
