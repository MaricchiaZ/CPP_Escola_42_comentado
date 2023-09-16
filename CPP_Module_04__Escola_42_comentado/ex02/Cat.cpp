/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:30:30 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/27 08:12:27 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Estava inicializando assim, mas o pdf diz: "Após a construção, Cão e Gato criarão seu Cérebro usando new Brain()"
// Cat::Cat(void): Animal("Cat"), brain(new Brain()) {
// 	std::cout << "Cat Default Constructor called" << std::endl;
// }

Cat::Cat(void): AAnimal("Cat") {
	std::cout << "Cat Default Constructor called 🐈" << std::endl;
	this->brain = new Brain(); // assim primeiro aparece o log da construcão do cat e depois do brain
}

Cat::~Cat(void) {
	std::cout << "Cat Destructor called 🐈☠️" << std::endl;
	delete this->brain;
}

Cat::Cat(Cat const &src): AAnimal("Cat") {
	std::cout << "Cat Copy Constructor called 🐈 🐈" << std::endl;
	this->brain = new Brain(*src.getBrain());
    *this = src;
}

Cat &Cat::operator=(Cat const &src) {
    this->type = src.getType();
	*this->brain = *src.getBrain();
	std::cout << "Cat copy assignment operator called 🐈=🐈" << std::endl;
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << "* Miau rrrrrrr miau 🐈 🎵 *" << std::endl;
}

Brain* Cat::getBrain(void) const {
	return this->brain;
}
