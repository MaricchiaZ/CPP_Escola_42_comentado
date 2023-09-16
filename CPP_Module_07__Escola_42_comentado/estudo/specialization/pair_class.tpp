/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_class.tpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:01:39 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/19 11:17:33 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

// TEMPLATE GENERIC __________________________________________________________________
template<typename T, typename U>

class Pair{
    
public:
    Pair<T, U>(T const & lhs, U const & rhs) : _lhs(lhs), _rhs(rhs){
        std::cout << "Generic template" << std::endl;
    }
    
    ~Pair<T, U>(void){
    }
    
    T const & fst(void) const {return this->_lhs;}
    U const & snd(void) const {return this->_rhs;}

private:
    T _lhs;
    U _rhs;
    
    Pair<T, U>(void);
};

// TEMPLATE PARTIAL SPECIALIZED ____________________________________________________________
// É importante observar que a classe Pair<int, U> é uma especialização parcial, pois ainda depende 
// de um segundo tipo U. Essa especialização parcial permite fornecer uma implementação personalizada
//  para casos específicos em que o primeiro tipo é int e o segundo tipo pode ser qualquer tipo U.

//É comum usar especializações parciais em templates para tratar de casos específicos ou fornecer 
// implementações especializadas para determinadas combinações de tipos.
template<typename U>

class Pair<int, U>{
    
public:
    Pair<int, U>(int lhs, U const & rhs) : _lhs(lhs), _rhs(rhs){
        std::cout << "Int partial specialization" << std::endl;
    }
    
    ~Pair<int, U>(void){
    }
    
    int fst(void) const {return this->_lhs;}
    U snd(void) const {return this->_rhs;}

private:
    int _lhs;
    U _rhs;
    
    Pair<int, U>(void);
};

// TEMPLATE BOOL/BOOL SPECIALIZED ____________________________________________________________
template<>
class Pair<bool, bool>{

public:
    Pair<bool, bool>(bool bool1, bool bool2){
    std::cout << "Bool/bool specialization" << std::endl;
    this->_n = 0;
    this->_n |= static_cast<int>(bool1) << 0;
    this->_n |= static_cast<int>(bool2) << 1;
    return ;
    }

    ~Pair<bool, bool>(void){
    }
    bool fst(void) const {return this->_n & 0x01;}
    bool snd(void) const {return this->_n & 0x02;}

private:
    int _n;
    Pair<bool, bool>(void);
    
};


template<typename T, typename U>
std::ostream & operator<<(std::ostream & o, Pair<T, U> const & p){
    o << "Pair(" << p.fst() << ", " << p.snd() << ")";
    return o;
}

std::ostream & operator<<(std::ostream & o, Pair<bool, bool> const & p){
    o << std::boolalpha << "Pair(" << p.fst() << ", " << p.snd() << ")";
    return o;
}