#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "cabecalho.h"


/// @brief Escreve o cabeçalho no arquivo
/// @param f ponteiro para o arquivo
/// @param c cabeçalho a ser escrito

void escreveCabecalho(FILE *f, cabecalho c){
    //posiciona o ponteiro do arquivo no inicio
    fseek(f, 0, SEEK_SET);
    //escreve o cabecalho
    fwrite(&c, 1, sizeof(cabecalho), f);

}

/// @brief Le o cabeçalho do arquivo
/// @param f ponteiro do arquivo
/// @param c cabeçalho a receber a leitura
void leCabecalho(FILE *f, cabecalho *c){
    
    fseek(f, 0, SEEK_SET);

    fread(c, 1, sizeof(cabecalho), f);
}