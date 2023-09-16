/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:52:52 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/27 07:12:09 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_H
#define WRONG_ANIMAL_H

# include <string>
# include <iostream>

class WrongAnimal {

public:

    WrongAnimal(void);
    ~WrongAnimal(void); // não é virtual, então não é polimórfico
    WrongAnimal(WrongAnimal const &src);
    WrongAnimal & operator=(WrongAnimal const &src);

    WrongAnimal(std::string type);

    void setType(std::string type);
    std::string	getType(void) const;
    void	makeSound(void) const; // não é virtual, então não é polimórfico

protected:

    std::string	type;
};

#endif
