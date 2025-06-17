#ifndef FUNCOES_CARTAS_H
#define FUNCOES_CARTAS_H

#include <stdbool.h>
#include "tipos.h"

void criar_baralho(CARTA* baralho_novo);
void exibir_baralho(CARTA *baralho);
void exibir_carta(CARTA carta);

void embaralhar(CARTA *baralho);

#endif
