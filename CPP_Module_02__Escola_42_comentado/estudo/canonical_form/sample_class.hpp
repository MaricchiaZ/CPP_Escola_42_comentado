/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample_class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:49:28 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/03 21:12:59 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

#include <iostream>

class Sample{
    
public:
    Sample(void); // FORMA CANONICA
    Sample(int const n);
    Sample(Sample const & src); // FORMA CANONICA
    ~Sample(void); // FORMA CANONICA

    Sample & operator=(Sample const & rhs); // FORMA CANONICA
    
    int getFoo(void) const;

private:
    int _foo;
};

std::ostream & operator<<(std::ostream & o, Sample const & rhs);

#endif