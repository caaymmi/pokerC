#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "funcoesCartas.h"

void inicializar_cartas(CARTA* baralho_novo){

    int indice = 0;
    
    // 1 -> Copas, 2 -> Espadas, 3 -> Ouros, 4 -> Espadas.
    //N de naipe, V de valor.
    for (int n = 0; n < 4; n++){
        for (int v = 1; v <= 13; v++){

            baralho_novo[indice].id = indice + 1;
            baralho_novo[indice].naipe = n + 1;
            baralho_novo[indice].valor = v;
            
            //Se for ás transforme-o no valor 14.
            if (v == 1)
                baralho_novo[indice].valor += 13;

            indice++;
            
        }
    }

}

void embaralhar(CARTA *baralho){

    int i, j, ultima_posicao = 51;

    //Algoritmo de embaralhamento Fisher Yates
    for (i = ultima_posicao; i > 0; i--){

        j = rand() % (i + 1);

        CARTA temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;

    }

}

void preencher_baralho_cartas(PILHA* baralho, CARTA *cartas){

    for (int i = 51; i >= 0; i--){
        inserir_carta_pilha(baralho, cartas[i]);
    }

}

void exibir_carta(CARTA carta){

    printf ("\nCARTA de ID: %d\n", carta.id);
    //printf ("CARTA de naipe: %d\n", carta.naipe);
    //printf ("CARTA de valor: %d\n", carta.valor);

    switch(carta.valor){
        
        case 2: printf ("Dois de "); break;
        case 3: printf ("Tres de "); break;
        case 4: printf ("Quatro de "); break;
        case 5: printf ("Cinco de "); break;
        case 6: printf ("Seis de "); break;
        case 7: printf ("Sete de "); break;
        case 8: printf ("Oito de "); break;
        case 9: printf ("Nove de "); break;
        case 10: printf ("Dez de "); break;
        case 11: printf ("Valete de "); break;
        case 12: printf ("Rainha de "); break;
        case 13: printf ("Rei de "); break;
        case 14: printf ("As de "); break;
        default: break;

    }
    switch(carta.naipe){

        case 1: printf ("Copas\n"); break;
        case 2: printf ("Espadas\n"); break;
        case 3: printf ("Ouros\n"); break;
        case 4: printf ("Paus\n"); break;
        default: break;

    }

}

void exibir_baralho(PILHA baralho){
    
    PONTc pcAux = baralho.topo;

    while (pcAux){
    
        exibir_carta(pcAux->carta);
        pcAux = pcAux->prox;

    }

}

void exibir_vetor_cartas(CARTA *baralho, int tamanho){

    for (int indice = 0; indice < tamanho; indice++)
        exibir_carta(baralho[indice]);

}

//Vou ter que reescrever o avaliador de sequências
//Porque é melhor fazer os naipes e os valores
//Com um freq counter com hash table