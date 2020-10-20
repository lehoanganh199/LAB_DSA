//
//  Pointer.cpp
//  test-cpp
//
//  Created by Le Hoang Anh on 10/19/20.
//

#include "Pointer.h"

void inputArray(int* &a, int &n) {
    if (a != nullptr)
        delete[] a;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n > 0) {
        a = new int[n];

        for (int i = 0; i < n; i++) {
            cout << "Enter a[" << i << "] = ";
            cin >> a[i];
        }
    }
}

void deallocateArray(int* &a) {
    if (a != nullptr)
        delete[] a;
}

void printArray(int* a, int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

int findMin(int* a, int n) {
    int minValue = a[0];

    for (int i = 1; i < n; i++)
        if (minValue > a[i])
            minValue = a[i];

    return minValue;
}

int findMaxAbsolute(int* a, int n) {
    int maxAbs = abs(a[0]);

    for (int i = 1; i < n; i++)
        if (maxAbs < abs(a[i]))
            maxAbs = abs(a[i]);

    return maxAbs;
}

bool isAscending(int* a, int n) {
    for (int i = 0; i < n - 1; i++)
        if (!(a[i] <= a[i + 1]))
            return false;

    return true;
}

int sumOfArray(int* a, int n) {
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += a[i];

    return sum;
}

bool isPrime(int n) {
    if (n < 2)
        return false;

    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}

int countPrime(int* a, int n) {
    int count = 0;

    for (int i = 0; i < n; i++)
        if (isPrime(a[i]))
            ++count;

    return count;
}

void reverseArray(int* &a, int* b, int n) {
    if (b != nullptr)
        delete[] b;

    b = new int[n];

    for (int i = 0; i < n; i++)
        b[i] = a[n - 1 - i];
}

int LinearSearch(int* a, int n, int key) {
    for (int i = 0; i < n; i++)
        if (a[i] == key)
            return i;

    return -1;
}

int SentinelLinearSearch(int* a, int n, int key) {
    a[n] = key;
    int i = 0;

    for (i = 0;; i++)
        if (a[i] == key)
            break;

    return (i == n) ? -1 : i;
}

int BinarySearch(int* a, int n, int key) {
    int left = 0;
    int right = n - 1;
    int mid;

    while (left < right) {
        mid = (left + right) / 2;

        if (a[mid] == key)
            return mid;
        if (a[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int RecursiveBinarySearch(int* a, int left, int right, int key) {
    int mid = (left + right) / 2;

    if (left >= right)
        return -1;
    if (a[mid] == key)
        return mid;
    if (a[mid] < key)
        return RecursiveBinarySearch(a, mid + 1, right, key);
    return RecursiveBinarySearch(a, left, mid - 1, key);
}
