
#include <iostream>
#include "sample_class.hpp"

int main (){

    Sample instance; // aqui instanciamos (declaramos e inicializamos) um OBJETO da classe Sample usando o 
    //construtor padrão Sample::Sample(). Isso cria uma instância do objeto Sample chamada instance.
    //Quando a instância é criada, o construtor da classe Sample é automaticamente chamado, executando o 
    // código que você definiu dentro dele. Nesse caso, o construtor exibirá a 
    //  "Constructor called" usando a função std::cout.


    instance.foo = 42; // o int foo que pertence a instance recebe o valor de 42.
    std::cout << "instace.foo: " << instance.foo << std::endl; // imprimimos o valor de instance.foo ...

    instance.bar(); // aqui chamamos a função bar que pertence a instance

    return 0;
}

// g++ -Wall -Wextra -Wno-used -Werror sample_class.cpp sample_class_main.cpp 

/* OUTPUT
~/Trabalhos/MC_42/CPP_00__Escola_42/estudo_classes ❯ ./a.out

Constructor called
Destructor called

*/