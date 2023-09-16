# CPP Module 04 - Polimorfismo e Classe Abstrata
Este repositório contém a lista de exercícios do Module 04 do curso de C++ da Escola 42. Nesta lista, exploramos os conceitos de polimorfismo de subtipos, classes abstratas e interfaces.

## Resumo dos Conteúdos
Nesta lista, você encontrará exercícios que abordam os seguintes tópicos:

### 1. Polimorfismo de Subtipos
Polimorfismo de subtipos é um conceito fundamental da programação orientada a objetos que permite tratar objetos de classes derivadas como se fossem objetos da classe base. Isso significa que um objeto de uma classe derivada pode ser atribuído a um ponteiro ou referência da classe base, e os métodos virtuais da classe base podem ser chamados para manipular o objeto derivado.

Ao usar o polimorfismo de subtipos, podemos escrever um código genérico e flexível, capaz de lidar com diferentes tipos de objetos de forma transparente. Isso permite a reutilização de código, já que podemos criar algoritmos e funções que operam em objetos da classe base e podem ser aplicados a objetos de qualquer classe derivada.

Para aplicar o polimorfismo de subtipos, é necessário usar ponteiros ou referências da classe base para acessar os objetos derivados. Isso permite que o compilador resolva as chamadas de função corretamente, selecionando as implementações adequadas dos métodos virtuais em tempo de execução, com base no tipo real do objeto.

Em resumo, nesta lista, aprendemos sobre o polimorfismo de subtipos, que permite tratar objetos de classes derivadas como se fossem objetos da classe base. Isso é alcançado através do uso de ponteiros ou referências da classe base para acessar os membros das classes derivadas. O polimorfismo de subtipos permite escrever código genérico que pode lidar com diferentes tipos de objetos, tornando o código mais flexível e reutilizável.

#### Exemplo 1 (Sem polimorfismo de subtipos):
```cpp
class Character{
    public:
        void    sayHello(std::string const &target);
};

class Warrior : public Character{
    public:
        void    sayHello(std::string const &target);
};

int main(){
    Warrior* a = new Warrior();
    Character* b = new Warrior();
    a->sayHello("students");
    b->sayHello("students");
    return 0;
}

```
...
```bash
F*** off students, I don't like you!
Hello students!
```
B se comporta como um Character e não como um Warrior.
A chamada da função é resolvida em tempo de compilação com base no tipo estático do ponteiro b, ou seja, é chamada a implementação do método na classe Character. Isso ocorre porque o tipo declarado do ponteiro é Character, e o compilador não consideraria a classe derivada Warrior.

Nesse caso, não ocorre o polimorfismo de subtipos, e todas as chamadas para b->sayHello("students") resultam na execução da implementação do método na classe Character, independentemente do tipo real do objeto apontado pelo ponteiro.


#### Exemplo 2 (Com polimorfismo de subtipos):
```cpp
class Character{
    public:
        virtual void    sayHello(std::string const &target);
};

class Warrior : public Character{
    public:
        virtual void    sayHello(std::string const &target);
};

int main(){
    Warrior* a = new Warrior();
    Character* b = new Warrior();
    a->sayHello("students");
    b->sayHello("students");
    return 0;
}

```
...
```bash
F*** off students, I don't like you!
F*** off students, I don't like you!
```
B se comporta como um Warrior e não como um Character.
No código fornecido, a variável b é declarada como um ponteiro para Character e recebe um objeto Warrior por meio do operador new. O polimorfismo de subtipos permite que um ponteiro ou referência à classe base (Character) possa apontar para um objeto de uma classe derivada (Warrior).

Quando chamamos o método sayHello usando o ponteiro b, o compilador usa a tabela de funções virtuais (tabela VTable) para determinar qual implementação do método deve ser chamada. Nesse caso, como b aponta para um objeto Warrior, a implementação do método sayHello na classe Warrior é executada, mesmo que o ponteiro seja declarado como um ponteiro para Character.

Portanto, **a declaração do método como virtual** é fundamental para habilitar o polimorfismo de subtipos e garantir que as chamadas de função sejam resolvidas com base no tipo real do objeto durante a execução. **Isso permite que as classes derivadas substituam e forneçam suas próprias implementações dos métodos virtuais da classe base.**

### 2. Classes Abstratas
As classes abstratas, são classes que não podem ser instanciadas diretamente, mas servem como base para classes derivadas. 
As classes abstratas geralmente contêm métodos virtuais puros, que são métodos sem implementação, assim, as classes derivadas devem implementar esses métodos para se tornarem classes concretas. 
As classes abstratas fornecem uma forma de definir uma interface comum para um grupo de classes relacionadas.

Já que a classe abstrata é uma classe que não pode ser instanciada diretamente, ela serve como uma base para outras classes que a estendem, fornecendo uma estrutura comum e definindo uma interface para as classes derivadas.

**Usamos uma classe abstrata quando desejamos criar uma classe genérica que encapsula características e comportamentos comuns a várias classes relacionadas, mas não faz sentido ter instâncias diretas dessa classe específica.**

Uma classe abstrata pode conter métodos abstratos, que são métodos declarados na classe base, mas não têm implementação. Os métodos abstratos fornecem apenas a assinatura, especificando o nome, os parâmetros e o tipo de retorno, sem fornecer uma implementação real. Esses métodos abstratos são destinados a serem implementados pelas classes derivadas, que são obrigadas a fornecer uma implementação para todos os métodos abstratos da classe base.

Uma classe abstrata também pode ter métodos concretos, ou seja, métodos com implementações completas, que podem ser herdados e usados ​​pelas classes derivadas. Esses métodos concretos podem fornecer comportamentos padrão ou funcionalidades compartilhadas pelas classes derivadas.

Ao herdar de uma classe abstrata, as classes derivadas devem fornecer implementações para todos os métodos abstratos herdados. Essa abordagem permite que as classes derivadas especializem e personalizem o comportamento de acordo com suas necessidades específicas, mantendo a conformidade com a interface definida pela classe abstrata.

### 3. Interfaces
Nesta lista também aprenderemos o conceito de interface em C++.
As interfaces são um tipo especial de classe abstrata que define apenas métodos virtuais puros, que formam um conjunto de métodos que uma classe deve implementar, especificando a funcionalidade que a classe deve fornecer.

Em C++, uma interface é uma classe abstrata que contém apenas métodos puramente virtuais (também conhecidos como métodos abstratos) e não possui implementações concretas de métodos. Ela define um conjunto de métodos que devem ser implementados por qualquer classe que a herde. Sendo assim, a interface é usada para definir um contrato ou um conjunto de obrigações que uma classe derivada deve cumprir. **Ela estabelece uma interface comum para várias classes diferentes, permitindo que objetos de diferentes classes sejam tratados de maneira uniforme por meio de polimorfismo.**

Ao herdar de uma interface, uma classe derivada é obrigada a implementar todos os métodos puramente virtuais definidos na interface. Essa implementação é necessária para que a classe derivada possa ser considerada uma implementação válida da interface. Dessa forma, as interfaces fornecem um mecanismo para alcançar o polimorfismo de subtipos, permitindo que diferentes objetos sejam tratados de forma intercambiável através de um ponteiro ou referência à interface.

As interfaces são úteis para criar contratos claros e definir comportamentos esperados para as classes que a implementam. Elas promovem a interoperabilidade e a reutilização do código, permitindo que diferentes classes compartilhem uma interface comum e sejam usadas de maneira consistente em situações que requerem polimorfismo.
As várias classes derivadas podem fornecer implementações diferentes para os métodos definidos na interface desde que implementem todos os métodos definidos na interface.

Vale ressaltar que C++ não possui um mecanismo de interface explícito, como em algumas outras linguagens de programação. No entanto, é possível simular uma interface criando uma classe abstrata com métodos puramente virtuais.

### 4. Cópia superficial (shallow copy) - complemento de conceitos
Em C++, cópia superficial (shallow copy) e cópia profunda (deep copy) são dois conceitos relacionados à cópia de objetos.

Na cópia superficial, apenas os valores dos membros do objeto são copiados. Se o objeto original contém ponteiros para outros objetos, a cópia superficial copiará apenas os endereços dos ponteiros, resultando em dois objetos que apontam para o mesmo bloco de memória. Isso significa que as alterações feitas em um objeto afetarão o outro, pois eles compartilham os mesmos dados.

```cpp
#include <iostream>

class ShallowCopy {
public:
    int* data;

    ShallowCopy(int value) {
        data = new int(value);
    }

    ShallowCopy(const ShallowCopy& other) {
        data = other.data;  // Cópia superficial
    }

    ~ShallowCopy() {
        delete data;
    }
};

int main() {
    ShallowCopy original(42);
    ShallowCopy copy(original);

    // Ambos os objetos apontam para o mesmo bloco de memória
    std::cout << "Original data: " << *original.data << std::endl;  // Output: 42
    std::cout << "Copy data: " << *copy.data << std::endl;  // Output: 42

    // Modificando o dado através do objeto 'copy'
    *copy.data = 99;

    // Ambos os objetos refletem a modificação
    std::cout << "Original data: " << *original.data << std::endl;  // Output: 99
    std::cout << "Copy data: " << *copy.data << std::endl;  // Output: 99

    return 0;
}
```
No exemplo de cópia superficial, a cópia do objeto simplesmente copia o endereço do ponteiro 'data', resultando em objetos que compartilham o mesmo bloco de memória. Isso significa que as alterações feitas em um objeto afetarão o outro, pois eles compartilham os mesmos dados.

### 5. Cópia profunda (deep copy) - complemento de conceitos
Na cópia profunda, além de copiar os valores dos membros do objeto, os objetos apontados por ponteiros também são copiados. Isso significa que é criada uma nova área de memória para cada objeto, evitando assim que as alterações em um objeto afetem o outro. A cópia profunda é mais segura, pois cada objeto tem seus próprios dados independentes.

```cpp
#include <iostream>

class DeepCopy {
public:
    int* data;

    DeepCopy(int value) {
        data = new int(value);
    }

    DeepCopy(const DeepCopy& other) {
        data = new int(*other.data);  // Cópia profunda
    }

    ~DeepCopy() {
        delete data;
    }
};

int main() {
    DeepCopy original(42);
    DeepCopy copy(original);

    // Ambos os objetos têm suas próprias cópias independentes dos dados
    std::cout << "Original data: " << *original.data << std::endl;  // Output: 42
    std::cout << "Copy data: " << *copy.data << std::endl;  // Output: 42

    // Modificando o dado através do objeto 'copy'
    *copy.data = 99;

    // Os objetos não são afetados pela modificação mútua
    std::cout << "Original data: " << *original.data << std::endl;  // Output: 42
    std::cout << "Copy data: " << *copy.data << std::endl;  // Output: 99

    return 0;
}

```
Já no exemplo de cópia profunda, a cópia do objeto cria uma nova área de memória para armazenar o valor do ponteiro 'data', garantindo que cada objeto tenha seus próprios dados independentes. Isso significa que as alterações feitas em um objeto não afetarão o outro, pois eles têm cópias separadas dos dados.

Assim, a cópia superficial cria objetos que compartilham os mesmos dados, enquanto a cópia profunda cria objetos independentes com cópias separadas dos dados. A escolha entre cópia superficial e cópia profunda depende do contexto e da necessidade de garantir a independência dos objetos.

## Como utilizar
Clone este repositório em sua máquina local.
Navegue até o diretório do exercício desejado.
Compile usando o `make` e execute o código do exercício de sua preferência.

Espero que este Readme.md seja útil para você na organização e compreensão dos exercícios do CPP Módulo 04.
Bom trabalho!