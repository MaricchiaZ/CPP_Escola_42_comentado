/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:25:41 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/11 08:48:47 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// construtor padrão
FragTrap::FragTrap(void): ClapTrap() {
	std::cout << "FragTrap Default Constructor called." << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

// destrutor
FragTrap::~FragTrap(void) {
	std::cout << "FragTrap Destructor called: " << getName() << " died!" << std::endl;
}

// construtor de cópia	
FragTrap::FragTrap(FragTrap const &src): ClapTrap(src) {
	std::cout << "FragTrap Copy Constructor called: Creating FragTrap Clone" << std::endl;
}

// atribuição de cópia
FragTrap&	FragTrap::operator=(FragTrap const &src) {
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(src);
	return *this;
}

// construtor parametrizado
FragTrap::FragTrap(std::string name): ClapTrap(name) {
	std::cout << "FragTrap Constructor called with name: " << name << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

void	FragTrap::attack(std::string const& target) {
    // conferimos se temos um alvo para atacar - sem alvo não há ataque
	if (target.empty()) {
		std::cout << this->_name << " can't attack... No target!" << std::endl;
		return ;
	}
    // conferimos se temos pelo menos 1 ponto de vida para atacar - quem tá morto não ataca
    if (this->_hitPoints < 1) {
        std::cout << this->_name << " can't attack " << target << ": He is dead!" << std::endl;
        return ;
    }
    // conferimos se temos pelo menos 1 ponto de energia para usar no ataque - sem energia não há ataque
    if (this->_energyPoints < 1) {
        std::cout << this->_name << " can't attack " << target << ": No energy!" << std::endl;
        return ;
    }
    // ataque
	std::cout << "FragTrap " << this->getName() << " attacks " << target << ", causing "
	<< this->getAttackDamage() << " points of damage!" << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void	FragTrap::highFiveGuys(void) {
    if (this->getHitPoints() == 0)
		std::cout << this->getName() << " cannot high five" << " because he is dead!" << std::endl;
    else
	    std::cout << "FragTrap " << this->getName() << " wants to give you high fives !!!" << std::endl;
}