/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 08:26:28 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/18 08:40:30 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(void){
    
    int a = 42; // Valor de Referência

    double b = a; // IMPLÍCITA conversão de promoção
    int c = b; // EXPLÍCITA conversão de demoção
    int d = static_cast<int>(b); // EXPLÍCITA conversão de demoção

    return (0);
}

/*
- **Conversões numéricas implícitas:** É possível usar o static_cast para converter tipos numéricos relacionados, como inteiros para floats ou vice-versa. Ele realiza conversões simples entre tipos numéricos compatíveis.
*/