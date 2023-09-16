
#include <iostream>
#include "sample_class.hpp"

/*
o código demonstra a utilização de ponteiros para membros de classe, permitindo o acesso e a chamada de 
membros e funções membro através desses ponteiros. Isso permite uma maior flexibilidade e dinamicidade 
no uso dos membros da classe.

As únicas formas corretas de utilizar um ponteiro para membro é através do operador   .*    OU    ->*
exemplos:
- instance.*p = 21;
- instance->*p = 21;
*/

int main (){

    Sample instance;
    Sample*  instance_pointer = &instance; // Cria um ponteiro para a instância instance da classe Sample.

    int Sample::*p = NULL; //  Declara um ponteiro para um membro inteiro QUALQUER da classe Sample chamado-o 
    // de p e o inicializa com NULL.
    void    (Sample::*f)(void)const; // Declara um ponteiro para uma função membro QUALQUER sem retorno e sem 
    // parâmetros da classe Sample chamado f.

    p = &Sample::foo; // Atribui o endereço do membro foo da classe Sample ao ponteiro p.

    std::cout << "Value of member foo: " << instance.foo << std::endl;
    instance.*p = 21; // Acessa o membro foo da instância instance usando o ponteiro p e atribui o valor 21 a ele.
    std::cout << "Value of member foo: " << instance.foo << std::endl;
    instance_pointer->*p = 42; // Acessa o membro foo da instância apontada por instance_pointer usando 
    // o ponteiro p e atribui o valor 42 a ele.
    std::cout << "Value of member foo: " << instance.foo << std::endl;

    f = &Sample::bar; //  Atribui o endereço da função membro bar da classe Sample ao ponteiro f.

    (instance.*f)(); // Chama a função membro bar na instância instance usando o ponteiro f.
    (instance_pointer->*f)(); //  Chama a função membro bar na instância apontada por instance_pointer usando
    // o ponteiro f.

    return 0;
}

// g++ -Wall -Wextra -Wno-used -Werror sample_class.cpp sample_class_main.cpp 

/* OUTPUT
~/Trabalhos/MC_42/CPP_Module_00__Escola_42/estudo_pointer ❯ ./a.out

Constructor called
Value of member foo: 0
Value of member foo: 21
Value of member foo: 42
Member function bar called
Member function bar called
Destructor called

*/