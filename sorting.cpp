#include <iostream>
#include <chrono>
#include <random>

// iostream
using std::cin;
using std::cout;
using std::endl;

// chrono
using std::micro;
using std::chrono::duration;
using std::chrono::high_resolution_clock;

// random
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

typedef struct Node
{
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
} Node;

int randomNumberGenerate(int, int);
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
void bubbleSort(Node**, int);
void optimizedBubbleSort(Node**, int);
void selectionSort(Node**);
void optimizedSelectionSort(Node**);

int main()
{
    
    Node* lista1 = createNode(0);
    Node* lista2 = createNode(0);
    Node* lista3 = createNode(0);
    Node* lista4 = createNode(0);
    
    for (int i = 0; i < 29999; i++) {
        insertFront(&lista1, randomNumberGenerate(-69696969, 69696969));
        insertFront(&lista2, randomNumberGenerate(-69696969, 69696969));
        insertFront(&lista3, randomNumberGenerate(-69696969, 69696969));
        insertFront(&lista4, randomNumberGenerate(-69696969, 69696969));
    }
    
    // ------------------------ BUBBLE SORT ------------------------
    auto start = high_resolution_clock::now();
    
    bubbleSort(&lista1, 30000);
    
    auto end = high_resolution_clock::now();
    
    duration<double, micro> duration = end - start;

    cout << "Tempo de execução (BUBBLE): " << duration.count() << " microssegundos" << endl;
    
    // ------------------------ OPTIMIZED BUBBLE SORT ------------------------
    start = high_resolution_clock::now();
    
    optimizedBubbleSort(&lista2, 30000);
    
    end = high_resolution_clock::now();
    
    duration = end - start;

    cout << "Tempo de execução (OPTIMIZED BUBBLE): " << duration.count() << " microssegundos" << endl;
    
    // ------------------------ SELECTION SORT ------------------------
    start = high_resolution_clock::now();
    
    selectionSort(&lista3);
    
    end = high_resolution_clock::now();
    
    duration = end - start;

    cout << "Tempo de execução (SELECTION): " << duration.count() << " microssegundos" << endl;
    
    // ------------------------ OPTIMIZED SELECTION SORT ------------------------
    start = high_resolution_clock::now();
    
    optimizedSelectionSort(&lista4);
    
    end = high_resolution_clock::now();
    
    duration = end - start;

    cout << "Tempo de execução (OPTIMIZED SELECTION): " << duration.count() << " microssegundos" << endl;

    return 0;
}

int randomNumberGenerate(int iMin, int iMax)
{
    // Cria um gerador de números pseudo-aleatórios
    random_device rd;
    mt19937 gen(rd());
    
    // Cria uma distribuição uniforme de inteiros dentro da faixa especificada
    uniform_int_distribution<int> dist(iMin, iMax);

    // Retorna um número aleatório
    return dist(gen);
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

void optimizedBubbleSort(Node** head, int iLength)
{
    if (*head == nullptr)
    {
        cout << "Lista vazia." << endl;
        return;
    }

    Node* ptrCurrent = nullptr;
    
    // Inicia o ptrFinal no último nó da lista
    // ptrFinal: ponteiro da posição que indica o fim de cada loop
    Node* ptrFinal = *head;
    while(ptrFinal -> ptrNext != nullptr) ptrFinal = ptrFinal -> ptrNext;
    
    int iOrdened = 0;

    for (int i = 1; i < iLength; i++)
    {
        ptrCurrent = *head;

        while (ptrCurrent->ptrNext != ptrFinal->ptrNext)
        {
            if (ptrCurrent->iPayload > ptrCurrent->ptrNext->iPayload)
            {
                swapValue(ptrCurrent, ptrCurrent->ptrNext);
                iOrdened = 1;
            }

            ptrCurrent = ptrCurrent->ptrNext;
        }
        
        if (!iOrdened) return; // caso em que a lista já está ordenada
        ptrFinal = ptrFinal->ptrPrev;
        iOrdened = 0; // atualiza a verificação
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
            if (ptrInnerLoop->iPayload < ptrOuterLoop->iPayload)
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
            if (ptrInnerLoop->iPayload < ptrMinNode->iPayload)
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
