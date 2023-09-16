
#ifndef SAMPLE1_CLASS_H
# define SAMPLE1_CLASS_H

class Sample1{ //estamos definindo a classe Sample.

public: //public indica que os (MEMBROS = atributos + métodos) subsequentes da classe (Sample) são acessíveis a partir de qualquer lugar.

// ATRIBUTOS da classe Sample1
    char    a1;
    int     a2;
    float   a3;

// MÉTODOS ou funçoes da classe Sample1

    Sample1( char p1, int p2, float p3); // esse é o constructor da classe, vai com o mesmo nome da classe
    ~Sample1(void); // esse é o destructor, é o nome da classe com o "~" antes

}; // a definição de uma classe acaba com um ";"

#endif