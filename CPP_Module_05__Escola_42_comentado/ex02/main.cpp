/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:46:21 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/17 15:29:58 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    Bureaucrat person1("Aime", 50);
    Bureaucrat person2("President", 1);

    AForm *form1 = new PresidentialPardonForm("Pardon_195");
    AForm *form2 = new RobotomyRequestForm("Robotomy_00");
    AForm *form3 = new ShrubberyCreationForm("Shrubbery_01");

    std::cout << std::string(80, '-') << std::endl;
    std::cout << *form1 << std::endl;
    std::cout << *form2 << std::endl;
    std::cout << *form3 << std::endl;
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

    // 4
    std::cout << "✔️ Person 1 sign Presidential Pardon Form 25/5" << std::endl;
    try
    {
       person2.signForm(*form1);
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    // 4
    std::cout << "✔️ Person 1 execute Presidential Pardon Form 25/5" << std::endl;
    try
    {
       person2.executeForm(*form1);
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    std::cout << std::endl;
    
    // 5
        std::cout << "✔️ Person 1 sign Robotomy Request Form 72/45" << std::endl;
    try
    {
       person2.signForm(*form2);
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    // 5
    std::cout << "✔️ Person 1 execute Robotomy Request Form 72/45" << std::endl;
    try
    {
       person2.executeForm(*form2);
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
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
}
