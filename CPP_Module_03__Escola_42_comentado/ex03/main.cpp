/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:25:42 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/25 19:58:59 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp" 
#include "DiamondTrap.hpp" 

int main(void) {

    DiamondTrap diamond_robo1("D1");
    DiamondTrap diamond_robo2(diamond_robo1);
    DiamondTrap diamond_robo3("D3");

	std::cout << std::string(80, '-') << std::endl;
	std::cout << "Diamond_robo1, who are you?  ";
    diamond_robo1.whoAmI();
	std::cout << "Diamond_robo2 is a clone of Diamond_robo1." << std::endl;
	std::cout << "Diamond_robo2, who are you?  ";
    diamond_robo2.whoAmI();
	std::cout << "Diamond_robo3 is a copy of Diamond_robo1." << std::endl;
    diamond_robo3 = diamond_robo1;
	std::cout << "Diamond_robo3, who are you?  ";
    diamond_robo3.whoAmI();

	std::cout << "---Diamond_robo powers: ---" << std::endl;
    diamond_robo1.attack( "the shadows" );
    diamond_robo1.takeDamage(3);
    diamond_robo1.beRepaired(10);
	std::cout << std::string(80, '-') << std::endl;

	return 0;
}
