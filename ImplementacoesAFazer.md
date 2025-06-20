# Acrescentar

Refatorar as sequências e talvez colocar todas elas com contadores do tipo:
**dupla(frequencia_valor[])** passará a retornar um inteiro que indicará quantoas
duplas existem naquela sequência, sendo uma duas ou três. O mesmo serve para uma ou duas trincas.

Isso pouparia a função duas_duplas e os returns ainda funcionariam de forma semelhante já que basta usar **!** para saber se é falso.

### Sequencias.c

**Linha 80 a Linha 91** aqui está sendo preparado o protótipo do que será o setor da função que retornará a melhor sequência possível com as cartas disponíveis.  
Sendo assim, analisando o código principalmente o início dele com o **for** e o **if** que são responsáveis por encontrar o valor que tem par.  
Esse número deve ser encontrado antes desse setor do código ou seja retornado pela verificação de sequência. Para que não hajam um loop dentro de outro.