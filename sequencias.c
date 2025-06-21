#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "tipos.h"
#include "sequencias.h"

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

};

int verificar_sequencia(CARTA *cartas_jogador, CARTA *cartas_mesa){

    FREQ_COUNTER freq;

    freq = frequency_counter(cartas_jogador, cartas_mesa);
    // Retornando a melhor sequencia possível

    //ORGANIZAR A ORDEM DOS IF'S E ELSE'S

    //Funcionando, porém ainda não está perfeito.
    if (quadra(freq.valores)){
        printf ("\nA sua sequencia tem uma quadra.\n");
        printf ("RANKING: TOP 3");
        return 3;
    }
    //Funcionando, porém ainda não está perfeito.
    else if(full_house(freq.valores)){
        printf ("\nA sua sequencia tem um full house.\n");
        printf ("RANKING: TOP 4");
        return 4;

    }
    //Funcionando, porém ainda não está perfeito.
    else if (duas_duplas(freq.valores)){
        printf ("\nA sua sequencia tem duas duplas.\n");
        printf ("RANKING: TOP 8");
        return 8;

    }
    //Funcionando, porém ainda não está perfeito.
    else if (trinca(freq.valores)){
        printf ("\nA sua sequencia tem uma trinca.\n");
        printf ("RANKING: TOP 7");
        return 7;

    }
    //Funcionando, porém ainda não está perfeito.
    else if (uma_dupla(freq.valores)){
        printf ("\nA sua sequencia tem uma dupla.\n");
        printf ("RANKING: TOP 9");

        // k = 0;
        // int valor_repetido;

        // //VERSAO 1
        // for (int i = 14; i >= 0; i--){
        //     if (freq.valores[i] == 2)
        //         valor_repetido = i;
        // }
        // for (int j = 0; j < 7; j++)
        //     if (cartas[j].valor == valor_repetido){
        //         melhor_sequencia[k] = cartas[j];
        //         k++;
        //     }

        //  //VERSAO 2
        // for (int i = 14; i >= 0; i--){
        //     //Identifica o valor que é dupla.
        //     if (freq.valores[i] == 2){
                
        //         //Percorre o vetor de cartas para atribuir
        //         //As cartas para a sequência que será retornada.

        //         for (int j = 0; j < 7; j++)
        //             if (cartas[j].valor == i){
        //                 melhor_sequencia[k] = cartas[j];
        //                 k++;
        //             }

        //     }
        // }

        return 9;

    }

    if (straight_flush(freq.valores, freq.naipes)){
        printf ("\nA sua sequencia tem um straight flush.\n");
        printf ("RANKING: TOP 2");
        return 2;

    }
    else if (straight(freq.valores)){
        printf ("\nA sua sequencia tem um straight.\n");
        printf ("RANKING: TOP 6");
        return 6;

    }
    else if (flush(freq.naipes)){
        printf ("\nA sua sequencia tem um flush.\n");
        printf ("RANKING: TOP 5");
        return 5;

    }

    printf ("\nA sua sequencia e uma carta alta.\n");
    printf ("RANKING: TOP 10");
    return 10;

}

bool uma_dupla(int *frequencias_valores){
    
    for (int i = 14; i >= 0; i--)
        if (frequencias_valores[i] == 2)
            return true;
    
    return false;

}

int dupla(FREQ_COUNTER *freq, int *valores_repetidos){

    int cont_duplas = 0;

    //Itera todo o array de frequências de valores.
    for (int i = 14; i >= 2; i--){
        //Se houver alguma carta que aparece duas vezes.
        if (freq->valores[i] == 2){
            valores_repetidos[cont_duplas] = i;
            cont_duplas++;
        }
    }

    return cont_duplas;

}

int trinca(FREQ_COUNTER *freq, int *valores_repetidos){

    int cont_trincas = 0;

    for (int i = 14; i >= 2; i--){

        if (freq->valores[i] == 3){
            valores_repetidos[cont_trincas] = i;
            cont_trincas++;
        }

    }

    return cont_trincas;

}

int quadra(FREQ_COUNTER *freq, int *valores_repetidos){

    int cont_quadras = 0;

    for (int i = 14; i >= 2; i--){

        if (freq->valores[i] == 4){
            *valores_repetidos = i;
            cont_quadras++;
        }

    }

    return cont_quadras;

}

int full_house(FREQ_COUNTER *freq, int *valores_repetidos){

    int cont_full_house = 0;

    if ((trinca(freq, valores_repetidos) == 2) || 
        (trinca(freq, valores_repetidos) == 1 && dupla(freq, valores_repetidos) == 1))
        return 1;

    return 0;

}

bool duas_duplas(int *frequencias_valores){

    int contador = 0;

    for (int i = 14; i >= 0; i--)
        if (frequencias_valores[i] == 2)
            contador++;
    
    if (contador == 2)
        return true;

    return false;

}

bool trinca(int *frequencias_valores){
    
    for (int i = 14; i >= 0; i--)
        if (frequencias_valores[i] == 3)
            return true;
    
    return false;

}

bool quadra(int *frequencias_valores){
        
    for (int i = 14; i >= 0; i--)
        if (frequencias_valores[i] == 4)
            return true;
    
    return false;

}

bool full_house(int *frequencias_valores){

    int cont_trincas = 0;
    int cont_duplas = 0;

    for (int i = 14; i >= 0; i--){
        if (frequencias_valores[i] == 3)
            cont_trincas++;
        else if (frequencias_valores[i] == 2)
            cont_duplas++;

        if (cont_trincas == 1 && cont_duplas == 1)
            return true;
        else if (cont_trincas == 2)
            return true;
    }

    return false;

}

bool flush(int *frequencias_naipes){

    for (int i = 0; i < 5; i++)
        if (frequencias_naipes[i] >= 5)
            return true;
    
    return false;

}

bool straight(int *frequencias_valores){

    int consecutivos = 0;

    //Parte do fim do vetor de frequências para que
    //Assim que encontrar o maior straight possível o retorn.
    for (int i = 14; i >= 2; i--){

        //Verifica se o valor atual aparece na sequência.
        //Caso não apareça, reseta o contador de números consecutivos.
        if (frequencias_valores[i] > 0){
            consecutivos++;
            if (consecutivos == 5)
                return true;
        }
        else{
            consecutivos = 0;
        }

    }

    return false;

}

bool straight_flush(int *frequencias_valores, int *frequencias_naipes){

    return straight(frequencias_valores) && flush(frequencias_naipes);

}

//Repensar
/*bool royal_flush(CARTA *cartas){

    return straight_flush(cartas) && (cartas[0].valor==10 && cartas[4].valor==14);
        
}*/