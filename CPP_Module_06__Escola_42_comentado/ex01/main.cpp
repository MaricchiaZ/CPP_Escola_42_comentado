/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:21:10 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/07 16:14:34 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"
#include "Serialize.hpp"

int main (void) {
	Data *initial_pointer = new Data("Test if pointer is the same after deserialization");

	uintptr_t pointer_after_serialize = serialize(initial_pointer);

	Data *end_pointer = deserialize(pointer_after_serialize);
	std::cout << "Work a reinterpret_cast in CPP, the adress not change" << std::endl;

	std::cout << "Address BEFORE serialization: 📌 " << initial_pointer << std::endl;
	std::cout << "Data string: ❝ " << initial_pointer->getData() << " ❞" <<std::endl;

	std::cout << "Address AFTER deserialization: 📌 " << end_pointer << std::endl; 
	std::cout << "Data string: ❝ " << end_pointer->getData() << " ❞" <<std::endl;

	delete initial_pointer;
	return (0);
}
