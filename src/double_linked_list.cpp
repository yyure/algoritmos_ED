#include <iostream>
#include <cstdlib>
#include "double_list_functions.h"
#include "sort_functions.h"

using std::cout;
using std::endl;

namespace DoubleLinkedList
{
    Node* createNode(int iPayLoad)
    {
        Node* temp = (Node*) malloc(sizeof(Node));

        if (temp != nullptr)
        {
            temp->iPayload = iPayLoad;
            temp->ptrNext = nullptr;
            temp->ptrPrev = nullptr;
        }
        return temp;
    }

    void displayList(Node** head)
    {
        if (*head == nullptr)
        {
            cout << "Lista vazia" << endl;
        } else {
            Node* current = *head;
            while (current->ptrNext != nullptr)
            {
                cout << current->iPayload << " ";
                current = current->ptrNext;
            }
            cout << current->iPayload << endl;
        }
    }

    void insertFront(Node** head, int iPayload)
    {
        Node* temp = createNode(iPayload);

        if (*head == nullptr)
        {
            *head = temp;
        } else {
            (*head)->ptrPrev = temp;
            temp->ptrNext = *head;
            *head = temp;
        }
    }

    void insertEnd(Node** head, int iPayload)
    {
        Node* temp = createNode(iPayload);

        if (*head == nullptr)
        {
            *head = temp;
        } else {
            Node* current = *head;
            while (current->ptrNext != nullptr)
            {
                current = current->ptrNext;
            }
            current->ptrNext = temp;
            temp->ptrPrev = current;
        }
    }

    void insertAfter(Node* ptrLocation, int iPayload)
    {
        if (ptrLocation == nullptr)
        {
            cout << "Localização Vazia" << endl;
        } else {
            Node* temp = createNode(iPayload);

            if (ptrLocation->ptrNext != nullptr)
            {
                ptrLocation->ptrNext->ptrPrev = temp;
                temp->ptrNext = ptrLocation->ptrNext;
            }
            ptrLocation->ptrNext = temp;
            temp->ptrPrev = ptrLocation;
        }
    }

    void insertBefore(Node** head, Node* ptrLocation, int iPayload)
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
            Node* temp = createNode(iPayload);

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

    void deleteNode(Node** head, Node* ptrDelete)
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

    void deleteList(Node** head)
    {
        while(*head != nullptr)
        {
            Node* nextNode = (*head)->ptrNext;
            free(*head);
            *head = nextNode;
        }
    }

    void deleteNodebyValue(Node** head, int iPayload)
    {
        if (*head == nullptr)
        {
            cout << "Lista Vazia" << endl;
        } else {
            Node* temp = searchNodebyValue(head, iPayload);

            deleteNode(head, temp);
        } 
    }

    Node* searchNodebyValue(Node** head, int iPayLoad)
    {
        if (*head == nullptr)
        {
            cout << "Lista Vazia" << endl;
        } else {
            Node* current = *head;
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

    void swapValue(Node* ptrNode1, Node* ptrNode2)
    {
        int iTemp = ptrNode1->iPayload;
        ptrNode1->iPayload = ptrNode2->iPayload;
        ptrNode2->iPayload = iTemp;
    }
}