#ifndef SEQUENCIAS_H
#define SEQUENCIAS_H

#include <stdbool.h>
#include "tipos.h"

FREQ_COUNTER frequency_counter(CARTA *cartas_jogador, CARTA *cartas_mesa);
int verificar_sequencia(CARTA *cartas_jogador, CARTA *mesa_cartas);
void melhor_sequencia(FREQ_COUNTER *freq);

int dupla(FREQ_COUNTER *freq);
int trinca(FREQ_COUNTER *freq);
int quadra(FREQ_COUNTER *freq);

#endif