/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:14:18 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/07 14:14:24 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <cstdlib>
# include <string>
# include <cmath>
# include <climits>
# include <limits>

class ScalarConverter {
    
public:

    ScalarConverter(const std::string input_convert);
    ~ScalarConverter(void);
    // confere o input passado
    char checkInputType(void);

// As funções estáticas não agem sobre o objeto, mas agem sobre a classe.
// As funções-membro estáticas não estão vinculadas a nenhum objeto, ou seja, não possuem um this->ponteiro. 
// Como resultado, não podemos nos referir ao thisinterior do corpo de uma função de membro estática. Essa 
// restrição se aplica tanto a usos explícitos this quanto a usos implícitos this chamando um membro não estático .
	static void convert(const char value);
	static void convert(const int value);
	static void convert(const float value);
	static void convert(const double value);
    static void convertNothing(void);
    
    // print results
	void printError(std::string const& type, std::string msg);
	void printConversion(void);

	class NotConvertible : public std::exception  // classe aninhada
	{
        public:
            virtual const char *what() const throw();
	};
    
private:

    ScalarConverter(void);
    ScalarConverter(const ScalarConverter &sc);
    ScalarConverter &operator=(const ScalarConverter &sc);

    static std::string input;
    static char _char;
    static int _int;
    static float _float;
    static double _double;
    static bool nothing;
};

#endif
