/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:42:09 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/27 08:10:00 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void): type("Aanimal") {
	std::cout << "AAnimal Default Constructor called 👻" << std::endl;
}

AAnimal::~AAnimal(void) {
	std::cout << "AAnimal Destructor called 👻☠️" << std::endl;
}

AAnimal::AAnimal(AAnimal const &src) {
	std::cout << "AAnimal Copy Constructor called 👻👻" << std::endl;
	*this = src;
}

AAnimal&	AAnimal::operator=(AAnimal const &src) {
	std::cout << "AAnimal copy assignment operator called 👻=👻" << std::endl;
	this->type = src.getType();
	return *this;
}

AAnimal::AAnimal(std::string type) {
	std::cout << "AAnimal Constructor called with type: " << type << std::endl;
	this->setType(type);
}

void AAnimal::setType(std::string type) {
	this->type = type;
}

std::string	AAnimal::getType(void) const {
	return this->type;
}

// void	AAnimal::makeSound(void) const {
// 	std::cout << "* generic sound *" << std::endl;
// }