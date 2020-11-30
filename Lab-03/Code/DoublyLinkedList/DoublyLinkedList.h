#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_

struct Node {
    int key;
    Node* pNext;
    Node* pPrev;
};

struct DList {
    Node* pHead;
    Node* pTail;
};

// Initialize a node from a given integer.
Node* createNode(int value);

// Initialize a list from a given integer.
DList* createList(int value);

// Check if the list is empty or not.
bool isEmpty(DList* dList);

// Add a node at the front of a given List.
bool addHead(DList* &dList, int value);

// Add a node before a given node.
bool insertBefore(DList* &dList, Node* &node, int value);

// Add a node after a given node.
bool insertAfter(DList* &dList, Node* &node, int value);

// Add a node at the end of a given List.
bool addTail(DList* &dList, int value);

// Remove a node at the front of a given List. 
void removeHead(DList* &dList);

// Remove a node at the end of a given List. 
void removeTail(DList* &dList);

// Remove the first node with given value.
void removeFirstValue(DList* &dList, int value);

// Remove all nodes.
void removeAll(DList* &dList);

#endif