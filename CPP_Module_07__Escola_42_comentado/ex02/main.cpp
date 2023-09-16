/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:11:47 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/07 20:35:20 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Array.hpp"

template<typename T>
void printArray(Array<T> const& arr) {
	for (size_t i = 0; i < arr.size(); i++) {
		std::cout << arr[i];
	}
	std::cout << std::endl;
}

#define MAX_VAL 750
int main(int, char**)
{
    std::cout << " ----------- 42 - Main tests ----------- " << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//


    std::cout << " ----------- Other tests  ----------- " << std::endl;

    std::cout << "⛓️ Array void" << std::endl;
    Array<int> intArrayVoid = Array<int>();
    std::cout << " ---------------------- " << std::endl;
    std::cout << "⛓️ Size array void: "; 
	std::cout << intArrayVoid.size() << std::endl;
    std::cout << " ---------------------- " << std::endl;
    
    std::cout << "⛓️ Array recives '12345'" << std::endl;
	Array<int> intArray(5);
	intArray[0] = 0;
	intArray[1] = 1;
	intArray[2] = 2;
	intArray[3] = 3;
	intArray[4] = 4;
	printArray(intArray);
    std::cout << " ---------------------- " << std::endl;
    
    std::cout << "⛓️ Array recives 'Maria'" << std::endl;
	Array<char> charArray(5);
	charArray[0] = 'M';
	charArray[1] = 'A';
	charArray[2] = 'R';
	charArray[3] = 'I';
	charArray[4] = 'A';
	printArray(charArray);
    std::cout << " ---------------------- " << std::endl;
    
    std::cout << "⛓️ Array copy 'Maria' recives 'Clara'" << std::endl;
	Array<char> copy(charArray);
	copy[0] = 'C';
	copy[1] = 'L';
	copy[2] = 'A';
	copy[3] = 'R';
	copy[4] = 'A';
	printArray(copy);
    std::cout << " ---------------------- " << std::endl;
    
    std::cout << "⛓️ Array 'Maria' change array[2] to 'n'" << std::endl;
	Array<char> assign = charArray;
	assign[2] = 'N';
	printArray(assign);
    std::cout << " ----------------------------------- " << std::endl;

    std::cout << "⛓️ We try to change the position array[-1]" << std::endl;
	try
	{
		charArray[-1] = 'x';
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    std::cout << " ----------------------------------- " << std::endl;
    
    std::cout << "⛓️ We try to change the position array[7] to 'x'" << std::endl;
	try
	{
		charArray[7] = 'x';
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    std::cout << " ----------------------------------- " << std::endl;
    return 0;
}
