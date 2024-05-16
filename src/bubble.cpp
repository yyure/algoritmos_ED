#include <iostream>
#include "double_list_functions.h"
#include "sort_functions.h"

using std::cout;
using std::endl;

void bubbleSort(Node** head)
{
    if (*head == nullptr)
    {
        cout << "Lista Vazia" << endl;
        return;
    }

    Node* ptrCount = *head; // Atua como um contador do número de loops externos
    Node* ptrCurrent = nullptr;

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

void optimizedBubbleSort(Node** head)
{
    if (*head == nullptr)
    {
        cout << "Lista vazia." << endl;
        return;
    }

    Node* ptrCount = *head;
    Node* ptrCurrent = nullptr;
    
    // Inicia o ptrFinal no último nó da lista
    // ptrFinal: ponteiro da posição que indica o fim de cada loop
    Node* ptrFinal = *head;
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