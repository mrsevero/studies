/*
Trabalho Feito Por:

Bruno Severo Camilo			TIA: 41781619
João Pedro Colafati Pedroso	TIA: 31819656
Matheus Soares Santos	  	TIA: 31895263
Wanderson Lima	  			TIA: 31895591
*/
#include <stdio.h>
#include <stdlib.h>
/* 	Função Scanner que reconhece numeros inteiros ou ponto flutuantes        
	String é a palavra a ser lida
	i é o contador da posição da palavra       */

int scanner(char *string, int *i){ 

  q0:	/* Q0 é o estado inicial do automato */
    (*i)++; /* incrementar o contador da string */
    if(string[*i] >= 48 && string[*i] <= 57) goto q1; /* Verificar se é numero na tabela ASCII*/
    else if(string[*i] == 43) goto q4; /* compara com o simbolo + da tabela ASCII */
    else if(string[*i] == 45) goto q4; /* compara com o simbolo - da tabela ASCII*/
    else if(string[*i] == 46) goto q5; /* compara com o simbolo . da tabela ASCII*/
    else if((string[*i] >= 65 && string[*i] <= 90) || (string[*i] >= 97 && string[*i] <= 122)) goto q5; /* Verificar se é caracter na tabela ASCII*/
    else if(string[*i] == 0 || string[*i] == ' ') return 3; /* ERRO            */ 

  q1:  /* Q1 Estado de numero inteiros e estado final */
    (*i)++;/* incrementar o contador da string */
    if(string[*i] >= 48 && string[*i] <= 57) goto q1 ;
    else if(string[*i] == 43) goto q5;	/* compara com o simbolo + da tabela ASCII */
    else if(string[*i] == 45) goto q5;	/* compara com o simbolo - da tabela ASCII*/
    else if(string[*i] == 46) goto q2;	/* compara com o simbolo . da tabela ASCII*/
    else if((string[*i] >= 65 && string[*i] <= 90) || (string[*i] >= 97 && string[*i] <= 122)) goto q5;/* Verificar se é caracter na tabela ASCII*/
    else if(string[*i] == 0 || string[*i] == ' ') return 2;  /* INTEIRO            */   

  q2:/* Q2 Estado de erro */
    (*i)++;/* incrementar o contador da string */
    if(string[*i] >= 48 && string[*i] <= 57) goto q3;
    else if(string[*i] == 43) goto q5;	/* compara com o simbolo + da tabela ASCII */
    else if(string[*i] == 45) goto q5;	/* compara com o simbolo - da tabela ASCII*/
    else if(string[*i] == 46) goto q5;	/* compara com o simbolo . da tabela ASCII*/
    else if((string[*i] >= 65 && string[*i] <= 90) || (string[*i] >= 97 && string[*i] <= 122)) goto q5;/* Verificar se é caracter na tabela ASCII*/
    else if(string[*i] == 0 || string[*i] == ' ') return 3;	/* ERRO            */ 

  q3:/* Q3 Estado de numero flutuantes e estado final */
    (*i)++;/* incrementar o contador da string */
    if(string[*i] >= 48 && string[*i] <= 57) goto q3;
    else if(string[*i] == 43) goto q5;	/* compara com o simbolo + da tabela ASCII */
    else if(string[*i] == 45) goto q5;	/* compara com o simbolo - da tabela ASCII*/
    else if(string[*i] == 46) goto q5;	/* compara com o simbolo . da tabela ASCII*/
    else if((string[*i] >= 65 && string[*i] <= 90) || (string[*i] >= 97 && string[*i] <= 122)) goto q5;/* Verificar se é caracter na tabela ASCII*/
    else if(string[*i] == 0 || string[*i] == ' ') return 1; /* PONTO FLUTUANTE            */ 

  q4:/* Q4 Estado de erro */
    (*i)++;/* incrementar o contador da string */
    if(string[*i] >= 48 && string[*i] <= 57) goto q1;
    else if(string[*i] == 43) goto q5;	/* compara com o simbolo + da tabela ASCII */
    else if(string[*i] == 45) goto q5;	/* compara com o simbolo - da tabela ASCII*/
    else if(string[*i] == 46) goto q5;	/* compara com o simbolo . da tabela ASCII*/
    else if((string[*i] >= 65 && string[*i] <= 90) || (string[*i] >= 97 && string[*i] <= 122)) goto q5;/* Verificar se é caracter na tabela ASCII*/
    else if(string[*i] == 0 || string[*i] == ' ') return 3; /* ERRO            */ 

  q5: /* Q5 Estado de erro*/
    (*i)++;/* incrementar o contador da string */
    if(string[*i] >= 48 && string[*i] <= 57) goto q5;
    else if(string[*i] == 43) goto q5;	/* compara com o simbolo + da tabela ASCII */
    else if(string[*i] == 45) goto q5;	/* compara com o simbolo - da tabela ASCII*/
    else if(string[*i] == 46) goto q5;	/* compara com o simbolo . da tabela ASCII*/
    else if((string[*i] >= 65 && string[*i] <= 90) || (string[*i] >= 97 && string[*i] <= 122)) goto q5;/* Verificar se é caracter na tabela ASCII*/
    else if(string[*i] == 0 || string[*i] == ' ') return 3;  /* ERRO            */  
}

int main(void) {
  char *input = "-21 +45.67 0.123 23.456 42 ..5"; /* input de teste de automato*/
  int i = -1; /* Indice da palavra             */

  do {
    int result = scanner(input, &i);

    switch(result) {
      case 1:
        printf("<P.FLUTUANTE>\n");
        break;

      case 2:
        printf("<INTEIRO>\n");
        break;

      case 3:
        printf("<ERRO>\n");
        break;

    }
  } while (input[i] != 0);
}
