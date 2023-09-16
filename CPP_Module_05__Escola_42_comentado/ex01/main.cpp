/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:46:21 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/17 14:56:45 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat person1("Aime", 140);
    Bureaucrat person2("Jonh", 60);
    Bureaucrat person3("Lider", 5);
    
    Bureaucrat person4("Dany", 71);
    Bureaucrat person5("Jonas", 10);
    
    
    Form form1("basic", 150 ,150);
    Form form2("middle" ,70, 70);
    Form form3("advanced" ,10, 10);

    std::cout << std::string(80, '-') << std::endl;
    std::cout << form1 << std::endl;
    std::cout << std::string(80, '-') << std::endl;
    std::cout << "✔️ Form Basic 150/150 be signed Person 140" << std::endl;
    try
    {
       form1.beSigned(person1);
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    
    std::cout << "❌Form Middle 70/70 be signed Person 140" << std::endl;
    try
    {
       form2.beSigned(person1);
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    
    std::cout << "❌Form Advanced 10/10 be signed Person 140" << std::endl;
    try
    {
       form3.beSigned(person1);
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
        std::cout << "✔️ Person 140 sign form Basic 150/150" << std::endl;
    try
    {
       person1.signForm(form1);
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    
    std::cout << "❌Person 140 sign form Middle 70/70" << std::endl;
    try
    {
       person1.signForm(form2);
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    
    std::cout << "❌Person 140 sign form Advanced 10/10" << std::endl;
    try
    {
       person1.signForm(form3);
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    std::cout << std::string(80, '-') << std::endl;
    
    std::cout << "✔️ Person 60 sign form Middle 70/70" << std::endl;
    try
    {
       person2.signForm(form2);
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    std::cout << "✔️ Person 5 sign form Middle Advanced 10/10" << std::endl;
    try
    {
       person3.signForm(form3);
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    
    std::cout << std::string(80, '-') << std::endl;
    std::cout << "❌Person 71 sign form Basic Middle 70/70" << std::endl;
    try
    {
       person4.signForm(form2);
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    
    std::cout << "➕ Person 71 increment grade" << std::endl;
    person4.incrementGrade(); // grade here will be 70
    
    std::cout << "✔️ Person 70 sign form Basic Middle 70/70" << std::endl;
    try
    {
       person4.signForm(form2);
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    std::cout << std::string(80, '-') << std::endl;
    std::cout << "✔️ Person 10 sign form Middle Advanced 10/10" << std::endl;
    try
    {
       person5.signForm(form3);
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    
    std::cout << "➖ Person 10 decrement grade" << std::endl;
    person5.decrementGrade();
    
    std::cout << "❌Person 11 sign form Basic Advanced 10/10" << std::endl;
    try
    {
       person5.signForm(form3);
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    std::cout << std::string(80, '-') << std::endl;
    std::cout << form1 << std::endl;
    std::cout << form2 << std::endl;
    std::cout << form3 << std::endl;
    std::cout << std::string(80, '-') << std::endl;
}
