/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:04:17 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/27 08:11:14 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain default constructor called 🧠" << std::endl;
	std::stringstream ss;
	std::string s;

	for (int i = 0; i < 100; i++) {
		ss << i + 1;
		ss >> s;
		ss.clear();
		this->ideas[i] = "💡 Idea: " + s;
	}
}

Brain::~Brain(void) {
 	std::cout << "Brain destructor called 🧠☠️" << std::endl;
}


Brain::Brain(const Brain & src) {
	std::cout << "Brain copy constructor called 🧠🧠" << std::endl;
	*this = src;
}

Brain &Brain::operator=(const Brain &src) {
	std::cout << "Brain assignment operator called 🧠=🧠" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = src.getIdea(i);
	}
	return (*this);
}

std::string Brain::getIdea(int i) const {
	return (this->ideas[i]);
}

void Brain::setIdea(int i, std::string idea) {
	this->ideas[i] = idea;
}
