/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:37:58 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/27 07:33:27 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog") {
	std::cout << "Dog Default Constructor called 🐶" << std::endl;
}

Dog::~Dog(void) {
	std::cout << "Dog Destructor called 🐶☠️" << std::endl;
}

Dog::Dog(Dog const &src): Animal("Dog") {
	std::cout << "Dog Copy Constructor called 🐶 🐶" << std::endl;
    *this = src;
}

Dog &Dog::operator=(Dog const &src) {
    this->type = src.getType();
	std::cout << "Dog copy assignment operator called 🐶=🐶" << std::endl;
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << "* Auau rrr auau 🐶 🎵 *" << std::endl;
}
