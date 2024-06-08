#include <iostream>
#include "double_list_functions.h"
#include "sort_functions.h"

using std::cout;
using std::endl;

using namespace DoubleLinkedList;

template<typename T>
void bucketSort(List<T>* list)
{
    //pega o maior e o menor valor da lista
    int iMaxValue = 0, iMinValue = 0;
    Node<T>* ptrCurrent = list->ptrHead;
    while (ptrCurrent != nullptr)
    {
        if (ptrCurrent->iPayload > iMaxValue) iMaxValue = ptrCurrent->iPayload;
        if (ptrCurrent->iPayload < iMinValue) iMinValue = ptrCurrent->iPayload;
        ptrCurrent = ptrCurrent->ptrNext;
    }

    //calcula o range dos baldes
    int iBucketCount = 10;
    int iBucketRange = (iMaxValue - iMinValue) / iBucketCount + 1;

    //cria os baldes
    List<T>* arrBuckets[iBucketCount];
    for (int i = 0; i < iBucketCount; i++) arrBuckets[i] = createList<T>();

    //insere os elementos nos baldes
    ptrCurrent = list->ptrHead;
    while (ptrCurrent != nullptr)
    {
        int iBucketIndex = (ptrCurrent->iPayload - iMinValue) / iBucketRange;
        insertEnd(arrBuckets[iBucketIndex], ptrCurrent->iPayload);
        ptrCurrent = ptrCurrent->ptrNext;
    }

    //ordena os baldes
    for (int i = 0; i < iBucketCount; i++) optimizedSelectionSort(arrBuckets[i]);

    deleteList(list);
    
    //concatena os baldes
    for (int i = 0; i < iBucketCount; i++)
    {
        if (arrBuckets[i] != nullptr)
        {
            if (list->ptrHead == nullptr)
            {
                list->ptrHead = arrBuckets[i]->ptrHead;
                list->ptrTail = arrBuckets[i]->ptrTail;
            } else {
                list->ptrTail->ptrNext = arrBuckets[i]->ptrHead;
                arrBuckets[i]->ptrHead->ptrPrev = list->ptrTail;
                list->ptrTail = arrBuckets[i]->ptrTail;
            }
        }
    }
}

// instanciação explícita
template void bucketSort<int>(List<int>*);

template void bucketSort<float>(List<float>*);