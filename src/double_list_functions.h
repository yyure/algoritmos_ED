#pragma once

namespace DoubleLinkedList
{
    typedef struct Node
    {
        int iPayload;
        Node* ptrNext;
        Node* ptrPrev;
    } Node;

    Node* createNode(int);
    void displayList(Node**);
    void insertFront(Node**, int);
    void insertEnd(Node**, int);
    void insertAfter(Node*, int);
    void insertBefore(Node**, Node*, int);
    void deleteNode(Node**, Node*);
    void deleteNodebyValue(Node**, int);
    Node* searchNodebyValue(Node**, int);
    void swapValue(Node*, Node*);
}
