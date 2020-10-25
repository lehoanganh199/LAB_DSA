//
//  Recursion.h
//  test-cpp
//
//  Created by Le Hoang Anh on 10/19/20.
//

#ifndef RECURSION_H_
#define RECURSION_H_

// Findthetotalvalueofallintegersthatlessthanorequalton: S = 1 + 2 + ... + n.
int sumOfSquares(int n);

// Find the greatest common divisor of 2 integers a and b.
int GCD(int a, int b);

// Determine if a given array is palindrome.
bool isPalindrome(int a[], int n);

// Find the Factorial of a number.
bool isPalindromeRecursion(int a[], int left, int right);

// Count the digits of a given number.
int Factorial(int n);

// Find the nth Fibonacci number using by the following formula: F(n) = F(n − 1) + F(n − 2).
int countDigit(int n);

int Fib(int n);

#endif
