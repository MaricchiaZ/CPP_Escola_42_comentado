# Lista CPP Module 07 - Template

Esta é a lista de exercícios CPP Module 07 da escola 42, com o tema template.

## Pasta Estudo:
Nesta pasta você encontrará os arquivos .cpp que aparecem nos vídeos da Intra42 e os resumos que são úteis para aprender sobre o conteúdo deste módulo. Os conteúdos estão organizado em pastas na sequência de vídeos da Intra42.
1. templates
2. default_type
3. specialization 

## Resumo sobre Templates em C++

Os templates em C++ são uma poderosa ferramenta que permitem a criação de código genérico. Um template é uma maneira de parametrizar um tipo ou uma função, permitindo que eles sejam usados com tipos diferentes sem precisar reescrever o código para cada tipo.

### Funções Template

Uma função template é uma função que pode operar em diferentes tipos de dados. Em vez de especificar um tipo de dados específico, você pode usar um parâmetro de tipo genérico (geralmente denotado por `T`) e escrever o código da função de forma genérica. A função será então instanciada pelo compilador para cada tipo de dados em que for usada.

Exemplo de uma função template que retorna o maior valor entre dois valores:

```cpp
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
```

### Classes Template

Assim como as funções, as classes também podem ser templates. Você pode criar uma classe genérica que pode ser usada com diferentes tipos de dados. O parâmetro de tipo pode ser usado em membros da classe, como variáveis de membro, métodos e até mesmo como tipos de retorno de métodos.

Exemplo de uma classe template para uma pilha genérica:

```cpp
template <typename T>
class Stack {
private:
    T* elements;
    int size;
public:
    // Construtor e métodos da pilha...
    void push(T element);
    T pop();
};
```

### Uso de Templates

Para usar uma função ou classe template, você deve fornecer o tipo de dados específico que será usado como argumento para o parâmetro de tipo. Isso é feito entre chaves angulares (`<>`) após o nome da função ou classe template.

Exemplo de uso da função `max` e da classe `Stack`:

```cpp
int main() {
    int a = 10, b = 20;
    int maxInt = max<int>(a, b);

    Stack<double> doubleStack;
    doubleStack.push(3.14);
    doubleStack.push(2.718);
    double poppedElement = doubleStack.pop();

    // Restante do código...
}
```

Neste exemplo, especificamos `int` como o tipo de dado para a função `max`, e `double` como o tipo de dado para a classe `Stack`.

## Como Executar os Exercícios

Cada exercício nesta lista possui um diretório separado com os arquivos de código-fonte necessários. Para executar os exercícios, siga as instruções abaixo:

1. Clone este repositório ou faça o download dos arquivos em seu computador.
2. Navegue até o diretório do exercício desejado.
3. Compile os arquivos de código-fonte utilizando o compilador C++ de sua preferência.
4. Execute o programa gerado.
