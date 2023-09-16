# Explicit keyword em C++
A palavra-chave `explicit` é usada em declarações de construtores ou cast operators para especificar que a conversão não deve ser realizada implicitamente pelo compilador. Ela impede a conversão automática de um tipo para outro em certos contextos.

Quando um construtor ou cast operator é declarado como `explicit`, a conversão só pode ser realizada explicitamente por meio de uma chamada de função de conversão. Isso significa que o compilador não realizará conversões automáticas de forma implícita.

A principal razão para usar a palavra-chave `explicit` é evitar conversões indesejadas e ambíguas. Ela ajuda a tornar o código mais legível e evita problemas de segurança. Também força o programador a ser explícito sobre suas intenções de conversão.

Um exemplo comum de uso da palavra-chave `explicit` é em construtores de classes que recebem um único parâmetro. Ao marcar esse construtor como `explicit`, evita-se que ocorram conversões implícitas indesejadas ao criar objetos da classe.

Em resumo, o `explicit` é usado para controlar a conversão automática de tipos e garantir que as conversões sejam realizadas somente quando especificamente solicitadas pelo programador.

## Exemplo prático (tirado do vídeo `cpp_bootcamp_-_d06_-_09_explicit_keyword` - Intra42)

observe o código abaixo:

```cpp
#include <iostream>

class A {};
class B {};
class C{

public:
    C(A const & _) {return; }
    explicit C(B const & _) {return; }
};

void    f(C const & c) {return; }

int main(void){

    f(A()); // IMPLÍCITA conversão
    f(B()); // EXPLÍCITA conversão - ❌Conversion is NOT OK - constructor é explícito

    return 0;
}
```
Nesse exemplo, temos as classes `A`, `B` e `C`. A classe `C` possui dois construtores: um que aceita um parâmetro do tipo `A` e outro que aceita um parâmetro do tipo `B`. 

O construtor de `C` que recebe um parâmetro do tipo `B` foi **marcado como `explicit`, o que significa que a conversão implícita de `B` para `C` não será permitida.** Essa marcação indica que a conversão deve ser realizada explicitamente pelo programador, por meio de uma chamada de função de conversão.

No `main`, chamamos a função `f` passando um objeto temporário de `A` como argumento. Essa conversão é permitida, pois não há marcação `explicit` no construtor que recebe `A`. Portanto, ocorre uma conversão implícita de `A` para `C`.

No entanto, quando chamamos a função `f` passando um objeto temporário de `B`, ocorre um erro de compilação. Isso acontece porque a conversão de `B` para `C` é marcada como `explicit`. O compilador não permite essa conversão implícita e indica que a conversão não é permitida.

Em resumo, a marcação `explicit` em um construtor impede a conversão implícita do tipo correspondente para o tipo da classe. Isso garante que as conversões sejam feitas explicitamente pelo programador, tornando o código mais seguro e legível.