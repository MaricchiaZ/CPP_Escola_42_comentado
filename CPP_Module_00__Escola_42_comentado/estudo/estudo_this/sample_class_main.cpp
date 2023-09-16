
#include <iostream>
#include "sample_class.hpp"

int main (){

    Sample instance; // aqui instanciamos (declaramos e inicializamos) um OBJETO da classe Sample usando o 
    //construtor padrão Sample::Sample(). 

    return 0;
}

// g++ -Wall -Wextra -Wno-used -Werror sample_class.cpp sample_class_main.cpp 

/* OUTPUT
~/Trabalhos/MC_42/CPP_Module_00__Escola_42/estudo_this ❯ ./a.out

Constructor called
this->foo: 42
Member function bar called
Destructor called

*/