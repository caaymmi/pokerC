# Implementações a Fazer

## 24 de junho de 2025

### Problema

O programa está reconhecendo uma dupla inexistente e como ele reconhece ele tenta a retornar na melhor sequência possível, o que não é possível já que essa suposta dupla de cartas não existe na sequência auxiliar. 

```c
PRINTANDO A SEQUENCIA AUXILIAR DO jorge

CARTA de ID: 43
Quatro de Paus

CARTA de ID: 9
Nove de Copas

CARTA de ID: 45
Seis de Paus

CARTA de ID: 11
Valete de Copas

CARTA de ID: 5
Cinco de Copas

CARTA de ID: 34
Oito de Ouros

CARTA de ID: 2
Dois de Copas

uma dupla

EXIBINDO OS VALORES DA SEQUENCIA POSSIVEL:

13      13      8       9       11

EXIBINDO A MELHOR SEQUENCIA POSSIVEL:

CARTA de ID: 6420836

CARTA de ID: 0

CARTA de ID: 34
Oito de Ouros

CARTA de ID: 9
Nove de Copas

CARTA de ID: 11
Valete de Copas
```

Isso ocorre por uma sobrescritura de valores no vetor `freq->valores` que são necessários para a verificação de sequências. E isso se deve a sequência de if's e else if's abaixo.

```c
if (quadra(&freq) == 1){
    //...
    return 4;
}
else if (trinca(&freq) == 1){
    //...
    return 7;
}
else if (dupla(&freq) == 1){
    //...
    return 9;

} else if (dupla(&freq) == 2){
    //...
    return 8;
}
```
O problema ocorre pois estamos tratando com ponteiros e passagens por referências, portanto em cada uma dessas verificações o vetor `freq->valores` é sobrescrito com os valores das cartas que estão sendo verificadas, mesmo que sejam as mesmas .

```c
int quadra(FREQ_COUNTER *freq){

    int cont_quadras = 0;
    int j = 0;

    //Itera todo o array de frequências de valores.
    for (int i = 14; i >= 2; i--){

        //Armazena os maiores valores da sequência auxiliar,
        //Para colocar na melhor sequência.
        if (freq->valores[i] == 1){
            if (freq->valores[19 - j] == 0){
                freq->valores[19 - j] = i;
                j++;
            }
        }
        //Se houver alguma carta que aparece quatro vezes.
        else if (freq->valores[i] == 4){
            freq->valores[15] = i;
            freq->valores[16] = i;
            freq->valores[17] = i;
            freq->valores[18] = i;
            cont_quadras++;
        }

    }

    return cont_quadras;

}
```

Esse código o vetor de valores na memória ainda que a função retorne zero, o vetor de valores já foi sobrescrito com os valores das cartas que estão sendo verificadas. E isso se repete nas funções abaixo, `trinca` e `dupla`. Podemos realizar um teste de sanidade para verificar se isso de fato está acontecendo.

```c
PRINTANDO A SEQUENCIA AUXILIAR DO wilson

CARTA de ID: 41
Dois de Paus

CARTA de ID: 37
Valete de Ouros

CARTA de ID: 43
Quatro de Paus

CARTA de ID: 19
Seis de Espadas

CARTA de ID: 16
Tres de Espadas

CARTA de ID: 18
Cinco de Espadas

CARTA de ID: 11
Valete de Copas

TESTE DE SANIDADE:

JA FOI COMPUTADO NA melhor sequencia
PRESENTE AO FIM DA FREQ COUNTER DE VALORES
A CARTA DE VALOR: 6
A CARTA DE VALOR: 5
A CARTA DE VALOR: 4
A CARTA DE VALOR: 3
A CARTA DE VALOR: 2

uma dupla

EXIBINDO OS VALORES DA SEQUENCIA POSSIVEL:

11      11      4       5       6

EXIBINDO A MELHOR SEQUENCIA POSSIVEL:

CARTA de ID: 37
Valete de Ouros

CARTA de ID: 11
Valete de Copas

CARTA de ID: 43
Quatro de Paus

CARTA de ID: 18
Cinco de Espadas

CARTA de ID: 19
Seis de Espadas
```

Percebe-se que ao fim do vetor de valores da frequência encontramos os valores 6, 5, 4, 3 e 2, que foram analisados nas funções `quadra`, `trinca` anteriormente.  

Saída acima reproduzida pelo bloco de código abaixo.

```c
printf ("\n\n\n\nTESTE DE SANIDADE:\n\n\n\n");
printf ("JA FOI COMPUTADO NA melhor sequencia\n");
printf ("PRESENTE AO FIM DA FREQ COUNTER DE VALORES\n");
for (int i = 19; i >= 15; i--){
    printf ("A CARTA DE VALOR: %d\n", freq->valores[i]);
}
```

Do **índice 19 ao 15** deveria se conter apenas os valores das cartas que estão na melhor sequência. Contudo, quando não há sequência nenhuma, dupla, trinca ou quadra, esses valores se aglutinam até o **índice 13**, que é o que conta quantos Reis existem na sequência auxiliar. Isso se deve ao bloco de código abaixo:

```c
for (int i = 14; i >= 2; i--){
    if (freq->valores[i] == 1){
        if (freq->valores[19 - j] == 0){
            //Se J = 6; 19 - 6 = 13
            freq->valores[19 - j] = i; 
            j++;
        }
    }
}
```
Não há condição de parada de **J**.  
Então se houverem 7 cartas de valores diferentes o J chegará a 6.  
Isso fará com que a atribuição do valor para melhor sequência passe a ser considerado como a quantidade de reis que existem.

No primeiro exemplo dado a tabela de valores ficava assim:

| Valor    | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 |
|---------:|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|
| Aparições| 0 | 0 | **1** | 0 | **1** | **1** | **1** | 0 | **1** | **1** | 0  | **1**  | 0  | 0  | 0  |

Na primeira verificação da sequência auxiliar na função `quadra`, os índices 19 a 15 ficavam assim:

| Índice    | 13 | 14 | 15 | 16 | 17 | 18 | 19 |
|----------:|----|----|----|----|----|----|----|
| Valor     | **2**  | **4**  | **5**  | **6**  |  **8** |  **9** | **11** |

E isso faz com que o resto do código interprete que:
- Houvessem duas cartas de valor 13, dois Reis;
- Houvessem quatro cartas de valor 14, quatro Ás;

O que afeta a função `dupla`e afetaria a função `quadra` se ela fosse chamada posteriormente, pois fará com que se reconheça uma dupla e/ou uma quadra onde não há.

Dessa forma, a solução para isso é adicionar uma condição de parada para o **J**, um `break` ou fazer com que não haja essa sobrescrita.

## 22 de Junho de 2025

### Problema

A função de retornar a melhor sequência possível tem os valores corretos, contudo está passando cartas literalmente repetidas.

```c
for (int j = 0; j < 5; j++)
        for (int i = 0; i < 7; i++)
            if (freq->sequencia_aux[i].valor == freq->valores[15 + j])
                freq->melhor_sequencia[j] = freq->sequencia_aux[i];
```

O primeiro loop ancora o valor e o segundo loop percorre a sequência para encontrar a carta que tem o valor correspondente. Contudo, como se trata de pares de cartas, existem duas cartas com o mesmo valor, então o loop percorre a sequência e encontra a primeira carta com o valor correspondente, mas não verifica se essa carta já foi adicionada à melhor sequência.

```c
PRINTANDO A SEQUENCIA AUXILIAR DO LUCCAS

CARTA de ID: 12
Rainha de Copas

CARTA de ID: 48
Nove de Paus

CARTA de ID: 15
Dois de Espadas

CARTA de ID: 51
Rainha de Paus

CARTA de ID: 8
Oito de Copas

CARTA de ID: 42
Tres de Paus

CARTA de ID: 49
Dez de Paus

uma dupla

EXIBINDO OS VALORES DA SEQUENCIA POSSIVEL:

12      12      8       9       10

EXIBINDO A MELHOR SEQUENCIA POSSIVEL:

CARTA de ID: 51
Rainha de Paus

CARTA de ID: 51
Rainha de Paus

CARTA de ID: 8
Oito de Copas

CARTA de ID: 48
Nove de Paus

CARTA de ID: 49
Dez de Paus
```

Nota-se que o **Rainha de Paus** se repete, enquanto que deveria ser a **Rainha de Paus** e a **Rainha de Copas**, indicada lá em cima no começo do bloco de código. 

Para resolver isso, é necessário adicionar uma verificação para garantir que a carta não foi adicionada.

## 21 de Junho de 2025

### Problema

Verificar quais são as sequências possíveis não é um problema, contudo o problema é retornar quais são os valores repetido de forma eficiente. Exemplo:

| Valor    | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 |
|---------:|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|
| Aparições| 0 | 0 | 1 | 0 | 1 | 0 | 1 | **2** | 0 | 0 | 0  | 0  | 0  | **2**  | 0  |

O problema aqui é ter uma forma de retornar **o número 14 (O Ás)** e retornar **o número 7**. 
Com o intuito de tê-los para reconhecer as cartas na sequência auxiliar para transferir para a melhor sequência possível.

## 20 de junho de 2025

### Sequencias.c

**Linha 80 a Linha 91** aqui está sendo preparado o protótipo do que será o setor da função que retornará a melhor sequência possível com as cartas disponíveis.  
Sendo assim, analisando o código principalmente o início dele com o **for** e o **if** que são responsáveis por encontrar o valor que tem par.  
Esse número deve ser encontrado antes desse setor do código ou seja retornado pela verificação de sequência. Para que não hajam um loop dentro de outro. 


## 19 de junho de 2025

### Refatoração de código

Refatorar as sequências e talvez colocar todas elas com contadores do tipo:
**dupla(frequencia_valor[])** passará a retornar um inteiro que indicará quantoas
duplas existem naquela sequência, sendo uma duas ou três. O mesmo serve para uma ou duas trincas.

Isso pouparia a função duas_duplas e os returns ainda funcionariam de forma semelhante já que basta usar **!** para saber se é falso.