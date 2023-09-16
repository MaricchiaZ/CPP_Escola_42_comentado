/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:40:03 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/19 09:00:00 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T>
T max(T const & x, T const & y) {
    return (x > y ? x : y);
}

int foo(int x) {
    std::cout << "Long compiting time" << std::endl;
    return x;
}

int main(void){
    
    int a = 21;
    int b = 42;

    // EXPLICIT instantiation  ->  "max<int>(a, b)"
    std::cout << "Max of " << a << " and " << b << " is " << max<int>(a, b) << std::endl;
    
    // IMPLICIT instantiation
    std::cout << "Max of " << a << " and " << b << " is " << max(a, b) << std::endl;

    float c = -1.7f;
    float d = 4.2f;
    // EXPLICIT instantiation  ->  "max<float>(a, b)"
    std::cout << "Max of " << c << " and " << d << " is " << max<float>(c, d) << std::endl;
    
    // IMPLICIT instantiation
    std::cout << "Max of " << c << " and " << d << " is " << max(c, d) << std::endl;

    char e = 'a';
    char f = 'z';
    // EXPLICIT instantiation  ->  "max<char>(a, b)"
    std::cout << "Max of " << e << " and " << f << " is " << max<char>(e, f) << std::endl;
    
    // IMPLICIT instantiation
    std::cout << "Max of " << e << " and " << f << " is " << max(e, f) << std::endl;

    // No problem here....
    int ret = max<int>(foo(a), foo(b)); // EXPLICIT instantiation  ->  "max<int>(foo(a), foo(b))"
    std::cout << "Max of " << a << " and " << b << " is " << ret << std::endl;

    return 0;    
}

/*
g++ -Wall -Wextra -Werror main2.cpp

~/Trabalhos/MC_42/CPP_Module_07__Escola_42/estudo/templates ❯ ./a.out
Max of 21 and 42 is 42
Max of 21 and 42 is 42
Max of -1.7 and 4.2 is 4.2
Max of -1.7 and 4.2 is 4.2
Max of a and z is z
Max of a and z is z
Long compiting time
Long compiting time
Max of 21 and 42 is 42

*/