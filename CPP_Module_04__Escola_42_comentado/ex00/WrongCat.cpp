/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:11:02 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/27 07:34:12 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat") {
	std::cout << "WrongCat Default Constructor called 🐱🕸" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src): WrongAnimal(src.type) {
	std::cout << "WrongCat Copy Constructor called 🐱🐱🕸" << std::endl;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat Destructor called 🐱🕸☠️" << std::endl;
}

WrongCat&	WrongCat::operator=(WrongCat const & src) {
	std::cout << "WrongCat copy assignment operator called 🐱=🐱🕸" << std::endl;
	this->type = src.type;
	return *this;
}

void	WrongCat::makeSound(void) const {
	std::cout << "* uaiM uaiM 🎵🐱🕸*" << std::endl;
}
