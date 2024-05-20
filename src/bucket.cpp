#include <iostream>
#include "double_list_functions.h"
#include "sort_functions.h"

using std::cout;
using std::endl;

using namespace DoubleLinkedList;

void bucketSort(Node** head)
{
    Node* bucket[101];

    for(int i = 0; i <= 100; i++) bucket[i] = nullptr;

    Node* current = *head;

    while(current != nullptr)
    {
        int iNum = current->iPayload;
        insertEnd(&bucket[iNum], iNum);
        current = current->ptrNext;
    }

    deleteList(head);

    for(int i = 1; i <= 100; i++)
    {
        Node* currentBucket = bucket[i];

        while(currentBucket != nullptr)
        {
            insertEnd(head, i);
            currentBucket = currentBucket->ptrNext;
        }
    }
}