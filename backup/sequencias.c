#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "tipos.h"
#include "sequencias.h"
#include "funcoesCartas.h"

FREQ_COUNTER frequency_counter(CARTA *cartas_jogador, CARTA *cartas_mesa){

    FREQ_COUNTER frequencias;
    int chave_valor, chave_naipe, k;

    memset(frequencias.valores, 0, sizeof(frequencias.valores));
    memset(frequencias.naipes, 0, sizeof(frequencias.naipes));

    for (int i = 0; i < 5; i++) frequencias.sequencia_aux[i] = cartas_mesa[i];
    for (int i = 0; i < 2; i++) frequencias.sequencia_aux[5 + i] = cartas_jogador[i];
    
    for (int i = 0; i < 7; i++){
        chave_valor = frequencias.sequencia_aux[i].valor;
        chave_naipe = frequencias.sequencia_aux[i].naipe;
        frequencias.valores[chave_valor]++;
        frequencias.naipes[chave_naipe]++;
    }

    return frequencias;

}

int verificar_sequencia(CARTA *cartas_jogador, CARTA *cartas_mesa){

    FREQ_COUNTER freq;
    freq = frequency_counter(cartas_jogador, cartas_mesa);

    if (dupla(&freq) == 1){
        printf ("\n\numa dupla\n\n");
        

        printf ("\n\n\n\nEXIBINDO OS VALORES DA SEQUENCIA POSSIVEL:\n\n\n\n");
        for (int i = 15; i <= 19; i++)
            printf("%d\t", freq.valores[i]);
        //ultra teste
        melhor_sequencia(&freq);

        return 9;
    } else if (dupla(&freq) == 2){
        printf ("\n\nduas duplas\n\n");

        for (int i = 15; i <= 19; i++)
            printf("%d\t", freq.valores[i]);
        //ultra teste
        melhor_sequencia(&freq);

        return 8;
    }

    printf ("carta alta");
    return 10;

}

void melhor_sequencia(FREQ_COUNTER *freq) {

    bool carta_usada[7] = {false};

    for (int j = 0; j < 5; j++){

        for (int i = 0; i < 7; i++){
            
            if (!carta_usada[i] &&
                freq->sequencia_aux[i].valor == freq->valores[15 + j]){
                
                freq->melhor_sequencia[j] = freq->sequencia_aux[i];
                carta_usada[i] = true;
                break;
                
            }
            
        }

    }

    printf ("\n\n\n\nEXIBINDO A MELHOR SEQUENCIA POSSIVEL:\n\n\n\n");
    // ultra teste.
    exibir_vetor_cartas(freq->melhor_sequencia, 5);
}

int dupla(FREQ_COUNTER *freq){

    int cont_duplas = 0;
    int j = 0;

    //Itera todo o array de frequências de valores.
    for (int i = 14; i >= 2; i--){

        //Armazena os maiores valores da sequência auxiliar,
        //Para colocar na melhor sequência.
        if (freq->valores[i] == 1){
            if (freq->valores[19 - j] == 0){
                freq->valores[19 - j] = i;
                j++;
            }
        }
        //Se houver alguma carta que aparece duas vezes.
        else if (freq->valores[i] == 2){
            freq->valores[15 + (2 * cont_duplas)] = i;
            freq->valores[16 + (2 * cont_duplas)] = i;
            cont_duplas++;
        }

    }

    return cont_duplas;

}

int trinca(FREQ_COUNTER *freq){

    int cont_trincas = 0;

    for (int i = 14; i >= 2; i--){

        if (freq->valores[i] == 3){
            freq->valores[15 + cont_trincas] = i;
            cont_trincas++;
        }

    }

    return cont_trincas;

}

int quadra(FREQ_COUNTER *freq){

    int cont_quadras = 0;

    for (int i = 14; i >= 2; i--){

        if (freq->valores[i] == 4){
            
            //Local no array de valores que guardará o valor repetido.
            freq->valores[15 + cont_quadras] = i;
            cont_quadras++;

        }

    }

    return cont_quadras;

}