#include <iostream>
#include <cstdlib>
#include <chrono>

#include "src/sort_functions.h"
#include "src/double_list_functions.h"

// iostream
using std::cout;
using std::endl;

// chrono
using std::chrono::nanoseconds;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;

int randomNumberGenerate(int, int);

int main()
{   
    Node* head;

    for (int i = 0; i < 100; i++) {

        head = NULL;

        for (int j = 0; j < 10000; j++) {
            insertFront(&head, rand());
        }
        auto start = high_resolution_clock::now();

        optimizedSelectionSort(&head); // Modifique, se quiser, a função de ordenação
        
        auto end = high_resolution_clock::now();
        
        auto duration = duration_cast<nanoseconds>(end - start);

        cout << duration.count() << endl;
    }

    return 0;
}