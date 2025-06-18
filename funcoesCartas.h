#ifndef FUNCOES_CARTAS_H
#define FUNCOES_CARTAS_H

#include <stdbool.h>
#include "tipos.h"
#include "funcoesEstruturasDados.h"

void inicializar_cartas(CARTA* baralho_novo);
void embaralhar(CARTA *baralho);
void preencher_baralho_cartas(PILHA* baralho, CARTA *cartas);
void exibir_carta(CARTA carta);
void exibir_baralho(PILHA baralho);
void exibir_vetor_cartas(CARTA *baralho);

#endif
