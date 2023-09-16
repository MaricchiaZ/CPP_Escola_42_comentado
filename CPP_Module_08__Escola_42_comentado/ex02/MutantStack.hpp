/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:46:16 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/08 12:50:43 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
#include <deque>

// O código que você compartilhou define uma classe chamada MutantStack que é uma derivação 
// (ou herdeira) da classe std::stack da biblioteca padrão C++. A classe MutantStack tem a 
// capacidade de armazenar elementos de um determinado tipo T em um contêiner especificado Container.
template <typename T, typename Container = std::deque<T> > //  Esta linha define a classe MutantStack 
// como uma derivação da classe std::stack. Ela utiliza dois tipos de template: T é o tipo dos elementos
// armazenados na pilha e Container é o tipo de contêiner subjacente que será usado para armazenar os elementos.
class MutantStack : public std::stack<T, Container>
{
public:
        // Constructors
        MutantStack() : MutantStack<T, Container>::stack() { // o construtor padrão da classe MutantStack. 
        // Ele chama o construtor padrão da classe base std::stack usando a sintaxe de inicialização do construtor. 
        // Ele cria uma pilha vazia usando o contêiner especificado.
        }

        ~MutantStack() {
        }
        
        MutantStack(const MutantStack<T, Container>& other) : MutantStack<T, Container>::stack(other){
        } // Este é o construtor de cópia da classe MutantStack. Ele chama o construtor de cópia da classe base 
        // std::stack usando a sintaxe de inicialização do construtor. Isso permite que você crie uma nova instância de
        // MutantStack copiando o conteúdo de outra instância.
        
        MutantStack<T, Container>& operator=(const MutantStack<T, Container>& other){
                if (&other == this)
                        return (*this);
                else if (this != &other)
                        this->MutantStack<T, Container>::stack::operator=(other);
                return *this;
            } // Este é o operador de atribuição da classe MutantStack. Ele permite que você atribua o conteúdo de uma instância 
            // MutantStack a outra. O código dentro deste operador verifica se as duas instâncias não são iguais para evitar 
            // atribuições desnecessárias. Ele chama o operador de atribuição da classe base std::stack.
            
    // iterator
    typedef typename Container::iterator iterator;
    iterator begin() { //  Este método retorna um iterador apontando para o início do contêiner subjacente.
    // Ele permite que você use a sintaxe do iterador para percorrer os elementos da pilha.
    return this->c.begin();
    };
    
    iterator end() { // Este método retorna um iterador apontando para o final do contêiner subjacente.
    return this->c.end();
    };
                
};

// Essa classe MutantStack estende as funcionalidades da classe std::stack, adicionando a capacidade de usar
// iteradores para percorrer os elementos da pilha. Isso permite que você aproveite os recursos de um contêiner 
// subjacente, como std::deque, enquanto mantém a interface de uma pilha.

#endif
