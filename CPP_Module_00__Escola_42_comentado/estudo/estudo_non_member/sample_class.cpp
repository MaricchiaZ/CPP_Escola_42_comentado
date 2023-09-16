
#include <iostream>
#include "sample_class.hpp"

Sample::Sample(void){
    std::cout << "Constructor called" << std::endl;
    Sample::nbInst += 1;
    return;
}

Sample::~Sample(void){
    std::cout << "Destructor called" << std::endl;
    Sample::nbInst -= 1;
    return;
}

int    Sample::getNbInst(void){
    return Sample::nbInst;
}

int Sample::nbInst = 0; // para iniciacializar um atributo que não percente as instâncias da classe, inicializamos
// fora das funções.

// As funções não membros não estão associadas a objetos específicos e podem ser chamadas independentemente de uma instância da classe.