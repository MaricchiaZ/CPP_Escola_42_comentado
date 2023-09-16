/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:41:41 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/27 08:26:27 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
    
int main()
{
	std::cout << std::string(80, '-') << std::endl;
	std::cout << "Test subject" << std::endl;
	std::cout << std::string(80, '-') << std::endl;
	
	
	std::cout << "Creating an array[10] of animals, half dog and half cat: " << std::endl;
	Animal *animals[10]; // criamos 10 ponteiros, um para cada animal, metada serão dogs e metade cats
	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	
	// para ver se a matriz foi preenchida, cada animal faz um som
	std::cout << "Each animal created makes a sound: " << std::endl;
    for(int i = 0; i < 10 ; i++)
		animals[i]->makeSound();
		
	// aí excluiremos todos os animais
	std::cout << "We delete the created animals: " << std::endl;
	for (int i = 0; i < 10; i++)
			delete animals[i]; 
	
	std::cout << std::endl;
	{
		std::cout << std::string(80, '-') << std::endl;
		std::cout << "Test Brain" << std::endl;
		std::cout << std::string(80, '-') << std::endl;
		std::string	ideas[100] = { "Hi, ", "I'm", "a", "thinking", "Brain"};

		Brain	a;
		for(int i = 0; i < 5; i++)
			a.setIdea(i, ideas[i]);
		
		Brain	b(a);
		std::cout << std::endl;
		
		std::cout << "🧠 Brain a: ";
		for(int i = 0; i < 5; i++)
			std::cout << a.getIdea(i) << " ";
		std::cout << std::endl;
		
		std::cout << "🧠 Brain b: ";
		for(int i = 0; i < 5; i++)
			std::cout << b.getIdea(i) << " ";
		std::cout << std::endl;

		std::cout << std::endl;
		std::cout << "Changing an idea in b ..." << std::endl;
		std::string	ideas2[100] = { "I", "changed", "all", "my", "ideas"};
		for(int i = 0; i < 5; i++)
			b.setIdea(i, ideas2[i]);
			
		std::cout << std::endl;
		std::cout << "🧠 Brain a: ";
		for(int i = 0; i < 5; i++)
			std::cout << a.getIdea(i) << " ";
		std::cout << std::endl;
		
		std::cout << "🧠 Brain b: ";
		for(int i = 0; i < 5; i++)
			std::cout << b.getIdea(i) << " ";
		std::cout << std::endl;

		std::cout << std::endl;

		Brain c;
		std::cout << "Capacity brain...." << std::endl;
		std::cout << "Brain c: ";
		for(int i = 0; i < 100; i++)
			std::cout << c.getIdea(i) << " ";
		std::cout << std::endl;
	}
	{
		std::cout << std::string(80, '-') << std::endl;
		std::cout << "Test Animal - Cat and Dog - with brains" << std::endl;
		std::cout << std::string(80, '-') << std::endl;

		Animal*	animal;
		Cat*	cat = new Cat();
		Dog*	dog = new Dog();

		std::string	ideas[100] = {"A", "B", "C"};
		std::string	dogIdeas[100] = {"play", "ball", "run", "eat", "play", "sleep", "play"};

		// set Cat ideias
		for(int i = 0; i < 3; i++)
			cat->getBrain()->setIdea(i, ideas[i]);
		std::cout << std::endl;

		std::cout << "🐈 Cat's ideas: ";
		for(int i = 0; i < 3; i++)
			std::cout << cat->getBrain()->getIdea(i) << " ";
		std::cout << std::endl;
		
		// set Dog ideias
		for(int i = 0; i < 7; i++)
			dog->getBrain()->setIdea(i, dogIdeas[i]);

		std::cout << "🐶 Dog's ideas: ";
		for(int i = 0; i < 7; i++)
			std::cout << dog->getBrain()->getIdea(i) << " ";
		std::cout << std::endl;

		std::cout << std::endl;
		
		animal = cat; // the complilator allows to copy the cat in the animal
		//cat = animal; // but does NOT allow to copy the cat in the animal
		// cat = dog; // and also does NOT allow to copy the dog in the cat

		delete animal;
		delete dog;

		std::cout << std::string(80, '-') << std::endl;
	}
}
