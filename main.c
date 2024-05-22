#include<stdio.h>
#include"funcionalidades.h"

int main(){
    //espera-se <comando> <arq.csv> <arq.bin>
    int comando;
    char nomeCSV[50], nomeBin[50];

    scanf("%d %s %s", &comando, nomeCSV, nomeBin);

    switch (comando){
    case 1:
        func1(nomeCSV, nomeBin);
        break;
    case 2:
        // funcionalidade 2
        break;
    case 3:
        // funcionalidade 3
        break;
    default:
        // nada
        break;
    }

    return 0;

}