/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample_class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:25:07 by maclara-          #+#    #+#             */
/*   Updated: 2023/06/27 14:38:16 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

#include <iostream>

class Sample {

public:
    Sample();
    ~Sample();

// AQUI TEMOS 4 FUNÇÕES BAR COM ASSINATURAS DIFERENTES - ISSO É O POLIMORFISMO
/*
No polimorfismo ad-hoc, as funções são diferenciadas pela sua assinatura, que consiste no tipo e/ou número de parâmetros. Quando uma função é chamada, o compilador seleciona automaticamente a versão correta da função com base nos argumentos fornecidos.
*/
    void    bar(char const c) const;
    void    bar(int const n) const;
    void    bar(float const z) const;
    void    bar(Sample const &i) const;
    
};

#endif