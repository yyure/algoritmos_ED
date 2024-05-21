#include <iostream>
#include <cstdlib>
#include "double_list_functions.h"
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
    void displayList(Node<T>** head)
    {
        if (*head == nullptr)
        {
            cout << "Lista vazia" << endl;
        } else {
            Node<T>* current = *head;
            while (current->ptrNext != nullptr)
            {
                cout << current->iPayload << " ";
                current = current->ptrNext;
            }
            cout << current->iPayload << endl;
        }
    }

    template<typename T>
    void insertFront(Node<T>** head, T iPayload)
    {
        Node<T>* temp = createNode(iPayload);

        if (*head == nullptr)
        {
            *head = temp;
        } else {
            (*head)->ptrPrev = temp;
            temp->ptrNext = *head;
            *head = temp;
        }
    }

    template<typename T>
    void insertEnd(Node<T>** head, T iPayload)
    {
        Node<T>* temp = createNode(iPayload);

        if (*head == nullptr)
        {
            *head = temp;
        } else {
            Node<T>* current = *head;
            while (current->ptrNext != nullptr)
            {
                current = current->ptrNext;
            }
            current->ptrNext = temp;
            temp->ptrPrev = current;
        }
    }

    template<typename T>
    void insertAfter(Node<T>* ptrLocation, T iPayload)
    {
        if (ptrLocation == nullptr)
        {
            cout << "Localização Vazia" << endl;
        } else {
            Node<T>* temp = createNode(iPayload);

            if (ptrLocation->ptrNext != nullptr)
            {
                ptrLocation->ptrNext->ptrPrev = temp;
                temp->ptrNext = ptrLocation->ptrNext;
            }
            ptrLocation->ptrNext = temp;
            temp->ptrPrev = ptrLocation;
        }
    }

    template<typename T>
    void insertBefore(Node<T>** head, Node<T>* ptrLocation, T iPayload)
    {
        if (*head == nullptr)
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
                *head = temp;
            }
            ptrLocation->ptrPrev = temp;
            temp->ptrNext = ptrLocation;
        }
    }

    template<typename T>
    void deleteNode(Node<T>** head, Node<T>* ptrDelete)
    {
        if (*head == nullptr)
        {
            cout << "Lista Vazia" << endl;
            return;
        }
        
        if (ptrDelete == nullptr)
        {
            cout << "Nó Vazio" << endl;
        } else {
            if (ptrDelete->ptrPrev == nullptr)
            {
                // o nó a ser deletado é o primeiro da lista
                // atualiza o ponteiro da lista para o ptrNext
                *head = ptrDelete->ptrNext;
                ptrDelete->ptrNext->ptrPrev = nullptr;
            } else if (ptrDelete->ptrNext == nullptr) {
                // o nó a ser deletado é o último da lista
                ptrDelete->ptrPrev->ptrNext = nullptr;
            } else {
                ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;
                ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev;
            }

            free(ptrDelete);
        }
    }

    template<typename T>
    void deleteList(Node<T>** head)
    {
        while(*head != nullptr)
        {
            Node<T>* nextNode = (*head)->ptrNext;
            free(*head);
            *head = nextNode;
        }
    }

    template<typename T>
    void deleteNodebyValue(Node<T>** head, T iPayload)
    {
        if (*head == nullptr)
        {
            cout << "Lista Vazia" << endl;
        } else {
            Node<T>* temp = searchNodebyValue(head, iPayload);

            deleteNode(head, temp);
        } 
    }

    template<typename T>
    Node<T>* searchNodebyValue(Node<T>** head, T iPayLoad)
    {
        if (*head == nullptr)
        {
            cout << "Lista Vazia" << endl;
        } else {
            Node<T>* current = *head;
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
    void swapValue(Node<T>* ptrNode1, Node<T>* ptrNode2)
    {
        T iTemp = ptrNode1->iPayload;
        ptrNode1->iPayload = ptrNode2->iPayload;
        ptrNode2->iPayload = iTemp;
    }

    // instanciação explícita
    template Node<int>* createNode<int>(int);
    template void displayList<int>(Node<int>**);
    template void insertFront<int>(Node<int>**, int);
    template void insertEnd<int>(Node<int>**, int);
    template void insertAfter<int>(Node<int>*, int);
    template void insertBefore<int>(Node<int>**, Node<int>*, int);
    template void deleteNode<int>(Node<int>**, Node<int>*);
    template void deleteList<int>(Node<int>**);
    template void deleteNodebyValue<int>(Node<int>**, int);
    template Node<int>* searchNodebyValue<int>(Node<int>**, int);
    template void swapValue<int>(Node<int>*, Node<int>*);

    template Node<float>* createNode<float>(float);
    template void displayList<float>(Node<float>**);
    template void insertFront<float>(Node<float>**, float);
    template void insertEnd<float>(Node<float>**, float);
    template void insertAfter<float>(Node<float>*, float);
    template void insertBefore<float>(Node<float>**, Node<float>*, float);
    template void deleteNode<float>(Node<float>**, Node<float>*);
    template void deleteList<float>(Node<float>**);
    template void deleteNodebyValue<float>(Node<float>**, float);
    template Node<float>* searchNodebyValue<float>(Node<float>**, float);
    template void swapValue<float>(Node<float>*, Node<float>*);
}