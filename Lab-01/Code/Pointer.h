//
//  Pointer.h
//  test-cpp
//
//  Created by Le Hoang Anh on 10/19/20.
//

#ifndef POINTER_H_
#define POINTER_H_

#include <iostream>

using namespace std;

void inputArray(int* &a, int &n);

void deallocateArray(int* &a);

void printArray(int* a, int n);

int findMin(int* a, int n);

int findMaxAbsolute(int* a, int n);

bool isAscending(int* a, int n);

int sumOfArray(int* a, int n);

bool isPrime(int n);

int countPrime(int* a, int n);

void reverseArray(int* &a, int* b, int n);

int LinearSearch(int* a, int n, int key);

int SentinelLinearSearch(int* a, int n, int key);

int BinarySearch(int* a, int n, int key);

int RecursiveBinarySearch(int* a, int left, int right, int key);

#endif
