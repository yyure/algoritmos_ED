# Bucket Sort

O Bucket Sort é um algoritmo de ordenação que divide o conjunto de elementos em uma série de "baldes" e, em seguida, ordena cada balde individualmente, geralmente usando outro algoritmo de ordenação.

## Funcionamento do Bucket Sort
- Inicialmente, encontra-se o valor máximo e mínimo da lista de elementos a serem ordenados para determinar o intervalo de cada bucket.
- Divide-se o intervalo de valores em um número fixo de buckets. Cada elemento da lista é então colocado no bucket correspondente com base em seu valor.
- Cada bucket é então ordenado individualmente. Isso pode ser feito utilizando qualquer algoritmo de ordenação.
- Finalmente, os buckets ordenados são concatenados para formar a lista final ordenada.

## Exemplo
Imagine que temos a lista de números [29, 25, 3, 49, 9, 37, 21, 43] e queremos ordená-los utilizando o Bucket Sort.

### Distribuição nos Buckets

Suponha que decidimos usar 5 buckets. Calculamos o intervalo de cada bucket com base no valor máximo (49) e mínimo (3) dos elementos.
Intervalo de cada bucket: (49 - 3) / 5 = 9.2 (aproximamos para 10 para facilitar).
Então os buckets seriam:
```
Bucket 0: 0-9
Bucket 1: 10-19
Bucket 2: 20-29
Bucket 3: 30-39
Bucket 4: 40-49
```
Distribuímos os elementos nos buckets:
```
Bucket 0: [3, 9]
Bucket 1: []
Bucket 2: [29, 25, 21]
Bucket 3: [37]
Bucket 4: [49, 43]
```
### Ordenação dos Buckets

Ordenamos cada bucket individualmente:
```
Bucket 0: [3, 9] (já está ordenado)
Bucket 1: [] (vazio)
Bucket 2: [21, 25, 29]
Bucket 3: [37] (já está ordenado)
Bucket 4: [43, 49]
```
### Concatenar os Buckets Ordenados

Concatenamos os buckets ordenados para formar a lista final ordenada:
```
Lista final: [3, 9, 21, 25, 29, 37, 43, 49]
```
