
#include "sample_class.hpp"

int main (){

    Sample instance; // aqui instanciamos (declaramos e inicializamos) um OBJETO da classe Sample usando o 
    //construtor padrão Sample::Sample(). Isso cria uma instância do objeto Sample chamada instance.
    
    //Quando a instância é criada, o construtor da classe Sample é automaticamente chamado, executando o 
    // código que você definiu dentro dele. Nesse caso, o construtor exibirá a 
    //  "Constructor called" usando a função std::cout.
    return 0;
}

// g++ -Wall -Wextra -Wno-used -Werror sample_class.cpp sample_class_main.cpp 

/* OUTPUT
~/Trabalhos/MC_42/CPP_00__Escola_42/estudo_classes ❯ ./a.out

Constructor called
Destructor called

*/