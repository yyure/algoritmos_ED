#pragma once

namespace BinarySearchTree
{
    template<typename T>
    struct Node
    {
        T iPayload;
        Node<T>* ptrLeft;
        Node<T>* ptrRight;
    };

    template<typename T>
    Node<T>* createTreeNode(T);
    template<typename T>
    Node<T>* insertNode(Node<T>*, T);
    template<typename T>
    Node<T>* dfsSearchNode(Node<T>*, T);
    template<typename T>
    Node<T>* lesserLeaf(Node<T>*);
    template<typename T>
    Node<T>* deleteNode(Node<T>*, T);
    template<typename T>
    void traversePreOrder(Node<T>*);
    template<typename T>
    void traverseInOrder(Node<T>*);
    template<typename T>
    void traversePostOrder(Node<T>*);
    template<typename T>
    void bfsTraversal(Node<T>*);
    template<typename T>
    Node<T>* bfsSearchNode(Node<T>*, T);
    template<typename T>
    Node<T>* treeHeight(Node<T>*);
}