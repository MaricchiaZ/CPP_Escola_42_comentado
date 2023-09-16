/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:58:06 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/25 19:58:47 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// constructor
DiamondTrap::DiamondTrap(void): ClapTrap("_clap_name"), FragTrap(), ScavTrap() {
	std::cout <<  "DiamondTrap Default Constructor called🤖" << std::endl;
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setAttackDamage(FragTrap::getAttackDamage());
}

// destrutor
DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap Destructor called: " << _name << " died! ⚡☠️" << std::endl;
}

// construtor de cópia
DiamondTrap::DiamondTrap(DiamondTrap const &src): ClapTrap(src), FragTrap(src), ScavTrap(src), _name(src._name) {
	std::cout << "DiamondTrap Copy Constructor called: Creating DiamondTrap Clone🤖🤖" << std::endl;
}

// atribuição de cópia
DiamondTrap &DiamondTrap::operator=(DiamondTrap const &src) {
	std::cout << "DiamondTrap copy assignment operator called🤖=🤖" << std::endl;
	DiamondTrap();
	this->_name = src._name;
	return *this;
}

// construtor parametrizado
DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(),
	_name(name) {
	std::cout << "DiamondTrap Constructor called with name: " << _name << " 🤖" << std::endl;
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setAttackDamage(FragTrap::getAttackDamage());
}

void	DiamondTrap::attack(std::string const &target) {
    if (!this->getHitPoints()){
        std::cout << "Diamond " << this->getName() << " cannot attack because he is dead! ☠️" << std::endl;
    }
	else if (this->getEnergyPoints() == 0)
		std::cout << "Diamond " << this->getName() << " cannot attack because he is out of energy!"<< std::endl;
        
	else if (target.empty()) {
		std::cout << "Diamond " << this->_name << " can't attack... No target!" << std::endl;
		return ;
	}
    else
	    ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)  {
    std::cout << "I am a DiamondTrap named " << this->_name << ", ClapTrap name: " << ClapTrap::_name << " ❗" <<std::endl;
}
