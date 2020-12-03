#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

void printList(DList* dList) {
    if (!isEmpty(dList)) {
        for (Node* p = dList->pHead; p; p = p->pNext)
            cout << p->key << " ";
        cout << endl;
    } else {
        cout << "empty" << endl;
    } 
}

void printReverseList(DList* dList) {
    if (!isEmpty(dList)) {
        for (Node* p = dList->pTail; p; p = p->pPrev)
            cout << p->key << " ";
        cout << endl;
    } else {
        cout << "empty" << endl;
    }
}

int main() {
    DList* dList = nullptr;
    printList(dList);
    dList = createList(19);
    printList(dList);

    addHead(dList, 16);
    printList(dList);
    addHead(dList, 13);
    printList(dList);
    addHead(dList, 100);
    printList(dList);

    addTail(dList, 58);
    printList(dList);
    addTail(dList, 60);
    printList(dList);
    addTail(dList, 42);
    printList(dList);

    insertBefore(dList, dList->pHead, 28);
    printList(dList);
    insertBefore(dList, dList->pHead->pNext->pNext, 30);
    printList(dList);
    insertBefore(dList, dList->pTail, 94);
    printList(dList);

    insertAfter(dList, dList->pHead, 67);
    printList(dList);
    insertAfter(dList, dList->pHead->pNext->pNext, 67);
    printList(dList);
    insertAfter(dList, dList->pTail, 90);
    printList(dList);

    removeHead(dList);
    printList(dList);
    removeTail(dList);
    printList(dList);
    removeFirstValue(dList, 53);
    printList(dList);
    removeFirstValue(dList, 60);
    printList(dList);

    removeAll(dList);

    return 0;
}
