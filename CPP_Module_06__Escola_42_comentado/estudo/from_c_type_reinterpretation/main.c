/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:55:06 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/17 21:34:17 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void){

    float a = 420.042f; // Valor de referência

    //Como o tipo void * é um ponteiro genérico, ele pode apontar para qualquer tipo de dado. 
    // Nesse caso, estamos fazendo um cast de reinterpretação implícito e explícito, respectivamente, 
    // convertendo o endereço de a para o tipo void *.
    
    void * b = &a; // IMPLÍCITO cast de reinterpretação de tipo.
    void * c = (void *) &a; // EXPLÍCITO cast de reinterpretação de tipo.

    // O ponteiro d do tipo void * recebe o endereço de a. Isso é um cast de promoção implícito, pois 
    // estamos convertendo o ponteiro &a de float * para void *.
    void * d = &a; // IMPLÍCITO cast de promoção

    // Fazemos um cast de demotion implícito em e, atribuindo o valor de d a ele. No entanto, é importante
    //  observar que esse cast é perigoso, pois estamos convertendo um ponteiro genérico para um tipo 
    // específico sem garantir que os tipos sejam compatíveis.
    int * e = d; // IMPLÍCITO cast de demoção

    // No caso de f, realizamos um cast de demotion explícito, usando (int *) para converter d para 
    // int *. Nesse caso, estamos informando explicitamente ao compilador que estamos cientes do risco
    //  de demotion e queremos realizar a conversão.
    int * f = (int *) d; // EXPLÍCITO cast de demoção

    printf("%p, %f\n", &a, a);
    
    printf("%p\n", b);
    printf("%p\n", c);
    
    printf("%p\n", d);
    printf("%p, %d\n", e, *e);
    printf("%p, %d\n", e, *f);

    return (0);
}

/*
gcc -Wall -Wextra -Werror main.c

~/Trabalhos/MC_42/CPP_Module_06__Escola_42/estudo/from_c_type_reinterpretation ❯ ./a.out
0x7ffe86b0159c, 420.041992
0x7ffe86b0159c
0x7ffe86b0159c
0x7ffe86b0159c
0x7ffe86b0159c, 1137837408
0x7ffe86b0159c, 1137837408

EXPLICAÇÃO:

A primeira linha 0x7ffe86b0159c, 420.041992 corresponde à impressão do endereço de memória de a e seu valor como float. O endereço de a é 0x7ffe86b0159c e o valor é aproximadamente 420.041992.

A segunda, terceira e quarta linhas 0x7ffe86b0159c correspondem à impressão dos valores de b, c e d, que são ponteiros void * que apontam para o endereço de a. O valor impresso é o mesmo endereço de memória 0x7ffe86b0159c que foi atribuído a `b` `c` e `d`.

A penúltima linha 0x7ffe86b0159c, 1137837408 corresponde à impressão do valor do ponteiro e e o valor apontado por ele (*e). O ponteiro e recebeu o valor de d, que é um ponteiro void *. No entanto, ao acessar o valor apontado por e, que era originalmente um float, ocorre uma interpretação incorreta do valor, pois agora está sendo tratado como um int. O valor impresso 1137837408 é uma representação numérica do conteúdo de memória interpretado como int, mas não corresponde ao valor original de a.

A última linha 0x7ffe86b0159c, 1137837408 é semelhante à penúltima linha, pois f é outro ponteiro int * que recebeu o valor de d após um cast explícito. O resultado é o mesmo, com *f interpretando incorretamente o valor original de a.

*/