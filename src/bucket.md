# Bucket Sort

O Bucket Sort é um algoritmo de classificação que divide o conjunto de elementos em uma série de "baldes" e, em seguida, classifica cada balde individualmente, geralmente usando outro algoritmo de classificação, como o Insertion Sort. Aqui está uma explicação do código fornecido:

## Declaração da função bucketSort

A função bucketSort é declarada para classificar uma lista duplamente encadeada (Node** head) usando o algoritmo de Bucket Sort.

## Criação dos baldes:

Um array de ponteiros para nós (Node* bucket[101]) é criado para representar os baldes. Aqui, estamos assumindo que os elementos a serem classificados variam de 1 a 100.

Cada elemento do array é inicializado como nullptr para indicar que inicialmente nenhum elemento foi adicionado aos baldes.

## Distribuição dos elementos nos baldes:

A função itera sobre a lista encadeada original, percorrendo cada nó.

Para cada nó, o valor contido no nó é usado como um índice para determinar em qual balde o nó deve ser colocado.

O nó é então inserido no final do balde correspondente usando a função insertEnd.

## Liberação da lista original:

Após distribuir todos os elementos nos baldes, a lista original é liberada usando a função deleteList. Isso é feito porque os elementos da lista original não são mais necessários após serem distribuídos nos baldes.

## Concatenação dos baldes ordenados:

Em seguida, cada balde é percorrido em ordem, e os elementos de cada balde são adicionados de volta à lista original.

Isso é feito percorrendo cada balde e inserindo cada elemento no final da lista original usando a função insertEnd.

## Resultado:

Após esse processo, a lista original contém todos os elementos ordenados.

O Bucket Sort é eficaz quando os elementos estão uniformemente distribuídos no intervalo de classificação e quando o número de elementos em cada balde é relativamente pequeno. No entanto, a eficiência do Bucket Sort pode ser afetada negativamente se os elementos estiverem muito concentrados em alguns baldes, ou se o número de baldes for muito pequeno em relação ao número total de elementos.
