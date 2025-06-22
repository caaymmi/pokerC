# 22 de junho de 2025

Retorno da melhor sequência possível de um jogador com um par de cartas ou dois pares de cartas realizada. 
Através do código abaixo:

```c
void melhor_sequencia(FREQ_COUNTER *freq) {

    bool carta_usada[7] = {false};

    for (int j = 0; j < 5; j++){

        for (int i = 0; i < 7; i++){
            
            if (!carta_usada[i] &&
                freq->sequencia_aux[i].valor == freq->valores[15 + j]){
                
                freq->melhor_sequencia[j] = freq->sequencia_aux[i];
                carta_usada[i] = true;
                break;
                
            }
            
        }

    }
}
```

O primeiro loop ancora os valores da sequência e o segundo percorre as cartas disponíveis para o jogador. Ele analisa se a carta tem o mesmo valor que está presente na sequência e se a carta ainda não foi utilizada, essa segunda parte é muito importante pois previne que uma mesma carta seja adicionada duas vezes. 

A variável `carta_usada` foi essencial.

# 21 de junho de 2025

## Implementação pelo armazenamento dos valores das cartas da melhor sequência possível de um jogador

Através de uma possível _"gambiarra",_ os valores das melhores cartas foram armazenados nas últimas 5 posições do contador de frequência de valores
por meio de frequency_counter.valores[15~19] é onde se encontram os melhores valores disponíveis. No caso atual, em que inicialmente foram implementadas
as duplas temos o ou os valores duplicados ocupando em casos de:

- **Uma dupla: `frequency_counter.valores[15] e [16]`**
- **Duas duplas: `frequency_counter.valores[17] e [18]`**

E os últimos índices contém os maiores valores disponíveis na sequência do jogador.

## Exemplo: 

### 1. Duas duplas

| Valor    | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 |
|---------:|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|
| Aparições| 0 | 0 | 1 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | 0  | 0  | **2**  | 0  | **2**  |

### 2. Uma dupla

| Valor    | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 |
|---------:|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|
| Aparições| 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | 1 | 0  | 0  | **2**  | 1  | 1 |

**Se rodarmos:**

```c
    for (int i = 15; i < 20; i++){
        printf("%d  ", frequency_counter_exemplo1.valores[i]);
    }

    // Imprimirá:
    14  14  12  12  13

    for (int i = 15; i < 20; i++){
        printf("%d  ", frequency_counter_exemplo2.valores[i]);
    }

    // Imprimirá:
    12  12  9  13  14
```

# 18 de junho de 2025

## Refatoração do código das sequências

Refatoração do código de verificação de sequências, que ainda não foi finalizada. Os loops foram invertidos para que partam do seu fim em direção ao início, para casos em que existam:

- Três duplas
- Duas trincas
- Mais de um straight

Sejam verificados as sequências com os maiores valores possíveis.  

### Três Duplas, duas duplas, com a escolha das duas maiores duplas.

| Valor    | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 |
|---------:|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|
| Aparições| 0 | 0 | 0 | 0 | **2** | 0 | 1 | **2** | 0 | 0 | 0  | 0  | 0  | **2**  | 0  |

Com o **novo código** será reconhecido a **dupla de 13 e a dupla de 7**  
Com o **código anterior** o **Par de Duplas** seria composto por uma **dupla de 4 e outra dupla de 7**

### Duas trincas, lê-se um Full House, com a escolha da trinca de maior valor o par de menor.

| Valor    | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 |
|---------:|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|
| Aparições| 0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | **3** | **3**  | 0  | 0  | 0  | 0  |

Com o **novo código** será reconhecido a **trinca de 10 e o par de 9.**  
Com o **código anterior** o **Full House** seria composto por uma **trinca de 9 e o par de 10**.  

### Mais de um straight, dois straights ou três straights.

| Valor     | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 |
|----------:|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|
| Aparições | 0 | 0 | 0 | **1** | **1** | **1** | **1** | **1** | **1** | **1** | 0  | 0  | 0  | 0  | 0  |

Com o **novo código** será reconhecido a **o straight de 5, 6, 7, 8, 9.**  
Com o **código anterior** o **straight** seria composto por uma **sequência de 3, 4, 5, 6, 7.**

<br><br>

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
