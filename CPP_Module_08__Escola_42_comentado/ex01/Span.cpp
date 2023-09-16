/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:48:40 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/08 12:25:54 by maclara-         ###   ########.fr       */
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

// Esse método é responsável por adicionar um número ao contêiner _vec.
void Span::addNumber(int n) {
    if (_vec.size() == _n) // Primeiro, ele verifica se o tamanho do contêiner _vec é igual ao valor _n, onde _n é a
	// capacidade máxima do contêiner.
        throw std::out_of_range("Span::addNumber: list is full"); // . Se o contêiner estiver cheio, 
		// uma exceção do tipo std::out_of_range é lançada, indicando que o contêiner está cheio.
    _vec.push_back(n); //  o número n é adicionado ao final do contêiner _vec usando a função push_back.
}


//  Este método recebe dois iteradores, begin e end, que definem um intervalo em um contêiner externo (neste caso, um std::vector<int>). 
// O objetivo é adicionar todos os números desse intervalo ao contêiner _vec.
void Span::addNumber(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end)
{
	std::vector<int>::iterator iter = begin; // Primeiro, um iterador chamado iter é inicializado com o valor do iterador begin.
	
	while (iter != end) { // Um loop é usado para percorrer o intervalo definido pelos iteradores begin e end. 
    	if (_vec.size() == _n) // Dentro do loop, é verificado se o tamanho do contêiner _vec é igual ao valor _n, 
		// onde _n é a capacidade máxima do contêiner.
			throw std::runtime_error("Span::addNumber: list is full"); // Se o contêiner estiver cheio, uma exceção do tipo
			// std::runtime_error é lançada, indicando que o contêiner está cheio.
    	
		_vec.push_back(*iter); // Caso contrário, o número apontado pelo iterador iter é adicionado ao final do contêiner _vec 
		// usando a função push_back, e o iterador iter é incrementado para apontar para o próximo elemento no intervalo.
    	iter++;
	}
}

const std::vector<int> *Span::getVector(void) const {
	return &_vec;
}

// Calcula o maior intervalo entre os elementos do contêiner _vec e retornar esse valor.
int Span::longestSpan( void ) const {
    if (_vec.size() < 2) //  verifica se o tamanho do contêiner _vec é menor que 2. Se for o caso, 
	// lança uma exceção do tipo std::out_of_range, com uma mensagem de erro indicando que o contêiner 
	// está vazio ou contém apenas um elemento.
        throw std::out_of_range("Span is empty or contains only one element!");
	// Caso o contêiner tenha pelo menos dois elementos, o método calcula o maior intervalo possível entre os elementos do contêiner.
    int max_diff = *std::max_element(_vec.begin(), _vec.end() ) - *std::min_element( _vec.begin(), _vec.end());
    return (max_diff);
}

// Esse método é responsável por calcular o menor intervalo entre os elementos do contêiner _vec. 
int Span::shortestSpan(void) const
{
	std::vector<int> copy = _vec; // É criada uma cópia do contêiner _vec chamada copy. 
	// Isso é feito para que o contêiner original não seja modificado durante a ordenação.
	std::sort(copy.begin(), copy.end()); // A cópia do contêiner copy é ordenada usando a função std::sort.
	//  Isso coloca os elementos em ordem crescente.
	int prev = *copy.begin();
	int min_diff = INT_MAX; // poderíamos inicializar com qualquer valor
    std::vector<int>::iterator iter;
    
	if (_vec.empty() || _vec.size() == 1) // Antes de iniciar o loop, é verificado se o contêiner _vec está vazio
	//  ou contém apenas um elemento. Se for o caso, uma exceção do tipo std::out_of_range é lançada, indicando que o
	//  contêiner está vazio ou contém apenas um elemento.
		throw std::out_of_range("Span is empty or contains only one element!");

	
	for (iter = copy.begin() + 1; iter != copy.end(); iter++)
	{
		min_diff = std::min(min_diff, *iter - prev); // Para cada elemento no loop, a diferença entre o elemento atual e o 
		// elemento anterior (*iter - prev) é calculada e comparada com o valor atual de min_diff. Se for menor que min_diff, 
		// min_diff é atualizado com esse novo valor.
		prev = *iter;
	}

	return min_diff;
}

std::ostream& operator<<( std::ostream& o, const Span& span ) {
    for (std::vector<int>::const_iterator it = span.getVector()->begin(); it != span.getVector()->end(); ++it)
        o << *it << " ";
    return o;
}
