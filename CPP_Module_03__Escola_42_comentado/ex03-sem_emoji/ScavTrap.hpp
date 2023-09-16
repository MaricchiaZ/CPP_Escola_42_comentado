/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:48:04 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/10 22:57:45 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap { // é um outro robo da franquia de games Borderlands

public:

    ScavTrap(); // default constructor
    ~ScavTrap(); // default destructor
    ScavTrap(ScavTrap const &src); // copy constructor
    ScavTrap &operator=(ScavTrap const &src); // assignation operator overload
    
    ScavTrap(std::string name); // parameter constructor

// funcionalidades desse robo
    void attack(const std::string &target);
    void guardGate(void);
};

#endif