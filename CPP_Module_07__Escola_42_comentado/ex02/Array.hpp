/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:12:18 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/08 10:45:55 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <exception>
# include <iostream>

template<typename T>
class Array
{
private:
	T *array_done; // array do tipo passado
	unsigned int size_array; // tamanho do array

public:
	// Canonical Form
	Array(void): array_done(new T()), size_array(0) {
	};
	
	~Array(void) {
		delete [] array_done;
	}

// Um construtor de cópia é usado para criar uma nova instância da classe, copiando os valores de
//  uma instância existente da mesma classe. Isso é útil quando você deseja criar uma cópia de um objeto 
// para que as alterações em uma instância não afetem a outra.
    Array(const Array& other) : array_done(new T[other.size()]), size_array(other.size()) { // array_done(new T[other.size()]): Isso aloca 
	// memória para um novo array dinâmico do tipo T (definido pela classe Array) com o mesmo tamanho do array no objeto other.
        for ( unsigned int i( 0 ); i < size_array; i++ ) // O loop for itera sobre os elementos do array no objeto other e os copia
		//  para o novo array criado na instância atual.
            array_done[i] = other.array_done[i];
    }; // Em resumo, esse construtor de cópia é responsável por criar uma cópia profunda do objeto other, garantindo que um novo 
	// array seja alocado e os valores sejam copiados. Isso é importante para que as alterações em um objeto Array não afetem o outro objeto.

    Array& operator=(const Array& other) {
        if (this != &other) { // Verifica se não estamos atribuindo o objeto a si mesmo
            delete [] array_done; // Libera a memória do array atual
            array_done = new T[other.size()];  // Aloca novo espaço de memória para o array
            size_array = other.size_array; // Atualiza o tamanho do array
            for ( unsigned int i( 0 ); i < size_array; i++ )
                array_done[i] = other.array_done[i]; // // Copia os valores do array de 'other'
        }
        return *this; // Retorna uma referência para o objeto atual
    } // Esse operador de atribuição é importante para garantir que a cópia de atribuição entre objetos Array seja feita de forma 
	// correta, liberando recursos alocados anteriormente e criando uma cópia profunda dos valores.

	
	// ________________________________________________________________________

	// parametric constructor
	Array(unsigned int n) : array_done(new T[n]), size_array(n) {
	};

	unsigned int  size(void) const {
		return size_array;
	}

// Aqui vai a definição de dois operadores de indexação ([]) sobrecarregados para uma classe chamada Array. 
// Esses operadores permitem acessar elementos de objeto da classe Array como se fosse um array verdadeiro.

	// operador de indexação não-constante, essa referência permite a modificação do elemento
    T& operator[]( unsigned int i ) const {
        if ( i >= size_array )
            throw Array::IndexErrorException();

        return array_done[i];
    }

// classe aninhada para execessão
	class IndexErrorException : public std::exception
	{
	public:
		const char* what() const throw(){
			return "Error: Index is out of the limits!";
		}
	};
};

// Ao retornar o fluxo de saída out, você permite que o operador de inserção seja usado em um estilo de encadeamento,
// o que significa que você pode imprimir vários objetos separados por << em uma única linha
template < typename T >
std::ostream& operator<<( std::ostream& out, const Array<T>& arr ) {
    for ( unsigned int i( 0 ); i < arr.size(); i++ )
        out << arr[i] << " "; // Imprime o elemento do array seguido de um espaço
    return out; 
}

#endif
