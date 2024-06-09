#include <iostream>
#include <cstdlib>
#include <chrono>

#include "src/sort_functions.h"
#include "src/double_list_functions.h"
#include "src/binary_search_tree.h"

// iostream
using std::cout;
using std::endl;

// chrono
using std::chrono::nanoseconds;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;

int main()
{   
    /*
    DoubleLinkedList::List<int>* list;

    // Criar 100 listas com 10000 elementos cada
    // Analisar o tempo de cada algoritmo de ordenação
    for (int i = 0; i < 100; i++) {

        list = DoubleLinkedList::createList<int>();

        for (int j = 0; j < 10000; j++) {
            DoubleLinkedList::insertFront(list, rand() % 100 + 1); // números entre 1 e 100
        }
        auto start = high_resolution_clock::now();

        bucketSort(list); // Modifique, se quiser, a função de ordenação

        auto end = high_resolution_clock::now();
        
        auto duration = duration_cast<nanoseconds>(end - start);

        cout << duration.count() << endl;

        DoubleLinkedList::deleteList(list);
        free(list);
    }*/

    BinarySearchTree::Node<int>* tree;

    // criar 100 árvores binárias, com 100000 nós cada
    // Analisar o tempo de cada tipo de busca
    for (int i = 0; i < 100; i++) {

        tree = BinarySearchTree::createTreeNode<int>(1);

        for (int j = 0; j < 100000; j++) {
            BinarySearchTree::insertNode(tree, rand() % 100000 + 1); // números entre 1 e 100000
        }
        auto start = high_resolution_clock::now();

        BinarySearchTree::bfsSearchNode<int>(tree, rand() % 100000 + 1); // modifique entre DFS e BFS

        auto end = high_resolution_clock::now();
        
        auto duration = duration_cast<nanoseconds>(end - start);

        cout << duration.count() << endl;
    }

    return 0;
}
