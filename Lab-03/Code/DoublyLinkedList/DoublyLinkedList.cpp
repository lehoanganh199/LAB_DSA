#include "DoublyLinkedList.h"

d_NODE* createNode(int value) {
    d_NODE* node = new d_NODE;

    if (node != nullptr) {
        node->key = value;
        node->pNext = nullptr;
        node->pPrev = nullptr;
    }

    return node;
}

d_List* createList(int value) {
    d_List* dList = new d_List;

    if (dList != nullptr) {
        d_NODE* node = createNode(value);
        dList->pHead = dList->pTail = node;
    }

    return dList;
}

bool isEmpty(d_List* dList) {
    return dList == nullptr || dList->pHead == nullptr;
}

bool addHead(d_List* &dList, int value) {
    // if (isEmpty(dList)) {
    //     dList = createList(value);
    //     if (isEmpty(dList))
    //         return false;
    // } else {
    //     d_NODE* node = createNode(value);
    //     if (node == nullptr)
    //         return false;

    //     node->pNext = dList->pHead;
    //     dList->pHead->pPrev = node;
    //     dList->pHead = node;
    // }

    // return true;


    if (dList == nullptr) {
        dList = new d_List;
        if (dList == nullptr)
            return false;
    }

    d_NODE* node = createNode(value);
    if (node == nullptr)
        return false;

    node->pNext = dList->pHead;

    if (dList->pHead != nullptr)
        dList->pHead->pPrev = node;

    dList->pHead = node;

    return true;
}

bool insertBefore(d_List* &dList, d_NODE* &node, int value) {
    if (node == nullptr)
        return false;

    d_NODE* p = createNode(value);
    if (p == nullptr)
        return false;

    d_NODE* prev = node->pPrev;

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

bool insertAfter(d_List* &dList, d_NODE* &node, int value) {
    if (node == nullptr)
        return false;

    d_NODE* p = createNode(value);
    if (p == nullptr)
        return false;

    d_NODE* next = node->pNext;

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

bool addTail(d_List* &dList, int value) {
    // if (isEmpty(dList)) {
    //     dList = createList(value);
    //     if (isEmpty(dList))
    //         return false;
    // } else {
    //     d_NODE* node = createNode(value);
    //     if (node == nullptr)
    //         return false;

    //     node->pPrev = dList->pTail;
    //     dList->pTail->pNext = node;
    //     dList->pTail = node;
    // }

    // return true;


    if (dList == nullptr) {
        dList = new d_List;
        if (dList == nullptr)
            return false;
    }

    d_NODE* node = createNode(value);
    if (node == nullptr)
        return false;

    node->pPrev = dList->pTail;

    if (dList->pTail != nullptr)
        dList->pTail->pNext = node;

    dList->pTail = node;

    return true;
}

void removeHead(d_List* &dList) {
    if (isEmpty(dList))
        return;

    d_NODE* p = dList->pHead;
    dList->pHead = dList->pHead->pNext;

    if (dList->pHead == nullptr)
        dList->pTail = nullptr;
    else
        dList->pHead->pPrev = nullptr;

    delete p;
}

void removeTail(d_List* &dList) {
    if (isEmpty(dList))
        return;

    d_NODE* p = dList->pTail;
    dList->pTail = dList->pTail->pPrev;

    if (dList->pTail == nullptr)
        dList->pHead = nullptr;
    else
        dList->pTail->pNext = nullptr;

    delete p;
}

void removeFirstValue(d_List* &dList, int value) {
    if (isEmpty(dList))
        return;

    d_NODE* p = dList->pHead;
    while (p != nullptr && p->key != value)
        p = p->pNext;

    if (p != nullptr) {
        d_NODE* prev = p->pPrev;
        d_NODE* next = p->pNext;

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

void removeAll(d_List* &dList) {
    if (dList != nullptr) {
        if (dList->pHead != nullptr) {
            d_NODE* p = dList->pHead;

            while (dList->pHead != nullptr) {
                dList->pHead = dList->pHead->pNext;
                delete p;
                p = dList->pHead;
            }
        }

        delete dList;
        dList = nullptr;
    }
}