#ifndef TIPOS_H
#define TIPOS_H

#define MAX 120

typedef struct{

    int id, naipe, valor;

} CARTA;

typedef struct{

    char nome[MAX];
    int id, banca, aposta;

    CARTA mao[2];

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

#endif