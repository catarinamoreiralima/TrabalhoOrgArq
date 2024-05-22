#ifndef LECSV_H
#define LECSV_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "registros.h"
//"id" "idade" "nomeJogador" "nacionalidade" "nomeClube"
#define TITULOS_CSV 5 

//São 5 campos fixos de tipo int: 
// id, idade, tamNomeJog, tamNacionalidade, tamNomeClube
//+ proximo bit offset (tamanho de ponteiro, long)
#define TAM_FIXO 5*sizeof(int) + sizeof(long)


FILE *AbreArqCSV (FILE **f, char *nomeArq);
int leRegistroCSV (FILE *f, registro *r);


#endif