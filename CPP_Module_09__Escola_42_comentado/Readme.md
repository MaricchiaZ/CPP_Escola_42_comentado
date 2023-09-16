# Lista de Exercícios CPP-09 - Contêineres Padrão da STL

Nesta lista de exercícios, exploraremos os diferentes tipos de contêineres padrão fornecidos pela STL (Standard Template Library) em C++. Os contêineres da STL são estruturas de dados que permitem armazenar e organizar coleções de elementos de forma eficiente. Cada contêiner possui características específicas e é projetado para atender a diferentes necessidades de armazenamento e manipulação de dados.

## Dicas importantes

- **A maior dificuldade dessa lista é não poder repetir o tipo de conteiner de um exercício para o outro**. Por exemplo, se você utilizar um vector no exercício 1, não poderá utilizar um vector no exercício 2. Isso é proposital para que você possa explorar os diferentes tipos de contêineres padrão da STL.
- Leia atentamente as descrições dos exercícios e certifique-se de entender claramente o que cada exercício faz antes de começar a codificar.
- Estude os contêineres padrão da STL e encontre o mais apropriado para cada caso. Isso ajudará a resolver os problemas de forma mais eficiente e segura.
- Esquematize que exercício vai usar qual tipo de conteiner. Isso vai te ajudar a não se perder e a não repetir o tipo de conteiner.

## Como utilizar esta lista

Cada exercício desta lista pode ser feito de diversas maneiras, e cada um deve ser usar algum contêiner padrão da STL, como vector, list, deque, map, set, entre outros. Aqui está a forma como eu fiz, e não é a única maneira de fazer, e nem necessariamente a melhor. Mas é uma forma que funciona :)

## Conteúdos abordados

1. Exercício 00 - Banco de dados CSV, std::map
2. Exercício 01 - std::stack
3. Exercício 02 - std::list e std::vector

### Banco de dados csv

Um banco de dados no formato CSV (Comma-Separated Values) é uma forma simples de armazenar dados tabulares em um arquivo de texto. Nesse formato, cada linha representa uma entrada de dados e os campos (valores) são separados por vírgulas. Geralmente, a primeira linha do arquivo CSV contém os nomes das colunas.

Por exemplo, um banco de dados de clientes em formato CSV pode ser assim:

```
Nome,Idade,Cidade
Alice,30,São Paulo
Bob,25,Rio de Janeiro
Carol,35,Belo Horizonte
```

Cada linha representa um cliente, e os campos (Nome, Idade, Cidade) são separados por vírgulas.

O formato CSV é amplamente utilizado para importação e exportação de dados entre diferentes sistemas, pois é simples, leve e facilmente legível tanto por humanos quanto por máquinas. No entanto, como não há padrões formais de CSV, diferentes aplicativos podem interpretar aspas, espaços, e outros caracteres de forma diferente, o que pode levar a problemas de compatibilidade em alguns casos.

### std::map
O `std::map` é um contêiner associativo da biblioteca padrão do C++ (STL) que armazena elementos em pares de chave-valor, onde cada chave é única. A implementação interna do `std::map` é geralmente baseada em uma árvore binária balanceada chamada árvore vermelha-preta, o que garante que as operações de inserção, busca e remoção sejam eficientes com uma complexidade média de O(log n), onde "n" é o número de elementos no mapa.

Principais características do `std::map`:

1. Ordenação: Os elementos do `std::map` são sempre mantidos em ordem ascendente com base nas chaves. Isso permite uma busca eficiente usando a chave.

2. Chaves únicas: Cada chave em um `std::map` é única, o que significa que não pode haver chaves duplicadas no mapa.

3. Pares de chave-valor: Cada elemento no `std::map` é um par de chave-valor, onde a chave é usada para identificar o valor associado a ela.

4. Busca rápida: A busca de um elemento pelo seu valor é altamente eficiente em um `std::map`, graças à estrutura de árvore balanceada.

5. Inserção e remoção eficientes: A inserção e remoção de elementos em um `std::map` também são operações eficientes, devido à estrutura de árvore balanceada.

6. Interface de acesso: O acesso aos elementos do `std::map` pode ser feito usando a notação de colchetes `[]`, onde a chave é passada como índice.

Exemplo de uso do `std::map`:

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;

    // Inserindo elementos no mapa
    myMap[1] = "apple";
    myMap[2] = "banana";
    myMap[3] = "orange";

    // Acessando elementos pelo índice (chave)
    std::cout << myMap[1] << std::endl; // Output: "apple"

    // Verificando se uma chave existe no mapa
    if (myMap.find(2) != myMap.end()) {
        std::cout << "Key 2 exists in the map." << std::endl;
    }

    // Iterando pelos elementos do mapa
    for (const auto& pair : myMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    return 0;
}
```

Este exemplo demonstra algumas operações comuns do `std::map`, como inserir elementos, acessar elementos por suas chaves, verificar se uma chave existe e iterar pelos elementos do mapa. Note que os elementos são automaticamente ordenados pelas chaves (números inteiros neste caso).

É possível usar o std::map para armazenar esses dados e permitir o acesso à cotação do Bitcoin em relação à data. Nesse caso, a chave do std::map seria a data e o valor associado seria o preço do Bitcoin naquela data.

Você pode definir o std::map da seguinte maneira:
```cpp
#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, double> bitcoinPrices;

    // Inserindo os dados no mapa
    bitcoinPrices["2010-08-14"] = 0.0;
    bitcoinPrices["2010-08-17"] = 0.0;
    bitcoinPrices["2010-08-20"] = 0.07;
    bitcoinPrices["2010-08-23"] = 0.07;
    bitcoinPrices["2010-08-26"] = 0.07;
    bitcoinPrices["2010-08-29"] = 0.06;
    bitcoinPrices["2010-09-01"] = 0.06;
    bitcoinPrices["2010-09-04"] = 0.06;

    // Acessando a cotação do Bitcoin em uma determinada data
    std::string date = "2010-08-20";
    if (bitcoinPrices.find(date) != bitcoinPrices.end()) {
        double price = bitcoinPrices[date];
        std::cout << "Cotação do Bitcoin em " << date << ": " << price << std::endl;
    } else {
        std::cout << "Data não encontrada." << std::endl;
    }

    return 0;
}

```
Neste exemplo, cada linha dos dados é inserida no std::map, onde a chave é a data e o valor é o preço do Bitcoin naquela data. Para acessar a cotação do Bitcoin em uma data específica, você pode usar a função find() do std::map para verificar se a data está presente no mapa e, se estiver, acessar o preço correspondente. Caso a data não seja encontrada, uma mensagem adequada é exibida.

### Notação Polonesa Reversa (RPN)
A notação polonesa reversa, também conhecida como notação pós-fixa ou RPN (Reverse Polish Notation), é uma forma de escrever expressões matemáticas em que os operadores são escritos após os operandos. Nessa notação, não são necessários parênteses para determinar a ordem de execução das operações, pois ela segue uma regra bem definida para calcular o resultado.

Em vez de escrever a expressão como "2 + 3", na notação polonesa reversa, escrevemos "2 3 +". A ordem de execução é a seguinte:

1. Os dois primeiros números são os operandos.
2. O operador "+", que está após os operandos, é aplicado aos dois números, resultando em "5".

Essa notação foi proposta pelo matemático polonês Jan Łukasiewicz na década de 1920 e é comumente utilizada em calculadoras e linguagens de programação, especialmente em algumas linguagens funcionais ou de pilha, como Forth.

A principal vantagem da notação polonesa reversa é que ela elimina a necessidade de usar parênteses para indicar a ordem de execução das operações, tornando a expressão mais clara e menos ambígua. Além disso, o cálculo das expressões em RPN pode ser facilmente realizado usando uma pilha, o que torna a avaliação de expressões mais eficiente em alguns casos. No entanto, a notação polonesa reversa pode parecer menos intuitiva para algumas pessoas acostumadas com a notação tradicional de operadores entre os operandos.

### std::stack
Podemos implementar um programa que calcule a notação polonesa reversa (RPN) usando uma pilha (stack) da STL (Standard Template Library) do C++. A pilha é uma estrutura de dados que segue o princípio "último a entrar, primeiro a sair" (LIFO - Last In, First Out), o que é perfeito para resolver expressões RPN. Pode-se usar o std::deque (que funciona como uma lista duplamemte linkada) e é a mesma coisa.

Aqui está um exemplo de como fazer isso:

```cpp
#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cctype>

int calculateRPN(const std::string& expression) {
    std::stack<int> stack;

    std::istringstream iss(expression);
    std::string token;
    while (iss >> token) {
        if (isdigit(token[0])) {
            stack.push(std::stoi(token));
        } else {
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();

            switch (token[0]) {
                case '+':
                    stack.push(a + b);
                    break;
                case '-':
                    stack.push(a - b);
                    break;
                case '*':
                    stack.push(a * b);
                    break;
                case '/':
                    stack.push(a / b);
                    break;
                default:
                    std::cerr << "Invalid operator: " << token[0] << std::endl;
                    return -1;
            }
        }
    }

    return stack.top();
}

int main() {
    std::string rpn_expression = "5 10 + 3 *";
    int result = calculateRPN(rpn_expression);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
```

Neste exemplo, a função `calculateRPN` recebe uma expressão RPN como uma string e retorna o resultado da expressão. A função percorre cada token na string e, se for um número, coloca na pilha. Se for um operador, retira dois números da pilha, executa a operação e coloca o resultado de volta na pilha.

No exemplo do programa principal, a expressão RPN "5 10 + 3 *" é calculada, o que corresponde a (5 + 10) * 3. O resultado impresso será "45".

Note que este é um exemplo simples para fins de ilustração. Para aplicativos mais complexos, você pode precisar adicionar mais validações de erros e manipulação de casos especiais.

#### Exemplo de uso de pilha num caso de Notação Polonesa Reversa

No uso de notação polonesa reversa (RPN) a pilha é uma abordagem eficiente para lidar com expressões matemáticas complexas. Na RPN, os números e operadores são dispostos de forma que não seja necessário usar parênteses ou regras de precedência para determinar a ordem de execução. A estrutura de pilha é utilizada para armazenar temporariamente os valores intermediários durante a avaliação da expressão.

Quando você encontra um operador, como o "*" ou "-", em uma expressão RPN, você retira os dois últimos valores da pilha, aplica o operador a eles e coloca o resultado de volta na pilha. Isso garante que a ordem correta de execução seja mantida.

```t
De exemplo faremos essa conta: "  8 9 * 9 - 9 - 9 - 4 - 1 + 5*  "

Nesse exemplo, cada número e operador são colocados na pilha seguindo a sequência da expressão RPN. Vamos seguir passo a passo:

1. Coloca 8 na pilha.
   Pilha: 8
2. Coloca 9 na pilha.
   Pilha: 8 9
3. Encontra o operador "*", retira os dois últimos valores (8 e 9) e coloca o resultado (72) de volta na pilha.
   Pilha: 72
4. Coloca 9 na pilha.
   Pilha: 72 9
5. Encontra o operador "-", retira os dois últimos valores (72 e 9) e coloca o resultado (63) de volta na pilha.
   Pilha: 63
6. Coloca 9 na pilha.
   Pilha: 63 9
7. Encontra o operador "-", retira os dois últimos valores (63 e 9) e coloca o resultado (54) de volta na pilha.
   Pilha: 54
8. Coloca 9 na pilha.
   Pilha: 54 9
9. Encontra o operador "-", retira os dois últimos valores (54 e 9) e coloca o resultado (45) de volta na pilha.
   Pilha: 45
10. Coloca 4 na pilha.
    Pilha: 45 4
11. Encontra o operador "-", retira os dois últimos valores (45 e 4) e coloca o resultado (41) de volta na pilha.
    Pilha: 41
12. Coloca 1 na pilha.
    Pilha: 41 1
13. Encontra o operador "+", retira os dois últimos valores (41 e 1) e coloca o resultado (42) de volta na pilha.
    Pilha: 42
14. Coloca 5 na pilha.
    Pilha: 42 5
15. Encontra o operador "*", retira os dois últimos valores (42 e 5) e coloca o resultado (210) de volta na pilha.
    Pilha: 210

No final, temos o resultado da expressão "8 9 * 9 - 9 - 9 - 4 - 1 + 5*" na pilha, que é 210. A ordem correta de execução foi mantida usando a estrutura de pilha.

```
Em resumo, a pilha é uma abordagem eficiente e segura para avaliar expressões na notação polonesa reversa, mesmo quando a expressão é grande e complexa. Isso torna a RPN uma notação muito útil para realizar cálculos matemáticos sem precisar lidar com a complexidade das regras de precedência e parênteses.

### O Algoritmo merge-insertion sort de Ford-Johnson
O algoritmo merge-insertion sort de Ford-Johnson é uma abordagem híbrida que combina os conceitos do merge sort (ordenação por mistura) e do insertion sort (ordenação por inserção) para obter um desempenho eficiente em diferentes cenários.

Existem inúmeros algoritmos de ordenação, sendo quase sempre criados pensando em sua eficiência e no menor tempo. O algoritmo merge-insertion-sort de Ford-Johnson foi pensado para ordenar usando o número de comparações possíveis, ele surgiu em 1959, desenvolvido por Lester Ford e Selmer Johnson. Esse algoritmo, que originalmente chamava “Um problema de torneio.” tem pouco uso prático, pois requer estruturas de dados complexas e é mais lento do que outras classificações mais comuns e mais simples de implementar.

Aqui está uma descrição mais detalhada de como o algoritmo funciona:

**Divisão**: O primeiro passo é dividir a lista de elementos em pares consecutivos (ou em grupos de tamanho 2), e comparar os elementos de cada par para determinar o maior ou o menor, dependendo da ordem desejada.

**Torneio:** Os elementos vencedores de cada par são então reunidos para formar uma nova lista, que é uma "rodada" do torneio. Essa nova lista é novamente dividida em pares, e os elementos vencedores são determinados novamente.

**Repetição:** O processo de torneio é repetido até que haja apenas um elemento vencedor, que é o elemento máximo ou mínimo da lista, dependendo da ordem de classificação.

**Inserção:** Depois de encontrar o vencedor, esse elemento é inserido na posição correta na lista final usando uma abordagem semelhante à inserção direta, empurrando os elementos maiores (ou menores) para a direita para abrir espaço.

**Combinação:** O processo de torneio e inserção é repetido até que todos os elementos tenham sido inseridos na lista final na ordem desejada.

O algoritmo de Ford-Johnson tem uma complexidade de tempo médio de O(n log n), onde "n" é o número de elementos a serem ordenados. No entanto, ele pode ser mais eficiente em comparação com outros algoritmos de ordenação, especialmente quando a lista já está parcialmente ordenada.

Vale ressaltar que o nome "Merge Insertion" vem do fato de que o algoritmo combina a abordagem de dividir e conquistar do merge sort com a inserção direta do insertion sort. Isso permite que ele aproveite as vantagens de ambos os métodos para otimizar a ordenação usando o menor número de comparações.

### Ordenando muitos números (3 mil) com o uso de conteiners e o algoritmo merge-insertion sort de Ford-Johnson 
Para implementar o algoritmo merge-insertion sort de Ford-Johnson, você pode optar por usar os seguintes containers da STL do C++:

1. **std::vector**: O std::vector é uma boa escolha para armazenar os 3000 números a serem ordenados. Ele oferece acesso rápido aos elementos por meio de índices e permite a adição de novos elementos no final do vetor com facilidade. Como o algoritmo Ford-Johnson envolve muitas operações de acesso e manipulação de elementos, o std::vector é uma opção eficiente para isso.

2. **std::list**: A std::list é outra opção que pode ser usada para implementar o merge-insertion sort de Ford-Johnson. A lista é uma estrutura de dados duplamente encadeada, o que significa que ela permite inserção e remoção eficientes de elementos em qualquer posição da lista. No entanto, o acesso aos elementos por meio de índices não é tão rápido quanto no std::vector, o que pode impactar o desempenho do algoritmo em listas grandes.

3. **std::deque**: O std::deque é uma alternativa ao std::list que também oferece inserção e remoção eficientes de elementos em qualquer posição, mas também suporta acesso rápido aos elementos por meio de índices, assim como o std::vector. Portanto, o std::deque pode ser uma escolha adequada para implementar o algoritmo Ford-Johnson.

Qual escolher depende da natureza dos dados e dos requisitos específicos do seu problema. **Se você precisa apenas ordenar os elementos e não precisa de inserções e remoções frequentes, o std::vector pode ser a melhor escolha devido ao seu acesso rápido aos elementos**. Se a inserção e remoção de elementos forem necessárias durante o processo de ordenação, o std::list ou o std::deque podem ser mais adequados devido à sua eficiência nessas operações.

É importante notar que o desempenho exato pode variar dependendo das implementações específicas da STL e das características do hardware em que o código está sendo executado. É sempre recomendável fazer testes de desempenho em cenários reais para determinar quais as duas melhores opções para o seu caso específico.


## Como utilizar
Clone este repositório em sua máquina local.
Navegue até o diretório do exercício desejado.
Compile usando o `make` e execute o código do exercício de sua preferência.

Divirta-se programando e explorando os contêineres, em C++!

Boa sorte nos exercícios!

## Referências

Ford, Lester R. e Selmer M. Johnson. “Um problema de torneio.” The American Mathematical Monthly, vol. 66, nº. 5, 1959, pp. 387–389. JSTOR, www.jstor.org/stable/2308750 

Knuth, Donald E. A arte da programação de computadores: Volume 3: Classificando e pesquisando. Profissional Addison-Wesley; 2 edição (4 de maio de 1998). (pág 184)
