/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 22:00:03 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/18 10:18:41 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Parent {};
class Child1 : public Parent {};
class Child2 : public Parent {};

int main(void){
    
    Child1 a; // valor de referencia

    // Aqui ocorre um upcast implícito, onde o ponteiro da classe derivada Child1 é atribuído a um 
    // ponteiro da classe base Parent. Isso é permitido porque Child1 é uma classe derivada de Parent.
    Parent *b = &a; // IMPLÍCITO cast de reinterpretação

    //  Neste caso, também ocorre um upcast, mas de forma explícita usando uma conversão de tipo. 
    // O endereço do objeto a é reinterpretado como um ponteiro da classe base Parent. Isso também é 
    // permitido, mas pode ser perigoso se o objeto subjacente não for realmente um objeto da classe base.
    Parent *c = (Parent *)&a; // EXPLÍCITO cast de reinterpretação
    
    Parent *d = &a; // IMPLÍCITO upcast

    //Aqui ocorre um downcast implícito, onde um ponteiro da classe base Parent é atribuído a um 
    // ponteiro da classe derivada Child1. Essa operação não é permitida implicitamente porque d é um 
    // ponteiro da classe base, e não é possível ter certeza de que ele aponta para um objeto da classe
    //  derivada. O código pode compilar sem erros, mas pode levar a comportamentos indefinidos.
    Child1 *e = d; // IMPLÍCITO downcast - ❌ não compila

    //  Neste caso, ocorre um downcast explícito usando uma conversão de tipo. O ponteiro d da 
    // classe base Parent é reinterpretado como um ponteiro da classe derivada Child2. No entanto, 
    // isso é perigoso, pois d aponta para um objeto da classe Child1, não para um objeto da classe 
    // Child2. A conversão não é segura e pode levar a comportamentos indefinidos.
    Child2 *f = (Child2 *)d; // EXPLÍCITO downcast
    
    return 0;
}

/*

❌O COMPILADOR NÂO PERMITE COMPILAR POR CAUSA DO CAST DA LINHA 38 ❌
g++ -Wall -Wextra -Werror -std=c++98 -Wno-unused main.cpp

~/Trabalhos/MC_42/CPP_Module_06__Escola_42/estudo/upcast_and_downcast ❯ g++ -Wall -Wextra -Werror -std=c++98 -Wno-unused main.cpp
main.cpp: In function ‘int main()’:

main.cpp:38:17: error: invalid conversion from ‘Parent*’ to ‘Child1*’ [-fpermissive]
   38 |     Child1 *e = d; // IMPLÍCITO downcast
      |                 ^
      |                 |
      |                 Parent*



*/