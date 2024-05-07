#include <iostream>

using std::cin;
using std::cout;
using std::endl;

typedef struct Node
{
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
} Node;

Node* createNode(int);
void insertFront(Node**, int);
void insertEnd(Node**, int);
void displayList(Node*);
void insertAfter(Node*, int);
void insertBefore(Node*, int);
void deleteNode(Node**, Node*);
void deleteNodebyValue(Node**, int);
Node* searchNodebyValue(Node**, int);
void swapValue(Node*, Node*);
void selectionSort(Node**);
void optimizedSelectionSort(Node**);

int main()
{   
    return 0;
}


Node* createNode(int iPayload)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp -> iPayload = iPayload;
    temp -> ptrNext = nullptr;
    temp -> ptrPrev = nullptr;
    
    return temp;
}


void displayList(Node* node)
{
    if (node == nullptr)
    {
        cout << "Lista vazia: Não é possível realizar displayList" << endl;
        return;
    }
    
    if  (node -> ptrPrev != nullptr)
    {
        cout << "Meio ou Fim da Lista: Não é possível realizar displayList" << endl;
        return;
    }
    
    Node* temp = node;
     
    cout << "Payload: ";
    
    while(temp != nullptr)
    {
        cout << temp -> iPayload<< " ";
        temp = temp -> ptrNext;
    }
    
    cout << endl;
}

void insertFront(Node** head, int iPayload)
{
    Node* newNode = createNode(iPayload);

    if (*head != nullptr)
    {
        (*head)->ptrPrev = newNode;
        newNode->ptrNext = (*head);
        (*head) = newNode;
        return;
    }

    (*head) = newNode;
}

void insertEnd(Node** head, int iPayload)
{
    Node* newNode = createNode(iPayload);

    if (*head == nullptr)
    {
        (*head) = newNode;
        return;
    }

    Node* temp = (*head);

    //Percorremos a lista até seu fim(ptrNext do ultimo nó é NULL)
    while(temp -> ptrNext != nullptr) temp = temp -> ptrNext;

    newNode -> ptrPrev = temp; //newNode aponta para o fim da lista
    temp -> ptrNext = newNode; //Antigo último elemento aponta para o novo nó
}

void insertAfter(Node* ptrLocation, int iPayLoad)
{
    if (ptrLocation == nullptr)
    {
        cout << "Location is NULL." << endl;
    }
    
    Node* newNode = createNode(iPayLoad);

    //Corrigir nó a ser inserido
    newNode->ptrNext = ptrLocation->ptrNext;
    newNode->ptrPrev = ptrLocation;

    //Corrigir o ponto de inserção
    ptrLocation->ptrNext = newNode;
    
    if (newNode->ptrNext != nullptr) newNode->ptrNext->ptrPrev = newNode;
}

void insertBefore(Node* ptrLocation, int iPayload)
{
    if (ptrLocation == nullptr)
    {
        cout << "Location is NULL." << endl;
    }

    Node* newNode = createNode(iPayload);

    //Corrigir nó a ser inserido
    newNode->ptrNext = ptrLocation;
    newNode->ptrPrev = ptrLocation->ptrPrev;

    //Corrigir o ponto de inserção
    ptrLocation->ptrPrev = newNode;

    if (newNode->ptrPrev != nullptr) newNode->ptrPrev->ptrNext = newNode;
}

void deleteNode(Node** head, Node* ptrDelete)
{
    if (*head == nullptr || ptrDelete == nullptr)
    {
        cout << "Não foi possível remover." << endl;
        return;
    }

    // Caso o ptrDelete seja o primeiro elemento da lista
    if (*head == ptrDelete) *head = ptrDelete->ptrNext;

    // Se o ptrDelete não é o último nó
    if (ptrDelete->ptrNext != nullptr) ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev;
    
    // Se o ptrDelete não é o primeiro nó
    if (ptrDelete->ptrPrev != nullptr) ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;

    free(ptrDelete);
}

void deleteNodebyValue(Node** head, int iValue)
{
    Node* ptrDelete = searchNodebyValue(head, iValue);


    if (ptrDelete == nullptr)
    {
        cout << "A lista não possui um nó de valor " << iValue << endl;
    }
    else
    {
        deleteNode(head, ptrDelete);
    }

    return;
}

Node* searchNodebyValue(Node** head, int iValue)
{
    if (*head == nullptr)
    {
        cout << "Lista vazia." << endl;
        return nullptr;
    }

    Node* ptrCurrent = *head;

    // Percorre a lista até encontrar um nó de valor iValue
    while (ptrCurrent != nullptr)
    {
        if (ptrCurrent->iPayload == iValue)
        {
            return ptrCurrent;
        }

        ptrCurrent = ptrCurrent->ptrNext;
    }

    cout << "A lista não possui um nó de valor " << iValue << endl;

    return nullptr;
}

void swapValue(Node* ptrNode1, Node* ptrNode2)
{
    int iTemp = ptrNode1->iPayload;
    ptrNode1->iPayload = ptrNode2->iPayload;
    ptrNode2->iPayload = iTemp;

    return;
}

void bubbleSort(Node** head, int iLength)
{
    if (*head == nullptr)
    {
        cout << "Lista vazia." << endl;
        return;
    }

    Node* ptrCurrent = nullptr;

    for (int i = 1; i < iLength; i++)
    {
        ptrCurrent = *head;

        while (ptrCurrent->ptrNext != nullptr)
        {
            if (ptrCurrent->iPayload > ptrCurrent->ptrNext->iPayload)
            {
                swapValue(ptrCurrent, ptrCurrent->ptrNext);
            }

            ptrCurrent = ptrCurrent->ptrNext;
        }
    }

    return;
}

void selectionSort(Node** head)
{
    if (*head == nullptr)
    {
        cout << "Lista vazia." << endl;
        return;
    }

    Node* ptrOuterLoop = *head;
    Node* ptrInnerLoop = nullptr;

    while (ptrOuterLoop != nullptr)
    {
        ptrInnerLoop = ptrOuterLoop->ptrNext;

        while(ptrInnerLoop != nullptr)
        {
            if (ptrInnerLoop->iPayload > ptrOuterLoop->iPayload)
            {
                swapValue(ptrOuterLoop, ptrInnerLoop);
            }

            ptrInnerLoop = ptrInnerLoop->ptrNext;
        }

        ptrOuterLoop = ptrOuterLoop->ptrNext;
    }

    return;
}

void optimizedSelectionSort(Node** head)
{
    if (*head == nullptr)
    {
        cout << "Lista vazia." << endl;
        return;
    }

    Node* ptrOuterLoop = *head;
    Node* ptrInnerLoop = nullptr;
    Node* ptrMinNode = nullptr;

    while (ptrOuterLoop != nullptr)
    {
        ptrMinNode = ptrOuterLoop;
        ptrInnerLoop = ptrOuterLoop->ptrNext;

        while(ptrInnerLoop != nullptr)
        {
            if (ptrInnerLoop->iPayload > ptrMinNode->iPayload)
            {
                ptrMinNode = ptrInnerLoop;
            }

            ptrInnerLoop = ptrInnerLoop->ptrNext;
        }

        swapValue(ptrOuterLoop, ptrMinNode);

        ptrOuterLoop = ptrOuterLoop->ptrNext;
    }

    return;
}