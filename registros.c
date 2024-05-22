#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "registros.h"
#include "lecsv.h"


/// @brief Escreve um registro em um arquivo binário
/// @param f Ponteiro para arquivo
/// @param r Registro a ser escrito
void escreveRegistroArquivo(FILE *f, registro r){

    //escreve campo a campo
    fwrite(&r.removido, 1, sizeof(char), f);
    fwrite(&r.tamanhoRegistro, 1, sizeof(int), f);
    fwrite(&r.Prox, 1, sizeof(long), f);
    fwrite(&r.id, 1, sizeof(int), f);
    fwrite(&r.idade, 1, sizeof(int), f);
    fwrite(&r.tamNomeJog, 1, sizeof(int), f);
    fwrite(r.nomeJogador, 1, r.tamNomeJog*sizeof(char), f);
    fwrite(&r.tamNacionalidade, 1, sizeof(int), f);
    fwrite(r.nacionalidade, 1, r.tamNacionalidade*sizeof(char), f);
    fwrite(&r.tamNomeClube, 1, sizeof(int), f);
    fwrite(r.nomeClube, 1, r.tamNomeClube*sizeof(char), f);

    //libera ponteiros das strings
    free(r.nomeJogador);
    free(r.nacionalidade);
    free(r.nomeClube);

}

/// @brief Le um registro de um arquivo.
/// @param f Ponteiro do arquivo binário
/// @param r Registro a receber a leitura
/// @return Retorna 1 (true) se consegue ler e 0 (false) se não consegue
int leRegistroArquivo(FILE *f, registro *r){

    //verifica se consegue ler o primeiro byte -> ou seja, se existe registro
    if(fread(&r->removido, 1, sizeof(char), f)>0){

        //le demais campos
        fread(&r->tamanhoRegistro, 1, sizeof(int), f);
        fread(&r->Prox, 1, sizeof(long), f);
        fread(&r->id, 1, sizeof(int), f);
        fread(&r->idade, 1, sizeof(int), f);
        fread(&r->tamNomeJog, 1, sizeof(int), f);
        
        //aloca espaço para a string
        r->nomeJogador = malloc((r->tamNomeJog+1)*sizeof(char));
        fread(r->nomeJogador, 1, r->tamNomeJog*sizeof(char), f);
        //adiciona \0 para utilização em memoria primaria
        r->nomeJogador[r->tamNomeJog] = '\0';

        fread(&r->tamNacionalidade, 1, sizeof(int), f);
        
        r->nacionalidade = malloc((r->tamNacionalidade+1)*sizeof(char));
        fread(r->nacionalidade, 1, r->tamNacionalidade*sizeof(char), f);
        r->nacionalidade[r->tamNacionalidade] = '\0';

        fread(&r->tamNomeClube, 1, sizeof(int), f);

        r->nomeClube = malloc((r->tamNomeClube+1)*sizeof(char));
        fread(r->nomeClube, 1, r->tamNomeClube*sizeof(char), f);
        r->nomeClube[r->tamNomeClube] = '\0';

        r->tamanhoRegistro = (r->tamNacionalidade + r->tamNomeClube + r->tamNomeJog + TAM_FIXO);

        return 1;
    }

    return 0;
}