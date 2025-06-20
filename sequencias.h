#ifndef SEQUENCIAS_H
#define SEQUENCIAS_H

#include <stdbool.h>
#include "tipos.h"

int verificar_sequencia(CARTA *cartas_jogador, CARTA *mesa_cartas);

//Verificar funcionalidade destes com a última implementação feita
//Implementação com dois vetores de frequências, um pra naipe outro pra valores.
bool uma_dupla(int *frequencias_valores);
bool duas_duplas(int *frequencias_valores);
bool trinca(int *frequencias_valores);
bool quadra(int *frequencias_valores);
bool full_house(int *frequencias_valores);
bool flush(int *frequencias_naipes);

//Repensar todos abaixo
bool straight(int *frequencias_valores);
bool straight_flush(int *frequencias_valores, int *frequencias_naipes);
//bool royal_flush(CARTA *cartas);

#endif