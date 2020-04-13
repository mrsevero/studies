/*

1)A- memória interna do processador que visa guardar dados ou instruções afim de evitar acesso a memoria principal

  B- Como ela é interna ao processador ela evita que o processador precise procurar dados diretamente na memoria principal o que evita acessos desnecessario. O que deixa muito mais rapido o processos, visto que 

  C- Em 3 niveis, primeiro nivel dados/instrução, separadamente para cada core. segundo nivel generico para cada core tbm e terceiro nivel compartilhado por todos os cores.

  D- Direto - cada bloco da memoria principal é alocada em uma linha do cache e carrega 3 informacoes tag indice e endereço

     Associativo - cada bloco tem uma tag e pode ser alocado em qualquer lugar do cache a consulta é feita atraves da tag

     conjunto - o cache é sub dividido em conjuntos em que o bloco pode estar ou nao dentro do conjunto K


2) 16*50 + 2*1024 *0,30 + 256 * 1,5 = 

3) SRAM = SOLID RANDOM ACESS MEMORY = NAO PRECISA DE CONSTANTE ATUALIZAÇÃO NA MEMORIA ENTÃO GASTA MENOS ENERGIA
   
   DRAM = DINAMIC RANDOM ACESS MEMORY = PRECISA SER CONTANTEMENTE ATUALIZADA COM CORRENTE PARA NAO PERDER OS DADOS, GASTA MAIS ENERGIA

   HOJE É DRAM DDR

4) O TAMANHO DO ENDEREÇO MAIOR SIGNIFICA MAIS PALAVRAS DENTRO DELE.


2^16
2^32
2^64

5) 

o tamanho da palavra nao influencia na memória maxima.

6)

SEQUENCIAL acesso feito em sequencia linear 
ex: feita

direto: bloco individuais e registros tem endereço unico
ex HD

aleatório : tempo de acesso CONSTANTE
RANDOM

associativo : posição do dado é baseada em parte do arquivo
cache

8) memória volatio - os dados são matidos apenas quando tem CORRENTE  RAM CACHE REGISTRADOR
nao volartio nao precisa de corrente para manter dados HD PEN DRIVE SSD

9) 8*2^30 = 8.589.934.592

10) BARRAMENTO serve para transferencia de dados e indicação de endereço de memoria de dados e interliga os componentes do computador como memorias in/out etc

11) 64bits = 8bytes * 1800mhz = 14800mb/s

12) tamanho do barramento ou frequencia maxima assim aumentando a quantidade de dados e a velocidade de transferencia

13) A - 4gb

B - 4GB /4KB = 4*2^30/8*2^10  --->  2^19 BLOCOS

C - 8*2^10

14) A - 2^64

B - 2^64/4*2^10  =  2^62*4/4*2^10 = 2^52 BLOCOS

C - 4*2^10

15) NO MINIMO 33 BITS ou 64 visto que estamos na vida real

16) 



*/