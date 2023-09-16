/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:47:31 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/06 18:52:01 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {

public:
    Point(void); // Forma Canônica
    ~Point(void); // Forma Canônica
    Point(Point const &p);// Forma Canônica - Cópia do Construtor
    Point &operator=(Point const &p);// Forma Canônica - Atribuição por cópia

    Point(float const x, float const y); // Construtor parametrizado
    
    // acessors
    Fixed const getX(void) const;
    Fixed const getY(void) const;
    void setX(Fixed const x);
    void setY(Fixed const y);

private:
    Fixed const x;
    Fixed const y;

};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif