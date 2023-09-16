# Lista CPP Module 08 - Contêineres, Iteradores e Algoritmos

Esta lista de exercícios aborda os conceitos de contêineres, iteradores e algoritmos em C++. Os objetivos desta lista são familiarizar-se com a utilização de contêineres modelados, entender o funcionamento dos iteradores e aplicar algoritmos pré-definidos para manipulação de dados.

O objetivo desta lista é aprender o uso dos contêineres e algoritmos padrão fornecidos pelo STL (Standard Template Library). **Embora seja possível resolver muitos dos problemas sem utilizar esses rconteiner e algoritmo, é importante destacar que o uso adequado dos contêineres e algoritmos padrão é essencial para este módulo.**

## Pasta Estudo:
Nesta pasta você encontrará os arquivos .cpp que aparecem nos vídeos da Intra42 e os resumos que são úteis para aprender sobre o conteúdo deste módulo. Os conteúdos estão organizado em pastas na sequência de vídeos da Intra42.
1. STL (Standard Template Library)

## Contêineres Modelados

Os contêineres modelados são estruturas de dados que permitem armazenar e organizar elementos em C++. A biblioteca padrão do C++ fornece diversos contêineres, como vetores (vector), listas (list), filas (queue), pilhas (stack) e mapas (map). Esses contêineres têm diferentes características e funcionalidades, permitindo escolher a estrutura de dados mais adequada para cada necessidade.

É importante ressaltar que o uso adequado dos contêineres e algoritmos padrão simplifica o código, aumenta a legibilidade e melhora a eficiência. Portanto, é encorajado que você faça todos os esforços para utilizar contêineres e algoritmos padrão sempre que for apropriado. Isso demonstrará sua compreensão dos conceitos abordados neste módulo e contribuirá para a obtenção de notas melhores.

## Iteradores

Os iteradores são objetos que fornecem uma interface para percorrer e acessar elementos em um contêiner. Eles permitem a iteração sobre os elementos de um contêiner e realização de operações como leitura, escrita e remoção de elementos. Os iteradores podem ser usados para percorrer contêineres sequenciais, como vetores e listas, ou associativos, como mapas e conjuntos.

## Algoritmos

Os algoritmos são funções pré-definidas que operam em contêineres ou sequências de elementos. Eles fornecem funcionalidades comuns, como ordenação, busca, transformação e manipulação de elementos. A biblioteca padrão do C++ oferece uma ampla variedade de algoritmos, como sort, find, transform, entre outros. Esses algoritmos podem ser aplicados a diferentes contêineres e sequências de elementos para realizar operações específicas de forma eficiente e conveniente.

## std::vector
`std::vector` é uma classe do contêiner sequencial no C++ Standard Template Library (STL) que representa um vetor dinâmico. É uma das implementações de vetor fornecidas pelo STL. Um vetor dinâmico é uma estrutura de dados que permite armazenar um conjunto de elementos em uma sequência contígua de memória e aumentar ou diminuir automaticamente seu tamanho conforme necessário.

A classe `std::vector` é uma classe de template, o que significa que pode conter elementos de qualquer tipo de dados. Ela oferece várias funcionalidades e métodos úteis para manipular elementos no vetor dinâmico. Algumas das operações comuns que você pode realizar com `std::vector` incluem:

1. Inserção e remoção de elementos no final ou em qualquer posição do vetor.
2. Acesso aos elementos através de índices.
3. Verificação do tamanho do vetor.
4. Ordenação do vetor.
5. Redimensionamento do vetor.
6. Acesso a um ponteiro para os dados subjacentes do vetor.

Exemplo de uso de `std::vector`:

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> myVector;

    // Inserção de elementos no vetor
    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);

    // Acesso aos elementos através de índices
    std::cout << "Element at index 0: " << myVector[0] << std::endl; // Output: 1
    std::cout << "Element at index 2: " << myVector[2] << std::endl; // Output: 3

    // Verificação do tamanho do vetor
    std::cout << "Size of vector: " << myVector.size() << std::endl; // Output: 3

    // Redimensionamento do vetor
    myVector.resize(5);
    std::cout << "New size of vector: " << myVector.size() << std::endl; // Output: 5

    return 0;
}
```

Neste exemplo, criamos um vetor `myVector` e inserimos alguns elementos usando `push_back`. Em seguida, acessamos os elementos usando índices e exibimos seu valor na saída padrão. Também verificamos o tamanho do vetor usando o método `size()` e redimensionamos o vetor para conter mais elementos usando `resize()`.

## std::list

`std::list` é uma classe do contêiner sequencial no C++ Standard Template Library (STL) que representa uma lista duplamente encadeada. É uma das implementações de lista fornecidas pelo STL. Uma lista duplamente encadeada é uma estrutura de dados que consiste em nós, cada um contendo um valor e dois ponteiros que apontam para o nó anterior e o próximo nó na lista.

A classe `std::list` é uma classe de template, o que significa que pode conter elementos de qualquer tipo de dados. Ela oferece várias funcionalidades e métodos úteis para manipular elementos em uma lista duplamente encadeada. Algumas das operações comuns que você pode realizar com `std::list` incluem:

1. Inserção e remoção de elementos no início, fim ou em qualquer posição da lista.
2. Acesso aos elementos através de iteradores.
3. Verificação do tamanho da lista.
4. Ordenação da lista.
5. Reversão da ordem dos elementos na lista.
6. Remoção de elementos duplicados.

Exemplo de uso de `std::list`:

```cpp
#include <iostream>
#include <list>

int main() {
    std::list<int> myList;

    // Inserção de elementos na lista
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_front(0);

    // Iteração pelos elementos da lista usando um loop for-each
    for (const auto& value : myList) {
        std::cout << value << " ";
    }
    // Output: 0 1 2 3

    return 0;
}
```

Neste exemplo, criamos uma lista `myList` e inserimos alguns elementos no início e no final da lista usando `push_front` e `push_back`, respectivamente. Em seguida, usamos um loop for-each para percorrer todos os elementos da lista e exibimos seu valor na saída padrão. A ordem dos elementos na lista é preservada, já que as listas duplamente encadeadas mantêm a ordem de inserção.

## std::stack

`std::stack` é uma classe de contêiner adaptador (ou container adapter) fornecida pela biblioteca padrão do C++ que implementa uma pilha (stack). Uma pilha é uma estrutura de dados que segue a política de acesso LIFO (Last In, First Out), o que significa que o último elemento inserido é o primeiro a ser removido.

A classe `std::stack` é projetada para fornecer uma interface simples e fácil de usar para trabalhar com pilhas. Ela é construída sobre um contêiner sequencial subjacente, como `std::deque`, `std::list`, ou `std::vector`. Por padrão, o contêiner sequencial usado é `std::deque`, mas você pode especificar um contêiner diferente como argumento de template, se desejar.

Principais operações suportadas por `std::stack`:

1. `push(element)`: Adiciona um elemento no topo da pilha.
2. `pop()`: Remove o elemento do topo da pilha.
3. `top()`: Acessa o elemento no topo da pilha, sem removê-lo.
4. `empty()`: Verifica se a pilha está vazia.
5. `size()`: Retorna o número de elementos na pilha.

Exemplo de uso do `std::stack`:

```cpp
#include <iostream>
#include <stack>

int main() {
    std::stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    while (!stack.empty()) {
        std::cout << stack.top() << " "; // Imprime o elemento do topo da pilha
        stack.pop(); // Remove o elemento do topo
    }

    std::cout << std::endl;

    return 0;
}
```

Neste exemplo, a pilha é usada para armazenar alguns números inteiros e, em seguida, os elementos são removidos da pilha usando o método `pop()`. A saída do programa será: `30 20 10`, que é a ordem inversa da inserção original dos elementos. Isso ocorre porque o último elemento inserido é o primeiro a ser removido, seguindo a política LIFO da pilha.

## Lidar com os temas abordados

Nesta lista de exercícios, você será desafiado a implementar e utilizar contêineres modelados, criar e manipular iteradores e aplicar algoritmos pré-definidos para resolver problemas específicos. Cada exercício fornecerá instruções detalhadas sobre os requisitos e tarefas a serem cumpridas. Você será solicitado a implementar código que utilize os conceitos de contêineres, iteradores e algoritmos, aplicando as melhores práticas de programação e aproveitando ao máximo as funcionalidades oferecidas pela biblioteca padrão do C++.

## Como utilizar
Clone este repositório em sua máquina local.
Navegue até o diretório do exercício desejado.
Compile usando o `make` e execute o código do exercício de sua preferência.

Divirta-se programando e explorando os conceitos de contêineres, iteradores e algoritmos em C++!

Espero que isso te ajude a criar um Readme.md para a lista CPP Module 08 da escola 42!