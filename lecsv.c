#include <stdio.h>
#include <string.h>
#include "registros.h"
#include "lecsv.h"

/// @brief Pula  leitura de "id", "idade", "nomeJogador", "nacionalidade" e "nomeClube" do csv
/// @param f Ponteiro do arquivo csv
static void pulaTitulos(FILE *f){
    char buffer[100];
    fread(buffer, sizeof(char), 45, f);
}

/// @brief abre arquivo csv para leitura
/// @param f Ponteiro do arquivo csv    
/// @param nomeArq Nome do arquivo csv
/// @return retorna endereco do arquvivo aberto para leitura 
FILE *AbreArqCSV (FILE **f, char *nomeArq){

    *f = fopen(nomeArq, "r");

    if(*f == NULL){
        printf("Erro na leitura do arquivo %s", nomeArq);
        return NULL;
    }
    return *f; 
}

static void atribuiStr(int *tamNomeX, char **nomeX, char *buffer){
    printf("BUFFER DA VEZ: %s\n", buffer);
    (*tamNomeX) = strlen(buffer);
    (*nomeX) = (char *)malloc((*tamNomeX)*sizeof(char));
    strcpy((*nomeX), buffer);
}

/// @brief Verifica se há um registrador a ser lido, se sim, lê e armazena em cada respectivo campo
/// @param f Ponteiro para arquivo csv
/// @param r Struct que contem cada campo do registro
/// @return Retorna se existe um registrador a ser lido 
int leRegistroCSV(FILE *f, registro *r){

    char buffer[50];

    pulaTitulos(f);
    //CONVERTER STRING -> INT!!
    printf("Antes do if\n");
    // se o primeiro campo existir, leia e armazene...
    if(fscanf(f, "%[^,]d", &r->id) != 0){ 
        printf("ID: %d\n", r->id);

        // idade 
        fscanf(f, "%[^,]d", &r->idade);
        printf("IDADE: %d\n", r->idade);

        // nomeJogador e tamanho
        fscanf(f, "%[^,]s", buffer);
        atribuiStr(&r->tamNomeJog, &r->nomeJogador, buffer);
        printf("NOME JOGADOR: %s\n TAM DO NOME: %d\n", r->nomeJogador, r->tamNomeJog);
        
        // nacionalidade e tamanho
        fscanf(f, "%[^,\n]", buffer);
        atribuiStr(&r->tamNacionalidade, &r->nacionalidade, buffer);
        printf("NACIONALIDADE: %s\n TAM da NACIONALIDADE: %d", r->nacionalidade, r->tamNacionalidade);

        // nomeClube e tamanho
        fscanf(f, "%[^,\n]s", buffer);
        atribuiStr(&r->tamNomeClube, &r->nomeClube, buffer);
        printf("CLUBE: %s\n TAM do CLUBE: %d", r->nomeClube, r->tamNomeClube);

        //calcula tamanho do registro
        r->tamanhoRegistro = TAM_FIXO + 
        r->tamNomeJog + r->tamNomeClube + r->tamNomeClube;

        return 1; //registro lido e armazenado; existente
    }
    return 0; //nao ha registro
}
