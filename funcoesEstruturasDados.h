#ifndef FUNCOES_ESTRUTURAS_DADOS_H
#define FUNCOES_ESTRUTURAS_DADOS_H

#include "tipos.h"

void inicializar_lista(LISTA* lista);

void inserir_jogador_lista(LISTA* lista, JOGADOR novo_jogador);

bool excluir_jogador_lista(LISTA* lista, int id_jogador);

void inicializar_pilha(PILHA* pilha);

void inserir_carta_pilha(PILHA* pilha, CARTA nova_carta);

CARTA retirar_carta_pilha(PILHA* pilha);

#endif
