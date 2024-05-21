#pragma once

namespace DoubleLinkedList
{
    template<typename T>
    struct Node
    {
        T iPayload;
        Node<T>* ptrNext;
        Node<T>* ptrPrev;
    };

    template<typename T>
    Node<T>* createNode(T);
    template<typename T>
    void displayList(Node<T>**);
    template<typename T>
    void insertFront(Node<T>**, T);
    template<typename T>
    void insertEnd(Node<T>**, T);
    template<typename T>
    void insertAfter(Node<T>*, T);
    template<typename T>
    void insertBefore(Node<T>**, Node<T>*, T);
    template<typename T>
    void deleteNode(Node<T>**, Node<T>*);
    template<typename T>
    void deleteList(Node<T>**);
    template<typename T>
    void deleteNodebyValue(Node<T>**, T);
    template<typename T>
    Node<T>* searchNodebyValue(Node<T>**, T);
    template<typename T>
    void swapValue(Node<T>*, Node<T>*);
}
