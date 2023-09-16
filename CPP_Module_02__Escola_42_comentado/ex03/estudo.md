# BSP (Binary Space Partitioning) 

BSP (Binary Space Partitioning) é uma técnica utilizada em computação gráfica e jogos para organizar e subdividir o espaço em regiões (ou partições) de forma hierárquica. Essa técnica é frequentemente aplicada em cenários 3D para acelerar o processo de renderização, especialmente em cenas complexas.

## Como saber se um ponto está dentro de um triagulo?

A função bsp verifica se um ponto está dentro de um triângulo usando a técnica BSP (Binary Space Partitioning). A função recebe quatro parâmetros: três objetos Point que representam os vértices do triângulo (a, b, c) e um objeto Point que representa o ponto a ser verificado. Cada objeto Point possui dois atributos: x e y, que representam as coordenadas do ponto.

A função calcula as áreas de quatro triângulos: 
    - o triângulo formado pelos pontos a, b e c (chamado de área total) e
    - os três triângulos formados pelos pontos a, b e o ponto a ser verificado (chamados de área1, área2 e área3).

Em seguida, a função verifica se a soma das áreas dos três triângulos (área1 + área2 + área3) é igual à área total do triângulo. 
Além disso, verifica se todas as áreas são diferentes de zero. Se todas essas condições forem atendidas, isso significa que o ponto está dentro do triângulo e a função retorna true. 
Caso contrário, o ponto está fora do triângulo e a função retorna false.

Teste:

a(0, 0) b(0, 3) c(3, 0) p(1, 1) -> true

a(0.0f, 0.0f) b(0.0f, 3.0f) c(4.0f, 3.0f) p(100.0f, 200.0f) -> false

a(0.0f, 0.0f) b(0.0f, 3.0f) c(4.0f, 3.0f) p(1.0f, 2.0f) -> true0
