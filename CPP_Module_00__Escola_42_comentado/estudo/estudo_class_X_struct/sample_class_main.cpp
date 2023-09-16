
#include <iostream>
#include "sample_class.hpp"

int main (){

    Sample1 instance1; // por padrão as structs tem seus membros públicos
    // Sample2 instance2; // ele não me deixa compilar, pois por padrão as classes têm seus membros privados
    // a não ser que eu vá no header e declare eles como públicos

    return 0;
}

// g++ -Wall -Wextra -Wno-used -Werror sample_class.cpp sample_class_main.cpp 

/* OUTPUT
~/Trabalhos/MC_42/CPP_Module_00__Escola_42/estudo_class_X_struct ❯ ./a.out

Constructor called
this->foo: 42
Member function bar called
Destructor called

*/