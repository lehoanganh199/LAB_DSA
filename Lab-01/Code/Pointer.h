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

// Input a n-element integer array with int *a is the pointer point to the allocated dynamic memory.
void inputArray(int* &a, int &n);

// Remove allocated dynamic memory.
void deallocateArray(int* &a);

// Output all elements of the array.
void printArray(int* a, int n);

// Find the smallest value from the array.
int findMin(int* a, int n);

// Find the greatest absolute value from the array.
int findMaxAbsolute(int* a, int n);

// Determine if the array is ascending.
bool isAscending(int* a, int n);

// Find the total value of all elements of the array.
int sumOfArray(int* a, int n);

// Check if `n` is prime number or not.
bool isPrime(int n);

// Count the number of prime numbers in the array.
int countPrime(int* a, int n);

// Create a new dynamic array which is the reverse of the given array.
void reverseArray(int* &a, int* b, int n);

// Sequential Search.
// Returns the index of `key` value in the array.
// Returns -1 if the array not contains `key` value.
int LinearSearch(int* a, int n, int key);

// Sequential Search (using flag).
// Returns the index of `key` value in the array.
// Returns -1 if the array not contains `key` value.
int SentinelLinearSearch(int* a, int n, int key);

// Binary Search.
// Returns the index of `key` value in the array.
// Returns -1 if the array not contains `key` value.
int BinarySearch(int* a, int n, int key);

// Binary Search (using recursion).
// Returns the index of `key` value in the array.
// Returns -1 if the array not contains `key` value.
int RecursiveBinarySearch(int* a, int left, int right, int key);

#endif
