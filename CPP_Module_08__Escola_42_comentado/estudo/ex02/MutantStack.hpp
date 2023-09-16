/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:46:16 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/08 11:41:39 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
        // Constructors
        MutantStack() : MutantStack<T, Container>::stack() {
        }

        ~MutantStack() {
        }
        
        MutantStack(const MutantStack<T, Container>& other) : MutantStack<T, Container>::stack(other){
        }
        MutantStack<T, Container>& operator=(const MutantStack<T, Container>& other){
                if (&other == this)
                        return (*this);
                else if (this != &other)
                        this->MutantStack<T, Container>::stack::operator=(other);
                return *this;
            }
            
    // iterator
    typedef typename Container::iterator iterator;
    iterator begin() {
    return this->c.begin();
    };
    
    iterator end() {
    return this->c.end();
    };
                
};

#endif
