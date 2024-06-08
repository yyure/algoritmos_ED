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
    struct List
    {
        Node<T>* ptrHead;
        Node<T>* ptrTail;
    };

    template<typename T>
    Node<T>* createNode(T);
    template<typename T>
    List<T>* createList();
    template<typename T>
    void displayList(List<T>*);
    template<typename T>
    void insertFront(List<T>*, T);
    template<typename T>
    void insertEnd(List<T>*, T);
    template<typename T>
    void insertAfter(List<T>*, Node<T>*, T);
    template<typename T>
    void insertBefore(List<T>*, Node<T>*, T);
    template<typename T>
    void deleteNode(List<T>*, Node<T>*);
    template<typename T>
    void deleteList(List<T>*);
    template<typename T>
    void deleteNodebyValue(List<T>*, T);
    template<typename T>
    Node<T>* searchNodebyValue(List<T>*, T);
    template<typename T>
    void swapValue(Node<T>*, Node<T>*);
}
