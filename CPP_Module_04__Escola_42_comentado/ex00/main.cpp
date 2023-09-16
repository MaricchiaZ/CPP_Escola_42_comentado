/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:41:41 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/27 11:37:38 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/*
O polimorfismo de classe em C++ é um dos pilares da programação orientada a objetos e refere-se à 
capacidade de uma classe base ser tratada como uma de suas classes derivadas. Em outras palavras, é 
a habilidade de usar um objeto de uma classe derivada por meio de um ponteiro ou referência da classe base.
*/

int main()
{

	std::cout << "Test Polymorphism Class - Animal Class has a virtual method makeSound" << std::endl << std::endl;
	const Animal* meta = new Animal();
	std::cout << " Animal class (base) recive a Dog class (derived)" << std::endl;
	const Animal* j = new Dog(); // a classe animal(base) recebe a classe Dog (derivada)
	std::cout << " Animal classa(base) recive a Cat class (derived)" << std::endl;
	const Animal* i = new Cat();// a classe animal(base) recebe a classe Cat (derivada)

	std::cout << std::string(80, '-') << std::endl;

	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();
	std::cout << j->getType() << " " << std::endl;
	std::cout << "j->makeSound():  Dog class makeSound is call to pointer base class" << std::endl << std::endl;
	j->makeSound(); // aqui chamamos o som do cachorro (classe derivada) por meio de um ponteiro para a classe base
	std::cout << "i->makeSound():  Cat class makeSound is call to pointer base class" << std::endl;
	std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // aqui chamamos o som do gato (classe derivada) por meio de um ponteiro para a classe base
	std::cout << std::endl;
	
	std::cout << std::string(80, '-') << std::endl;
	std::cout << "WrongAnimal Class DONT HAS a virtual method makeSound" << std::endl;

	const WrongAnimal* test = new WrongAnimal();
	const WrongAnimal* test2 = new WrongCat();  // Se você não definir uma função na classe base como virtual e
	//  fizer uma classe derivada herdar essa função sem sobrescrevê-la, a função será simplesmente herdada como está, 
	// sem a capacidade de ser substituída pela classe derivada.
	std::cout << std::endl;
    
	std::cout << test->getType() << std::endl;
	test->makeSound();
	std::cout << test2->getType() << std::endl;
	std::cout << "test2->makeSound(); Wrongcat class makeSound is call to pointer base class" << std::endl;

	test2->makeSound(); // deveria fazer o som do Wrorng Cat, mas como a função makeSound não é declarada como virtual, 
	// ela não é sobreecrita, prevalencendo a declaração da clase base

	std::cout << std::string(80, '-') << std::endl;

	delete i;
	delete j;
	delete meta;
	delete test;
	delete test2;

	return 0;
}
