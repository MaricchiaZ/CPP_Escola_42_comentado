
#include <iostream>
#include "sample_class.hpp"

Sample::Sample(void){

    std::cout << "Constructor called" << std::endl;

    this->setFoo(0);
    std::cout << "this->getfoo: " << this->getFoo() << std::endl;

    return;
}

Sample::~Sample(void){
    std::cout << "Destructor called" << std::endl;
    return;
}

// getFoo() é um getter que retorna o valor do atributo foo de uma classe.
//  O modificador const indica que o método não irá modificar o estado interno da classe.
int    Sample::getFoo(void)const {
    return this->foo;
}

//  setFoo() é um setter que recebe um parâmetro value e atribui esse valor ao atributo foo de uma classe.
void    Sample::setFoo(int v){
    if (v >= 0)
        this->foo = v;

    return;
}