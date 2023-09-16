/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:52:40 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/27 07:33:39 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): type("WrongAnimal") {
	std::cout << "WrongAnimal Default Constructor called 🕷🕸" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal Destructor called 🕷🕸" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src): type(src.type) {
	std::cout << "WrongAnimal Copy Constructor called 🕷🕷🕸" << std::endl;
}
// é a mesma coisa que:
// WrongAnimal::WrongAnimal(const WrongAnimal &a) {
// 	std::cout << "WrongAnimal copy constructor called << std::endl;
// 	*this = a;
// }

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &src) {
	std::cout << "WrongAnimal copy assignment operator called 🕷=🕷🕸" << std::endl;
	this->type = src.getType();
	return *this;
}
// é a mesma coisa que:
// WrongAnimal::WrongAnimal(std::string const type) {
// 	std::cout << "WrongAnimal constructor called for " << type << std::endl;
// 	this->setType(type);
// }

WrongAnimal::WrongAnimal(std::string const type) {
	std::cout << "WrongAnimal constructor called for " << type << std::endl;
	this->setType(type);
}

void WrongAnimal::setType(std::string type) {
	this->type = type;
}

std::string	WrongAnimal::getType(void) const {
    return this->type;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "* WrongAnimal sound 🕷🎵 *" << std::endl;
}
