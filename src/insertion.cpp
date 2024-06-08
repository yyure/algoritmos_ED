#include <iostream>
#include "double_list_functions.h"
#include "sort_functions.h"

using std::cout;
using std::endl;

using namespace DoubleLinkedList;

template<typename T>
void insertionSort(List<T>* list)
{
    if (list->ptrHead == nullptr) {
        cout << "Lista vazia" << endl;
        return;
    }
    
    Node<T>* ptrOuterLoop = list->ptrHead;
    Node<T>* ptrInnerLoop = nullptr;
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

// instanciação explícita
template void insertionSort<int>(List<int>*);

template void insertionSort<float>(List<float>*);