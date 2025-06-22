#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

#include "tipos.h"
#include "dicio.h"

#define TAMANHO 7

TabelaHash* criar_tabela(int tamanho){

    TabelaHash *tabela = (TabelaHash*) malloc(sizeof(TabelaHash));
    tabela->tamanho = tamanho;
    tabela->contador = 0;
    tabela->itens = (Item **) calloc(tabela->tamanho, sizeof(Item*));

    for (int i = 0; i < tabela->tamanho; i++)
        tabela->itens[i] = NULL;

    return tabela;
        
}

void inserir(TabelaHash *tabela, int chave){

    bool par, trinca, quadra;
    par = trinca = quadra = false;

    unsigned int indice = chave;

    if (tabela->itens[indice] == NULL){

        Item *novo_item = malloc(sizeof(Item));
        novo_item->chave = chave;
        novo_item->frequencia = 1;
        tabela->itens[indice] = novo_item;
        
    } else {
        if (tabela->itens[indice]->chave == chave){
            tabela->itens[indice]->frequencia++;

            switch(tabela->itens[indice]->frequencia){
                case 2: par = true; break;
                case 3: trinca = true; break;
                case 4: quadra = true; break;
                default: break;
            }
        }
    }
}

Item *buscar(TabelaHash *tabela, int chave) {
    unsigned int indice = chave;

    if (tabela->itens[indice] != NULL &&
        tabela->itens[indice]->chave == chave) {
        return tabela->itens[indice];
    }

    // Não encontrado (ou colisão inesperada)
    return NULL;
}