/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:53:16 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/27 07:12:19 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public:
    WrongCat(void);
    ~WrongCat(void);
    WrongCat(const WrongCat &a);
    WrongCat &operator=(const WrongCat &a);

    void makeSound(void) const;
};

#endif
