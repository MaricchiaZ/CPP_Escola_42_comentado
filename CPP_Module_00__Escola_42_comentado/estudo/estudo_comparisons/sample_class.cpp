
#include <iostream>
#include "sample_class.hpp"

Sample::Sample(int v): foo(v){

    std::cout << "Constructor called" << std::endl;
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

// Este é um método compare() que recebe um ponteiro para um objeto da classe Sample e retorna um inteiro (int). 
// O modificador const no final indica que esse método não irá modificar os membros da classe. O método 
// compare() compara o valor do atributo foo do objeto atual (this) com o valor do atributo foo do objeto 
// passado como argumento other. Ele retorna um número negativo se foo for menor, zero se forem iguais ou 
// um número positivo se foo for maior.
int    Sample::compare(Sample * other) const{

    if (this->foo < other->getFoo())
        return -1;
    else if (this->foo > other->getFoo())
        return 1;

    return 0;
}