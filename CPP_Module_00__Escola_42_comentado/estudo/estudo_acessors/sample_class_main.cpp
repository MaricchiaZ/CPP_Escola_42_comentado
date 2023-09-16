
#include <iostream>
#include "sample_class.hpp"

int main (){

    Sample instance;

    instance.setFoo(10);
    std::cout << "instance.getFoo(): " << instance.getFoo() << std::endl;
    instance.setFoo(-10);
    std::cout << "instance.getFoo(): " << instance.getFoo() << std::endl;

    return 0;
}

// g++ -Wall -Wextra -Wno-used -Werror sample_class.cpp sample_class_main.cpp 

/* OUTPUT
~/Trabalhos/MC_42/CPP_Module_00__Escola_42/estudo_acessors ❯ ./a.out

Constructor called
this->getfoo: 0
instance.getFoo(): 10
instance.getFoo(): 10   // não modificou o valor por que temos um if que não deixa receber valores negativos
Destructor called

*/