/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:10:07 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/18 10:14:27 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
O `dynamic_cast` pode ser usado tanto em referências quanto em ponteiros.

Neste exemplo foi utilizado tanto para converter um ponteiro (`Parent*`) para um ponteiro (`Child1*`) quanto para converter uma referência (`Parent&`) para uma referência (`Child2&`).

A diferença está na maneira como o `dynamic_cast` lida com as conversões em cada caso. 
    - Quando usado com **ponteiros**, se a conversão não for possível, o resultado será um ponteiro nulo (`NULL` ou `nullptr`). 

    - Já quando usado com **referências**, se a conversão não for possível, será lançada uma exceção do tipo `std::bad_cast`.

Portanto, o `dynamic_cast` pode ser usado tanto em referências quanto em ponteiros para realizar conversões seguras entre tipos relacionados por herança.
*/

#include <iostream>
#include <typeinfo>
#include <exception>

class Parent {public: virtual ~Parent() {}};
class Child1 : public Parent {};
class Child2 : public Parent {};

int main(void){
    
    Child1 a; // Valor de Referência
    Parent * b = &a; // IMPLÍCITO upcast
    

    // EXPLÍCITO downcats em cast dinâmico - é válido ✔️

    // Aqui usamos a dynamic_cast para converter um ponteiro de Parent para um ponteiro de Child1.
    //  Se a conversão for bem-sucedida, o ponteiro c será diferente de NULL, indicando que a conversão 
    // foi bem-sucedida. Caso contrário, o ponteiro c será igual a NULL, indicando que a conversão falhou.
    Child1 * c = dynamic_cast<Child1 *>(b);
    if( c == NULL)
        std::cout << "❌Conversion is NOT OK" << std::endl;
    else
        std::cout << "✔️ Conversion is OK" << std::endl;

        
    
    // EXPLÍCITO downcats em cast dinâmico - ❌ nesse caso não funcionará (tentando por C1 em C2)

    // Já aqui, usamos a dynamic_cast para converter uma referência de Parent para uma referência de 
    // Child2. No entanto, em vez de verificar o resultado usando um ponteiro nulo, usamos um 
    // bloco try-catch para capturar a exceção std::bad_cast. Se a conversão for bem-sucedida, nenhum erro será lançado.. Caso contrário, a exceção será capturada e entraremos no código do catch.
    try{
        Child2 & d = dynamic_cast<Child2 &>(*b);
        std::cout << "✔️ Conversion is OK" << std::endl;
    }
    catch (std::bad_cast &bc){
        std::cout << "❌Conversion is NOT OK" << std::endl;
        return 0;
    }
    return 0;
}

/*
g++ -Wall -Wextra -Werror -std=c++98 -Wno-unused main.cpp

~/Trabalhos/MC_42/CPP_Module_06__Escola_42/estudo/dynamic_cast ❯ ./a.out
✔️ Conversion is OK
❌Conversion is NOT OK

EXPLICAÇÃO:
A conversão não ocorre na linha `Child2 &d = dynamic_cast<Child2&>(*b);` porque o objeto apontado por ``b` é do tipo `Child1` e não do tipo `Child2`.

O `dynamic_cast` é usado para fazer conversões seguras entre tipos relacionados por herança. No caso dessa linha, o objetivo é converter um ponteiro `Parent*` para uma referência `Child2&`, o que só seria válido se o objeto real apontado por `b` fosse do tipo `Child2` (ou uma classe derivada de `Child2`). No entanto, o objeto real apontado por `b` é do tipo `Child1`, sendoa ssim não é possível realizar uma conversão direta para `Child2`. 

*/
