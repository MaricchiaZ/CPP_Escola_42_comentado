
#include <iostream>
#include "sample_class.hpp"

Sample1::Sample1(void){ // aqui chamamos a função sample da classe sample
// Esse construtor é responsável por inicializar um objeto da classe quando ele é criado. 
    std::cout << "Constructor called" << std::endl;

    this->foo = 42;
    std::cout << "this->foo: " << this->foo << std::endl;

    this->bar();

    return;
}

Sample1::~Sample1(void){ // aqui chamamos o destructor
// O destrutor é responsável por liberar recursos ou realizar outras tarefas quando um objeto da classe é destruído. 
    std::cout << "Destructor called" << std::endl;
    return;
}

void    Sample1::bar(void)const{ // aqui podemos chamar a função bar que pertence a classe Sample

    std::cout << "Member function bar called" << std::endl;
    return;
}

Sample2::Sample2(void){ // aqui chamamos a função sample da classe sample
// Esse construtor é responsável por inicializar um objeto da classe quando ele é criado. 
    std::cout << "Constructor called" << std::endl;

    this->foo = 42;
    std::cout << "this->foo: " << this->foo << std::endl;

    this->bar();

    return;
}

Sample2::~Sample2(void){ // aqui chamamos o destructor
// O destrutor é responsável por liberar recursos ou realizar outras tarefas quando um objeto da classe é destruído. 
    std::cout << "Destructor called" << std::endl;
    return;
}

void    Sample2::bar(void)const{ // aqui podemos chamar a função bar que pertence a classe Sample

    std::cout << "Member function bar called" << std::endl;
    return;
}