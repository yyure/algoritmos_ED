#include <iostream>
#include "double_list_functions.h"
#include "sort_functions.h"

using std::cout;
using std::endl;

using namespace DoubleLinkedList;

template<typename T>
void selectionSort(Node<T>** head)
{
    if (*head == nullptr)
    {
        cout << "Lista vazia." << endl;
        return;
    }

    Node<T>* ptrOuterLoop = *head;
    Node<T>* ptrInnerLoop = nullptr;

    while (ptrOuterLoop != nullptr)
    {
        ptrInnerLoop = ptrOuterLoop->ptrNext;

        while(ptrInnerLoop != nullptr)
        {
            if (ptrInnerLoop->iPayload < ptrOuterLoop->iPayload)
            {
                swapValue(ptrOuterLoop, ptrInnerLoop);
            }

            ptrInnerLoop = ptrInnerLoop->ptrNext;
        }

        ptrOuterLoop = ptrOuterLoop->ptrNext;
    }

    return;
}

template<typename T>
void optimizedSelectionSort(Node<T>** head)
{
    if (*head == nullptr)
    {
        cout << "Lista vazia." << endl;
        return;
    }

    Node<T>* ptrOuterLoop = *head;
    Node<T>* ptrInnerLoop = nullptr;
    Node<T>* ptrMinNode = nullptr;

    while (ptrOuterLoop != nullptr)
    {
        ptrMinNode = ptrOuterLoop;
        ptrInnerLoop = ptrOuterLoop->ptrNext;

        while(ptrInnerLoop != nullptr)
        {
            if (ptrInnerLoop->iPayload < ptrMinNode->iPayload)
            {
                ptrMinNode = ptrInnerLoop;
            }

            ptrInnerLoop = ptrInnerLoop->ptrNext;
        }

        swapValue(ptrOuterLoop, ptrMinNode);

        ptrOuterLoop = ptrOuterLoop->ptrNext;
    }

    return;
}

// instanciação explícita
template void selectionSort<int>(Node<int>**);
template void optimizedSelectionSort<int>(Node<int>**);

template void selectionSort<float>(Node<float>**);
template void optimizedSelectionSort<float>(Node<float>**);