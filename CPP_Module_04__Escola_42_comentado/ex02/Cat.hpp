/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:29:32 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/27 07:47:42 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

# include <string>
# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {

public:

    Cat(void);
    ~Cat(void);
    Cat(Cat const &src);
    Cat& operator=(Cat const &src);

    void makeSound(void) const;
    Brain *getBrain(void) const;

private:

    Brain* brain;
};

#endif
