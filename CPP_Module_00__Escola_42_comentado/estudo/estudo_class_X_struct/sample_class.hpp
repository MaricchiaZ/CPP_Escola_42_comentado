
#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

// As structs e class são exatamente a mesma coisa em CPP e até a sintaxe é muito parecida,
// MAS temos algumas diferenças sutis:

//      1. Em uma struct, os membros são públicos por padrão, ou seja, são acessíveis de fora da estrutura. Em 
// contraste, em uma class, os membros são privados por padrão, ou seja, são acessíveis apenas dentro da classe.

//      2. Além disso, em uma classe, você pode declarar membros privados, protegidos e públicos usando os 
// modificadores de acesso private, protected e public. Nas structs, também é possível usar esses
//  modificadores, mas eles não são necessários quando você deseja tornar os membros públicos.

//      3. As structs sejam frequentemente usadas para representar agregados de dados simples.

// Em termos de recursos e funcionalidades, structs e classes têm os mesmos recursos disponíveis,
// como a capacidade de ter construtores, destrutores, métodos, herança, etc.

struct Sample1{ 
    int foo;

    Sample1(void);
    ~Sample1(void);
    void    bar(void)const;

};

class Sample2{ 
    int foo;

    Sample2(void);
    ~Sample2(void);
    void    bar(void)const;

};

#endif