#include "funcoesEstruturasDados.h"

void inicializar_lista(LISTA* lista){

    lista->inicio = NULL;
    lista->fim = NULL;

    lista->tamanho = 0;

}

void inserir_jogador_lista(LISTA* lista, JOGADOR novo_jogador){

    PONTj novo_elemento = (ELEMENTOj *)malloc(sizeof(ELEMENTOj));
    
    novo_elemento->jogador = novo_jogador;
    //Caso a lista esteja vazia apontará para o NULL o que não é problema.
    novo_elemento->ant = lista->fim;
    novo_elemento->prox = NULL;

    //Se a lista estiver vazia coloca o novo elemento no começo da lista,
    //Se não coloca o novo elemento como próximo ao fim da lista e reatribui esse fim.
    if (!lista->tamanho)
        lista->inicio = novo_elemento;
    else
        lista->fim->prox = novo_elemento;

    lista->fim = novo_elemento;
    lista->tamanho++;

}

bool excluir_jogador_lista(LISTA* lista, int id_jogador){

    PONTj pAux = lista->inicio;

    for (int i = 1; i <= lista->tamanho; i++){

        if (pAux->jogador.id == id_jogador){

            //Coloca o início da lista no próximo item e desconecta o ponteiro da lista.
            if (pAux == lista->inicio){

                lista->inicio = pAux->prox;
                pAux->prox = NULL;

            }
            //Coloca o fim da lista no item anterior e desconecta o ponteiro da lista.
            else if (pAux == lista->fim){

                lista->fim = pAux->ant;
                pAux->ant = NULL;

            }
            //Conecta o item anterior ao ponteiro atual com o próximo e desconecta o ponteiro da lista.
            else{
                
                pAux->ant->prox = pAux->prox;
                pAux->prox->ant = pAux->ant;
                pAux->ant = pAux->prox = NULL;

            }

            //Libera o espaço de memória alocado por esse ponteiro.
            //Diminui em um o tamanho da lista e retorna true.
            free(pAux);
            lista->tamanho--;
            return true;

        }
        else{
            pAux = pAux->prox;
        }

    }

    //Jogador não foi encontrado na lista.
    return false;

}
