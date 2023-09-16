/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:25:42 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/11 09:12:39 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp" 
#include "DiamondTrap.hpp" 

int main(void) {






// ROBÔ PADRÃO: ponto_de_vida(10), energia(10), dano_de_ataque(0)
// robo A (padrão) x B (forte)
    ClapTrap	a;
    ClapTrap	b;
    a.setName("The-Ant");
    b.setName("The-BIG-BOSS");
    b.setHitPoints(50);
    b.setEnergyPoints(20);
    // A ataca o B e o B revida
    a.attack(b.getName());
    b.attack(a.getName());
    // A e B tomam dano padrão (que é zero de dano)
    a.takeDamage(b.getAttackDamage());
    b.takeDamage(a.getAttackDamage());
    // B fica bravo e ativa o modo de ataque
    a.setAttackDamage(2);
    b.setAttackDamage(8);
    // A ataca o B novamente e, novamente, o B revida
    a.attack(b.getName());
    b.attack(a.getName());
    // A e B tomam dano e se recuperam
    a.beRepaired(3);
    b.beRepaired(21);
    // A ataca o B e o B revida
    a.attack(b.getName());
    b.attack(a.getName());
    // A toma um super dano do ataque forte de B, e B toma um dano fraco do A
    a.takeDamage(b.getAttackDamage());
    b.takeDamage(a.getAttackDamage());
    // A e B tentam se recuperar
    a.beRepaired(3);
    b.beRepaired(21);

    std::cout << std::endl;
    std::cout << "END OF THE BATTLE" << std::endl;
    std::cout << a.getName() << " has " << a.getHitPoints() << " life's point and " << a.getEnergyPoints() << " energy's point!" << std::endl;
    std::cout << b.getName() << " has " << b.getHitPoints() << " life's point and " << b.getEnergyPoints() << " energy's point!" << std::endl;
    
    std::cout << std::string(80, '-') << std::endl;

    // ROBÔS CLONES: ponto_de_vida(10), energia(10), dano_de_ataque(0)
    ClapTrap	x1001;
    ClapTrap	x1002;

    x1001.setName("CT-x1001");
    x1002 = x1001;
    // A ataca o B e o B revida
    x1001.attack(x1002.getName());
    x1002.attack(x1001.getName());
    // A e B tomam dano padrão (que é zero de dano)
    x1001.takeDamage(x1002.getAttackDamage());
    x1002.takeDamage(x1001.getAttackDamage());
    // B fica bravo e ativa o modo de ataque, A também ativa o modo de ataque
    x1001.setAttackDamage(5);
    x1002.setAttackDamage(5);
    // A ataca o B novamente e, novamente, o B revida
    x1001.attack(x1002.getName());
    x1002.attack(x1001.getName());
    // A e B tomam dano e se recuperam
    x1001.takeDamage(x1002.getAttackDamage());
    x1002.takeDamage(x1001.getAttackDamage());
    x1001.beRepaired(3);
    x1002.beRepaired(21);
    // A ataca o B e o B revida
    x1001.attack(x1002.getName());
    x1002.attack(x1001.getName());
    // A e B tomam dano
    x1001.takeDamage(x1002.getAttackDamage());
    x1002.takeDamage(x1001.getAttackDamage());
    // A e B tentam se recuperar
    x1001.beRepaired(3);
    x1002.beRepaired(21);
    std::cout << std::string(80, '-') << std::endl;












    
	
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