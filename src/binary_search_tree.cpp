#include <iostream>

#include "binary_search_tree.h"
#include "double_list_functions.h"

using std::cout;
using std::endl;
using std::cerr;

namespace BinarySearchTree
{
    template<typename T>
    Node<T>* createTreeNode(T value)
    {
        Node<T>* tmp = (Node<T>*) malloc(sizeof(Node<T>));
        
        if (tmp == nullptr)
        {
            cerr << "Erro em createTreeNode: malloc" << endl;
            exit(1);
        }
        
        tmp->iPayload = value;
        tmp->ptrLeft = nullptr;
        tmp->ptrRight = nullptr;
        
        return tmp;
    }

    template<typename T>
    Node<T>* insertNode(Node<T>* startingNode, T iData)
    {
        if(startingNode == nullptr)
        {
            return createTreeNode(iData);
        }
        
        if(iData < startingNode->iPayload)
        {
            startingNode->ptrLeft = insertNode(startingNode->ptrLeft, iData);
        }
        else
        {
            startingNode->ptrRight = insertNode(startingNode->ptrRight, iData);
        }
        
        return startingNode;
    }

    template<typename T>
    Node<T>* searchNode(Node<T>* startingNode, T iData)
    {
        if(startingNode == nullptr) return nullptr;
        else if(iData == startingNode->iPayload) return startingNode;
        else if(iData < startingNode->iPayload) return searchNode(startingNode->ptrLeft, iData);
        else return searchNode(startingNode->ptrRight, iData);
    }

    template<typename T>
    Node<T>* lesserLeaf(Node<T>* startingNode)
    {
        Node<T>* ptrCurrent = startingNode;
    
        while (ptrCurrent && ptrCurrent->ptrLeft != nullptr) ptrCurrent = ptrCurrent->ptrLeft;
        
        return ptrCurrent;
    }

    template<typename T>
    Node<T>* deleteNode(Node<T>* startingNode, T iData)
    {
        if (startingNode == nullptr) return nullptr;
        
        if (iData < startingNode->iPayload) startingNode->ptrLeft = deleteNode(startingNode->ptrLeft, iData);
        else if (iData > startingNode->iPayload) startingNode->ptrRight = deleteNode(startingNode->ptrRight, iData);
        else
        {
            Node<T>* ptrTemp = nullptr;
            
            if (startingNode->ptrLeft == nullptr)
            {
                ptrTemp = startingNode->ptrRight;
                free(startingNode);
                return ptrTemp;
            }
            else if (startingNode->ptrRight == nullptr)
            {
                ptrTemp = startingNode->ptrLeft;
                free(startingNode);
                return ptrTemp;            
            }
            
            ptrTemp = lesserLeaf(startingNode->ptrRight);
            
            startingNode->iPayload = ptrTemp->iPayload;
            
            startingNode->ptrRight = deleteNode(startingNode->ptrRight, ptrTemp->iPayload);
        }
        
        return startingNode;
    }

    template<typename T>
    void traversePreOrder(Node<T>* ptrStartingNode)
    {
        if (ptrStartingNode != nullptr)
        {
            cout << " " << ptrStartingNode->iPayload;
            traversePreOrder(ptrStartingNode->ptrLeft);
            traversePreOrder(ptrStartingNode->ptrRight);
        }
    }

    template<typename T>
    void traverseInOrder(Node<T>* ptrStartingNode)
    {
        if (ptrStartingNode != nullptr)
        {
            traverseInOrder(ptrStartingNode->ptrLeft);
            cout << " " << ptrStartingNode->iPayload;
            traverseInOrder(ptrStartingNode->ptrRight);
        }
    }

    template<typename T>
    void traversePostOrder(Node<T>* ptrStartingNode)
    {
        if (ptrStartingNode != nullptr)
        {
            traversePostOrder(ptrStartingNode->ptrLeft);
            traversePostOrder(ptrStartingNode->ptrRight);
            cout << " " << ptrStartingNode->iPayload;
        }
    }

    template<typename T>
    void bfsTraversal(Node<T>* startingNode)
    {
        if (startingNode == nullptr) return;
        
        // Parte 1 do Trabalho: Alterar para Lista Encadeada
        DoubleLinkedList::List<Node<T>*>* queue = DoubleLinkedList::createList<Node<T>*>();

        DoubleLinkedList::insertEnd(queue, startingNode);

        while (queue->ptrHead != nullptr)
        {
            Node<T>* current = queue->ptrHead->iPayload;
            cout << current->iPayload << " ";
            DoubleLinkedList::deleteNode(queue, queue->ptrHead);
            
            if (current->ptrLeft != nullptr) DoubleLinkedList::insertEnd(queue, current->ptrLeft);
            if (current->ptrRight != nullptr) DoubleLinkedList::insertEnd(queue, current->ptrRight);
        }
    }

    // instanciação explícita
    template Node<int>* createTreeNode<int>(int);
    template Node<int>* insertNode<int>(Node<int>*, int);
    template Node<int>* searchNode<int>(Node<int>*, int);
    template Node<int>* lesserLeaf<int>(Node<int>*);
    template Node<int>* deleteNode<int>(Node<int>*, int);
    template void traversePreOrder<int>(Node<int>*);
    template void traverseInOrder<int>(Node<int>*);
    template void traversePostOrder<int>(Node<int>*);
    template void bfsTraversal<int>(Node<int>*);

    template Node<float>* createTreeNode<float>(float);
    template Node<float>* insertNode<float>(Node<float>*, float);
    template Node<float>* searchNode<float>(Node<float>*, float);
    template Node<float>* lesserLeaf<float>(Node<float>*);
    template Node<float>* deleteNode<float>(Node<float>*, float);
    template void traversePreOrder<float>(Node<float>*);
    template void traverseInOrder<float>(Node<float>*);
    template void traversePostOrder<float>(Node<float>*);
    template void bfsTraversal<float>(Node<float>*);
}