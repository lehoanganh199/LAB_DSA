//
//  Recursion.cpp
//  test-cpp
//
//  Created by Le Hoang Anh on 10/19/20.
//

#include "Recursion.h"

int sumOfSquares(int n) {
    if (n <= 1)
        return 1;
    return (n * n) + sumOfSquares(n - 1);
}

int GCD(int a, int b) {
    if (a < 0)
        return GCD(-a, b);
    if (b < 0)
        return GCD(a, -b);

    if (b == 0)
        return a;
    return GCD(b, a % b);
}

bool isPalindrome(int a[], int n) {
    if (n < 0 || a == nullptr)
        return false;
    
    return isPalindromeRecursion(a, 0, n - 1);
}

bool isPalindromeRecursion(int a[], int left, int right) {
    if (left == right || left == right + 1)
        return a[left] == a[right];
    if (a[left] != a[right])
        return false;
    return isPalindromeRecursion(a, left + 1, right - 1);
}

int Factorial(int n) {
    if (n <= 1)
        return 1;

    return n * Factorial(n - 1);
}

int countDigit(int n) {
    if (n < 0)
        return countDigit(-n);

    if (n == 0)
        return 0;
    return 1 + countDigit(n / 10);
}

int Fib(int n) {
    if (n <= 2)
        return 1;
    return Fib(n - 1) + Fib(n - 2);
}

