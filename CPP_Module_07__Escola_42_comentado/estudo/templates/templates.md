# Templates

Templates são uma alternativa à sobrecarga de funções, quando estas envolvem lógicas de programas e operações idênticas para vários tipos de dados.

## Template de Função
O uso de templates permite ao programador a implementação de um único código para uma determinada função. O C++ gera automaticamente funções gabarito para tratar cada tipo de chamada realizada.
```cpp
#include <iostream>

template <typename T>
void print(T value) {
    std::cout << "Valor: " << value << std::endl;
}

int main() {
    int intValue = 42;
    double doubleValue = 3.14;
    std::string stringValue = "Hello";

    print(intValue); // Gera uma função especializada para int
    print(doubleValue); // Gera uma função especializada para double
    print(stringValue); // Gera uma função especializada para std::string

    return 0;
}
```

Neste exemplo, temos a função `print` que é um template. Ela pode ser chamada com diferentes tipos de dados, como `int`, `double` e `std::string`. O compilador C++ gera automaticamente funções especializadas para cada tipo de chamada.

Durante a compilação, o compilador cria versões especializadas da função `print` para cada tipo de dado usado na chamada. Isso permite que a função seja otimizada e adaptada para cada tipo específico, mantendo a flexibilidade de ter um único código genérico.

Ao executar o programa, você verá a saída correspondente para cada tipo de dado passado para a função `print`, graças à geração automática das funções especializadas.

Assim vemos como o uso de templates no C++ permite a implementação de um único código para uma função, com geração automática de funções especializadas para tratar cada tipo de chamada realizada.

## Template de Classe
Templates também pode ser usados para criar gabaritos de classe (classes genéricas). Neste caso, todos os seus métodos devem ser implementados no arquivo de cabeçalho, uma vez que o compilador gera automaticamente o código quando a palavra-chave template é encontrada.

```cpp
// Exemplo de classe genérica usando templates
template <typename T>
class MinhaClasse {
private:
    T valor1;
    T valor2;
    
public:
    MinhaClasse(T v1, T v2) : valor1(v1), valor2(v2) {}

    T getMax() const {
        return (valor1 >= valor2 ? valor1 : valor2);
    }

    T getMin() const {
        return (valor1 < valor2 ? valor1 : valor2);
    }
};

int main() {
    // Instanciando a classe com tipo int
    MinhaClasse<int> minhaClasseInt(10, 20);
    int maxInt = minhaClasseInt.getMax();
    int minInt = minhaClasseInt.getMin();
    std::cout << "Max Int: " << maxInt << std::endl;
    std::cout << "Min Int: " << minInt << std::endl;

    // Instanciando a classe com tipo double
    MinhaClasse<double> minhaClasseDouble(3.14, 2.71);
    double maxDouble = minhaClasseDouble.getMax();
    double minDouble = minhaClasseDouble.getMin();
    std::cout << "Max Double: " << maxDouble << std::endl;
    std::cout << "Min Double: " << minDouble << std::endl;

    return 0;
}
```

Nesse exemplo, criamos a classe `MinhaClasse` como uma classe genérica usando templates. A classe possui dois atributos do tipo `T`, onde `T` é o tipo fornecido ao instanciar a classe. Ela também possui dois métodos, `getMax()` e `getMin()`, que retornam o valor máximo e mínimo dos atributos, respectivamente.

No `main()`, instanciamos a classe `MinhaClasse` com dois tipos diferentes: `int` e `double`. Podemos chamar os métodos `getMax()` e `getMin()` para obter os valores máximos e mínimos correspondentes aos atributos de cada instância.

Observe que o código da classe genérica deve ser implementado no arquivo de cabeçalho (geralmente com extensão `.hpp`), pois o compilador gera automaticamente o código necessário com base no tipo fornecido durante a instanciação da classe.

Dessa forma, podemos criar uma classe genérica que pode ser usada com diferentes tipos de dados sem precisar repetir a implementação para cada tipo específico. O compilador cuidará de gerar as versões necessárias dos métodos da classe conforme necessário.