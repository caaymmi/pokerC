#include "funcoesJogo.h"
#include "funcoesCartas.h"

void distribuicao_cartas_jogadores(LISTA* lista_jogadores, PILHA* pilha_cartas){

    PONTj pjAux = lista_jogadores->inicio;

    for (int k = 1; k <= lista_jogadores->tamanho; k++){

        pjAux->jogador.mao[0] = retirar_carta_pilha(pilha_cartas);
        pjAux->jogador.mao[1] = retirar_carta_pilha(pilha_cartas);
        
        printf ("\nSEGUE A MAO DO %s", pjAux->jogador.nome);
        exibir_carta (pjAux->jogador.mao[0]);
        exibir_carta (pjAux->jogador.mao[1]);

        pjAux = pjAux->prox;

    }

}