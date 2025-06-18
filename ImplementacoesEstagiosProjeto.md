# 17 de junho de 2025

## Implementações das estruturas de dados responsáveis pelas listas de jogadores presentes e pelas pilhas de cartas, contando com:

- Inicialização de elementos;
- Inclusão de elementos;
- Exibição de elementos;
- Exclusão de elementos;
     
## Refatoração do código de inicialização de cartas:

```
int indice = 0;

for (int n = 0; n < 4; n++){
    for (int v = 1; v <= 13; v++){

        baralho_novo[indice].id = indice + 1;
        baralho_novo[indice].naipe = n + 1;
        baralho_novo[indice].valor = v;
        
        if (v == 1)
            baralho_novo[indice].valor += 13;

        indice++;
        
    }
}
```

A implementação desses dois for's simplifica a implementação anterior que estava utilizando um for de 0 até 51, que dificultava a sessão de atribuição de valores. Sendo necessário usar if's e else's junto de operações de cálculo de resto para que fosse possível realizar as atribuições corretas aos naipes e, principalmente, os valores das cartas.