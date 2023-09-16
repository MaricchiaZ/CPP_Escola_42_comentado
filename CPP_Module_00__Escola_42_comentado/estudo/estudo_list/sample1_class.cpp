
#include <iostream>
#include "sample1_class.hpp"

Sample1::Sample1(char p1, int p2, float p3){ // aqui chamamos a função sample da classe sample ou CONSTRUCTOR

    std::cout << "Constructor called" << std::endl;

    this->a1 = p1;
    //  O uso de this-> é opcional, mas é utilizado para explicitar que a variável foo pertence ao objeto atual.
    std::cout << "this->a1: " << this->a1 << std::endl;

    this->a2 = p2;
    std::cout << "this->a1: " << this->a2 << std::endl;

    this->a3 = p3;
    std::cout << "this->a1: " << this->a3 << std::endl;

    return;
}

Sample1::~Sample1(void){ // aqui chamamos o destructor
// O destrutor é responsável por liberar recursos ou realizar outras tarefas quando um objeto da classe é destruído. 
    std::cout << "Destructor called" << std::endl;
    return;
}
