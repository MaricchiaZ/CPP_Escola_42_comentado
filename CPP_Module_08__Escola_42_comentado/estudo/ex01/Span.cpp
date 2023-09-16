/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:48:40 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/20 11:47:07 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {
}

Span::~Span(void) {   
}

Span::Span( const Span& src ) {
    *this = src;
}

Span& Span::operator=( Span const &src ) {
    if ( this != &src ) {
        this->_n = src._n;
        this->_vec = src._vec;
    }
    return *this;
}

void Span::addNumber(int n) {
    if (_vec.size() == _n)
        throw std::out_of_range("Span::addNumber: list is full");
    _vec.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end)
{
	std::vector<int>::iterator iter = begin;
	
	while (iter != end) {
    	if (_vec.size() == _n)
			throw std::runtime_error("Span::addNumber: list is full");
    	
		_vec.push_back(*iter);
    	iter++;
	}
}

const std::vector<int> *Span::getVector(void) const {
	return &_vec;
}

int Span::longestSpan( void ) const {
    if (_vec.size() < 2)
        throw std::out_of_range("Span is empty or contains only one element!");
    int max_diff = *std::max_element(_vec.begin(), _vec.end() ) - *std::min_element( _vec.begin(), _vec.end());
    return (max_diff);
}

int Span::shortestSpan(void) const
{
	std::vector<int> copy = _vec;
	std::sort(copy.begin(), copy.end());
	int prev = *copy.begin();
	int min_diff = INT_MAX;
    std::vector<int>::iterator iter;
    
	if (_vec.empty() || _vec.size() == 1)
		throw std::out_of_range("Span is empty or contains only one element!");

	
	for (iter = copy.begin() + 1; iter != copy.end(); iter++)
	{
		min_diff = std::min(min_diff, *iter - prev);
		prev = *iter;
	}

	return min_diff;
}

std::ostream& operator<<( std::ostream& o, const Span& span ) {
    for (std::vector<int>::const_iterator it = span.getVector()->begin(); it != span.getVector()->end(); ++it)
        o << *it << " ";
    return o;
}
