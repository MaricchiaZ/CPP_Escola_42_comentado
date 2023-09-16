/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_class.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:20:05 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/19 09:45:29 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// o nome vertex_class.tpp com o (.tpp) indica que é um aquivo de template :)

#include <iostream>
#include <iomanip>

template <typename T = float>
class Vertex{

public:
    Vertex(T const & x, T const & y, T const & z) : _x(x), _y(y), _z(z){
    }
    
    ~Vertex(void){
    }
    T const & getX(void) const {return this->_x;}
    T const & getY(void) const {return this->_y;}
    T const & getZ(void) const {return this->_z;}

private:
    T const _x;
    T const _y;
    T const _z;
    
    Vertex(void);
};

template <typename T>
std::ostream & operator<<(std::ostream & o, Vertex<T> const & v){
    std::cout.precision(1);
    o << setiosflags(std::ios::fixed);
    o << "Vertex(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
    return o;
}