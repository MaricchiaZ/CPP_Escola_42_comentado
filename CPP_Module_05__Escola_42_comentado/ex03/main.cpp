/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:46:21 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/18 09:15:05 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
    Bureaucrat person1("Aime", 50); // um objeto do tipo Bureaucrat é criado diretamente no stack de memória. 
    // Isso significa que a memória necessária para o objeto é alocada automaticamente e é liberada quando
    //  a variável person1 sai de escopo.
    Bureaucrat *person2 = new Bureaucrat("Teo", 150); // um ponteiro para um objeto do tipo Bureaucrat é 
    // criado no stack de memória. Em seguida, a palavra-chave new é usada para alocar dinamicamente memória 
    // no heap para o objeto Bureaucrat. O endereço de memória alocado é atribuído ao ponteiro person2. 
    // Dessa forma, o objeto Bureaucrat é criado no heap e permanecerá na memória até que seja explicitamente 
    // liberado usando a palavra-chave delete.

    AForm *form1;
    AForm *form2;
    AForm *form3;
    AForm *fail;
    
    Intern someone;

    std::cout << std::string(80, '-') << std::endl;
    std::cout << "✔️ Intern creates presidential request to Presient..." << std::endl;
    form1 = someone.makeForm("presidential request", "President");
    std::cout << "✔️ Intern creates robotomy request to Jonh..." << std::endl;
    form2 = someone.makeForm("robotomy request", "Jonh");
    std::cout << "✔️ Intern creates shrubbery request to Aime..." << std::endl;
    form3 = someone.makeForm("shrubbery request", "Aime");
    std::cout << std::string(80, '-') << std::endl;
    // 1
    std::cout << "❌Person 50 sign Presidential Pardon Form 25/5" << std::endl;
    try
    {
       person1.signForm(*form1);
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    // 1
    std::cout << "❌Person 50 execute Presidential Pardon Form 25/5" << std::endl;
    try
    {
       person1.executeForm(*form1);
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    std::cout << std::endl;
    
    // 2
        std::cout << "✔️ Person 50 sign Robotomy Request Form 72/45" << std::endl;
    try
    {
       person1.signForm(*form2);
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    // 2
    std::cout << "❌Person 50 execute Robotomy Request Form 72/45" << std::endl;
    try
    {
       person1.executeForm(*form2);
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    std::cout << std::endl;

    // 3
        std::cout << "✔️ Person 50 sign Shrubbery Creation Form 145/137" << std::endl;
    try
    {
       person1.signForm(*form3);
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    // 3
    std::cout << "✔️ Person 50 execute Shrubbery Creation Form 145/137" << std::endl;
    try
    {
       person1.executeForm(*form3);
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    std::cout << std::string(80, '-') << std::endl;
    
    //4
    std::cout << "❌Someone intern creating invalid form" << std::endl;
    try {
        fail = someone.makeForm("invalid form", "Nobody");
        person2->signForm(*fail);
        std::cout << *fail;
        person2->executeForm(*fail);
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}
    std::cout << std::endl;

    std::cout << std::string(80, '-') << std::endl;
    std::cout << *form1 << std::endl;
    std::cout << *form2 << std::endl;
    std::cout << *form3 << std::endl;
    std::cout << std::string(80, '-') << std::endl;
    
    delete form1;
    delete form2;
    delete form3;
    delete person2;
    // fail não está aqui, pois não foi efetivamente criada, então não recebeu alocação, aí não precisa ser
    // deletada pelo "delete fail;"
}
