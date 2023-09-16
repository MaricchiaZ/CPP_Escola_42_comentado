/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:18:16 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/11 10:05:53 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// construrctor
ClapTrap::ClapTrap(void) : _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

// destructor
ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap Destructor called: " << getName() << " died!" << std::endl;
}

// Construtor de Cópia: Um construtor que permite criar uma cópia exata de um objeto existente da mesma classe.
ClapTrap::ClapTrap(ClapTrap const &src):
	_name(src.getName()),
	_hitPoints(src.getHitPoints()),
	_energyPoints(src.getEnergyPoints()),
	_attackDamage(src.getAttackDamage()) {
	std::cout << "ClapTrap Copy Constructor called: Creating ClapTrap Clone."
	<< std::endl;
	// a inicialização por lista fazendo a cópia dos atributos dessa classe em src pode ser trocada por essa única linha:
	// *this = src;
}

// Operador de Atribuição (Assignment Operator): Um operador sobrecarregado que permite atribuir o valor de um objeto a outro objeto da mesma classe.
ClapTrap&	ClapTrap::operator=(ClapTrap const &src) {
	std::cout << "ClapTrap copy assignment operator called." << std::endl;
	this->setName(src.getName());
	this->setHitPoints(src.getHitPoints());
	this->setEnergyPoints(src.getEnergyPoints());
	this->setAttackDamage(src.getAttackDamage());
	return *this;
}

// construtor parametrizado
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap Parameter Constructor called with name: " << name << "."<< std::endl;
}

// acessors SET

void	ClapTrap::setName(std::string name){
    this->_name = name;
}

void	ClapTrap::setHitPoints(unsigned int hitPoints){
	this->_hitPoints = hitPoints;
}

void	ClapTrap::setEnergyPoints(unsigned int energyPoints) {
	this->_energyPoints = energyPoints;
}
void	ClapTrap::setAttackDamage(unsigned int attackDamage) {
	this->_attackDamage = attackDamage;
}

// acessors GET
std::string	ClapTrap::getName(void) const{
     return _name;
}

unsigned int ClapTrap::getHitPoints(void) const{
    return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints(void) const{
    return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage(void) const{
    return _attackDamage;
}

// funcionalidades dos robos

void	ClapTrap::attack(std::string const &target) { 
    // conferimos se temos um alvo para atacar - sem alvo não há ataque
	if (target.empty()) {
		std::cout << "ClapTrap " << this->_name << " can't attack... No target!" << std::endl;
		return ;
	}
    // conferimos se temos pelo menos 1 ponto de vida para atacar - quem tá morto não ataca
    if (this->_hitPoints < 1) {
        std::cout << "ClapTrap " << this->_name << " can't attack " << target << ": He is dead ☠️ !" << std::endl;
        return ;
    }
    // conferimos se temos pelo menos 1 ponto de energia para usar no ataque - sem energia não há ataque
    if (this->_energyPoints < 1) {
        std::cout << "ClapTrap " << this->_name << " can't attack " << target << ": No energy!" << std::endl;
        return ;
    }
    // ataque
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "
	<< this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
    // conferimos se o robo tem algum ponto de vida, quem está morto não sofre dano
	if (!this->_hitPoints) {
		std::cout << "ClapTrap " << this->_name << " can't take damage: He is already dead!" << std::endl;
		return ;
	}
    // leva dano
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!"
	<< std::endl;
	if (amount >= this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
    // conferimos se o robo está vivo, quem está morto não pode ser reparar
    if (!this->_hitPoints) {
    std::cout << this->_name << " can't be repaired: He is already dead!" << std::endl;
    return ;
	}
    // conferimos se temos pelo menos 1 ponto de energia para usar na reparaçãi - sem energia não há como o robô se reparar
    if (this->_energyPoints < 1) {
        std::cout << this->_name << " can't be repaired: No energy!" << std::endl;
        return ;
    }
    // o robô se repara
	std::cout
	<< "ClapTrap " << this->_name << " is being repaired and receives " << amount << " health." << std::endl;
	this->_energyPoints--;
}