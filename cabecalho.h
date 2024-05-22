#ifndef CABECALHO_H
#define CABECALHO_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct{
    char status;
    long topo;
    long proxByteOffset;
    int nroRegArq;
    int nroRegRem;
}cabecalho;


void escreveCabecalho(FILE *f, cabecalho c);
void leCabecalho(FILE *f, cabecalho *c);







#endif