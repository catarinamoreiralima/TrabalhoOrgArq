#include <stdio.h>
#include <string.h>
#include "registros.h"
#include "lecsv.h"
#include "cabecalho.h"
#include "funcionalidades.h"
#include "binario.h"

/// @brief Abre um arquivo binario no modo de escrita
/// @param f ponteiro pro arquivo
/// @param nome nome do arquivo
/// @return 
int abreArquivoEscritaBinario(FILE **f, char *nome){
    *f = fopen(nome, "wb");
    if (f!=NULL){
        printf("abri o arquivo binario");
        return 1;
    }

    printf("DEU RUIM NO BINARIO");
    return 0;
}