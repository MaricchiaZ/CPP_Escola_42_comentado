
/*
Objetos mágicos:
"cin" - entrada padrão
"cout" - saída padrão
*/

/* SITE REFERÊNCIA com TODA DOCUMENTAÇÃO sobre a linguagem C++
https://cplusplus.com/reference/

https://cplusplus.com/reference/iostream/

*/



/*
OPERADORES NOVOS DO CPP

:: - operador de resolução de escopo. Ele dá contexto ao que está se referindo, ele desambigua uma possível situação onde pode haver confusão entre dois ou mais membros. Ele é usado em duas situações:

    1. Para indicar que um membro pertence a um determinado namespace como no exemplo do "std::cout" (std é um namespace). É uma família diferente de componentes, então para usar membros de uma família diferente da atual você não pode usar só o nome do membro, mas também precisa usar o sobrenome dele também. Seria como dizer, quero usar o "std" que percente ao namespace "cout". Mesmo se tiver outro std definido em outro namespace não haverá confusão uma vez que eu deixo claro que estou usando o "std" que percente ao namespace "cout".

    2. Indicar a que classe pertence um membro. Isto é necessário quando vamos definir os métodos (e não quando vamos declarar). Sem dizer a que classe ele pertence o compilador não tem como saber o que ele está implementando e isto é uma informação fundamental.

<< - back arrow - nos permite redirecionar o fluxo para a saída padrão (terminal);

>> - arrow - permite redirecionar o fluxo de entrada para uma variável;


*/

#include <iostream>

int main(void) {

    std::cout << "Hello world!" << std::endl; // O Famoso Hello World em CPP :)
    // std::cout  - indica que vamos redirecionar algo para a saída padrão
    //  << "Hello world!" -  o que estamos redirecionando é a string Hello world!
    // << std::endl - estamos redirecinando para a saída, mais uma coisa, o endline que é o correspondente ao '\n'

    // _______________________________________________________________
    // agora vamos receber uma palavra do terminal e printar na tela

    char    buff[100]; // criamos um buffer de letras de 100 bytes

    std::cout << "Input a word: "; // redirecionamos para a saída padrão (std::cout) a string "Input a word: "
    // e nesse caso optamos por não colocar a quebra de linha !!!!!!
    std::cin >> buff; // agora redirecionamos a entrada padrão para o buffer criado
    std::cout << "You entered: ["<< buff <<"]" << std::endl; // e por último, redirecionamos para a saída padrão,
    // a frase interpolada com o buffer "You entered: + buffer" e além deles, 
    // também redirecionamos uma quebra de linha (std::endl)

    return 0;
}

// g++ -Wall -Wextra -Wno-used -Werror estudo_stdio.cpp

/* OUTPUT
~/Trabalhos/MC_42/CPP_00__Escola_42 ❯ ./a.out

Hello world!
Input a word: oi
You entered: [oi]

*/