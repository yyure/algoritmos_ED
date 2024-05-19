#include <iostream>
#include "double_list_functions.h"
#include "sort_functions.h"

using std::cout;
using std::endl;

using namespace DoubleLinkedList;

void selectionSort(Node** head)
{
    if (*head == nullptr)
    {
        cout << "Lista vazia." << endl;
        return;
    }

    Node* ptrOuterLoop = *head;
    Node* ptrInnerLoop = nullptr;

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

void optimizedSelectionSort(Node** head)
{
    if (*head == nullptr)
    {
        cout << "Lista vazia." << endl;
        return;
    }

    Node* ptrOuterLoop = *head;
    Node* ptrInnerLoop = nullptr;
    Node* ptrMinNode = nullptr;

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