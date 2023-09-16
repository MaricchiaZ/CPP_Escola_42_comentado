
/*       NAMESPACE
Um namespace é uma região declarativa que fornece um escopo para os identificadores
 (os nomes de tipos, funções, variáveis etc.) dentro dele. Namespaces são usados para 
 organizar código em grupos lógicos e evitar colisões de nome que podem ocorrer especialmente 
 quando sua base de código inclui várias bibliotecas
*/

#include <stdio.h>

int gl_var = 1;
int f(void){return 2;}

namespace Bar { // namespace é uma subdivisão dentro de um arquivo (é um bloco independente, de modo que ele não alerta para uma segunda declaração da variável global gl_var)
    int gl_var = 5; // declaro as variáveis q vou usar
    int f(void) {return 6;} // declaro as funções que vou usar
}

namespace Ber {
    int gl_var = 10; // declaro as variáveis q vou usar
    int f(void) {return 20;} // declaro as funções que vou usar
}

namespace Bir = Bar; // funciona como um "alias", ou um apelido para um namespace já existente
// a partir de agora posso usar o namespace Bar pelo nome de Bir

int main(void){

    printf("gl_var: [%d]\n", gl_var);
    printf("f(): [%d]\n", f());

    printf("::gl_var: [%d]\n", ::gl_var); // é exatamente a mesma síntaxe das duas linhas de cima, quando não defimos a que namespace pertence, normalmnete é uma variável global (reforçamos isso coloando gl_antes_do_nome)
    printf("::f(): [%d]\n", ::f());

    printf("Bar::gl_var: [%d]\n", Bar::gl_var); // essa síntaxe "Bar::gl_var" diz que eu quero acessar o valor de gl_var dentro do namespace Bar, ou que pertence ao escopo do namespace Bar
    printf("f(): [%d]\n", Bar::f());// essa síntaxe "Bar::f()" diz que eu quero acessar o valor executar a funçao f() que pertence ao namespace Bar

    printf("Ber::gl_var: [%d]\n", Ber::gl_var);
    printf("f(): [%d]\n", Ber::f());

    printf("Bir::gl_var: [%d]\n", Bir::gl_var);
    printf("f(): [%d]\n", Bir::f());
}

// g++ -Wall -Wextra -Werror -Wno-used estudo_namespace.cpp

/* OUTPUT
~/Trabalhos/MC_42/CPP_00__Escola_42 ❯ ./a.out

gl_var: [1]
f(): [2]
::gl_var: [1]
::f(): [2]
Bar::gl_var: [5]
f(): [6]
Ber::gl_var: [10]
f(): [20]
Bir::gl_var: [5]
f(): [6]



*/