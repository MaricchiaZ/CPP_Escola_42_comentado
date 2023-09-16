
#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample{ // A palavra-chave class é usada para definir uma classe. No caso, estamos definindo a classe Sample.

public: // A palavra-chave public é chamada de modificador de acesso e indica que os membros subsequentes
// da classe (Sample) são acessíveis a partir de qualquer lugar.

    int foo; // aqui estamos declarando a variável que pertence a essa classe

// aqui são declaradas as funções da classe Sample

    Sample(void); // esse é o constructor da classe, normalmente vai com o mesmo nome da classe
    // O construtor é responsável por inicializar um objeto da classe quando ele é criado
    ~Sample(void); // esse com a negativa "~" é o destructor, é o nome da classe com o "~" antes
    // O destrutor é responsável por liberar recursos quando um objeto é destruído.
    void    bar();

}; // a definição de uma classe acaba com um ";"

#endif