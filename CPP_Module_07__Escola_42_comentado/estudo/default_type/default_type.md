# Default type

Em C++, quando você define um template, você pode fornecer um tipo padrão (default type) para o parâmetro de tipo do template. Isso significa que, caso nenhum tipo seja especificado explicitamente ao instanciar o template, o tipo padrão será utilizado.

A definição de um tipo padrão em um template é feita através do uso da sintaxe `typename = default` na declaração do parâmetro de tipo. Por exemplo:

```cpp
template <typename T = int>
class MyClass {
    // ...
};

int main(void){

    MyClass<> myClass; // Instancia MyClass com o tipo padrão (int)
    MyClass<double> myClassDouble; // Instancia MyClass com o tipo double
    
    return 0;
}
```

Nesse exemplo, a classe `MyClass` é um template com um parâmetro de tipo `T`, que tem um tipo padrão definido como `int`. Isso significa que, se nenhum tipo for fornecido ao instanciar `MyClass`, o tipo `int` será utilizado automaticamente.

A definição de um tipo padrão em um template pode ser útil quando você deseja fornecer uma opção padrão conveniente para os usuários do template, mas também permite que eles especifiquem um tipo diferente, se desejado.