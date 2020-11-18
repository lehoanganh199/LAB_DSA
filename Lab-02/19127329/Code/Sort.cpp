#include "Sort.h"
#include <algorithm> // use function std::swap.
#include <cmath> // use function log10.

using namespace std;

// Declare some functions to support.
void mergeArray(int a[], int left, int mid, int right);
void MergeSortImp(int a[], int left, int right);
void shift(int a[], int left, int right);
void createHeap(int a[], int n);
void QuickSortImp(int a[], int left, int right);
int findMax(int a[], int n);
void findMaxAndMin(int a[], int n, int &maxElement, int &minElement);
// End of declaration.


// Implement some functions to support.
void mergeArray(int a[], int left, int mid, int right) {
    int n = mid - left + 1;
    int m = right - mid;

    int b[n], c[m];
    for (int i = left; i <= mid; i++) 
        b[i - left] = a[i];
    for (int i = mid + 1; i <= right; i++)
        c[i - mid - 1] = a[i];

    int ib = 0, ic = 0, ia = left;
    while (ib < n && ic < m) {
        if (b[ib] <= c[ic])
            a[ia++] = b[ib++];
        else 
            a[ia++] = c[ic++];
    }

    while (ib < n)
        a[ia++] = b[ib++];
    while (ic < m)
        a[ia++] = c[ic++];
}

void MergeSortImp(int a[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        MergeSortImp(a, left, mid);
        MergeSortImp(a, mid + 1, right);
        mergeArray(a, left, mid, right);
    }
}

void shift(int a[], int left, int right) {
    int i = left;
    int j = 2 * i;
    int x = a[i];

    while (j <= right) {
        if (j < right && a[j + 1] > a[j])
            ++j;

        if (x >= a[j])
            break;
        
        a[i] = a[j];
        i = j;
        j = 2 * i;
    }

    a[i] = x;
}

void createHeap(int a[], int n) {
    int i = n / 2;

    while (i >= 0) {
        shift(a, i, n - 1);
        --i;
    }
}

void QuickSortImp(int a[], int left, int right) {
    int i = left;
    int j = right;
    int x = a[(left + right) / 2];

    do {
        while (a[i] < x) ++i;
        while (x < a[j]) --j;

        if (i <= j) {
            swap(a[i], a[j]);
            ++i;
            --j;
        }
    } while (i <= j);

    if (left < j)
        QuickSortImp(a, left, j);
    if (i < right)
        QuickSortImp(a, i, right);
}

int findMax(int a[], int n) {
    int maxValue = a[0];

    for (int i = 1; i < n; i++)
        if (maxValue < a[i])
            maxValue = a[i];

    return maxValue;
}

void findMaxAndMin(int a[], int n, int &maxElement, int &minElement) {
    maxElement = a[0];
    minElement = a[0];

    for (int i = 1; i < n; i++) {
        if (maxElement < a[i])
            maxElement = a[i];
        else if (minElement > a[i])
            minElement = a[i];
    }
}
// End of implementation.


// The functions are declared in "Sort.h" file.
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

void BinaryInsertionSort(int a[], int n) {
    int x;

    for (int i = 1; i < n; i++) {
        x = a[i];

        int left = 0;
        int right = i - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (a[mid] <= x)
                left = mid + 1;
            else 
                right = mid - 1;
        }

        for (int j = i - 1; j > left; j--)
            a[j] = a[j - 1];

        a[left] = x;
    }
}

void BubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
            if (a[j - 1] > a[j])
                swap(a[j - 1], a[j]);
}

void ShakerSort(int a[], int n) {
    int left = 1;
    int right = n - 1;
    int lastPosition = 0;

    do {
        for (int i = right; i >= left; i--)
            if (a[i - 1] > a[i]) {
                swap(a[i - 1], a[i]);
                lastPosition = i;
            }

        left = lastPosition + 1;

        for (int i = left; i <= right; i++)
            if (a[i - 1] > a[i]) {
                swap(a[i - 1], a[i]);
                lastPosition = i;
            }

        right = lastPosition - 1;
    } while (left <= right);
}

void ShellSort(int a[], int n) {

}

void HeapSort(int a[], int n) {
    createHeap(a, n);

    int right = n - 1;
    while (right > 0) {
        swap(a[0], a[right]);
        --right;
        shift(a, 0, right);
    }
}

void MergeSort(int a[], int n) {
    MergeSortImp(a, 0, n - 1);
}

void QuickSort(int a[], int n) {
    if (n > 1)
        QuickSortImp(a, 0, n - 1);
}

void CoutingSort(int a[], int n) {

}

void RadixSort(int a[], int n) {
    int maxElement = findMax(a, n);
    int maxCountDigit = (int)log10(maxElement) + 1;
    int temp = 1;

    int* size = new int[10]{0};
    int** classify = new int*[10];
    for (int i = 0; i < 10; i++)
        classify[i] = new int[n];

    while (maxCountDigit > 0) {
        for (int i = 0; i < n; i++) {
            int digit = (a[i] / temp) % 10;
            classify[digit][size[digit]++] = a[i];
        }

        int j = 0;
        int* index = new int[10]{0};
        for (int i = 0; i < n; i++) {
            while (size[j] == 0 || index[j] == size[j]) 
                ++j;

            a[i] = classify[j][index[j]++];
        }
        delete[] index;

        temp *= 10;
        --maxCountDigit;
    }

    delete[] size;
    for (int i = 0; i < 10; i++)
        delete[] classify[i];
    delete[] classify;
}

// don't optimize.
void FlashSort(int a[], int n) {
    // find max and min.
    int maxElement;
    int minElement;
    findMaxAndMin(a, n, maxElement, minElement);

    // count the number of classes.
    int countClasses = 4;

    // separate classes.
    int* classes = new int[maxElement + 1];
    int* size = new int[countClasses] {0};

    for (int i = 0; i < n; i++) {
        int k = ((countClasses - 1) * (a[i] - minElement)) / (maxElement - minElement);
        classes[a[i]] = k;
        ++size[k];
    }

    int* sizeCurrent = new int[countClasses] {0};
    int* dummy = new int[n];
    for (int i = 0; i < n; i++) {
        int index = sizeCurrent[classes[a[i]]]++;
        for (int j = 0; j < classes[a[i]]; j++)
            index += size[j];
    
        dummy[index] = a[i];
    }

    int offset = 0;
    for (int i = 0; i < countClasses; i++) {
        SelectionSort(dummy + offset, size[i]);
        offset += size[i];
    }

    for (int i = 0; i < n; i++)
        a[i] = dummy[i];

    delete[] dummy;
    delete[] sizeCurrent;
    delete[] classes;
    delete[] size;
}
