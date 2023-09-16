/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:57:38 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/27 09:01:20 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main(void) {
    std::cout << std::string(80, '-') << std::endl;
    std::cout << "Test the subject" << std::endl;
    std::cout << std::string(80, '-') << std::endl;

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    std::cout << std::string(80, '-') << std::endl;
    std::cout << "Test the game" << std::endl;
    std::cout << std::string(80, '-') << std::endl;

    Character* character = new Character("Baymax");
    Character* character2 = new Character("Tadashi");
    AMateria* cure = new Cure();

    character->unequip(0);
    character->use(0, *character);
    character->equip(new Cure());
    character->equip(new Cure());
    character->equip(new Cure());
    character->equip(new Ice());
    character->equip(cure);
    character->unequip(2);

    character->use(0, *character2);

std::cout << std::string(80, '-') << std::endl;
    delete character;
    delete character2;
    delete cure;

return 0;
}
