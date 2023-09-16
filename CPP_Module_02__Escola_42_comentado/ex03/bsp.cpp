/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:57:12 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/06 20:00:50 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
A fórmula utilizada para calcular a área de um triângulo é conhecida como "fórmula de Shoelace" 
ou "método do determinante". Nesse caso, a fórmula é simplificada utilizando a fórmula do produto
 cruzado entre vetores.
*/
float area(float x1, float y1, float x2, float y2, float x3, float y3) {
	float area; 
	
	area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
	if (area < 0)
		area *= -1.0;
	return (area);
}

/*
A função bsp verifica se um ponto está dentro de um triângulo usando a técnica BSP (Binary Space 
Partitioning). Ela calcula as áreas de quatro triângulos: o triângulo formado pelos pontos a, b e c 
(chamado de área total) e os três triângulos formados pelos pontos a, b e o ponto a ser verificado 
(chamados de área1, área2 e área3), e verifica se a soma das áreas dos três triângulos (área1 + área2 + 
área3) é igual à área total do triângulo. Se for, o ponto está dentro do triângulo, caso contrário, não 
está.
*/
bool bsp(Point const a, Point const b, Point const c, Point const point) {
	float area1;
	float area2;
	float area3;
	float area_total;

	area1 = area(point.getX().toFloat(), point.getY().toFloat(),
					a.getX().toFloat(), a.getY().toFloat(),
					b.getX().toFloat(), b.getY().toFloat());

	area2 = area(point.getX().toFloat(), point.getY().toFloat(),
					a.getX().toFloat(), a.getY().toFloat(),
					c.getX().toFloat(), c.getY().toFloat());

	area3 = area(point.getX().toFloat(), point.getY().toFloat(),
					b.getX().toFloat(), b.getY().toFloat(),
					c.getX().toFloat(), c.getY().toFloat());

	area_total = area(a.getX().toFloat(), a.getY().toFloat(),
					b.getX().toFloat(), b.getY().toFloat(),
					c.getX().toFloat(), c.getY().toFloat());

	if (area_total == (area1 + area2 + area3) && area_total != 0 &&\
					area1 != 0 && area2 != 0 && area3 != 0)
                    
		return (true);
	else
		return (false);
}