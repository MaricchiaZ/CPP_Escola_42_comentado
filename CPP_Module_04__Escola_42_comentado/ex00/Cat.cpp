/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:30:30 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/27 07:33:14 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal("Cat") {
	std::cout << "Cat Default Constructor called 🐈" << std::endl;
}

Cat::~Cat(void) {
	std::cout << "Cat Destructor called 🐈☠️" << std::endl;
}

Cat::Cat(Cat const &src): Animal("Cat") {
	std::cout << "Cat Copy Constructor called 🐈 🐈" << std::endl;
    *this = src;
}

Cat &Cat::operator=(Cat const &src) {
    this->type = src.getType();
	std::cout << "Cat copy assignment operator called 🐈=🐈" << std::endl;
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << "* Miau rrrrrrr miau 🐈 🎵 *" << std::endl;
}
