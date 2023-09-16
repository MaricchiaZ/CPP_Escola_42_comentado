# CPP Module 02 - Introdução a Classes em C++
Este é o segundo módulo do curso de C++ da escola 42. Neste módulo, vamos nos aprofundar no conceito de classes em C++ e aprender a criar e manipular objetos, com enfoque em Polimorfismo ad-hoc, sobrecarga de operadores
 e forma de classe canónica ortodoxa.

## Tópicos abordados
Neste módulo, iremos cobrir os seguintes tópicos:

- Encapsulamento
- Herança e polimorfismo
- Sobrecarga de operadores
- Templates em C++
- Exceções

## Conceitos básicos:

### Polimorfismo ad-hoc OU Sobrecarga de funções
O polimorfismo ad-hoc, também conhecido como sobrecarga de funções, é um conceito em C++ que permite definir várias funções com o mesmo nome, mas com diferentes parâmetros ou tipos de retorno. Isso permite que você execute diferentes implementações da função com base nos argumentos passados durante a chamada.

No polimorfismo ad-hoc, as funções são diferenciadas pela sua assinatura, que consiste no tipo e/ou número de parâmetros. Quando uma função é chamada, o compilador seleciona automaticamente a versão correta da função com base nos argumentos fornecidos.

A sobrecarga de funções é uma forma de polimorfismo estático, pois a seleção da função a ser chamada é feita em tempo de compilação. Isso oferece flexibilidade e permite que você crie interfaces mais intuitivas, onde diferentes versões da mesma função podem ser usadas dependendo do contexto.

Por exemplo, você pode ter uma função chamada "soma" que pode ser sobrecarregada para lidar com diferentes tipos de parâmetros, como inteiros, números de ponto flutuante ou até mesmo objetos personalizados. Dessa forma, você pode chamar a função "soma" com diferentes tipos de argumentos e obter resultados apropriados para cada caso.

### Sobrecarga de operadores
A sobrecarga de operadores é um recurso em C++ que permite que você atribua significado especial a operadores existentes quando eles são aplicados a objetos de uma classe personalizada. Com a sobrecarga de operadores, você pode definir o comportamento dos operadores para tipos de dados personalizados, permitindo que eles sejam usados de maneira mais intuitiva e semântica em seu código.

Em C++, os operadores podem ser sobrecarregados para trabalhar com tipos de dados personalizados, como objetos de uma classe específica. Isso significa que você pode definir como os operadores aritméticos, operadores de comparação, operadores de atribuição e outros operadores devem se comportar quando aplicados a objetos de sua classe.

A sobrecarga de operadores é realizada através da definição de funções especiais chamadas "funções de sobrecarga de operadores" que têm o nome do operador a ser sobrecarregado, precedido pelo operador "operator". Essas funções especiais definem o comportamento personalizado do operador quando aplicado aos objetos da classe.

Por exemplo, você pode sobrecarregar o operador de adição (+) para permitir que dois objetos de uma classe personalizada sejam adicionados juntos. Isso permite que você escreva código como objeto1 + objeto2, onde a adição é realizada de acordo com a lógica que você definiu na função de sobrecarga do operador de adição.

A sobrecarga de operadores é uma ferramenta poderosa em C++ que permite que você crie interfaces mais intuitivas e expressivas para suas classes personalizadas, permitindo que você trabalhe com elas de maneira semelhante aos tipos de dados primitivos. No entanto, é importante usar a sobrecarga de operadores com cuidado e garantir que seu uso esteja de acordo com as convenções e expectativas dos desenvolvedores que usarão seu código.

### Forma de classe canônica ortodoxa
A forma de classe canônica (ou "canonically-implemented form") é uma prática recomendada em C++ para a implementação consistente dos membros especiais de uma classe. Esses membros especiais incluem o construtor padrão, o construtor de cópia, o operador de atribuição de cópia e o destruidor.

A forma canônica de uma classe garante que todos esses membros especiais sejam implementados de forma consistente, seguindo certas regras e convenções. A implementação correta desses membros é importante para garantir o comportamento adequado da classe em relação à cópia, atribuição e destruição de objetos.

A forma canônica de uma classe normalmente inclui os seguintes membros:

- Construtor padrão: Um construtor que pode ser chamado sem argumentos e cria um objeto vazio ou com um estado inicial padrão.

- Construtor de cópia: Um construtor que cria um novo objeto copiando os valores de outro objeto do mesmo tipo.

- Operador de atribuição de cópia: Um operador que permite atribuir os valores de um objeto a outro objeto do mesmo tipo.

- Destruidor: Um método especial que é chamado quando um objeto é destruído, liberando recursos alocados pelo objeto.

Ao implementar esses membros especiais de acordo com a forma canônica, você garante que a classe se comporte corretamente em operações de cópia, atribuição e destruição. Isso evita comportamentos inesperados, vazamento de memória e outros problemas relacionados à manipulação de objetos da classe.

Além disso, seguir a forma canônica torna sua classe mais consistente e fácil de entender para outros programadores que possam trabalhar com o código. Também facilita a interoperabilidade com bibliotecas e recursos do C++ que esperam a presença desses membros especiais.

#### Exemplo de uma classe que segue a forma canônica (aqui está só o header)

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

### Sample(const Sample& other), o que é o **&** ?
O & na declaração const Sample& other **indica que o parâmetro other é uma referência constante para um objeto do tipo Sample**.

Ao usar uma referência constante como parâmetro em uma função de cópia (construtor de cópia, no caso), estamos indicando que queremos receber uma referência ao objeto original que desejamos copiar, mas sem permitir sua modificação. Isso evita a necessidade de fazer uma cópia completa do objeto.
A referência constante permite acessar os membros do objeto original, mas não permite alterar seu estado. Isso é útil para operações de cópia, onde apenas desejamos obter os valores dos membros do objeto original para criar uma cópia correspondente.

### Sample& operator=(const Sample& other), o que é o **&**?
O & na declaração Sample& operator=(const Sample& other) indica que o retorno do operador de atribuição é uma referência a um objeto do tipo Sample.

Quando um operador de atribuição é definido como uma função membro de uma classe, geralmente é desejável retornar uma referência ao próprio objeto atualizado após a atribuição. Isso permite encadear múltiplas atribuições em uma única expressão, conhecida como "chaining".

Ao retornar uma referência Sample&, o operador de atribuição permite que a atribuição seja usada em uma expressão posterior, por exemplo:
```cpp
Sample a;
Sample b;
Sample c;

a = b = c;  // Chaining de atribuição

```
Nesse exemplo, `b = c` retorna uma referência a `b`, e em seguida, `a = b` retorna uma referência a `a`. Essa referência é usada para encadear as atribuições subsequentes.

Além disso, retornar uma referência também permite que o operador de atribuição seja usado em um contexto onde o objeto atualizado é necessário ou esperado, como em uma função que espera receber um objeto Sample& como argumento por referência.

## Como usar este repositório
Este repositório contém os exercícios práticos e exemplos de código para o módulo CPP Module 02. Cada exercício está localizado em seu diretório correspondente e contém um arquivo de código-fonte (.cpp) e um Makefile para compilar e executar o código.

Além disso, você encontrará os exercícios introdutórios baseados nos vídeos da intra42 sobre o CPP. Esses exercícios são úteis para entender os conceitos básicos de C++ e são um bom ponto de partida para este módulo.

Para compilar e executar um exercício, navegue até o diretório correspondente e execute o seguinte comando no terminal:

```
make
```
Isso irá compilar o código e gerar um executável. Em seguida, você pode executar o programa usando o seguinte comando:

```
./<nome_do_executavel>
```
Lembre-se de substituir <nome_do_executavel> pelo nome do arquivo executável gerado durante a compilação.

## Referências úteis
Durante este módulo, recomendo consultar as seguintes referências:

Livro: "The C++ Programming Language" de Bjarne Stroustrup
Documentação oficial do C++: https://en.cppreference.com/
