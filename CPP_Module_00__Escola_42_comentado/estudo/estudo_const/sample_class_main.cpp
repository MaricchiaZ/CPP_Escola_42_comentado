
#include <iostream>
#include "sample_class.hpp"

int main (){

    Sample instance(3.14); // aqui instanciamos (declaramos e inicializamos) um OBJETO da classe Sample e chamamos esse objeto de instance
    
    instance.bar(); // aqui rodamos a função bar que pertence ao objeto instance

    return 0;
}

// g++ -Wall -Wextra -Wno-used -Werror sample_class.cpp sample_class_main.cpp 

/* OUTPUT
~/Trabalhos/MC_42/CPP_Module_00__Escola_42/estudo_const ❯ ./a.out

Constructor called
Member function bar called
this->pi: 3.14
this->qd: 42
Destructor called

*/