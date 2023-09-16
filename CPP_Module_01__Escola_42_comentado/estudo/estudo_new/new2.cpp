/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new2.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:33:58 by maclara-          #+#    #+#             */
/*   Updated: 2023/06/18 10:53:12 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*  ________    NEW   E   DELETE    ________
 
Em C++, a utilização de new é preferida em relação ao malloc por algumas razões:

1. Semântica de objeto: new é usado para alocar e construir objetos dinamicamente, enquanto malloc é usado apenas para alocar memória bruta. Com new, além de alocar memória, o construtor do objeto é chamado automaticamente.

2. Tipo seguro: new é fortemente tipado, o que significa que o tipo de objeto alocado é inferido pelo compilador. Isso ajuda a evitar erros de tipo durante a alocação e liberação de memória.

3. Sobrecarga do operador new: em C++, é possível sobrecarregar o operador new para personalizar o comportamento da alocação de memória. Isso permite que você defina políticas de alocação personalizadas e execute tarefas adicionais durante a alocação de memória.

4. Liberação automática: quando você usa new para alocar memória, o C++ também fornece o operador delete correspondente para liberar automaticamente a memória alocada quando você não precisa mais dela. Isso ajuda a evitar vazamentos de memória.

Embora o uso de new seja mais comum em C++, ainda é possível usar malloc em código C++ quando necessário (MAS na 42 não pode). No entanto, é importante lembrar que, ao usar malloc, você precisa gerenciar manualmente a chamada do construtor e destrutor dos objetos e a liberação da memória usando free.

*/


#include <iostream>
#include <string>

class Student{

    private:
        std::string _login;
    
    public:
        Student(): _login("ldefault"){
            std::cout << "Student " << this->_login << " is born" << std::endl;
        }
        ~Student(){
            std::cout << "Student " << this->_login << " died" << std::endl;
        }   
};

int main(){
    
    Student* students= new Student[42]; // aqui alocamos os 42 estudantes

    //Para finalizar, devemos:
    
    delete []students; // aqui deletamos e desalocamos todos eles
    return (0);
}

// g++ new2.cpp

/*
~/Trabalhos/MC_42/CPP_Module_01__Escola_42/ex00/estudo/estudo_new ❯ ./a.out
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
*/
