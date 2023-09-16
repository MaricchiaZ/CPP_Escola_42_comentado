/* **************************************************************************** */
/*                                                                              */
/*                                                          :::      ::::::::   */
/*   notes.cpp                                            :+:      :+:    :+:   */
/*                                                      +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                  +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:42:56 by maclara-            #+#    #+#             */
/*   Updated: 2023/07/18 12:49:22 by maclara-           ###   ########.fr       */
/*                                                                              */
/* **************************************************************************** */

//------------------+---------+----------+----------+-------------+--------------//
//      Cast        |  Conv.  |  Reint.  |  Upcast  |  Downcast   |  Type qual.  //  
//------------------+---------+----------+----------+-------------+--------------//
// Implicit         |   YES   |          |   YES    |             |              //
// static_cast      |   YES   |          |   YES    |     YES     |              //
// dynamyc_cast     |         |          |   YES    |     YES     |              //
// const_cast       |         |          |          |             |    YES       //
// reinterpret_cast |         |   YES    |   YES    |     YES     |              //
//------------------+---------+----------+----------+-------------+--------------//
// Legacy C const   |   YES   |   YES    |   YES    |     YES     |    YES       //  
//------------------+---------+----------+----------+-------------+--------------//


//------------------+--------------------+--------------------+------------------//
//      Cast        |   Semantic check   |   Reliable at run  |  Tested at run   //  
//------------------+--------------------+--------------------+------------------//
// Implicit         |        YES         |         YES        |                  //
// static_cast      |        YES         |                    |                  //
// dynamyc_cast     |        YES         |         YES        |                  //
// const_cast       |                    |                    |      YES         //
// reinterpret_cast |                    |                    |                  //
//------------------+--------------------+--------------------+--- --------------//
// Legacy C const   |                    |                    |                  //  
//------------------+--------------------+--------------------+---+--------------//

Essas tabelas representam informações sobre diferentes tipos de casts em C++. Vamos explicar cada uma delas:

Na primeira tabela:
- Cast: Indica o tipo de cast.
- Conv.: Conversão implícita é permitida? Se "YES", indica que a conversão implícita é permitida; se estiver vazio, indica que a conversão implícita não é permitida.
- Reint.: Reinterpretação de tipo é permitida? Se "YES", indica que a reinterpretação de tipo é permitida; se estiver vazio, indica que a reinterpretação de tipo não é permitida.
- Upcast: Upcasting é permitido? Se "YES", indica que o upcasting é permitido; se estiver vazio, indica que o upcasting não é permitido.
- Downcast: Downcasting é permitido? Se "YES", indica que o downcasting é permitido; se estiver vazio, indica que o downcasting não é permitido.
- Type qual.: Cast com modificação de qualificador de tipo é permitido? Se "YES", indica que o cast com modificação de qualificador de tipo é permitido; se estiver vazio, indica que não é permitido.

Na segunda tabela:
- Cast: Indica o tipo de cast.
- Semantic check: Realiza verificação semântica? Se "YES", indica que o cast realiza verificação semântica; se estiver vazio, indica que não realiza verificação semântica.
- Reliable at run: É confiável em tempo de execução? Se "YES", indica que o cast é confiável em tempo de execução; se estiver vazio, indica que não é confiável em tempo de execução.
- Tested at run: Testado em tempo de execução? Se "YES", indica que o cast é testado em tempo de execução; se estiver vazio, indica que não é testado em tempo de execução.

Essas tabelas fornecem informações sobre as características e o comportamento dos diferentes tipos de casts em 
C++. Elas podem ajudar a entender as restrições e recursos de cada tipo de cast, bem como orientar na escolha adequada do cast para uma determinada situação.