/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:11:28 by maclara-          #+#    #+#             */
/*   Updated: 2023/06/26 18:57:36 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name){
    this->_name = name;
    this->weaponB = NULL;
}

HumanB::~HumanB(void) {
    
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->weaponB = &weapon;
}

void	HumanB::attack(void) {
	if (!weaponB) {
		std::cout << _name << " is unarmed" << std::endl;
		return ;
	}
	std::cout << _name << " attacks with their " << weaponB->getType() << std::endl;
}