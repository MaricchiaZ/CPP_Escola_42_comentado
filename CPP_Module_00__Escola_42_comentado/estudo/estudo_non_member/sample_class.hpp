
/*
Em C++, existem duas categorias principais de funções: funções membros (também conhecidas como métodos) e funções não membros. Existem algumas diferençaa entre essas duas categorias:

1. Funções Membros (Métodos):

- Funções que são declaradas e definidas dentro de uma classe.
- São associadas a objetos dessa classe e podem acessar os membros (atributos e outros métodos) desse objeto.
- Podem ser chamadas usando uma instância (objeto) da classe ou usando o operador de acesso -> para ponteiros de objetos.
- Têm acesso aos membros privados, protegidos e públicos da classe.
- Podem ser sobrecarregadas (ter várias versões com a mesma nomeação, mas parâmetros diferentes) dentro da mesma classe.


2. Funções Não Membros: (funções e atributos estáticos podem ser considerados NÃO MEMBROS)

- Funções que não estão declaradas dentro de uma classe. São independentes de qualquer classe.
- Elas não têm acesso direto aos membros (atributos e métodos) de uma classe, a menos que sejam declaradas como friend dentro da classe.
- São chamadas usando a sintaxe de uma função normal, passando argumentos.
- Não têm um objeto específico associado a eles.
- Podem acessar apenas membros públicos ou protegidos de uma classe.
- Podem ser funções globais (fora de qualquer classe) ou funções de outras classes que não a classe em questão.


Em resumo, funções membros são definidas dentro de uma classe e estão associadas a objetos específicos dessa classe, enquanto funções não membros não estão associadas a objetos específicos e podem ser chamadas independentemente de uma instância da classe.
*/

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample{

public:

// Métodos

    Sample(void);
    ~Sample(void);

    static int  getNbInst(void); // O modificador static indica que esse método pertence à classe Sample em vez
    //  de pertencer a instâncias individuais da classe. 
    // E como é estática, não depende de ter o objeto da classe instanciado. É independente.
    // Esse método getNbInst() é responsável por retornar o número de instâncias atualmente criadas da classe Sample.

private: 

    static int  nbInst; //  O modificador static indica que esse membro pertence à classe Sample em vez
    //  de pertencer a instâncias individuais da classe. 
    // E como é estática, não depende de ter o objeto da classe instanciado. É independente.
    //  O membro nbInst é responsável por armazenar o número de instâncias criadas da classe Sample.

};

#endif