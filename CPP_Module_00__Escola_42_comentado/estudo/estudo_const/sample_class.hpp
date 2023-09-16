
#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample{ //definição da classeSample.

public: // indica que os membros podem ser acessados sem restrição

// Atributos:

    float const pi; // O atributo pi é uma constante de ponto flutuante (float) e é declarado como CONST, o que significa que seu valor não pode ser alterado após a inicialização. (VALOR CONSTANTE)
    int qd;

// Métodos

    Sample(float const f); //constructor
    ~Sample(void); //destructor

    void    bar(void) const;

}; // a definição de uma classe acaba com um ";"

#endif