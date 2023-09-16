
#include <iostream>
#include "sample_class.hpp"

void    f0(void){
    Sample  instance;

    std::cout << "Number of instances: " << Sample::getNbInst() <<std::endl;
    return ;
}

void    f1(void){
    Sample  instance;

    std::cout << "Number of instances: " << Sample::getNbInst() <<std::endl;
    f0();
    return ;
}

int main (){

    std::cout << "Number of instances: " << Sample::getNbInst() <<std::endl;  //coisas estáticas não dependem de
    // ter um objeto da classe instanciado, e são independentes
    f1();
    std::cout << "Number of instances: " << Sample::getNbInst() <<std::endl;

    return 0;
}

// g++ -Wall -Wextra -Wno-used -Werror sample_class.cpp sample_class_main.cpp 

/* OUTPUT
~/Trabalhos/MC_42/CPP_Module_00__Escola_42/estudo_non_member ❯ ./a.out

Number of instances: 0
Constructor called
Number of instances: 1
Constructor called
Number of instances: 2
Destructor called
Destructor called
Number of instances: 0

*/