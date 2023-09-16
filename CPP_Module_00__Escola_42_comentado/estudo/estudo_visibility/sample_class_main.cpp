
#include <iostream>
#include "sample_class.hpp"

int main (){

    Sample instance; // aqui instanciamos (declaramos e inicializamos) um OBJETO da classe Sample e chamamos esse objeto de instance
    
    instance.public_foo = 42;
    std::cout << "instance.public_foo: " << instance.public_foo <<std::endl;
    
    instance.publicBar(); // podemos chamar a função public em qualquer lugar por que ela é pública

// vamos tentar chamar aqui os membros privados, e ele não deixará complilar, e já fica com friso vermelho em baixo avisando que ela é inacessível (descomente as linhas abaixo para ver)
    // instance.private_foo = 42;
    // std::cout << "instance.privateFoo: " << instance.privateFoo << std::endl;

    // instance.privateBar();
    return 0;
}

// g++ -Wall -Wextra -Wno-used -Werror sample_class.cpp sample_class_main.cpp 

/* OUTPUT
~/Trabalhos/MC_42/CPP_Module_00__Escola_42/estudo_visibility ❯ ./a.out

Constructor called
this->publicfoo: 0
this->privatefoo: 0
Member function publicBar called
Member function privateBar called
instance.public_foo: 42
Member function publicBar called
Destructor called

*/