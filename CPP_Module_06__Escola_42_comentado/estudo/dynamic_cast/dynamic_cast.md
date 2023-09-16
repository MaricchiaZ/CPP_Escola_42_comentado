# Dynamic cast em C++

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

## Dynamic cast em referências e ponteiros
Ele pode ser usado tanto em referências quanto em ponteiros.

No exemplo do vídeo (vide `main.cpp`) foi utilizado tanto para converter um ponteiro (`Parent*`) para um ponteiro (`Child1*`) quanto para converter uma referência (`Parent&`) para uma referência (`Child2&`).

A diferença está na maneira como o `dynamic_cast` lida com as conversões em cada caso. 
- Quando usado com **ponteiros**, se a conversão não for possível, o resultado será um ponteiro nulo (`NULL` ou `nullptr`). 

- Já quando usado com **referências**, se a conversão não for possível, será lançada uma exceção do tipo `std::bad_cast`.

Portanto, o `dynamic_cast` pode ser usado tanto em referências quanto em ponteiros para realizar conversões seguras entre tipos relacionados por herança.

```bash
~/CPP_Module_06__Escola_42/estudo/dynamic_cast ❯ ./a.out
✔️ Conversion is OK
❌Conversion is NOT OK
```
EXPLICAÇÃO:
A conversão não ocorre na linha `Child2 &d = dynamic_cast<Child2&>(*b);` porque o objeto apontado por `b` é do tipo `Child1` e não do tipo `Child2`.

O `dynamic_cast` é usado para fazer conversões seguras entre tipos relacionados por herança. No caso dessa linha, o objetivo é converter um ponteiro `Parent*` para uma referência `Child2&`, o que só seria válido se o objeto real apontado por `b` fosse do tipo `Child2` (ou uma classe derivada de `Child2`). No entanto, o objeto real apontado por `b` é do tipo `Child1`, sendo assim não é possível realizar uma conversão direta para `Child2`. 
