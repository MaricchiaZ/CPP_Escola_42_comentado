/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:12:53 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/18 11:17:24 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class A {};
class B {};
class C{

public:
    C(A const & _) {return; }
    explicit C(B const & _) {return; }
};

void    f(C const & c) {return; }

int main(void){

    f(A()); // IMPLÍCITA conversão
    f(B()); // EXPLÍCITA conversão - ❌Conversion is NOT OK - constructor é explícito

    return 0;
}