#include "funcoesEstruturasDados.h"

void preencher_lista_jogadores(LISTA* lista_jogadores){

    int total_jogadores;

    printf ("\nEntre com o total de jogadores: ");
    scanf ("%d", &total_jogadores);
    printf ("\n");

    for (int i = 1; i <= total_jogadores; i++){

        JOGADOR novo_jogador;

        printf ("Entre com o seu nome: ");
        scanf ("%s", &novo_jogador.nome);

        printf ("Entre com a sua banca: ");
        scanf ("%d", &novo_jogador.banca);

        novo_jogador.aposta = 0;

        inserir_jogador_lista(lista_jogadores, novo_jogador);

        printf ("\n");

    }

}

void exibir_jogadores(LISTA lista_jogadores){
  
    PONTj pAux = lista_jogadores.inicio;

    for (int i = 1; i <= lista_jogadores.tamanho; i++){
        
        printf ("\nJOGADOR:\t%s", pAux->jogador.nome);
        printf ("\nBANCA:\t\t%d FICHAS", pAux->jogador.banca);
        printf ("\n");

        pAux = pAux->prox;

    }

    free(pAux);

    printf ("\n");

}