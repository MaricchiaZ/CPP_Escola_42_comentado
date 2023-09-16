# Reinterpret cast em C++

O `reinterpret_cast` é um operador em C++ usado para realizar conversões de ponteiros ou referências entre tipos que não estão relacionados por herança. Ele é usado principalmente para converter ponteiros ou referências de um tipo para outro tipo, mesmo que os tipos não estejam relacionados entre si, permitindo reinterpretar o valor de um ponteiro ou referência como se fosse de um tipo diferente, sem realizar conversões de tipo explícitas.

O `reinterpret_cast` é uma **operação de baixo nível e possui riscos e limitações**. Ele não faz nenhuma verificação de segurança durante a conversão e *assume que o programador está ciente das implicações e possíveis consequências.*

Alguns exemplos de uso do reinterpret_cast incluem:

- Conversão de ponteiros entre tipos numéricos e ponteiros de objeto.
- Conversão de ponteiros de objeto para ponteiros de função e vice-versa.
- Conversão de um ponteiro para void* e de volta para o tipo original.

No entanto, é importante usar o reinterpret_cast com cuidado, pois ele pode levar a resultados indefinidos se usado de forma inadequada ou se a conversão não fizer sentido em termos de representação de memória dos tipos envolvidos. É recomendado o uso do reinterpret_cast apenas em situações específicas e quando absolutamente necessário.

###  Reinterpretar um ponteiro de um tipo para outro tipo:
O reinterpret_cast pode ser usado para converter ponteiros entre tipos diferentes. Ele permite converter ponteiros de um tipo para outro tipo, mesmo que os tipos não estejam relacionados entre si.
```cpp
int main(void){
    
    float a = 420.042f; // valor de referencia

    void * b = &a; // IMPLÍCITO cast de promoção
    int * c = reinterpret_cast<int *>(b); // EXPLÍCITO cast de demoção por reinterpretação
    int & d = reinterpret_cast<int &>(b); // EXPLÍCITO cast de demoção por reinterpretação

    return (0);
}
```
O `reinterpret_cast` está sendo usado para reinterpretar um ponteiro de `float` como um ponteiro para `int` e também reinterpretar o mesmo ponteiro como uma referência para `int`.

### ⚠️AO USAR O REINTERPRET CAST⚠️:
É importante mencionar que o `reinterpret_cast` **não executa verificações em tempo de execução** para garantir a validade da conversão. Portanto, é **responsabilidade do programador garantir que a conversão seja segura** e que não ocorra perda de informações. Se houver dúvidas sobre a validade da conversão, é recomendável usar operadores de casting mais seguros, como dynamic_cast ou static_cast.