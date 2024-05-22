#include <stdio.h>
#include <string.h>
#include "registros.h"
#include "lecsv.h"
#include "cabecalho.h"
#include "funcionalidades.h"
#include "binario.h"


/// @brief Lê um arquivo CSV e escreve seu conteúdo no formato de registros em um arquivo binário
/// @param nomecsv Nome do arquivo csv
/// @param nomebin Nome do arquivo binario 
void func1(char *nomecsv, char *nomebin){
    //declara ponteiros dos arquivos e demais necessarios
    FILE *fcsv;
    FILE *fbin;
    registro r;
    cabecalho c;
    
    //inicializa cabeçalho
    //ver se status ta certo
    c.status = 1;
    c.topo = -1;
    c.proxByteOffset = -1;
    c.nroRegRem = 0;
    c.nroRegArq = 0;
    //Abre o arquivo CSV
    AbreArqCSV(&fcsv, nomecsv);
    //Abre o arquivo binário no modo de escrita
    abreArquivoEscritaBinario(&fbin, nomebin);
    //Enquanto consegue ler um registro, escreve no binário
    while(leRegistroCSV(fcsv, &r)){
        //incrementa numero de registradores
        c.nroRegArq++;
        escreveRegistroArquivo(fbin, r);
        c.proxByteOffset = (SEEK_CUR-SEEK_SET);
    }
    
    c.status = 0;

    escreveCabecalho(fbin, c);

    fclose(fcsv);
    fclose(fbin);

}