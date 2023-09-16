/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:13:40 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/28 09:21:27 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    this->initMaterias();
}

MateriaSource::~MateriaSource() {
    this->clearMaterias();
}

MateriaSource::MateriaSource(MateriaSource const & src) : IMateriaSource(src) {
    *this = src;
}

MateriaSource& MateriaSource::operator=(MateriaSource const & src) {
    if (this != &src)
    {
        for (int i = 0; i < 4; i++)
            materias[i] = src.materias[i];
    }
    return *this;
}

AMateria* MateriaSource::getMateria( std::string const & type ) {
    for (int i = 0; i < 4; i++)
        if (materias[i] && materias[i]->getType() == type)
            return materias[i];
    return NULL;
}

void    MateriaSource::learnMateria(AMateria* m) { // implementa esse método da Interface IMateriaSource
    for (int i = 0; i < 4; i++)
        if (materias[i] == NULL)
        {
            materias[i] = m;
            std::cout << "MateriaSource: " << m->getType() << " added at index " << i << std::endl;
            return;
        }
    std::cout << "MateriaSource can't add " << m->getType() << std::endl;
}

AMateria*   MateriaSource::createMateria(std::string const& type) { // implementa esse método da Interface IMateriaSource
    for (int i = 0; i < 4; i++)
        if (materias[i] && materias[i]->getType() == type)
            return materias[i]->clone();
    std::cout << "MateriaSource can't create " << type << std::endl;
    return NULL;
}

void MateriaSource::initMaterias(void) {
    for (int i = 0; i < 4; i++)
    materias[i] = NULL;
}

void MateriaSource::clearMaterias(void) {
    for (int i = 0; i < 4; i++)
        if (materias[i])
            delete materias[i];
}
