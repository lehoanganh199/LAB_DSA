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

Stack* makeStack(int key);

bool isEmpty(Stack* st);

int count(Stack *st);

void push(Stack* &st, int key);

int pop(Stack* &st);

#endif
