# Acrescentar

### Problema dia 21 de Junho de 2025

Verificar quais são as sequências possíveis não é um problema, contudo o problema é retornar quais são os valores repetido de forma eficiente. Exemplo:

| Valor    | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 |
|---------:|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|
| Aparições| 0 | 0 | 1 | 0 | 1 | 0 | 1 | **2** | 0 | 0 | 0  | 0  | 0  | **2**  | 0  |

O problema aqui é ter uma forma de retornar **o número 14 (O Ás)** e retornar **o número 7**. 
Com o intuito de tê-los para reconhecer as cartas na sequência auxiliar para transferir para a melhor sequência possível.

### Refatoração de código

Refatorar as sequências e talvez colocar todas elas com contadores do tipo:
**dupla(frequencia_valor[])** passará a retornar um inteiro que indicará quantoas
duplas existem naquela sequência, sendo uma duas ou três. O mesmo serve para uma ou duas trincas.

Isso pouparia a função duas_duplas e os returns ainda funcionariam de forma semelhante já que basta usar **!** para saber se é falso.

### Sequencias.c

**Linha 80 a Linha 91** aqui está sendo preparado o protótipo do que será o setor da função que retornará a melhor sequência possível com as cartas disponíveis.  
Sendo assim, analisando o código principalmente o início dele com o **for** e o **if** que são responsáveis por encontrar o valor que tem par.  
Esse número deve ser encontrado antes desse setor do código ou seja retornado pela verificação de sequência. Para que não hajam um loop dentro de outro.