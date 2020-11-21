#include <iostream>
#include "Sort.h"
#include "DataGenerator.h"
#include <iomanip>
#include <vector>

using namespace std;

enum DataOrder { RANDOM, SORTED, REVERSE, NEARLY };
enum SortAlgorithms { 
    SELECTION, INSERTION, BINARY_INSERTION, BUBBLE, SHAKER,
    SHELL, HEAP, MERGE, COUNTING, QUICK, RADIX, FLASH 
};

double sortAndMeasureTime(int* &a, int n, int type) {
    double runTime = -1;
    clock_t start;

    switch (type) {
    case SELECTION:
        start = clock();
        SelectionSort(a, n);
        runTime = (double) (clock() - start) / CLOCKS_PER_SEC;
        break;
    case INSERTION:
        start = clock();
        InsertionSort(a, n);
        runTime = (double) (clock() - start) / CLOCKS_PER_SEC;
        break;
    case BINARY_INSERTION:
        start = clock();
        BinaryInsertionSort(a, n);
        runTime = (double) (clock() - start) / CLOCKS_PER_SEC;
        break;
    case BUBBLE:
        start = clock();
        BubbleSort(a, n);
        runTime = (double) (clock() - start) / CLOCKS_PER_SEC;
        break;
    case SHAKER:
        start = clock();
        ShakerSort(a, n);
        runTime = (double) (clock() - start) / CLOCKS_PER_SEC;
        break;
    case SHELL:
        start = clock();
        ShellSort(a, n);
        runTime = (double) (clock() - start) / CLOCKS_PER_SEC;
        break;
    case HEAP:
        start = clock();
        HeapSort(a, n);
        runTime = (double) (clock() - start) / CLOCKS_PER_SEC;
        break;
    case MERGE:
        start = clock();
        MergeSort(a, n);
        runTime = (double) (clock() - start) / CLOCKS_PER_SEC;
        break;
    case COUNTING:
        start = clock();
        CountingSort(a, n);
        runTime = (double) (clock() - start) / CLOCKS_PER_SEC;
        break;
    case QUICK:
        start = clock();
        QuickSort(a, n);
        runTime = (double) (clock() - start) / CLOCKS_PER_SEC;
        break;
    case RADIX:
        start = clock();
        RadixSort(a, n);
        runTime = (double) (clock() - start) / CLOCKS_PER_SEC;
        break;
    case FLASH:
        start = clock();
        FlashSort(a, n);
        runTime = (double) (clock() - start) / CLOCKS_PER_SEC;
        break;
    default:
        break;
    }
    
    return runTime;
}

int main() {
    vector<int> dataSize { 3000, 10000, 30000, 100000, 300000 };
    vector<string> dataOrder { "Random", "Sorted", "Reverse", "Nearly" };
    vector<string> algorithms {
        "Selection Sort", "Insertion Sort", "Binary Insertion Sort", "Bubble Sort",
        "Shaker Sort", "Shell Sort", "Heap Sort", "Merge Sort", "Counting Sort", "Quick Sort",
        "Radix Sort", "Flash Sort"
    };

    int* a = nullptr;

    for (int i = 0; i < dataOrder.size(); i++) {
        for (int j = 0; j < dataSize.size(); j++) {
            // for (int k = 0; k < algorithms.size(); k++) {
            //     a = new int[dataSize[j]];

            //     if (a == nullptr) {
            //         cout << "Error: not enough memory." << endl;
            //         j = dataSize.size();
            //         i = dataOrder.size();
            //         break;
            //     }

            //     GenerateData(a, dataSize[j], i);

            //     double runTime = sortAndMeasureTime(a, dataSize[j], k);
            //     cout << "----------------------------------------" << endl;
            //     cout << "- Algorithm : " << algorithms[k] << endl;
            //     cout << "- Data Size : " << dataSize[j] << endl;
            //     cout << "- Data Order: " << dataOrder[i] << endl;
            //     cout << "- Time      : " << fixed << setprecision(9) << runTime << "s" << endl;
            //     cout << "----------------------------------------" << endl;

            //     delete[] a;
            // }

            a = new int[dataSize[j]];

            if (a == nullptr) {
                cout << "Error: not enough memory." << endl;
                j = dataSize.size();
                i = dataOrder.size();
                break;
            }

            GenerateData(a, dataSize[j], i);

            double runTime = sortAndMeasureTime(a, dataSize[j], FLASH);
            cout << "----------------------------------------" << endl;
            cout << "- Algorithm : " << algorithms[FLASH] << endl;
            cout << "- Data Size : " << dataSize[j] << endl;
            cout << "- Data Order: " << dataOrder[i] << endl;
            cout << "- Time      : " << fixed << setprecision(9) << runTime << "s" << endl;
            cout << "----------------------------------------" << endl;

            delete[] a;
        }
    }

    return 0;
}
