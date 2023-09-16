
#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample{ //definição da classe Sample.

public: // A palavra-chave public é um modificador de acesso e indica que os membros subsequentes da
// classe Sample são acessíveis a partir de qualquer lugar.

// Atributos Públicos:

    int public_foo;

// Métodos Públicos 

    Sample(void); //constructor
    ~Sample(void); //destructor

    void    publicBar(void)const;//  O modificador const no final indica que esse método não irá modificar os atributos da classe.

private: // A palavra-chave private é um modificador de acesso e indica que os membros subsequentes 
//da classe Sample são acessíveis apenas dentro da própria classe. . Isso significa que eles não podem ser 
// acessados ou modificados por outras partes do programa diretamente. A utilização do
//  modificador private garante o encapsulamento e o controle de acesso desses membros.

// Isso permite um controle mais refinado sobre o acesso e a modificação dos membros da classe.

// Atributos Privados:

    int private_foo;

// Métodos Privados 

    void    privateBar(void)const;//  O modificador const no final indica que esse método não irá modificar os atributos da classe.

};

#endif