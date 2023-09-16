/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:46:23 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/18 10:12:56 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(void){
    
    float a = 420.042f; // valor de referencia

    void * b = &a; //✔️  IMPLÍCITO cast de promoção

    int * c = reinterpret_cast<int *>(b); //✔️  EXPLÍCITO cast de demoção por reinterpretação
    // Isso reinterpretará o ponteiro b como um ponteiro para int. 
    // Essa conversão permite tratar o valor apontado como um int, mesmo que originalmente fosse um float. 
    // ⚠️ No entanto, tenha em mente que isso é uma interpretação direta da representação de memória e pode 
    // levar a comportamentos indefinidos se você acessar e usar os valores de forma inadequada.

    
    int & d = reinterpret_cast<int &>(b); //✔️  EXPLÍCITO cast de demoção por reinterpretação
    // Isso reinterpretará o ponteiro b como uma referência para int. 
    // Novamente, isso é uma interpretação direta da representação de memória e pode levar a 
    // comportamentos indefinidos se você acessar e usar os valores de forma inadequada. 
    // O uso de uma referência aqui permite tratar o valor como um int de maneira mais conveniente, 
    // como se fosse uma variável int normal.

    // ⚠️É importante ressaltar que a utilização do reinterpret_cast dessa forma, reinterpretando tipos
    //  de forma não relacionada, é considerada uma prática arriscada e geralmente não é recomendada, a
    //  menos que você tenha uma necessidade específica e esteja ciente das implicações. Sempre leve
    //  em consideração as regras de tipo e as limitações da conversão reinterpret_cast.

    return (0);
}