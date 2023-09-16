/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:44:53 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/25 19:57:45 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap { // é um robozinho, mascote da franquia de games Borderlands

public:

    ClapTrap(void); // default constructor
    ~ClapTrap(void); // default destructor
    ClapTrap(ClapTrap const &src); // copy constructor
    ClapTrap &operator=(ClapTrap const &src); // assignation operator overload

    ClapTrap(std::string name); // parameter constructor

// acessors
    std::string		getName(void) const;
    unsigned int	getHitPoints(void) const;
    unsigned int	getEnergyPoints(void) const;
    unsigned int	getAttackDamage(void) const;

    void	setName(std::string name);
    void	setHitPoints(unsigned int hitPoints);
    void	setEnergyPoints(unsigned int energyPoints);
    void	setAttackDamage(unsigned int attackDamage);

// funcionalidades dos robos
    void	attack(std::string const &target);
    void	takeDamage(unsigned int amount);
    void	beRepaired(unsigned int amount);

protected: // o que era privado vira protected porque as classes que herdarem dela também precisam acessar

    std::string		_name;
    unsigned int	_hitPoints;
    unsigned int	_energyPoints;
    unsigned int	_attackDamage;

};

#endif
