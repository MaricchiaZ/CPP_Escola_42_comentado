# CPP Module 06 - Cast
Este repositório contém a lista de exercícios do Module 06 do curso de C++ da Escola 42. Nesta lista, exploramos os conceitos de cast em C++.

## Pasta Estudo:
Nesta pasta você encontrará os arquivos .cpp que aparecem nos vídeos da Intra42 e os resumos que são úteis para aprender sobre o conteúdo deste módulo. Os conteúdos estão organizado em pastas na sequência de vídeos da Intra42.
1. from_c_type_convertion
2. from_c_type_reinterpretation
3. from_c_type_qualifier_reinterpretation
4. upcast_and_downcast
5. static_cast
6. dynamic_cast
7. reinterpret_cast
8. const_cast
9. cast_operators
10. explicit_keyword

## Cast em C++
No C++, o cast (ou conversão) é uma operação que permite converter um valor de um tipo para outro tipo. O cast é usado para ajustar ou reinterpretar o tipo de dados de uma variável ou expressão.

Existem vários tipos de cast disponíveis no C++:

- **Cast estático (static_cast):** É usado para realizar conversões entre tipos relacionados de forma segura durante a compilação. Pode ser usado para converter tipos numéricos, ponteiros e referências.
```cpp
int num = 10;
double result = static_cast<double>(num);
```

- **Cast dinâmico (dynamic_cast):** É usado principalmente para realizar conversões entre tipos de classes polimórficas (que têm hierarquia de herança). O cast dinâmico verifica em tempo de execução se a conversão é válida e retorna um ponteiro ou referência nulo se a conversão não for possível.
```cpp
class Base {
public:
    virtual ~Base() {}
};

class Derived : public Base {};

Base* basePtr = new Derived();
Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
if (derivedPtr != nullptr) {
    // A conversão foi bem-sucedida
    // Usar derivedPtr aqui
} else {
    // A conversão falhou
}

```

- **Cast de constante (const_cast):** É usado para adicionar ou remover a constância de um objeto. Permite que uma variável constante seja modificada ou que uma variável não constante seja tratada como constante.
```cpp
const int num = 10;
int* numPtr = const_cast<int*>(&num);
*numPtr = 20; // Modificando uma variável constante (comportamento indefinido)

```

- **Cast de reinterpretção (reinterpret_cast):** É usado para reinterpretar o tipo de dados de um objeto. Ele permite converter um ponteiro ou um valor para outro tipo sem restrições de tipo. É usado quando há necessidade de manipulação de bits ou conversões não seguras entre tipos.
```cpp
int num = 10;
char* charPtr = reinterpret_cast<char*>(&num);

```

- **Cast implícito:** É uma conversão que ocorre automaticamente pelo compilador, sem a necessidade de utilizar uma sintaxe explícita. Isso acontece quando há compatibilidade entre os tipos envolvidos, como uma atribuição entre tipos compatíveis ou uma conversão numérica implícita.
```cpp
int num = 10;
double result = num; // Conversão implícita de int para double

```

É importante utilizar o cast adequado para garantir a segurança e a conversão correta. Cada tipo de cast possui suas regras e restrições específicas, e o uso incorreto pode resultar em comportamento indefinido ou erros de compilação. Portanto, é importante compreender as características e limitações de cada tipo de cast antes de utilizá-los.

## Conhecendo melhor alguns tipos de cast
Vamos nos aprofundar nos tipos de cast que são trabalhados nos vídeos e sao usados nesta lista:
### Castings presentes no C++
Em C++, os castings são operadores que permitem a conversão de um tipo de dado para outro. Eles fornecem uma maneira de realizar conversões explícitas entre tipos incompatíveis, permitindo que o programador controle o processo de conversão.

Existem quatro tipos de conversões em C++:

1. `static_cast`: É usado para realizar conversões seguras entre tipos relacionados. Ele pode ser usado para conversões numéricas, conversões entre tipos de ponteiros e referências relacionados, e para realizar conversões entre tipos base e derivados em hierarquias de classes.

2. `dynamic_cast`: É usado principalmente para conversões entre ponteiros ou referências de classes em hierarquias polimórficas. Ele permite que você verifique em tempo de execução se a conversão é possível e retorna um ponteiro ou referência nulo se a conversão falhar.

3. `reinterpret_cast`: É usado para realizar conversões de ponteiros e referências entre tipos não relacionados. Ele permite que você interprete a sequência de bits de um objeto de um tipo como um objeto de outro tipo, sem fazer qualquer verificação de tipo.

4. `const_cast`: É usado para adicionar ou remover a qualificação const ou volátil de um objeto. Ele permite que você altere a qualificação const ou volátil de um objeto, mas é importante usá-lo com cuidado para evitar comportamento indefinido.

Os `castings` fornecem flexibilidade ao programador para realizar conversões entre tipos de dados quando necessário. No entanto, é importante usá-los com cautela e garantir que as conversões sejam seguras e semânticamente corretas.

### Upcast e Downcast em C++

Em C++, o upcast e o downcast são termos usados para descrever operações de conversão entre classes relacionadas por meio de herança. Vamos ver o significado de cada um:

- **Upcast:** O upcast ocorre quando um ponteiro ou referência de uma classe derivada é atribuído a um ponteiro ou referência de uma classe base correspondente. É uma conversão segura, pois a classe derivada herda todas as características da classe base. Com o upcast, você está "subindo" na hierarquia de herança.

Exemplo:

```cpp
class Animal { ... };
class Dog : public Animal { ... };

Dog dog;
Animal* animalPtr = &dog; // Upcast: ponteiro da classe derivada para a classe base

```

- **Downcast:** O downcast ocorre quando um ponteiro ou referência de uma classe base é atribuído a um ponteiro ou referência de uma classe derivada correspondente. É uma conversão menos segura, pois a classe base não possui as características específicas da classe derivada. Com o downcast, você está "descendo" na hierarquia de herança. Para realizar um downcast de forma segura, é necessário usar o operador dynamic_cast ou static_cast, que permitem verificar se a conversão é válida em tempo de execução.

Exemplo:

```cpp
class Animal { ... };
class Dog : public Animal { ... };

Animal* animalPtr = new Dog();
Dog* dogPtr = dynamic_cast<Dog*>(animalPtr); // Downcast: ponteiro da classe base para a classe derivada
if (dogPtr != nullptr) {
    // A conversão foi bem-sucedida
} else {
    // A conversão falhou
}

```

É importante usar o downcast com cuidado e apenas quando você tem certeza de que o objeto subjacente é uma instância da classe derivada. Caso contrário, pode ocorrer comportamento indefinido ou erros em tempo de execução.

### Static_cast em C++

O `static_cast` é um operador de conversão usado em C++ para realizar conversões seguras entre tipos relacionados. Ele é usado para converter explicitamente um tipo em outro, desde que exista uma relação definida entre os tipos. O `static_cast` pode ser usado para:

- **Conversões numéricas:** É possível usar o static_cast para converter tipos numéricos relacionados, como inteiros para floats ou vice-versa. Ele realiza conversões simples entre tipos numéricos compatíveis.

```cpp
int main() {
    int intValue = 42;
    double doubleValue = static_cast<double>(intValue);
    return 0;
}
```

- **Conversões de ponteiros:** O static_cast pode ser usado para converter ponteiros entre tipos relacionados por herança. Ele permite conversões de ponteiros da classe base para ponteiros de classes derivadas e vice-versa, desde que a conversão seja estática e segura.
```cpp
class Parent {};
class Child : public Parent {};

int main() {
    Parent* parentPtr = new Parent();
    Child* childPtr = static_cast<Child*>(parentPtr);
    return 0;
}
```

- **Conversões de referências:** O static_cast pode ser usado para converter referências entre tipos relacionados. Ele permite converter referências de uma classe base para referências de classes derivadas e vice-versa, desde que a conversão seja estática e segura.

```cpp
class Parent {
public:
    virtual void speak() {
        std::cout << "I am the parent." << std::endl;
    }
};

class Child : public Parent {
public:
    void speak() override {
        std::cout << "I am the child." << std::endl;
    }
};

int main() {
    Child child;
    Parent& parentRef = child;  // Conversão implícita de Child& para Parent&
    
    // Usando static_cast para converter de volta para Child&
    Child& childRef = static_cast<Child&>(parentRef);
    
    childRef.speak();  // Resultado: "I am the child."
    
    return 0;
}

```

**É importante mencionar que o static_cast não executa verificações em tempo de execução para garantir a validade da conversão. Portanto, é responsabilidade do programador garantir que a conversão seja segura e que não ocorra perda de informações.** Se houver dúvidas sobre a validade da conversão, é recomendável usar operadores de casting mais seguros, como dynamic_cast ou reinterpret_cast.

### Dynamic cast em C++  - *É o mais especial 🌟*

O `dynamic_cast` é um operador em C++ usado **para realizar conversões de tipo em tempo de execução entre ponteiros ou referências de classes relacionadas por herança.** 
Ele é usado principalmente para converter ponteiros ou referências de uma classe base para ponteiros ou referências de uma classe derivada.

O `dynamic_cast` realiza a verificação em tempo de execução para garantir que a conversão seja segura. Ele retorna um ponteiro ou referência nulo se a conversão não for possível. **Isso é especialmente útil quando você não tem certeza do tipo real do objeto apontado e deseja garantir que a conversão seja bem-sucedida antes de acessar membros específicos da classe derivada.**

Veja um exemplo de uso do dynamic_cast:

```cpp
class Animal {
public:
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void bark() {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void meow() {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    Animal* animal = new Dog();

    Dog* dog = dynamic_cast<Dog*>(animal);
    if (dog != nullptr) {
        dog->bark();
    }

    Cat* cat = dynamic_cast<Cat*>(animal);
    if (cat != nullptr) {
        cat->meow();
    } else {
        std::cout << "Not a cat!" << std::endl;
    }

    delete animal;

    return 0;
}
```

Neste exemplo, usamos o `dynamic_cast` para converter um ponteiro de `Animal` para um ponteiro de `Dog.` Se a conversão for bem-sucedida, podemos chamar a função `bark()` da classe `Dog`. Em seguida, tentamos converter o mesmo ponteiro para um ponteiro de `Cat`, mas como o objeto apontado é um `Dog`, a conversão falhará e `cat` será um ponteiro nulo. Isso nos permite realizar a verificação em tempo de execução e evitar comportamentos inesperados ao trabalhar com hierarquias de classes complexas.

### Reinterpret cast em C++

O `reinterpret_cast` é um operador em C++ usado para realizar conversões de ponteiros ou referências entre tipos que não estão relacionados por herança. Ele é usado principalmente para converter ponteiros ou referências de um tipo para outro tipo, mesmo que os tipos não estejam relacionados entre si, permitindo reinterpretar o valor de um ponteiro ou referência como se fosse de um tipo diferente, sem realizar conversões de tipo explícitas.

O `reinterpret_cast` é uma **operação de baixo nível e possui riscos e limitações**. Ele não faz nenhuma verificação de segurança durante a conversão e *assume que o programador está ciente das implicações e possíveis consequências.*

Alguns exemplos de uso do reinterpret_cast incluem:

- Conversão de ponteiros entre tipos numéricos e ponteiros de objeto.
- Conversão de ponteiros de objeto para ponteiros de função e vice-versa.
- Conversão de um ponteiro para void* e de volta para o tipo original.

No entanto, é importante usar o reinterpret_cast com cuidado, pois ele pode levar a resultados indefinidos se usado de forma inadequada ou se a conversão não fizer sentido em termos de representação de memória dos tipos envolvidos. É recomendado o uso do reinterpret_cast apenas em situações específicas e quando absolutamente necessário.

### Const cast em C++

`const_cast` é um operador em C++ usado para remover ou adicionar a qualificação `const` a um tipo de dado. Ele permite que você faça modificações em uma variável ou objeto que foi declarado como `const`.

A sintaxe do `const_cast` é a seguinte:
```cpp
const_cast<type>(expression)
```

Onde `type` é o tipo de dado desejado e `expression` é a expressão a ser convertida.

O `const_cast` é comumente usado em situações em que você precisa trabalhar com um objeto `const` de alguma forma, como quando precisa modificar um membro de um objeto `const`. No entanto, é importante ter cuidado ao usar `const_cast`, pois ele permite modificações em objetos `const`, o que pode levar a comportamentos indefinidos se você fizer alterações incorretas.

Veja um exemplo simples de uso do `const_cast`:

```cpp
const int value = 42;

int* ptr = const_cast<int*>(&value);
*ptr = 99;

std::cout << value << std::endl;  // Imprime 99
```

Nesse exemplo, o `const_cast` é usado para remover a qualificação `const` de `value` e obter um ponteiro para `int`. Em seguida, o valor apontado pelo ponteiro é alterado para 99. Isso só é possível porque o `const_cast` permite que você remova temporariamente a `const`-ness de `value` e faça a modificação. No entanto, é importante lembrar que a modificação de um objeto `const` é uma prática arriscada e deve ser usada com cautela.

### Cast operators em C++
Em C++, os cast operators são funções especiais definidas dentro de uma classe que permitem a conversão de um objeto dessa classe para outro tipo de dado. Eles fornecem uma maneira personalizada de realizar conversões entre tipos diferentes.

Os cast operators são declarados com a palavra-chave `operator`, seguida pelo tipo de dado para o qual a conversão será realizada. Por exemplo, `operator float()` indica um cast operator que converte um objeto para o tipo `float`.

Os cast operators podem ser usados para realizar conversões implícitas de objetos da classe para o tipo desejado, sem a necessidade de uma chamada explícita de função de conversão. Eles são invocados automaticamente quando ocorre uma conversão envolvendo um objeto da classe em um contexto apropriado.

Os cast operators podem ser úteis quando você deseja permitir que objetos de sua classe sejam convertidos facilmente para outros tipos de dados sem a necessidade de chamar explicitamente uma função de conversão.

No entanto, é importante usar os cast operators com cuidado, garantindo que as conversões sejam seguras e que não resultem em comportamento indefinido ou perda de informações importantes.

# Explicit keyword em C++
A palavra-chave `explicit` é usada em declarações de construtores ou cast operators para especificar que a conversão não deve ser realizada implicitamente pelo compilador. Ela impede a conversão automática de um tipo para outro em certos contextos.

Quando um construtor ou cast operator é declarado como `explicit`, a conversão só pode ser realizada explicitamente por meio de uma chamada de função de conversão. Isso significa que o compilador não realizará conversões automáticas de forma implícita.

A principal razão para usar a palavra-chave `explicit` é evitar conversões indesejadas e ambíguas. Ela ajuda a tornar o código mais legível e evita problemas de segurança. Também força o programador a ser explícito sobre suas intenções de conversão.

Um exemplo comum de uso da palavra-chave `explicit` é em construtores de classes que recebem um único parâmetro. Ao marcar esse construtor como `explicit`, evita-se que ocorram conversões implícitas indesejadas ao criar objetos da classe.

Em resumo, o `explicit` é usado para controlar a conversão automática de tipos e garantir que as conversões sejam realizadas somente quando especificamente solicitadas pelo programador.

## Como utilizar
Clone este repositório em sua máquina local.
Navegue até o diretório do exercício desejado.
Compile usando o `make` e execute o código do exercício de sua preferência.

Espero que este Readme.md seja útil para você na organização e compreensão dos exercícios do *CPP Módulo 06*.
Bom trabalho!