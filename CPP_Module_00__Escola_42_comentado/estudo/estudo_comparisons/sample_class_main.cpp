
#include <iostream>
#include "sample_class.hpp"

int main (){

    Sample instance1(10); // criamos duas instâncias da classe Sample
    Sample instance2(10);

// Essas linhas comparam os endereços de memória das instâncias instance1 e instance2 usando o operador ==. 

    if (&instance1 == &instance1) // aqui comparamos o endereço de memória da instância1 com ela mesma
    // (aqui dará verdadeira pois ela se encontra no mesmo endereço que ela mesma :)
        std::cout << "instance1 and instance1 are physycally equal" << std::endl;
    else 
        std::cout << "instance1 and instance1 are NOT physycally equal" << std::endl;

    if (&instance1 == &instance2) // aqui a condição é falsa, pois instance1 e instance2 são instâncias diferentes 
    // e possuem endereços de memória diferentes.
        std::cout << "instance1 and instance2 are physycally equal" << std::endl;
    else 
        std::cout << "instance1 and instance2 are NOT physycally equal" << std::endl;


// Essas linhas chamam o método compare() da classe Sample para comparar as instâncias instance1 e 
// instance2 estruturalmente.
    if (instance1.compare (&instance1) == 0) // a condição é verdadeira, pois instance1 é comparada com
    //  ela mesma e os valores dos atributos foo são iguais. 
        std::cout << "instance1 and instance1 are structurally equal" << std::endl;
    else 
        std::cout << "instance1 and instance1 are NOT structurally equal" << std::endl;

    if (instance1.compare (&instance2) == 0) // a condição é verdadeira, pois os valores dos 
    // atributos foo de instance1 e instance2 também são iguais.
        std::cout << "instance1 and instance2 are structurally equal" << std::endl;
    else 
        std::cout << "instance1 and instance2 are NOT structurally equal" << std::endl;

    return 0;
}

// vamos complilar sem as flags porque a primeira condição é sempre verdadeira e a flag impede a compilação
// g++ sample_class.cpp sample_class_main.cpp 

/* OUTPUT
~/Trabalhos/MC_42/CPP_Module_00__Escola_42/estudo_comparisons ❯ ./a.out

Constructor called
Constructor called
instance1 and instance1 are physycally equal
instance1 and instance2 are NOT physycally equal
instance1 and instance1 are structurally equal
instance1 and instance2 are structurally equal
Destructor called
Destructor called

*/