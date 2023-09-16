# Adicionar um iterador ao `std::stack`

O `std::stack` na biblioteca padrão do C++ não suporta a iteração direta por meio de iteradores, pois não fornece acesso a todos os elementos do contêiner subjacente (por exemplo, `std::deque`, `std::list`, ou `std::vector`). Em vez disso, o `std::stack` fornece uma interface simplificada que restringe o acesso ao elemento do topo da pilha (o elemento mais recentemente inserido) e às operações de inserção/remoção nesse topo.

Se você precisar iterar sobre todos os elementos do `std::stack`, a abordagem recomendada é usar outro contêiner como apoio, como `std::deque` ou `std::vector`, que suporte a iteração completa por meio de iteradores.

Aqui está um exemplo de como criar um iterador personalizado para percorrer todos os elementos de um `std::stack` usando um contêiner subjacente `std::deque`:

```cpp
#include <iostream>
#include <stack>
#include <deque>

template<typename T>
class StackIterator {
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    StackIterator(typename std::deque<T>::iterator it) : it_(it) {}

    reference operator*() const {
        return *it_;
    }

    pointer operator->() const {
        return &(*it_);
    }

    StackIterator& operator++() {
        ++it_;
        return *this;
    }

    StackIterator operator++(int) {
        StackIterator tmp = *this;
        ++(*this);
        return tmp;
    }

    bool operator==(const StackIterator& other) const {
        return it_ == other.it_;
    }

    bool operator!=(const StackIterator& other) const {
        return !(*this == other);
    }

private:
    typename std::deque<T>::iterator it_;
};

int main() {
    std::stack<int, std::deque<int>> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Criando iteradores personalizados para o início e fim do std::stack
    StackIterator<int> begin(stack._Get_container().begin());
    StackIterator<int> end(stack._Get_container().end());

    // Iterando e imprimindo os elementos do std::stack
    for (StackIterator<int> it = begin; it != end; ++it) {
        std::cout << *it << " ";
    }

    std::cout << std::endl;

    return 0;
}
```

Este exemplo usa a classe `StackIterator` para criar um iterador personalizado que pode ser usado para percorrer todos os elementos do `std::stack` usando o contêiner subjacente `std::deque`. Lembre-se de que o acesso a `_Get_container()` não é uma interface padrão e pode não ser suportado em todas as implementações do compilador C++. Portanto, essa solução pode não ser portável para todas as plataformas e compiladores. É sempre melhor usar um contêiner diferente, como `std::vector` ou `std::deque`, se você precisar de iteração completa.