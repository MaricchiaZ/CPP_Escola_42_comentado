/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:58:35 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/28 08:58:45 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

# include <string>
# include "ICharacter.hpp"

class ICharacter; //  é uma declaração antecipada (forward declaration) da classe ICharacter. 
// Isso significa que você está informando ao compilador que a classe ICharacter existe, mas ainda 
// não está definida no momento.

/*      ESSA DECLARAÇÃO SERVE COMO INTERFACE e EVITA DEPENDÊNCIAS CIRCULARES

Interface de uso: A declaração antecipada fornece uma interface de uso da classe ICharacter sem expor os detalhes 
internos de sua implementação. Isso pode ser útil se você estiver criando uma biblioteca ou uma API em que deseja 
limitar o acesso aos detalhes internos das classes.

Resolução de dependências circulares: Suponha que a classe ICharacter também dependa da classe AMateria. 
Se você incluir o cabeçalho completo de ICharacter.hpp em AMateria.hpp, e também incluir AMateria.hpp em 
ICharacter.hpp, haverá uma dependência circular, o que pode causar problemas de compilação. Usando uma 
declaração antecipada, você evita essa dependência circular.

*/

class AMateria {
    
public:
    AMateria();
    virtual ~AMateria(void);
    AMateria(AMateria const &src);
    AMateria & operator=(AMateria const &src);
    
    AMateria(std::string const &type);

    std::string const & getType()const; // Returns the materia type
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);

protected:
    std::string type; 
};

#endif
