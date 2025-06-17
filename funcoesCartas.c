#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "funcoesCartas.h"

void criar_baralho(CARTA* baralho_novo){

    for (int indice = 0; indice < 52; indice++){

        baralho_novo[indice].id = indice+1;
        
        baralho_novo[indice].valor = (indice+1) % 13;
        if (!baralho_novo[indice].valor)
            baralho_novo[indice].valor = 13;
        if (baralho_novo[indice].valor == 1)
            baralho_novo[indice].valor = 14;

        if (baralho_novo[indice].id <= 13)
            baralho_novo[indice].naipe = 1;
        else if (baralho_novo[indice].id <= 26) 
            baralho_novo[indice].naipe = 2;
        else if (baralho_novo[indice].id <= 39)
            baralho_novo[indice].naipe = 3;
        else
            baralho_novo[indice].naipe = 4;

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

void exibir_baralho(CARTA *baralho){

    for (int indice = 0; indice < 52; indice++){

        exibir_carta(baralho[indice]);

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
        case 14: printf ("As de ");break;
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

//Vou ter que reescrever o avaliador de sequências
//Porque é melhor fazer os naipes e os valores
//Com um freq counter com hash table