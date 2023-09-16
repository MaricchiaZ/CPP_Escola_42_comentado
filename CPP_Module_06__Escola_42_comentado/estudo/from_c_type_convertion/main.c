/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:49:20 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/17 21:23:09 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void dump_32bits_integer(int const n){
    int i = 31;
    while (i >= 0){
        if ((n >> i) & 1)
            write(1, "1", 1);
        else
            write(1, "0", 1);
        if (i % 8 == 0)
            write(1, " ", 1);
        i--;
    }
    write(1, "\n", 1);
}

void dump_64bits_double(double const n){
    int i = 63;
    while (i >= 0){
        if (((unsigned long long)n >> i) & 1)
            write(1, "1", 1);
        else
            write(1, "0", 1);
        if (i % 8 == 0)
            write(1, " ", 1);
        i--;
    }
    write(1, "\n", 1);
}

int main(void){
    int a = 42; // Valor de referência
    
    double b = 0;
    double c = (double)a; // Conversão EXPLÍCITA valor inteiro a para um número de ponto flutuante de 64 bits.

    double d = a;// Conversão Implícita do valor inteiro a para um número de ponto flutuante de 64 bits.
    double e = d; // A ATRIBUIÇÃO DIRETA do valor de d para e.
    double f = (int)d; // Conversão EXPLÍCITA do valor de ponto flutuante d para um inteiro de 32 bits.

    dump_32bits_integer(a);
    dump_64bits_double(b);
    dump_64bits_double(c);

    dump_64bits_double(d);

    dump_32bits_integer(e);
    dump_32bits_integer(f);

    return (0);
}
/*
gcc -Wall -Wextra -Werror main.c

~/Trabalhos/MC_42/CPP_Module_06__Escola_42/estudo/from_c_type_convertion ❯ ./a.out 
00000000 00000000 00000000 00101010 
00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 
00000000 00000000 00000000 00000000 00000000 00000000 00000000 00101010 
00000000 00000000 00000000 00000000 00000000 00000000 00000000 00101010 
00000000 00000000 00000000 00101010 
00000000 00000000 00000000 00101010 


EXPLICAÇÂO DO LOG:
~/Trabalhos/MC_42/CPP_Module_06__Escola_42/estudo/from_c_type_convertion ❯ ./a.out 
// int 42
00000000 00000000 00000000 00101010 
// int 0 convertido pra double - conversão implícita
00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 
// int 42 convertido pra double - conversão explícita
00000000 00000000 00000000 00000000 00000000 00000000 00000000 00101010 
// int 42 convertido pra double p- promoção implícita
00000000 00000000 00000000 00000000 00000000 00000000 00000000 00101010
// double 42 convertido pra int - demoção implícita
00000000 00000000 00000000 00101010 
// double 42 convertido pra int - demoção explícita
00000000 00000000 00000000 00101010 

// demoção : acontece quando um valor de um tipo de dado maior é atribuído a um tipo de dado menor, você está convertendo um tipo de dado com maior precisão (int) para um tipo com menor precisão (double).
*/