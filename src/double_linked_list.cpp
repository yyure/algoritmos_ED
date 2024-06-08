#include <iostream>
#include <cstdlib>

#include "double_list_functions.h"
#include "binary_search_tree.h"
#include "sort_functions.h"

using std::cout;
using std::endl;

namespace DoubleLinkedList
{
    template<typename T>
    Node<T>* createNode(T iPayLoad)
    {
        Node<T>* temp = (Node<T>*) malloc(sizeof(Node<T>));

        if (temp != nullptr)
        {
            temp->iPayload = iPayLoad;
            temp->ptrNext = nullptr;
            temp->ptrPrev = nullptr;
        }
        return temp;
    }

    template<typename T>
    List<T>* createList()
    {
        List<T>* temp = (List<T>*) malloc(sizeof(List<T>));

        if (temp != nullptr)
        {
            temp->ptrHead = nullptr;
            temp->ptrTail = nullptr;
        }
        return temp;
    }

    template<typename T>
    void displayList(List<T>* list)
    {
        if (list->ptrHead == nullptr)
        {
            cout << "Lista vazia" << endl;
        } else {
            Node<T>* current = list->ptrHead;
            while (current->ptrNext != nullptr)
            {
                cout << current->iPayload << " ";
                current = current->ptrNext;
            }
            cout << current->iPayload << endl;
        }
    }

    template<typename T>
    void insertFront(List<T>* list, T iPayload)
    {
        Node<T>* temp = createNode(iPayload);

        if (list->ptrHead == nullptr)
        {
            list->ptrHead = temp;
            list->ptrTail = temp;
        } else {
            temp->ptrNext = list->ptrHead;
            list->ptrHead->ptrPrev = temp;
            list->ptrHead = temp;
        }
    }

    template<typename T>
    void insertEnd(List<T>* list, T iPayload)
    {
        Node<T>* temp = createNode(iPayload);

        if (list->ptrHead == nullptr)
        {
            list->ptrHead = temp;
            list->ptrTail = temp;
        } else {
            list->ptrTail->ptrNext = temp;
            temp->ptrPrev = list->ptrTail;
            list->ptrTail = temp;
        }
    }

    template<typename T>
    void insertAfter(List<T>* list, Node<T>* ptrLocation, T iPayload)
    {
        if (list->ptrHead == nullptr)
        {
            cout << "Lista Vazia" << endl;
            return;
        }

        if (ptrLocation == nullptr)
        {
            cout << "Localização Vazia" << endl;
        } else {
            Node<T>* temp = createNode(iPayload);

            if (ptrLocation->ptrNext != nullptr)
            {
                ptrLocation->ptrNext->ptrPrev = temp;
                temp->ptrNext = ptrLocation->ptrNext;
            } else {
                // o nó inserido torna-se o último da lista
                // atualiza o ponteiro da lista para o nó
                list->ptrTail = temp;
            }
            ptrLocation->ptrNext = temp;
            temp->ptrPrev = ptrLocation;
        }
    }

    template<typename T>
    void insertBefore(List<T>* list, Node<T>* ptrLocation, T iPayload)
    {
        if (list->ptrHead == nullptr)
        {
            cout << "Lista Vazia" << endl;
            return;
        }

        if (ptrLocation == nullptr)
        {
            cout << "Localização Vazia" << endl;
        } else {
            Node<T>* temp = createNode(iPayload);

            if (ptrLocation->ptrPrev != nullptr)
            {
                ptrLocation->ptrPrev->ptrNext = temp;
                temp->ptrPrev = ptrLocation->ptrPrev;
            } else {
                // o nó inserido torna-se o primeiro da lista
                // atualiza o ponteiro da lista para o nó
                list->ptrHead = temp;
            }
            ptrLocation->ptrPrev = temp;
            temp->ptrNext = ptrLocation;
        }
    }

    template<typename T>
    void deleteNode(List<T>* list, Node<T>* ptrDelete)
    {
        if (list->ptrHead == nullptr)
        {
            cout << "Lista Vazia" << endl;
        } else {
            if (ptrDelete->ptrPrev != nullptr)
            {
                ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;
            } else {
                list->ptrHead = ptrDelete->ptrNext;
            }

            if (ptrDelete->ptrNext != nullptr)
            {
                ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev;
            } else {
                list->ptrTail = ptrDelete->ptrPrev;
            }

            free(ptrDelete);
        }
    }

    template<typename T>
    void deleteList(List<T>* list)
    {
        while(list->ptrHead != nullptr)
        {
            Node<T>* nextNode = list->ptrHead->ptrNext;
            free(list->ptrHead);
            list->ptrHead = nextNode;
        }
    }

    template<typename T>
    Node<T>* searchNodebyValue(List<T>* list, T iPayLoad)
    {
        if (list->ptrHead == nullptr)
        {
            cout << "Lista Vazia" << endl;
        } else {
            Node<T>* current = list->ptrHead;
            while (current->ptrNext != nullptr)
            {
                if (current->iPayload == iPayLoad)
                {
                    return current;
                }
                current = current->ptrNext;
            }

            cout << "Nó não Encontrado" << endl;
        }
        return nullptr;
    }

    template<typename T>
    void deleteNodebyValue(List<T>* list, T iPayload)
    {
        if (list->ptrHead == nullptr)
        {
            cout << "Lista Vazia" << endl;
        } else {
            Node<T>* temp = searchNodebyValue(list, iPayload);

            deleteNode(list, temp);
        }
    }

    template<typename T>
    void swapValue(Node<T>* ptrNode1, Node<T>* ptrNode2)
    {
        T iTemp = ptrNode1->iPayload;
        ptrNode1->iPayload = ptrNode2->iPayload;
        ptrNode2->iPayload = iTemp;
    }

    // instanciação explícita
    template List<int>* createList<int>();
    template Node<int>* createNode<int>(int);
    template void displayList<int>(List<int>*);
    template void insertFront<int>(List<int>*, int);
    template void insertEnd<int>(List<int>*, int);
    template void insertAfter<int>(List<int>*, Node<int>*, int);
    template void insertBefore<int>(List<int>*, Node<int>*, int);
    template void deleteNode<int>(List<int>*, Node<int>*);
    template void deleteList<int>(List<int>*);
    template void deleteNodebyValue<int>(List<int>*, int);
    template Node<int>* searchNodebyValue<int>(List<int>*, int);
    template void swapValue<int>(Node<int>*, Node<int>*);

    template List<float>* createList<float>();
    template Node<float>* createNode<float>(float);
    template void displayList<float>(List<float>*);
    template void insertFront<float>(List<float>*, float);
    template void insertEnd<float>(List<float>*, float);
    template void insertAfter<float>(List<float>*, Node<float>*, float);
    template void insertBefore<float>(List<float>*, Node<float>*, float);
    template void deleteNode<float>(List<float>*, Node<float>*);
    template void deleteList<float>(List<float>*);
    template void deleteNodebyValue<float>(List<float>*, float);
    template Node<float>* searchNodebyValue<float>(List<float>*, float);
    template void swapValue<float>(Node<float>*, Node<float>*);

    template List<BinarySearchTree::Node<int>*>* createList<BinarySearchTree::Node<int>*>();
    template Node<BinarySearchTree::Node<int>*>* createNode<BinarySearchTree::Node<int>*>(BinarySearchTree::Node<int>*);
    template void insertEnd<BinarySearchTree::Node<int>*>(List<BinarySearchTree::Node<int>*>*, BinarySearchTree::Node<int>*);
    template void deleteNode<BinarySearchTree::Node<int>*>(List<BinarySearchTree::Node<int>*>*, Node<BinarySearchTree::Node<int>*>*);

    template List<BinarySearchTree::Node<float>*>* createList<BinarySearchTree::Node<float>*>();
    template Node<BinarySearchTree::Node<float>*>* createNode<BinarySearchTree::Node<float>*>(BinarySearchTree::Node<float>*);
    template void insertEnd<BinarySearchTree::Node<float>*>(List<BinarySearchTree::Node<float>*>*, BinarySearchTree::Node<float>*);
    template void deleteNode<BinarySearchTree::Node<float>*>(List<BinarySearchTree::Node<float>*>*, Node<BinarySearchTree::Node<float>*>*);
}