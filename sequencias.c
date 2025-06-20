#include <stdio.h>
#include <stdbool.h>

#include "tipos.h"
#include "sequencias.h"

int verificar_sequencia(CARTA *cartas_jogador, CARTA *cartas_mesa){

    //Atribui a essa sequência de cartas auxiliar as cartas da mesa e do jogador.
    //Sendo as cinco primeiras as cartas da mesa e as duas últimas as cartas do jogador.    
    CARTA cartas[7] = { cartas_mesa[0],
        cartas_mesa[1], cartas_mesa[2],
        cartas_mesa[3], cartas_mesa[4],
        cartas_jogador[0], cartas_jogador[1]};

    //frequency_counter.
    int frequencias_naipe[5] = {0};
    int frequencias_valor[15] = {0};
    int chave_valor, chave_naipe;

    //Perpassa a sequência de cartas na mão do jogador.
    for (int i = 0; i < 7; i++){

        // printf ("\nRODANDO O FREQUENCY COUNTER: %d\n\n", i);

        chave_valor = cartas[i].valor;
        // printf ("CHAVE_VALOR = %d\n", chave_valor);
        frequencias_valor[chave_valor]++;
        // printf ("FREQUENCIAS_VALOR %d = %d\n", chave_valor, frequencias_valor[chave_valor]);

        chave_naipe = cartas[i].naipe;
        // printf ("CHAVE_NAIPE = %d\n", chave_naipe);
        frequencias_naipe[chave_naipe]++;
        // printf ("FREQUENCIAS_NAIPE %d = %d\n", chave_naipe, frequencias_naipe[chave_naipe]);


    }

    //ORGANIZAR A ORDEM DOS IF'S E ELSE'S

    //Funcionando, porém ainda não está perfeito.
    if (quadra(frequencias_valor)){
        printf ("\nA sua sequencia tem uma quadra.\n");
        printf ("RANKING: TOP 3");
        return 3;
    }
    //Funcionando, porém ainda não está perfeito.
    else if(full_house(frequencias_valor)){
        printf ("\nA sua sequencia tem um full house.\n");
        printf ("RANKING: TOP 4");
        return 4;

    }
    //Funcionando, porém ainda não está perfeito.
    else if (duas_duplas(frequencias_valor)){
        printf ("\nA sua sequencia tem duas duplas.\n");
        printf ("RANKING: TOP 8");
        return 8;

    }
    //Funcionando, porém ainda não está perfeito.
    else if (trinca(frequencias_valor)){
        printf ("\nA sua sequencia tem uma trinca.\n");
        printf ("RANKING: TOP 7");
        return 7;

    }
    //Funcionando, porém ainda não está perfeito.
    else if (uma_dupla(frequencias_valor)){
        printf ("\nA sua sequencia tem uma dupla.\n");
        printf ("RANKING: TOP 9");
        return 9;

    }

    if (straight_flush(frequencias_valor, frequencias_naipe)){
        printf ("\nA sua sequencia tem um straight flush.\n");
        printf ("RANKING: TOP 2");
        return 2;

    }
    else if (straight(frequencias_valor)){
        printf ("\nA sua sequencia tem um straight.\n");
        printf ("RANKING: TOP 6");
        return 6;

    }
    else if (flush(frequencias_naipe)){
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