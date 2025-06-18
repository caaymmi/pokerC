#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "tipos.h"
#include "dicio.h"
#include "sequencias.h"
#include "funcoesJogo.h"
#include "funcoesCartas.h"
#include "funcoesJogadores.h"
#include "funcoesEstruturasDados.h"

void sequencia_teste(CARTA *sequencia, CARTA *cartas);

int main (){

    CARTA cartas[52];
    CARTA sequencia_aux[7];
    LISTA jogadores;
    PILHA baralho;
    // FILE *rankings;

    //Preenchimento da lista de jogadores.
    inicializar_lista(&jogadores);
    preencher_lista_jogadores(&jogadores);
    exibir_jogadores(jogadores);

    //Preenchimento do baralho de cartas.
    inicializar_cartas(cartas);
    srand(time(NULL));
    embaralhar(cartas);
    exibir_vetor_cartas(cartas);
    inicializar_pilha(&baralho);
    preencher_baralho_cartas(&baralho, cartas);

    printf("\n\n\n\nPRINTANDO AS MAOS\n\n\n\n");

    //Distribuição das cartas para as mãos dos jogadores.
    distribuicao_cartas_jogadores(&jogadores, &baralho);
    
    printf("\n\n\n\nPRINTANDO A PILHA\n\n\n\n");

    exibir_baralho(baralho);

    // rankings = fopen("Rankings.txt", "a+");


    // if (rankings == NULL){
    //     printf ("Erro na abertura do arquivo!\n");
    //     return 1;
    // }
    // else{
    //     printf ("Arquivo aberto com sucesso!\n");
    // }



    // sequencia_teste(sequencia_aux, cartas);

    // int quantidade_sequencia;
    // char linha_sequencia[20];

    // for (int i = 1; i < 20; i++){
    //     printf ("\n");
    // }

    // for (int j = 0; j < 9; j++){

    //     fgets(linha_sequencia, 20, rankings);
    //     printf ("\n");
    //     printf ("ULTRA TESTE: %s", linha_sequencia);
        
    //     char *nome_sequencia;
    //     char *quantidade_sequencia;
    //     int teste_qtd_sqc;

    //     nome_sequencia = strtok(linha_sequencia, ":");
    //     teste_qtd_sqc = *(strtok(NULL, "\n")) - '0';
    //     // teste_qtd_sqc = *quantidade_sequencia - '0';


    //     printf ("nome_sequencia: %s\n", nome_sequencia);
    //     // printf ("quantidade_sequencia: %s\n", quantidade_sequencia);
    //     printf ("teste_qtd_sqc: %d\n", teste_qtd_sqc);

    //     printf ("\n");

    // }

    // for (int i = 1; i < 20; i++){
    //     printf ("\n");
    // }
    // if (verificar_sequencia(sequencia_aux)){
    //     if (fscanf(rankings, "%d", &quantidade_sequencia) == 1){
    //         printf ("\nUrasLTRA TESTE: %d", quantidade_sequencia);
    //         // fprintf (rankings, "\nULTRA TESTE2");
    //     }
    // }

    // /* switch(verificar_sequencia(sequencia_aux)){

    //     case 1:
    //         //fscanf(rankings, "%d", &quantidade_sequencia);
    //         fprintf (rankings, "ROYAL FLUSH: 1\n");
    //         break;
    //     case 2:
    //         //fscanf(rankings, "%d", &quantidade_sequencia);    
    //         fprintf (rankings, "STRAIGHT FLUSH: 1\n");
    //         break;
    //     case 3:
    //         //fscanf(rankings, "%d", &quantidade_sequencia);
    //         fprintf (rankings, "QUADRA: 1\n");
    //         break;
    //     case 4:
    //         //fscanf(rankings, "%d", &quantidade_sequencia);
    //         fprintf (rankings, "FULL HOUSE: 1\n");
    //         break;
    //     case 5:
    //         //fscanf(rankings, "%d", &quantidade_sequencia);
    //         fprintf (rankings, "FLUSH: 1\n");
    //         break;
    //     case 6:
    //         //fscanf(rankings, "%d", &quantidade_sequencia);
    //         fprintf (rankings, "STRAIGHT: 1\n");
    //         break;
    //     case 7:
    //         //fscanf(rankings, "%d", &quantidade_sequencia);
    //         fprintf (rankings, "TRINCA: 1\n");
    //         break;
    //     case 8:
    //         //fscanf(rankings, "%d", &quantidade_sequencia);
    //         fprintf (rankings, "DUAS DUPLAS: 1\n");
    //         break;
    //     case 9:
    //         //fscanf(rankings, "%d", &quantidade_sequencia);
    //         fprintf (rankings, "UMA DUPLA: 1\n");
    //         break;
    //     case 10:
    //         if (fscanf(rankings, "%d", &quantidade_sequencia) == 1)
    //             printf ("ULTRA TESTE");
    //         fprintf (rankings, "CARTA ALTA: %d\n", quantidade_sequencia+1);
    //         break;
    //     default: break;

    // }*/
    
    // // int ranking = verificar_sequencia(sequencia_aux);
    
    // fclose(rankings);

    return 0;

}

void sequencia_teste(CARTA *sequencia, CARTA *cartas){

    for (int indice = 0; indice < 7; indice++){
        sequencia[indice] = cartas[indice];
    }

}