# Ponteiro e Referência (aplicados)

Em relação ao caso apresentado, onde temos as classes HumanA e HumanB, ambos com uma arma, existem algumas considerações a serem feitas sobre o uso de ponteiros e referências para a classe Arma.

1. HumanA sempre estará armado:
    Nesse caso, é mais apropriado usar uma referência para a Arma dentro da classe HumanA. Isso porque uma referência garante que sempre haverá uma instância válida de Arma associada a HumanA. Se HumanA sempre estiver armado, não faz sentido permitir que ele fique sem uma arma. Portanto, uma referência é a melhor escolha.

2. HumanB nem sempre tem uma arma:
    Já no caso de HumanB, onde nem sempre terá uma arma, o uso de um ponteiro para Arma é mais adequado. Um ponteiro pode ser nulo, o que significa que não há uma instância válida de Arma associada a HumanB. Dessa forma, é possível verificar se o ponteiro é nulo antes de acessar os membros da Arma. Isso evita erros e permite lidar com o caso em que HumanB não possui uma arma.

Assim aprendemos que: o uso de referência é mais apropriado quando se espera que um objeto sempre esteja associado a outro objeto. Já o uso de ponteiro é mais adequado quando a associação pode ser opcional ou nula, permitindo verificar sua validade antes de acessá-lo.