#include <stdio.h>

#include "tipos.h"

void preencher_lista_jogadores(){

    int total_jogadores;

    printf ("Entre com o total de jogadores: ");
    scanf ("%d", total_jogadores);

    for (int i = 1; i <= total_jogadores; i++){

        JOGADOR novo_jogador;

        printf ("Entre com o seu nome: ");
        scanf ("%s", &novo_jogador.nome);

        printf ("Entre com a sua banca: ");
        scanf ("%d", &novo_jogador.banca);

        novo_jogador.aposta = 0;



    }

}