/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:00:59 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/19 09:13:06 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
class List{
    
public:
    List<T>(T const & content){
        // etc..
    }
    List<T>(List<T> const & list){
        // etc...
    }
    ~List<T>(){
        // etc...
    }
    // etc...
private:
    T * _content;
    List<T> * _next; // ponteiro para o próximo elemento da lista (do tipo List<T>).
};

int main(void){
    
    List<int> a(42);
    List<float> b(3.14f);
    List<List<int>> c(a); // c é uma lista de listas de inteiros, inicializada com uma cópia de a.

    return 0;
}