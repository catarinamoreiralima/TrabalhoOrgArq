#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#ifndef REGISTROS_H
#define REGISTROS_H


/// @brief Define a struct para o registro de acordo com as especificações
typedef struct{
    char removido;
    int tamanhoRegistro;
    long Prox;
    int id;
    int idade;
    int tamNomeJog;
    char *nomeJogador;
    int tamNacionalidade;
    char *nacionalidade;
    int tamNomeClube;
    char *nomeClube;
}registro;

//prototipagem das funções
void escreveRegistroArquivo(FILE *f, registro r);
int leRegistroArquivo(FILE *f, registro *r);


#endif