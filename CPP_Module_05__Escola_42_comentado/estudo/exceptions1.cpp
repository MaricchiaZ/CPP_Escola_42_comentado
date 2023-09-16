/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions1.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:12:39 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/14 11:13:19 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>

void test1()
{
    try
    {
        //Do some stuff here
        if (/* there's an error */)
            throw std::exception();
        else
            //Do some more stuff
    }
    catch(const std::exception e)
    {
        // Handle the error here
    }
    
}

void test2()
{
    //Do some stuff here
    if (/* there's an error */)
        throw std::exception();
    else
        //Do some more stuff
}

void test3()
{
    try
    {
        test2();
    }
    catch(const std::exception& e)
    {
        // Handle error
    }
    
}

/*
O test4 define uma classe de exceção personalizada (PEBKACException) para lidar com um tipo específico de erro (problema entre o teclado e a cadeira) e usa blocos try-catch para capturar e tratar exceções lançadas 
pela função test3().
*/
void test4()
{
    // classe aninhada
    class PEBKACException : public std::exception  //classe aninhada PEBKACException é derivada da classe 
    // std::exception, que é uma classe base para exceções padrão do C++.
    {
        public:
            virtual const char* what() const throw() //  função membro chamada what(), que é uma função virtual
            //  herdada da classe std::exception. Essa função retorna uma string que descreve o erro, no caso, 
            // "Problem exists between keyboard and chair".
            {
                return ("Problem exists between keyboard and chair");
            }
    };
    
    // temos também um bloco try-catch
    try
    {
        test3();
    }
    catch(PEBKACException& e)
    {
        //Handle the fact that the user is an idiot
    }
    catch(const std::exception& e)
    {
        //Handle other exceptions that are like std::exception
    }
    
}