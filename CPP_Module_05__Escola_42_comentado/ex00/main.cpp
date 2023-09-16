/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:46:21 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/02 09:21:07 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

int main(void) {

    std::cout << std::string(80, '-') << std::endl;
    
    std::cout << "1. Instantiate a Bureaucrat - grade 0" << std::endl;
// As exceções lançadas podem ser capturadas e tratadas por blocos de código que estão preparados 
// para lidar com elas, usando a cláusula "try" e "catch". O bloco "try" é onde o código que pode 
// lançar exceções é colocado, e o bloco "catch" é onde o código que trata a exceção é colocado.

    try { // O uso do bloco try-catch é uma prática comum para capturar e tratar exceções em C++. Ele permite que o programa 
    // gerencie erros de forma controlada, evitando que o programa seja encerrado abruptamente por exceções não tratadas. Em 
    // vez disso, o programa pode tomar ações apropriadas para lidar com a exceção e continuar sua execução normalmente.
        Bureaucrat best("Best", 0);
    }
    catch(std::exception& e) {
        std::cout << e.what() << std::endl; //  a mensagem de erro da exceção será impressa no terminal através da chamada `e.what()`
    }
    std::cout << std::string(80, '-') << std::endl;
    std::cout << "2. Instantiate a Bureaucrat - grade 200" << std::endl;
    try {
        Bureaucrat worst("Worst", 200);
    }
    catch(std::exception& e) {
        std::cout <<  e.what() << std::endl; //  a mensagem de erro da exceção será impressa no terminal através da chamada `e.what()`
    }
    std::cout << std::string(80, '-') << std::endl;
	Bureaucrat high("High", 1);
	Bureaucrat low("Low", 150);
	Bureaucrat medium("Medium", 75);

	std::cout << std::endl;
    std::cout << "3. Show bureaucrat grade:" << std::endl;
	std::cout << high;  // operador << imprime o level do burocrata
	std::cout << medium;
	std::cout << low;
	std::cout << std::endl;

    std::cout << "4. Testing grade too high:" << std::endl;
	try {
		high.incrementGrade();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
    std::cout << "5. Testing grade too low:" << std::endl;
	try {
		low.decrementGrade();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
    std::cout << std::string(80, '-') << std::endl;
}
