
#include <iostream>
#include "sample1_class.hpp"
#include "sample2_class.hpp"

int main (){

    Sample1 instance1('a', 10, 1.5f); // aqui instanciamos um OBJETO da classe Sample1 (instanciar = declarar e inicializar)
    Sample2 instance2('b', 20, 4.5f);

    return 0;
}

// g++ -Wall -Wextra -Wno-used -Werror sample1_class.cpp sample2_class.cpp sample_class_main.cpp 

/* OUTPUT
~/Trabalhos/MC_42/CPP_Module_00__Escola_42/estudo_list ❯ ./a.out

Constructor called
this->a1: a
this->a1: 10
this->a1: 1.5
Constructor called
this->a1: b
this->a1: 20
this->a1: 4.5
Destructor called
Destructor called

*/