/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:42:04 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/27 07:38:55 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

# include <string>
# include <iostream>


class Animal {

public:

    Animal(void);
    virtual ~Animal(void); // É o destrutor virtual da classe Animal. Ele é declarado como virtual para permitir a 
    // destruição correta dos objetos de subclasses quando eles são manipulados por meio de ponteiros para a 
    // classe base.
    Animal(Animal const &src);
    Animal&	operator=(Animal const &src);

    Animal(std::string type);
    
    void setType(std::string type);
    std::string	getType(void) const;

    virtual void	makeSound(void) const; //  indica que a função makeSound é virtual, ou seja, pode ser substituída
    // em classes derivadas, mas não é uma função abstrata. Ela tem uma implementação padrão e pode ser chamada 
    // diretamente na classe base.

protected:

    std::string	type;

};

#endif
