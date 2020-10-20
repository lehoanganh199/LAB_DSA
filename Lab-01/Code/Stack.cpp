//
//  Stack.cpp
//  test-cpp
//
//  Created by Le Hoang Anh on 10/20/20.
//

#include "Stack.h"

Stack* makeStack(int key) {
    Stack* st = new Stack;

    if (st != nullptr)
        addHead(st->list, key);

    return st;
}

bool isEmpty(Stack* st) {
    return st == nullptr || isEmpty(st->list);
}

int count(Stack *st) {
    if (isEmpty(st))
        return 0;

    return countElements(st->list);
}

void push(Stack* &st, int key) {
    if (isEmpty(st))
        st = makeStack(key);
    else
        addHead(st->list, key);
}

int pop(Stack* &st) {
    if (isEmpty(st))
        return -1;

    int top = st->list->head->key;
    removeHead(st->list);

    return top;
}
