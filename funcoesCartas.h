#ifndef FUNCOES_CARTAS_H
#define FUNCOES_CARTAS_H

#include <stdbool.h>
#include "tipos.h"
#include "funcoesEstruturasDados.h"

void inicializar_cartas(CARTA* baralho_novo);
void embaralhar(CARTA *baralho);
void preencher_baralho_cartas(PILHA* baralho, CARTA *cartas);
void exibir_baralho(CARTA *baralho);
void exibir_carta(CARTA carta);

#endif
