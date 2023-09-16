/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:57:50 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/25 19:58:50 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {

public:

    DiamondTrap(void); // construtor
    ~DiamondTrap(void); // destrutor
    DiamondTrap(DiamondTrap const &src); // construtor de cópia
    DiamondTrap &operator=(DiamondTrap const &src); // sobrecarga do operador de atribuição

    DiamondTrap(std::string name); // construtor paramétrico

    void	attack(std::string const &target);
    void	whoAmI(void);

private:
    std::string	_name;
};

#endif
