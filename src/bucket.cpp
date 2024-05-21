#include <iostream>
#include "double_list_functions.h"
#include "sort_functions.h"

using std::cout;
using std::endl;

using namespace DoubleLinkedList;

template<typename T>
void bucketSort(Node<T>** head)
{
    //pega o maior e o menor valor da lista
    int iMaxValue = 0, iMinValue = 0;
    Node<T>* ptrCurrent = *head;
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
    Node<T>* arrBuckets[iBucketCount];
    for (int i = 0; i < iBucketCount; i++) arrBuckets[i] = nullptr;

    //insere os elementos nos baldes
    ptrCurrent = *head;
    while (ptrCurrent != nullptr)
    {
        int iBucketIndex = (ptrCurrent->iPayload - iMinValue) / iBucketRange;
        insertEnd(&arrBuckets[iBucketIndex], ptrCurrent->iPayload);
        ptrCurrent = ptrCurrent->ptrNext;
    }

    //ordena os baldes
    for (int i = 0; i < iBucketCount; i++) optimizedSelectionSort(&arrBuckets[i]);

    deleteList(head);
    
    //concatena os baldes
    for (int i = 0; i < iBucketCount; i++)
    {
        if (arrBuckets[i] != nullptr)
        {
            if (*head == nullptr)
            {
                *head = arrBuckets[i];
            }
            else
            {
                Node<T>* ptrCurrent = *head;
                while (ptrCurrent->ptrNext != nullptr) ptrCurrent = ptrCurrent->ptrNext;
                ptrCurrent->ptrNext = arrBuckets[i];
                arrBuckets[i]->ptrPrev = ptrCurrent;
            }
        }
    }
}

// instanciação explícita
template void bucketSort<int>(Node<int>**);

template void bucketSort<float>(Node<float>**);