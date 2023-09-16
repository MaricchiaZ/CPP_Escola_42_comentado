
#include <iostream>
#include "sample_class.hpp"

Sample::Sample(float const f): pi(f), qd(42){ // construímos c classe Sample já com a inicialização por lista
// o valor f é passado por parâmetro quando esse construtor for chamado (provavelmente na main)

    std::cout << "Constructor called" << std::endl;
    return;
}

Sample::~Sample(void){
    std::cout << "Destructor called" << std::endl;
    return;
}

void    Sample::bar(void)const { // aqui podemos chamar a função bar que pertence a classe Sample

    std::cout << "Member function bar called" << std::endl;

    std::cout << "this->pi: " << this->pi << std::endl;
    std::cout << "this->qd: " << this->qd << std::endl;

    // this->qd = 42; // se eu tentar trocar o valor de um membro da classe, não vai complilar, pois essa função é declarada como CONST, ela não TEM PODER de modificar os membros da classe
    
    return;
}