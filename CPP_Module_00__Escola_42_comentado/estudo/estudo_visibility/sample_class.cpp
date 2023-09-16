
#include <iostream>
#include "sample_class.hpp"

Sample::Sample(void){ // construímos c classe Sample já com a inicialização por lista
// o valor f é passado por parâmetro quando esse construtor for chamado (provavelmente na main)

    std::cout << "Constructor called" << std::endl;

// no constructor podemos chamar tanto os membros públicos como os privados
    this->public_foo = 0;
    std::cout << "this->publicfoo: " << this->public_foo <<std::endl;

// os membros privados SÓ PODEM ser usados no constructor
    this->private_foo = 0;
    std::cout << "this->privatefoo: " << this->private_foo <<std::endl;

    this->publicBar();
    this->privateBar(); // só podemos chamar as funções privates dentro do constructor

    return;
}

Sample::~Sample(void){
    std::cout << "Destructor called" << std::endl;
    return;
}

void    Sample::publicBar(void)const { // aqui podemos chamar a função bar que pertence a classe Sample

    std::cout << "Member function publicBar called" << std::endl;    
    return;
}

void    Sample::privateBar(void)const { // aqui podemos chamar a função bar que pertence a classe Sample

    std::cout << "Member function privateBar called" << std::endl;    
    return;
}