#include "DoublyLinkedList.h"

Node* createNode(int value) {
    Node* node = new Node;

    if (node) {
        node->key = value;
        node->pNext = nullptr;
        node->pPrev = nullptr;
    }

    return node;
}

DList* createList(int value) {
    DList* dList = new DList;

    if (dList) {
        Node* node = createNode(value);
        dList->pHead = dList->pTail = node;
    }

    return dList;
}

bool isEmpty(DList* dList) {
    return dList == nullptr || dList->pHead == nullptr;
}

bool addHead(DList* &dList, int value) {
    if (dList == nullptr) {
        dList = new DList;
        if (dList == nullptr)
            return false;
    }

    Node* node = createNode(value);
    if (node == nullptr)
        return false;

    node->pNext = dList->pHead;

    if (dList->pHead)
        dList->pHead->pPrev = node;

    dList->pHead = node;

    return true;
}

bool insertBefore(DList* &dList, Node* &node, int value) {
    if (node == nullptr)
        return false;

    Node* p = createNode(value);
    if (p == nullptr)
        return false;

    Node* prev = node->pPrev;

    p->pNext = node;
    node->pPrev = p;
        
    if (prev == nullptr) 
        dList->pHead = p;
    else {
        prev->pNext = p;
        p->pPrev = prev;
    }

    return true;
}

bool insertAfter(DList* &dList, Node* &node, int value) {
    if (node == nullptr)
        return false;

    Node* p = createNode(value);
    if (p == nullptr)
        return false;

    Node* next = node->pNext;

    p->pPrev = node;
    node->pNext = p;
        
    if (next == nullptr) 
        dList->pTail = p;
    else {
        next->pPrev = p;
        p->pNext = next;
    }

    return true;
}

bool addTail(DList* &dList, int value) {
    if (dList == nullptr) {
        dList = new DList;
        if (dList == nullptr)
            return false;
    }

    Node* node = createNode(value);
    if (node == nullptr)
        return false;

    node->pPrev = dList->pTail;

    if (dList->pTail)
        dList->pTail->pNext = node;

    dList->pTail = node;

    return true;
}

void removeHead(DList* &dList) {
    if (isEmpty(dList))
        return;

    Node* p = dList->pHead;
    dList->pHead = dList->pHead->pNext;

    if (dList->pHead == nullptr)
        dList->pTail = nullptr;
    else
        dList->pHead->pPrev = nullptr;

    delete p;
}

void removeTail(DList* &dList) {
    if (isEmpty(dList))
        return;

    Node* p = dList->pTail;
    dList->pTail = dList->pTail->pPrev;

    if (dList->pTail == nullptr)
        dList->pHead = nullptr;
    else
        dList->pTail->pNext = nullptr;

    delete p;
}

void removeFirstValue(DList* &dList, int value) {
    if (isEmpty(dList))
        return;

    Node* p = dList->pHead;
    while (p && p->key != value)
        p = p->pNext;

    if (p) {
        Node* prev = p->pPrev;
        Node* next = p->pNext;

        if (prev == nullptr) // p is head.
            removeHead(dList);
        else if (next == nullptr) // p is tail.
            removeTail(dList);
        else {
            prev->pNext = next;
            next->pPrev = prev;
            delete p;
        }
    }
}

void removeAll(DList* &dList) {
    if (dList) {
        if (dList->pHead) {
            Node* p = dList->pHead;

            while (dList->pHead) {
                dList->pHead = dList->pHead->pNext;
                delete p;
                p = dList->pHead;
            }
        }

        delete dList;
        dList = nullptr;
    }
}