/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:04:12 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/25 19:58:56 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

public:

    FragTrap(void); // Forma Canônica - construtor padrão
    ~FragTrap(void); // Forma Canônica - destrutor
    FragTrap(FragTrap const &src); // Forma Canônica - construtor de cópia
    FragTrap &operator=(FragTrap const &src); // Forma Canônica - atribuição de cópia
    
    FragTrap(std::string name); // construtor parametrizado

    void	attack(std::string const &target);
    void	highFiveGuys(void);

};

#endif
