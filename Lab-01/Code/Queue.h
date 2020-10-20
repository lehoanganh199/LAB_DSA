//
//  Queue.h
//  test-cpp
//
//  Created by Le Hoang Anh on 10/20/20.
//

#ifndef QUEUE_H_
#define QUEUE_H_

#include "LinkedList.h"

struct Queue {
    List* list;
};

Queue* makeQueue(int key);

bool isEmpty(Queue* q);

int count(Queue* q);

void enqueue(Queue* &q, int key);

int dequeue(Queue* &q);

#endif
