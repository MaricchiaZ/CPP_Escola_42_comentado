/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:12:29 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/07 14:33:41 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <stdint.h>
#include <ostream>
#include <string>

class Data
{
public:

	~Data(void);
	Data(std::string data_string);
	static std::string	getData(void);

private:
	Data(void);
	Data(const Data& other);
	Data & operator=(const Data& other);
	
	static std::string	_data;

};

#endif
