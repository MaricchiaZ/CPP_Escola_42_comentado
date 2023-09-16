
#include <iostream>
#include "sample2_class.hpp"

// função sample da classe sample ou CONSTRUCTOR
Sample2::Sample2(char p1, int p2, float p3) : a1(p1), a2(p2), a3(p3) {// aqui estamos fazendo uma inicialização de lista ou também conhecida por inicialização de atributos por meio de uma lista de inicializadores.

 // Sample2 recebe três parâmetros: char p1, int p2 e float p3. A parte ': a1(p1), a2(p2), a3(p3)' é chamada de lista de inicializadores. Ela é usada para inicializar os atributos da classe Sample2 com os valores passados como argumentos para o construtor.

    std::cout << "Constructor called" << std::endl;

    std::cout << "this->a1: " << this->a1 << std::endl;
    std::cout << "this->a1: " << this->a2 << std::endl;
    std::cout << "this->a1: " << this->a3 << std::endl;

    return;
}

Sample2::~Sample2(void){ // O destrutor é responsável por liberar recursos ou realizar outras tarefas quando um objeto da classe é destruído. 
    std::cout << "Destructor called" << std::endl;
    return;
}
