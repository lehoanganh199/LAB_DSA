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

bool isEmpty(List* list);

Node* makeNode(int data);
List* makeList(Node* node);

bool addHead(List* &list, int data);
bool addTail(List* &list, int data);

void removeHead(List* &list);
void removeTail(List* &list);
void removeDuplicate(List* &list);
void removeElement(List* &list, int key);
void removeAll(List* &list);

void printList(List* list);

int countElements(List* list);

List* reverseList(List *list);

#endif
