#include <iostream>
#include <fstream>
#include <cstdlib>
#include <chrono>

#include "src/sort_functions.h"
#include "src/double_list_functions.h"
#include "src/binary_search_tree.h"

// iostream
using std::cout;
using std::endl;
using std::ofstream;

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

    // BinarySearchTree::Node<int>* tree;

    // criar 100 árvores binárias, com 100000 nós cada
    // Analisar o tempo de cada tipo de busca
    /*for (int i = 0; i < 100; i++) {

        tree = BinarySearchTree::createTreeNode<int>(1);

        for (int j = 0; j < 100000; j++) {
            BinarySearchTree::insertNode(tree, rand() % 100000 + 1); // números entre 1 e 100000
        }
        auto start = high_resolution_clock::now();

        BinarySearchTree::bfsSearchNode<int>(tree, rand() % 100000 + 1); // modifique entre DFS e BFS

        auto end = high_resolution_clock::now();
        
        auto duration = duration_cast<nanoseconds>(end - start);

        cout << duration.count() << endl;
    }*/


   
   // analisar o tempo de criação de listas e árvores
   int arriNumbers[10000];

    for (int i = 0 ; i < 100; i++)
    {
        // preencher o vetor com 10000 números aleatórios
        for (int j = 0; j < 10000; j++) {
            arriNumbers[j] = rand() % 100 + 1;
        }

        // abrir arquivo para armazenar os tempos de criação da lista
        ofstream time_creation_list("algorithm_times/creation/time_creation_list.txt", std::ios::app);

        // tempo de criação da lista
        auto start = high_resolution_clock::now();
        DoubleLinkedList::List<int>* list = DoubleLinkedList::createList<int>();
        for (int j = 0; j < 10000; j++) {
            DoubleLinkedList::insertFront(list, arriNumbers[j]);
        }
        auto end = high_resolution_clock::now();

        // armazenar o tempo de criação da lista
        time_creation_list << duration_cast<nanoseconds>(end - start).count() << endl;
        time_creation_list.close();

        // abrir arquivo para armazenar os tempos de criação da árvore 
        ofstream time_creation_tree("algorithm_times/creation/time_creation_tree.txt", std::ios::app);

        // tempo de criação da árvore
        start = high_resolution_clock::now();
        BinarySearchTree::Node<int>* tree = nullptr;
        for (int j = 0; j < 10000; j++) {
            tree = BinarySearchTree::insertNode(tree, arriNumbers[j]);
        }
        end = high_resolution_clock::now();

        // armazenar o tempo de criação da árvore
        time_creation_tree << duration_cast<nanoseconds>(end - start).count() << endl;
        time_creation_tree.close();
    }

    return 0;
}