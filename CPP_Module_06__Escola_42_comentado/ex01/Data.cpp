/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:14:12 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/07 14:33:17 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

std::string	Data::_data = "\0";

Data::Data(void){  
}

Data::~Data(void) {
}

Data::Data(const Data& other){
    this->_data = other.getData();
}

Data & Data::operator=(const Data& other)
{
	this->_data = other._data;
	return *this;
}

Data::Data(std::string data_string){
    _data = data_string;
}

std::string Data::getData(void){ 
    return _data;
}

std::ostream & operator<<(std::ostream& os, const Data& _data)
{
	os << "Data( " << "data_string= " << _data.getData() << ")"<< std::endl;
	return os;
}
