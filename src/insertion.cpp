#include <iostream>
#include "double_list_functions.h"
#include "sort_functions.h"

using std::cout;
using std::endl;

using namespace DoubleLinkedList;

void insertionSort(Node** head)
{
    if (*head == nullptr) {
        cout << "Lista vazia" << endl;
        return;
    }
    
    Node* ptrOuterLoop = *head;
    Node* ptrInnerLoop = nullptr;
    while (ptrOuterLoop != nullptr)
    {
        ptrInnerLoop = ptrOuterLoop;
        while (ptrInnerLoop->ptrPrev != nullptr)
        {
            if (ptrInnerLoop->ptrPrev->iPayload > ptrInnerLoop->iPayload)
            {
                swapValue(ptrInnerLoop->ptrPrev, ptrInnerLoop);
            }
            
            ptrInnerLoop = ptrInnerLoop->ptrPrev;
        }
        
        ptrOuterLoop = ptrOuterLoop->ptrNext;
    }
    
    return;
}