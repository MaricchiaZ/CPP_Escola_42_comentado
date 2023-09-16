
/*
                            Accessors

Em C++, accessors, também conhecidos como getter e setter, são métodos utilizados para obter (get) e 
modificar (set) o valor de atributos privados de uma classe. Eles permitem um controle mais refinado 
sobre o acesso e a modificação dos membros privados.

O uso de accessors, como getters e setters, é uma prática recomendada para garantir o encapsulamento e a proteção dos atributos privados de uma classe. Ao usar accessors, você pode controlar como os atributos são acessados e modificados, adicionando validações ou realizando ações específicas quando eles são alterados ou lidos.
*/

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample{ //definição da classe Sample.

public:

// Métodos

    Sample(void); //constructor
    ~Sample(void); //destructor

    int    getFoo(void) const; // O getter é um método que retorna o valor atual de um atributo privado. 
    // Geralmente, seu nome segue a convenção de começar com "get" seguido pelo nome do atributo.

    void    setFoo(int v); // O setter é um método que permite modificar o valor de um atributo privado. 
    // Geralmente, seu nome segue a convenção de começar com "set" seguido pelo nome do atributo

private:

    int foo;

};

#endif