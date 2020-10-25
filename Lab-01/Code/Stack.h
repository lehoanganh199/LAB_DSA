//
//  Stack.h
//  test-cpp
//
//  Created by Le Hoang Anh on 10/20/20.
//

#ifndef STACK_H_
#define STACK_H_

#include "LinkedList.h"

struct Stack {
    List* list;
};

// Initialize a stack from a given key.
Stack* makeStack(int key);

// Determine if a given stack is empty.
bool isEmpty(Stack* st);

// Count the number of elements of a given queue.
int count(Stack *st);

// Push a key into a given stack.
void push(Stack* &st, int key);

// Pop an element out of a given stack, return the key’s value.
int pop(Stack* &st);

#endif
