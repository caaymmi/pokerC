#ifndef DICIO_H
#define DICIO_H

#include "tipos.h"

typedef struct{

    int chave;
    int frequencia;

}Item;

typedef struct{

    Item **itens;
    int tamanho;
    int contador;

}TabelaHash;

TabelaHash* criar_tabela(int tamanho);

void inserir(TabelaHash *tabela, int chave);

Item *buscar(TabelaHash *tabela, int chave);

#endif