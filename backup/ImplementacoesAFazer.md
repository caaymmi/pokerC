# Implementações a Fazer

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