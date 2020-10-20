//
//  Queue.cpp
//  test-cpp
//
//  Created by Le Hoang Anh on 10/20/20.
//

#include "Queue.h"

Queue* makeQueue(int key) {
    Queue* q = new Queue;

    if (q != nullptr)
        addHead(q->list, key);

    return q;
}

bool isEmpty(Queue* q) {
    return q == nullptr || isEmpty(q->list);
}

int count(Queue* q) {
    if (isEmpty(q))
        return 0;

    return countElements(q->list);
}

void enqueue(Queue* &q, int key) {
    if (isEmpty(q))
        q = makeQueue(key);
    else
        addTail(q->list, key);
}

int dequeue(Queue* &q) {
    if (isEmpty(q))
        return -1;

    int front = q->list->head->key;
    removeHead(q->list);

    return front;
}
