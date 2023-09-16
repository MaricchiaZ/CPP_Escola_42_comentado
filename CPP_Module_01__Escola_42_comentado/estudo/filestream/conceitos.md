# Filestreams

## o que são filestreams em cpp?

Filestreams em C++ são classes que fornecem uma interface para ler e gravar dados em arquivos. Essas classes estão disponíveis na biblioteca padrão do C++ e são usadas para lidar com operações de entrada e saída em arquivos.

Existem três principais classes de filestreams em C++:

1. `std::ifstream`  (input file stream): Essa classe é usada para ler dados de um arquivo. Ela fornece operações para ler dados de diferentes tipos, como inteiros, floats, caracteres, strings, etc., a partir de um arquivo.

2. `std::ofstream` (output file stream): Essa classe é usada para gravar dados em um arquivo. Ela permite escrever dados de diferentes tipos em um arquivo, como inteiros, floats, caracteres, strings, etc.

3. `std::fstream` (file stream): Essa classe é usada para operações de entrada e saída em um arquivo. Ela combina as funcionalidades do `std::ifstream` e `std::ofstream`, permitindo ler e gravar dados em um arquivo.

Essas classes fornecem métodos e operadores para ler e gravar dados em arquivos, como `open()` para abrir um arquivo, `close()` para fechar um arquivo, `>>` para ler dados e `<<` para escrever dados. Além disso, elas suportam manipulação de posições de leitura/gravação no arquivo, busca, leitura/escrita em modo binário, tratamento de erros, entre outras funcionalidades.

Com o uso de filestreams, é possível ler dados de um arquivo existente, gravar novos dados em um arquivo ou até mesmo criar um novo arquivo. As filestreams oferecem uma forma flexível e conveniente de interagir com arquivos em programas C++.