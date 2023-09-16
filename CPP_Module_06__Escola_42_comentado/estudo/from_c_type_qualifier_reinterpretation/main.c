/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:36:39 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/18 10:15:29 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(void)
{
    int a = 42; // valor de referência

    //  O ponteiro b é declarado como um ponteiro para um int constante. Isso significa que o valor 
    // apontado por b não pode ser modificado através desse ponteiro. Neste caso, b aponta para a variável a.
    int const * b = &a; // IMPLÍCITO cast de tipo de qualificador

    // A mesma ideia do ponteiro b, porém aqui é feito um cast explícito para garantir que o tipo 
    // seja interpretado corretamente. Neste caso, c também aponta para a variável a.
    int const * c = (int const *)&a; // EXPLÍCITO cast de tipo de qualificador

    // Outra declaração de ponteiro para um int constante, sem diferença em relação a b e c.
    int const *d = &a; // IMPLÍCITO cast promoção

    // Aqui ocorre um cast implícito de int const * para int *. Embora d seja originalmente um ponteiro
    //  para um int constante, ele é atribuído a e, que é um ponteiro para um int não constante. Esse 
    // tipo de conversão é chamado de demotion implicita, que permite converter um ponteiro constante em
    //  um ponteiro não constante. No entanto, isso pode levar a comportamento indefinido se tentar
    //  modificar o valor através do ponteiro e.
    int * e = d; // IMPLÍCITO cast demoção - ❌ não compila

    // Aqui é realizado um cast explícito para converter d, um ponteiro para um int constante, em um 
    // ponteiro para um int não constante. Essa conversão também é uma demotion explicita.
    int * f = (int *)d; // EXPLÍCITO cast demoção
    
    return (0);
}

/*
gcc -Wall -Wextra -Werror -Wno-unused main.c

❌O COMPILADOR NÂO DEIXA COMPILAR COM O CAST DA LINHA 33, POIS ESTÁ TENTANDO CONVERTER UM PONTEIRO CONSTANTE EM UM PONTEIRO NÃO CONSTANTE.:

~/Trabalhos/MC_42/CPP_Module_06__Escola_42/estudo/from_c_type_qualifier_reinterpretation ❯ gcc -Wall -Wextra -Werror -Wno-unused -Werror=discarded-qualifiers main.c

main.c: In function ‘main’:
main.c:21:15: error: initialization discards ‘const’ qualifier from pointer target type [-Werror=discarded-qualifiers]
   21 |     int * e = d;

   
*/