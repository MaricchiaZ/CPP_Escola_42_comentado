/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:48:48 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/08 11:41:21 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
#include <exception>

class Span
{

public:
	Span(unsigned int n);
	~Span();
	Span(const Span& other);
	Span& operator=(const Span& other);

	void addNumber(int num);
	void addNumber(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end);
	int shortestSpan(void) const;
	int longestSpan(void) const;
    const std::vector<int> *getVector(void) const;

private:
	unsigned int _n;
	std::vector<int> _vec;
	Span(void);
};

#endif
