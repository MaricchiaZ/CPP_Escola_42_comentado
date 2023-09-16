
#include <iostream>
#include "sample_class.hpp"

Sample::Sample(void){ // aqui chamamos a função sample da classe sample
// Esse construtor é responsável por inicializar um objeto da classe quando ele é criado. 
// Quando uma instância da classe Sample for criada, esse construtor será chamado automaticamente.
//  No caso, ele exibe a mensagem "Constructor called" usando a função std::cout.

    std::cout << "Constructor called" << std::endl;
    return;
}

Sample::~Sample(void){ // aqui chamamos o destructor
// Aqui, está sendo definido o destrutor da classe Sample. O destrutor é responsável por 
// liberar recursos ou realizar outras tarefas quando um objeto da classe é destruído. 
// Quando uma instância da classe Sample for destruída, o destrutor será chamado automaticamente. 
// Nesse caso, ele exibe a mensagem "Destructor called" usando a função std::cout.

    std::cout << "Destructor called" << std::endl;
    return;
}