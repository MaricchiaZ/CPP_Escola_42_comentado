# Forma Canônica de uma classe

A forma canônica em C++ refere-se a uma implementação padrão de certos membros em uma classe, garantindo que a classe se comporte de acordo com as expectativas do C++ e facilite a correta gestão de recursos. Uma classe que segue a forma canônica possui um conjunto específico de membros que devem ser implementados ou gerenciados para garantir um comportamento consistente e seguro.

A forma canônica em C++ geralmente inclui os seguintes membros em uma classe:

- Construtor Padrão: Um construtor que não recebe argumentos ou recebe argumentos padrão. É usado para criar objetos sem a necessidade de passar argumentos.

- Construtor de Cópia: Um construtor que permite criar uma cópia exata de um objeto existente da mesma classe.

- Operador de Atribuição (Assignment Operator): Um operador sobrecarregado que permite atribuir o valor de um objeto a outro objeto da mesma classe.

- Destrutor: É responsável por liberar recursos alocados na memória quando um objeto é destruído.

- (Opcional) Construtor com Parâmetros: Um construtor que aceita argumentos para inicializar os membros da classe durante a criação do objeto.

- (Opcional) Operadores Sobrecarregados: Podem ser fornecidos outros operadores sobrecarregados, como ==, !=, +, -, entre outros, para fornecer comportamentos específicos para a classe.

Seguir a forma canônica em C++ é importante para garantir que a classe seja facilmente utilizada, copiada, atribuída e destruída sem problemas, evitando vazamentos de memória e comportamentos indesejados.

## Exemplo de uma classe que segue a forma canônica (aqui está só o header)

```cpp
#ifndef SAMPLE_HPP
#define SAMPLE_HPP

#include <iostream>

class Sample {
public:
    // Construtor padrão
    Sample();

    // Construtor de cópia
    Sample(const Sample& other);

    // Operador de atribuição (assignment operator)
    Sample& operator=(const Sample& other);

    // Destrutor
    ~Sample();

    // Função para adicionar elementos ao objeto Sample
    void addData(int value);

    // Função para imprimir os elementos do objeto Sample
    void printData() const;

private:
    int* _data;
    int _size;
};

#endif
```