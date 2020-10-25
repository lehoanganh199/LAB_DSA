//
//  LinkedList.h
//  test-cpp
//
//  Created by Le Hoang Anh on 10/20/20.
//

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

struct Node {
    int key;
    Node* next;
};

struct List {
    Node* head;
    Node* tail;
};

// Check if a `List` is empty or not.
// List empty: `List` is null or not contains any node.
bool isEmpty(List* list);

// Initialize a `Node` from a given integer.
Node* makeNode(int data);

// Initialize a `List` from a given node.
List* makeList(Node* node);

// Insert an integer to the head of a given `List`.
bool addHead(List* &list, int data);

// Insert an integer to the tail of a given `List`.
bool addTail(List* &list, int data);

// Remove the first `Node` of a given `List`.
void removeHead(List* &list);

// Remove the last `Node` of a given `List`.
void removeTail(List* &list);

// Remove all duplicates from a given `List`.
void removeDuplicate(List* &list);

// Remove all `key` value from a given `List`.
void removeElement(List* &list, int key);

// Remove all `Node` from a given `List`.
void removeAll(List* &list);

// Print all elements of a given `List`.
void printList(List* list);

// Count the number of elements.
int countElements(List* list);

// Create a new `List` by reverse a given `List`.
List* reverseList(List *list);

#endif
