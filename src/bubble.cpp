#include <iostream>
#include "double_list_functions.h"
#include "sort_functions.h"

using std::cout;
using std::endl;

using namespace DoubleLinkedList;

template<typename T>
void bubbleSort(List<T>* list)
{
    if (list->ptrHead == nullptr)
    {
        cout << "Lista Vazia" << endl;
        return;
    }

    Node<T>* ptrCount = list->ptrHead; // Atua como um contador do número de loops externos
    Node<T>* ptrCurrent = nullptr;

    while (ptrCount->ptrNext != nullptr)
    {
        ptrCurrent = list->ptrHead;

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
void optimizedBubbleSort(List<T>* list)
{
    if (list->ptrHead == nullptr)
    {
        cout << "Lista vazia." << endl;
        return;
    }

    Node<T>* ptrCount = list->ptrHead; // Atua como um contador do número de loops externos
    Node<T>* ptrCurrent = nullptr;
    
    Node<T>* ptrFinal = list->ptrTail;
    
    bool bOrdened = true; // verifica se a lista está ordenada

    while (ptrCount->ptrNext != nullptr)
    {
        ptrCurrent = list->ptrHead;

        while (ptrCurrent->ptrNext != ptrFinal->ptrNext)
        {
            if (ptrCurrent->iPayload > ptrCurrent->ptrNext->iPayload)
            {
                swapValue(ptrCurrent, ptrCurrent->ptrNext);
                bOrdened = false;
            }

            ptrCurrent = ptrCurrent->ptrNext;
        }
        
        if (bOrdened) return; // caso em que a lista já está ordenada
        ptrFinal = ptrFinal->ptrPrev;
        bOrdened = true; // atualiza a verificação

        ptrCount = ptrCount->ptrNext;
    }

    return;
}

// instanciação explícita
template void bubbleSort<int>(List<int>*);
template void optimizedBubbleSort<int>(List<int>*);

template void bubbleSort<float>(List<float>*);
template void optimizedBubbleSort<float>(List<float>*);