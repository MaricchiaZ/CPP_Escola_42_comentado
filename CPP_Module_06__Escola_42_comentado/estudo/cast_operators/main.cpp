/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:42:25 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/18 10:54:04 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

// A classe Foo possui um construtor e dois cast operators. O construtor recebe um valor float e 
// inicializa o atributo privado _v com esse valor.

class Foo{
    
public:
    Foo(float const v): _v(v) {}
    float getV() const { return _v; }

    // Os cast operators são implementados como funções de conversão na classe Foo. 
    // Temos dois cast operators definidos: operator float() e operator int().
    operator float() {return this->_v;} // O operator float() permite converter um objeto Foo em um valor 
    // float. Ele retorna o valor do atributo _v.
    
    operator int() {return static_cast<int>(this->_v);} // O operator int() permite converter um objeto 
    // oo em um valor inteiro. Ele realiza uma conversão explícita do valor _v para um valor inteiro 
    // usando static_cast<int>.

private:
    float _v;
};


// Aqui criamos um objeto Foo chamado a com o valor 420.024f. Em seguida, realizamos as conversões
//  usando os cast operators. Atribuímos o valor de a a uma variável float b e a uma variável int c. 
int main(void)
{

    Foo a(420.024f);
    float b = a;
    int c = a;
    
    std::cout << a.getV() << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    
    return (0);
}

/*
g++ -Wall -Wextra -Werror -Wno-unused -std=c++98 main.cpp

~/Trabalhos/MC_42/CPP_Module_06__Escola_42/estudo/cast_operators ❯ ./a.out
420.024
420.024
420

Isso ocorre porque as conversões usando os cast operators retornam os valores _v do objeto Foo, convertidos para float e int, respectivamente.

*/