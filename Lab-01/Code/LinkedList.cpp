//
//  LinkedList.cpp
//  test-cpp
//
//  Created by Le Hoang Anh on 10/20/20.
//

#include "LinkedList.h"
#include <iostream>

using namespace std;

bool isEmpty(List* list) {
    return list == nullptr || list->head == nullptr;
}

Node* makeNode(int data) {
    Node* node = new Node;

    if (node != nullptr) {
        node->key = data;
        node->next = nullptr;
    }

    return node;
}

List* makeList(Node* node) {
    List* list = new List;

    if (list != nullptr) {
        list->head = list->tail = nullptr;

        for (Node* p = node; p; p = p->next)
            addTail(list, p->key);
    }

    return list;
}

bool addHead(List* &list, int data) {
    Node* node = makeNode(data);
    if (node == nullptr)
        return false;

    if (list == nullptr)
        list = makeList(nullptr);

    node->next = list->head;
    list->head = node;

    if (list->tail == nullptr)
        list->tail = list->head;

    return true;
}

bool addTail(List* &list, int data) {
    Node* node = makeNode(data);
    if (node == nullptr)
        return false;

    if (list == nullptr)
        list = makeList(nullptr);

    if (list->head == nullptr) {
        list->head = list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }

    return true;
}

void removeHead(List* &list) {
    if (isEmpty(list))
        return;

    if (list->head == list->tail)
        list->tail = list->tail->next;

    Node* temp = list->head;
    list->head = list->head->next;
    delete temp;
}

void removeTail(List* &list) {
    if (isEmpty(list))
        return;

    if (list->head == list->tail) {
        delete list->head;
        list->head = list->tail = nullptr;
    } else {
        Node* p = list->head;

        while (p->next != list->tail)
            p = p->next;

        delete list->tail;
        p->next = nullptr;
        p = list->tail;
    }
}

void removeAfter(Node* &node) {
    if (node != nullptr && node->next != nullptr) {
        Node* nextAfterRemoving = node->next->next;
        delete node->next;
        node->next = nextAfterRemoving;
    }
}

//void removeDuplicate(List* &list) {
//    if (list != nullptr && list->head != nullptr) {
//        Node* p = list->head;
//        Node* previousP = nullptr;
//
//        while (p != nullptr && p->next != nullptr) {
//            bool isDuplicated = false;
//            bool isIncreasedP = true;
//            int key = p->key;
//            Node* node = p;
//
//            while (node->next != nullptr) {
//                if (node->next->key == key) {
//                    removeAfter(node);
//                    isDuplicated = true;
//
//                    continue;
//                }
//
//                node = node->next;
//            }
//
//            // must remove p.
//            if (isDuplicated) {
//                if (node->key == key && node != p) { // node is tail.
//                    isIncreasedP = false;
//                    removeTail(list);
//                } else if (p == list->head) {
//                    removeHead(list);
//                    p = list->head;
//                } else if (p->next != nullptr)
//                    removeAfter(previousP);
//            }
//
//            if (!isIncreasedP)
//                p = p->next;
//        }
//    }
//}

void removeDuplicate(List* &list) {
    if (isEmpty(list))
        return;

    Node* p = list->head;
    Node* previousP = nullptr;

    while (p->next != nullptr) {
        bool isDuplicated = false;
        int key = p->key;
        Node* node = p->next;
        Node* previousNode = p;

        while (node != nullptr) {
            if (node->key == key) {
                node = node->next;
                if (node == nullptr)
                    list->tail = previousNode;

                removeAfter(previousNode);
                isDuplicated = true;

                continue;
            }

            previousNode = node;
            node = node->next;
        }

        // must remove p.
        if (isDuplicated) {
            if (p == list->head) {
                removeHead(list);

                p = list->head;
                previousP = nullptr;
            } else {
                if (p == list->tail)
                    list->tail = previousP;

                p = p->next;
                removeAfter(previousP);
            }

            if (list->head == nullptr || list->tail == previousP)
                return;
        } else {
            previousP = p;
            p = p->next;
        }
    }
}

void removeElement(List* &list, int key) {
    if (isEmpty(list))
        return;

    Node* node = list->head;
    Node* previousNode = nullptr;

    while (node->next != nullptr) {
        if (node->next->key == key) {
            removeAfter(node);
            continue;
        }

        previousNode = node;
        node = node->next;
    }

    if (node != list->head && node->key == key)
        removeAfter(previousNode);
    if (list->head->key == key)
        removeHead(list);
}

void removeAll(List* &list) {
    if (list != nullptr) {
        while (list->head != nullptr) {
            Node* temp = list->head;
            list->head = list->head->next;
            delete temp;
        }

        delete list;
        list = nullptr;
    }
}

void printList(List* list) {
    if (!isEmpty(list)) {
        for (Node* p = list->head; p; p = p->next)
            cout << p->key << " ";

        cout << endl;
    }
}

int countElements(List* list) {
    int count = 0;

    if (!isEmpty(list))
        for (Node* p = list->head; p; p = p->next)
            ++count;

    return count;
}

List* reverseList(List* list) {
    List* reversed = nullptr;

    if (!isEmpty(list)) {
        reversed = makeList(nullptr);

        for (Node* p = list->head; p; p = p->next)
            addHead(reversed, p->key);
    }

    return reversed;
}
