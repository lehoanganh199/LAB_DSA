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

// Initialize a queue from a given key.
Queue* makeQueue(int key);

// Determine if a given queue is empty.
bool isEmpty(Queue* q);

// Count the number of element of a given queue.
int count(Queue* q);

// Enqueue a key into a given queue.
void enqueue(Queue* &q, int key);

// Dequeue an element out of a given queue, return the key’s value.
int dequeue(Queue* &q);

#endif
