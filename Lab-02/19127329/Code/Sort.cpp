#include "Sort.h"

void SelectionSort(int a[], int n) {
    int pos;

    for (int i = 0; i < n - 1; i++) {
        pos = i;

        for (int j = i + 1; j < n; j++)
            if (a[pos] > a[j])
                pos = j;

        if (i != pos)
            swap(a[i], a[pos]);
    }
}

void InsertionSort(int a[], int n) {
    int x;
    int k;

    for (int i = 1; i < n; i++) {
        x = a[i];

        k = i - 1;
        while (k >= 0 && a[k] > x) {
            a[k + 1] = a[k];
            --k;
        }

        a[k + 1] = x;
    }
}

void BubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
            if (a[j - 1] > a[j])
                swap(a[j - 1], a[j]);
}

void HeapSort(int a[], int n) {

}

void MergeSort(int a[], int n) {

}

void QuickSort(int a[], int n) {

}

void RadixSort(int a[], int n) {

}