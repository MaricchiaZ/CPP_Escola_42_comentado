
/*
O método compare() compara o valor do atributo foo do objeto atual (this) com o valor do atributo foo do objeto passado como argumento other. Ele retorna um número negativo se foo for menor, zero se forem iguais ou um número positivo se foo for maior.
*/


#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample{

public:

    Sample(int v);
    ~Sample(void);

    int    getFoo(void) const; // O getter é um método que retorna o valor atual de um atributo privado. 
    // Geralmente, seu nome segue a convenção de começar com "get" seguido pelo nome do atributo.

    int    compare(Sample * other) const; // Essa linha declara um método compare() que recebe um ponteiro para 
    // um objeto da classe Sample e retorna um inteiro (int).
    // O modificador const no final indica que esse método não irá modificar os membros da classe. 
    // O método compare() compara o valor do atributo foo do objeto atual (this) com o valor do atributo 
    // foo do objeto passado como argumento other. Ele retorna um número negativo se foo for menor, 
    // zero se forem iguais ou um número positivo se foo for maior.

private:

    int foo;

};

#endif