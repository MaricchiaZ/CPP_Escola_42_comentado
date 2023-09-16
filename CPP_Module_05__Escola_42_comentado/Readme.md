# CPP Module 05 - Exceção
Este repositório contém a lista de exercícios do Module 05 do curso de C++ da Escola 42. Nesta lista, exploramos os conceitos de repetição e exceção em C++.

## Resumo dos Conteúdos
Nesta lista, você encontrará exercícios que abordam os seguintes tópicos:

### 1. Exceções em C++
Quando ocorre um erro, o C++ normalmente pára e gera uma mensagem de erro. O termo técnico para isto é: **O C++ lançará uma exceção (lançará um erro)**.

Em C++, exceções são mecanismos utilizados para lidar com erros e situações excepcionais que podem ocorrer durante a execução de um programa. Uma exceção é um objeto especial que é lançado (ou "jogado") quando ocorre uma condição anormal ou erro.

**Quando uma exceção é lançada, o fluxo normal de execução do programa é interrompido e o controle é transferido para um bloco catch correspondente que pode lidar com essa exceção**. O bloco catch é responsável por tratar a exceção e fornecer um comportamento apropriado para lidar com o erro.

As exceções em C++ são tipicamente objetos que pertencem a uma hierarquia de classes. A classe base para exceções é std::exception, que fornece métodos como what() para obter informações sobre a exceção. Além disso, é possível criar classes de exceção personalizadas que derivam de std::exception ou de suas classes derivadas.

O uso de exceções permite lidar com erros de forma mais estruturada, facilitando a separação do código de tratamento de erros do código principal de execução. Isso torna o código mais legível, modular e robusto, permitindo que os erros sejam tratados de maneira adequada sem interromper a execução normal do programa.

A biblioteca C++ Standard fornece uma classe de base especificamente concebida para declarar objectos a lançar como excepções. Chama-se `std::exception` e é definida no cabeçalho `#include <exception>`. Esta classe tem uma função de membro virtual denominada `what()` que devolve uma sequência de caracteres terminada em byte nulo (do tipo char *) e que pode ser substituída em classes derivadas por uma descrição da exceção.

Todas as classes de exceção padrão derivam, em última análise, da classe exception, como por exemplo, as `logic_error` e `runtime_error`
A classe `logic_error` representa erros na lógica de programação, como a passagem de um argumento inválido. Os erros em`runtime_error` são aqueles que ocorrem como resultado de forças imprevistas, como falha de hardware ou esgotamento de memória.

### 2. Blocos try/catch
Os blocos try-catch são uma construção em C++ que permite lidar com exceções lançadas durante a execução de um trecho de código.

Um **bloco try é usado para envolver o código que pode apresentar uma exceção**. Dentro do bloco try, você coloca o código que pode gerar uma exceção. Se uma exceção aparecer dentro do bloco try, a execução do código dentro desse bloco é interrompida e o programa procura por um bloco catch correspondente para lidar com a exceção.

Um **bloco catch é usado para capturar e tratar exceções específicas**. Você pode ter vários blocos catch após um bloco try, cada um tratando as exceções de tipos diferentes. **Cada bloco catch especifica o tipo de exceção que pode lidar e o bloco de código a ser executado para tratar essa exceção.**

Se uma exceção é lançada e corresponde ao tipo de exceção especificado em um bloco catch, o código dentro desse bloco é executado. Após a execução do bloco catch, o programa continua a execução normalmente. Assim, os blocos try-catch permitem capturar e tratar exceções de forma controlada, fornecendo uma maneira de lidar com erros e exceções durante a execução do programa, **evitando que o programa pare abruptamente, evitando segmentation fault**.

Um exemplo simples de como usar blocos try-catch em C++:
```cpp
#include <iostream>

int main() {
    try {
        int numerator = 10;
        int denominator = 0;
        int result = numerator / denominator; // Esta operação gera uma exceção de divisão por zero
        std::cout << "Resultado: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Ocorreu uma exceção: " << e.what() << std::endl;
    }

    std::cout << "Continuando a execução..." << std::endl;

    return 0;
}

```
Neste exemplo, temos um bloco try que envolve a operação de divisão numerator / denominator. Como o denominador é zero, isso gera uma exceção de divisão por zero. No bloco catch, capturamos a exceção do tipo std::exception (que é a classe base para exceções padrão) e imprimimos a mensagem de erro usando o método what(). Em seguida, o programa continua a execução normalmente.

A utilização de blocos try-catch permite que você trate exceções específicas ou genéricas de forma adequada, evitando que o programa encerre abruptamente devido a erros. Isso ajuda a lidar com situações excepcionais e fornecer um comportamento controlado em caso de falhas.

### 3. Médoto what()
O método what() é um método da classe std::exception em C++. Ele retorna uma sequência de caracteres (do tipo const char*) que descreve a exceção. **Esse método é frequentemente usado para obter informações sobre a exceção e exibi-las em mensagens de erro ou logs.**

Ao criar uma classe de exceção personalizada que herda de std::exception, é comum sobrescrever o **método what()** para fornecer uma descrição significativa da exceção específica. O método `what()` deve ser declarado como `const throw()` para indicar que não lança exceções, assim, pode-se chamar o método what() no objeto da exceção para obter a mensagem descritiva associada à exceção e usá-la para fins de depuração, registro ou comunicação de erros ao usuário.

## Como utilizar
Clone este repositório em sua máquina local.
Navegue até o diretório do exercício desejado.
Compile usando o `make` e execute o código do exercício de sua preferência.

Espero que este Readme.md seja útil para você na organização e compreensão dos exercícios do CPP Módulo 05.
Bom trabalho!