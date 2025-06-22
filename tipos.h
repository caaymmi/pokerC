#ifndef TIPOS_H
#define TIPOS_H

#define MAX 120

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct{

    int id, naipe, valor;

} CARTA;

typedef struct conexaoc{

    CARTA carta;
    struct conexaoc* prox;

}ELEMENTOc;

typedef ELEMENTOc* PONTc;

typedef struct{

    PONTc topo;
    int tamanho;

}PILHA;

typedef struct{

    char nome[MAX];
    int id, banca, aposta, ranking;

    CARTA mao[2];
    CARTA sequencia_aux[7];


} JOGADOR;

typedef struct conexaoj{

    JOGADOR jogador;
    struct conexaoj* ant;
    struct conexaoj* prox;

}ELEMENTOj;

typedef ELEMENTOj* PONTj;

typedef struct{

    PONTj inicio;
    PONTj fim;
    int tamanho;

}LISTA;


typedef struct {

    CARTA sequencia_aux[7];
    CARTA melhor_sequencia[5];
    int valores[20];
    int naipes[5];

}FREQ_COUNTER;

#endif