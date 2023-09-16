/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:54:12 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/28 09:22:08 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name) : name(name) {
    std::cout << "Character " << this->name << " born 🤴" << std::endl;
    this->initInventory();
}

Character::~Character() {
    std::cout << "Character " << this->name << " died 🤴☠️" << std::endl;
    this->clearInventory();
}

Character::Character(Character const & src) : name(src.name) {
    *this = src;
    std::cout << "Character " << this->name << " born 🤴🤴" << std::endl;
}

Character& Character::operator=(Character const & src) {
	this->name = src.name;
	this->clearInventory();
	for (size_t i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
			this->inventory[i] = src.inventory[i]->clone();
	}
	return *this;
}

void    Character::equip(AMateria* m) {  // aqui está implementando o método virtual puro do ICharacter
    for (int i = 0; i < 4; i++)
        if (this->inventory[i] == NULL)
        {
            this->inventory[i] = m;
            std::cout << "Character 🤴 " << this->name << " equipped with " << m->getType() << std::endl;
            return;
        }
    std::cout << "Character 🤴 " << this->name << " can't equip " << m->getType() << std::endl;
}

void    Character::unequip(int idx) {  // aqui está implementando o método virtual puro do ICharacter
    if (this->inventory[idx])
    {
        delete this->inventory[idx];
        this->inventory[idx] = NULL;
        std::cout << "Character 🤴 " << this->name << " unequipped" << std::endl;
    }
    else
        std::cout << "Character 🤴 " << this->name << " can't unequip" << std::endl;
}

void    Character::use( int idx, ICharacter& target ) {  // aqui está implementando o método virtual puro do ICharacter
    if (this->inventory[idx])
    {
        this->inventory[idx]->use(target);
        std::cout << "Character 🤴 " << this->name << " uses " << this->inventory[idx]->getType() << std::endl;
    }
    else
        std::cout << "Character 🤴 " << this->name << " can't use what is not in the inventory ❌💼" << std::endl;
}

std::string const& Character::getName() const {
    return this->name;
}

void Character::initInventory(void) {
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

void Character::clearInventory(void) {
    for (int i = 0; i < 4; i++)
        if (this->inventory[i])
            delete this->inventory[i];
}
