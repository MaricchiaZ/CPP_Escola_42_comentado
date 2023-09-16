/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:14:34 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/07 14:01:18 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

 std::string ScalarConverter::input = "\0";
 char ScalarConverter::_char = 0;
 int ScalarConverter::_int = 0;
 float ScalarConverter::_float = 0;
 double ScalarConverter::_double = 0;
 bool ScalarConverter::nothing = 0;

ScalarConverter::ScalarConverter(void) {
	this->_char = 0;
	this->_int = 0;
	this->_double = 0;
	this->_float = 0;
}

ScalarConverter::~ScalarConverter(void) {
}

ScalarConverter::ScalarConverter(const ScalarConverter &sc) {
	*this = sc;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &sc) {
	this->input = sc.input;
	this->_char = sc._char;
	this->_double = sc._double;
	this->_float = sc._float;
	this->_int = sc._int;
    this->nothing = sc.nothing;
	return (*this);
}

ScalarConverter::ScalarConverter(const std::string input_convert) {
	input = input_convert;
	nothing = false;
	char check;

	check = this->checkInputType();
	if (check == 'c') {
		this->convert(_char);
	}
	if (check == 'i') {
		this->convert(_int);
	}
	if (check == 'f') {
		this->convert(_float);
	}
	if (check == 'd') {
		this->convert(_double);
	}
	if (check == 0) {
		this->convertNothing();
		return ;
	}
}

char ScalarConverter::checkInputType(void) {
	char *check;

    // se for um char
	if (this->input.length() == 1 && std::isalpha(this->input[0])) {
		this->_char = this->input[0];
		return ('c');
	}
    // se for um long int é tratado como int
	strtol(this->input.c_str(), &check, 10);
	if (*check == '\0') { 
		this->_int = static_cast<int>(strtol(this->input.c_str(), NULL, 10));  // A função strtol é usada 
        // para converter a string this->input em um número de ponto flutuante (double). O resultado da 
        // conversão é armazenado na variável check, que também é um ponteiro para o próximo caractere após 
        // a conversão. O terceiro argumento 10 indica que a conversão deve ser feita na base decimal.
		return ('i');
	}
    // se for int
	strtod(this->input.c_str(), &check);
	if (*check == '\0') {
		this->_double = strtod(this->input.c_str(), &check);
		return ('d');
	}
    // se for float
	strtof(this->input.c_str(), &check);
	if (*check == 'f' && *(check + 1) == '\0') {
		this->_float = strtof(this->input.c_str(), &check);
		return ('f');
	}
	return (0);
}

// convertemos a entrada nos três outros tipos
void ScalarConverter::convert(const char value){
	_int = static_cast<int>(value);
	_double = static_cast<double>(value);
	_float = static_cast<float>(value);
}

// convertemos a entrada nos três outros tipos
void ScalarConverter::convert(const int value) {
	_char = static_cast<char>(value); // static_cast<___> para converter explicitamente um tipo em outro
	_float = static_cast<float>(value); // static_cast<___> para converter explicitamente um tipo em outro
	_double = static_cast<double>(value); // static_cast<___> para converter explicitamente um tipo em outro
}

// convertemos a entrada nos três outros tipos
void ScalarConverter::convert(const float value) {
	_char = static_cast<char>(value); // static_cast<___> para converter explicitamente um tipo em outro
	_int = static_cast<int>(value); // static_cast<___> para converter explicitamente um tipo em outro
	_double = static_cast<double>(value); // static_cast<___> para converter explicitamente um tipo em outro
}

// convertemos a entrada nos três outros tipos
void ScalarConverter::convert(const double value){
	_char = static_cast<char>(value); // static_cast<___> para converter explicitamente um tipo em outro
	_int = static_cast<int>(value); // static_cast<___> para converter explicitamente um tipo em outro
	_float = static_cast<float>(value); // static_cast<___> para converter explicitamente um tipo em outro
	
}

void ScalarConverter::convertNothing(void) {
	char *check;

	_char = 0;
	_int = 0;
	_float = strtof(input.c_str(), &check);
	_double = strtod(input.c_str(), &check);
	if (*check != '\0') {
        nothing = true;
	}
}

void ScalarConverter::printConversion(void) {
    if (nothing){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
    else{
        if (_int > 32 && _int < 127)
            std::cout << "char: " << this->_char << std::endl;
        else if ((std::isinf(_double) || std::isnan(_double)))
            std::cout << "char: impossible" << std::endl;
        else
            std::cout << "char: non displayable" << std::endl;
        if (_double < -2147483648 && _double > 2147483647)
            std::cout << "int: impossible" << std::endl;
        else if ((std::isinf(_double) || std::isnan(_double)))
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << this->_int << std::endl;
        float f = this->_float;
        if (f - _int != 0)
            std::cout << "float: " << this->_float << "f" <<std::endl;
        else
            std::cout << "float: " << this->_float << ".0f" <<std::endl;
        double d = this->_double;
        if (d - _int != 0)
            std::cout << "double: " << this->_double << std::endl;
        else
            std::cout << "double: " << this->_double << ".0" << std::endl;
    }

}

const char *ScalarConverter::NotConvertible::what() const throw() { 
    return ("Invalid format or can't be converted."); 
}
