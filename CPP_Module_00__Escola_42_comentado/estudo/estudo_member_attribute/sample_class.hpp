
/*
        * MEMBROS = ATRIBUTOS + MÉTODOS *

Pode-se dizer que os membros são formados pelo conjunto de atributos e métodos de uma classe?

Sim, isso mesmo! Em programação orientada a objetos, os membros de uma classe são o conjunto de atributos e métodos que definem o comportamento e as propriedades dos objetos criados a partir dessa classe.

*/


#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample{ // A palavra-chave class é usada para definir uma classe. No caso, estamos definindo a classe Sample.

public: // A palavra-chave public é chamada de modificador de acesso e indica que os MEMBROS subsequentes
// da classe (Sample) são acessíveis a partir de qualquer lugar.

// aqui vão os ATRIBUTOS da classe Sample (nesse caso temos apenas 1 atributo o "int foo")
    int foo; // aqui estamos declarando as variáveis que pertencem a essa classe

// aqui são declaradas as funções ou MÉTODOS da classe Sample

    Sample(void); // esse é o constructor da classe, normalmente vai com o mesmo nome da classe
    // O construtor é responsável por inicializar um objeto da classe quando ele é criado
    ~Sample(void); // esse com a negativa "~" é o destructor, é o nome da classe com o "~" antes
    // O destrutor é responsável por liberar recursos quando um objeto é destruído.
    void    bar();

}; // a definição de uma classe acaba com um ";"

#endif