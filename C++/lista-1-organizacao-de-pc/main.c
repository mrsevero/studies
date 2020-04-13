/*
1 - ALU - OPERAÇÕES LOGICAS E ARITIMETICAS
    PC - ENDEREÇO DA PROX INSTRUÇÃO
    IR - ENDEREÇO DA INSTRUÇÃO ATUAL
    MAR - REGISTRADOR DE ENDEREÇO
    MDR - REGISTRADOR DE DADOS E INSTRUÇÕES
    CU - UNIDADE DE CONTROLE (GERENCIA AS INSTRUÇÕES QUE CHEGAM NO BARRAMENTO) BUSCA / DECODIFICA /EXECUTA
    ACUMULADOR - RECEBE O RESULTADO DA ULA
    REGISTRADOR GENERICO - 


2 - ANTES DE EXECUTAR A PROXIMA INSTRUÇÃO ELE VERIFICA SE HOUVE INTERRUPÇÃO E CASO TEM OCORRIDO ELE TRABALHA EM CIMA DISSO, TOMANDO DECIÇÃO DE ARRUMAR OU PARAR

3 - ULA - TRABALHA COM NUMERO INTEIROS E A FPU TRABALHA COM FLOATING AMBAS TEM O MESMO PROPÓSITO

4 - INTERRUPÇÃO É UMA FERRAMENTA DE CONTROLE DE CICLOS DE OPERAÇÃO DO COMPUTADOR PARA TOMAR DECISÕES APARTAR DO ERRO E NAO AFETAR O PROCESSAMENTO AO TOMANDO. NAO GRAVAR COISAS ERRADA E TENTAR SOLUCIONAR ERROS PREVISTOS.

5 - PC - GUARDAR O ENDEREÇO DA PROXIMA INSTRUÇÃO DO PROGRAMA
    IR - GUARDAR O ENDEREÇO DA INSTRUÇÃO ATUAL DO PROGRAMA  
    FLAG - INDICA O STAUTS DO PROCESSO COM UMA FLAG DE OCORRENCIA (SINAL/ZERO/VAI UM)
    MAR - REGISTRADOR DE ENDEREÇO DA MEMORIA PRINCIPALE
    MBR - REGISTRADOR DE DADOS E INSTRUÇÕES DA MEMORIA

6 - FLAGS

SINAL - POS OU NEGATIVO
ZERO - INDICA SE É DIVISÃO POR ZERO
VAI-UM - VAI UM NA MATEMATICA
IGUAL - INDICA IGUALDADE
OVERFLOW - INDICA QUE EXECEDEU O LIMITE DE REPRESENTAÇÃO DE NUMERO FAMOSO TRANSBORDAMENTO
HABILITAR / DESABILITAR INTERRUPÇÕES - HABILITA OU DESABILITA INTERRUPÇÕES EM CADA CICLOS


7 - $ZERO INDICA ZERO
    $AT - REGISTRADOR RESERVADO PARA ASSEMBLER
    $V0,$V1 - VALORES DE RETORNO
    $A0,$A3 - ARGUMENTO DE FUNÇÃO
    $T0, $T7 - TEMP
    $S0 A $S7 - REGISTRADOR SALVO
    $K0, $K1 - KERNEL
    $GP - GLOBAL POINTER
    $SP - STACK POINTER(PILHA)
    $FB - FRAME POINTER
    $RA - RETURN ADRESS 


8 - TECNICA IMPLEMENTADA EM HARDWARE COM OBJETIVO DE PARALELIZAR VARIAS INSTRUÇÕES BASEADO NO MODELO FORD DE PRODUÇÃO

9 - 14 - ESTAGIOS

10 - 10 + 25000 - 1    25009 - 3.10^9  - 1SEG

                                25009 /3 Ns



11 - busca antecipada das proximas instruções que voce guarda no cache pra nao precisar ficar indo na memória PRINCIPALE

12  - 

4.10^9 - 1seg
x      - 1.10^-9  = 4 instruçoes por nano segundo

13 - 5 + 10 + 15 + 18 + 16 = 64ns cada CICLOS

5    - 64ns * 10^-9
x    - 1s
x  - 1.10^-9

5 = x.64*10^-9

5/64 = 0,078 * 10^9 anda 3 casas = 78ghz

14 - 25 + 14 + 5 + 17 + 26 = 87ns

5  - 87ns
x  - 1

5 = x.87.10^-9
 = 0,057 * 10^9 = 57mhz




15) porque nao precisa ficar buscando na memoria PRINCIPALE

16) varios nucleos de processamento que podem dividir as tarefas e/ou executar tarefas diferentes.

17) obvio demais

18) cpuz

19) APU - é um tipo de processador que mistura CPU e GPU  lidando com taferas comundo e tarefas graficas. A maioria dos processadores atuais são APU com a vinda dos processadores grapichs executar

20) comparar processadores

21) porque ela é  o segundo material mais abundante no planeta, temperatura de fusão alto
cobre, ouro e grafeno etc
 limite fisico
 procurar outros materiais
 computação quantica

22) 
cobre ouro grafeno

23) permite ver todo os ciclos de um programa e como o computador funciona a processar dados.

24) ????

25) li $s1, 3
    li $s2, 4
    li $s3, 4

    li $s3, $s1

    slt $t0,$s2, $s3
    bne $t0, ZERO
    li $s3, $s2

    




*/