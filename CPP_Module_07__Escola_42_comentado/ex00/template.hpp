/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:36:57 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/08 10:24:58 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

// Essas funções são projetadas para trabalhar com diferentes tipos de dados, como números, 
// strings ou objetos personalizados, graças ao uso de templates.
template <typename T> 
void swap ( T &a, T &b) // A função swap realiza a troca de valores entre duas variáveis do mesmo tipo:
{
    T x;
        x = a;
        a = b;
        b = x;
}

template <typename T> 
T min(T a , T b) // A função min retorna o valor mínimo entre dois valores do mesmo tipo:
{
    if(a < b)
        return a;
    return b;
}

template <typename T> T max(T a, T b) // A função max retorna o valor máximo entre dois valores do mesmo tipo:
{
    if(a > b)
        return a;
    return b;
}

#endif

// Essas funções são exemplos de como você pode usar templates para criar funções genéricas que funcionam 
// com diferentes tipos de dados. O compilador irá gerar versões específicas dessas funções para cada tipo 
// que você usar ao chamá-las. Isso permite que você escreva um código flexível e reutilizável para diferentes 
// tipos de dados sem ter que reescrever a lógica da função para cada tipo específico.