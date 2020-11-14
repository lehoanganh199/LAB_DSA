#include "Sort.h"

void mergeArray(int a[], int left, int mid, int right);
void MergeSortImp(int a[], int left, int right);

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

void shift(int a[], int left, int right) {
    int i = left;
    int j = 2 * i;
    int x = a[i];

    while (j <= right) {
        if (j < right && a[j + 1] > a[j])
            ++j;

        if (x > a[j])
            break;
        
        a[i] = a[j];
        i = j;
        j = 2 * i;
    }

    a[i] = x;
}

void createHeap(int a[], int n) {
    int left = n / 2;

    while (left >= 0) {
        shift(a, left, n - 1);
        --left;
    }
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

void MergeSort(int a[], int n) {
    MergeSortImp(a, 0, n - 1);
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

void QuickSort(int a[], int n) {
    if (n > 1)
        QuickSortImp(a, 0, n - 1);
}

void RadixSort(int a[], int n) {

}