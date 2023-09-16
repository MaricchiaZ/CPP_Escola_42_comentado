
#include <iostream>
#include "sample_class.hpp"

Sample::Sample(void){ // aqui chamamos a função sample da classe sample
// Esse construtor é responsável por inicializar um objeto da classe quando ele é criado. 
    std::cout << "Constructor called" << std::endl;

    this->foo = 42; // aqui atribuimos o valor 42 à variável foo do objeto atual.
    //  O uso de this-> é opcional, mas é utilizado para explicitar que a variável foo pertence ao objeto atual.
    // é semelhante ao modo como usamos as variáveis de uma struct em C.

    std::cout << "this->foo: " << this->foo << std::endl;

    this->bar(); // chamamos o método bar() do objeto atual. O uso de this-> é opcional neste caso também.

    return;
}

Sample::~Sample(void){ // aqui chamamos o destructor
// O destrutor é responsável por liberar recursos ou realizar outras tarefas quando um objeto da classe é destruído. 
    std::cout << "Destructor called" << std::endl;
    return;
}

void    Sample::bar(void){ // aqui podemos chamar a função bar que pertence a classe Sample

    std::cout << "Member function bar called" << std::endl;
    return;
}