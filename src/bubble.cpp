#include <iostream>
#include "double_list_functions.h"
#include "sort_functions.h"

using std::cout;
using std::endl;

using namespace DoubleLinkedList;

template<typename T>
void bubbleSort(Node<T>** head)
{
    if (*head == nullptr)
    {
        cout << "Lista Vazia" << endl;
        return;
    }

    Node<T>* ptrCount = *head; // Atua como um contador do número de loops externos
    Node<T>* ptrCurrent = nullptr;

    while (ptrCount->ptrNext != nullptr)
    {
        ptrCurrent = *head;

        while (ptrCurrent->ptrNext != nullptr)
        {
            if (ptrCurrent->iPayload > ptrCurrent->ptrNext->iPayload)
            {
                swapValue(ptrCurrent, ptrCurrent->ptrNext);
            }

            ptrCurrent = ptrCurrent->ptrNext;
        }
        
        ptrCount = ptrCount->ptrNext;
    }

    return;
}

template<typename T>
void optimizedBubbleSort(Node<T>** head)
{
    if (*head == nullptr)
    {
        cout << "Lista vazia." << endl;
        return;
    }

    Node<T>* ptrCount = *head;
    Node<T>* ptrCurrent = nullptr;
    
    // Inicia o ptrFinal no último nó da lista
    // ptrFinal: ponteiro da posição que indica o fim de cada loop
    Node<T>* ptrFinal = *head;
    while(ptrFinal -> ptrNext != nullptr) ptrFinal = ptrFinal -> ptrNext;
    
    int iOrdened = 0; // verifica se a lista está ordenada

    while (ptrCount->ptrNext != nullptr)
    {
        ptrCurrent = *head;

        while (ptrCurrent->ptrNext != ptrFinal->ptrNext)
        {
            if (ptrCurrent->iPayload > ptrCurrent->ptrNext->iPayload)
            {
                swapValue(ptrCurrent, ptrCurrent->ptrNext);
                iOrdened = 1;
            }

            ptrCurrent = ptrCurrent->ptrNext;
        }
        
        if (!iOrdened) return; // caso em que a lista já está ordenada
        ptrFinal = ptrFinal->ptrPrev;
        iOrdened = 0; // atualiza a verificação

        ptrCount = ptrCount->ptrNext;
    }

    return;
}

// instanciação explícita
template void bubbleSort<int>(Node<int>**);
template void optimizedBubbleSort<int>(Node<int>**);

template void bubbleSort<float>(Node<float>**);
template void optimizedBubbleSort<float>(Node<float>**);